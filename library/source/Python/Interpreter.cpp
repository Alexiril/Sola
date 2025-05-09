#include "Python/Interpreter.hpp"

namespace Sola
{
    namespace Python
    {
        Interpreter::Interpreter(Interpreter &&other)
            : _initialized(std::exchange(other._initialized, false)), _modules(std::move(other._modules))
        {
        }

        Interpreter::~Interpreter() noexcept
        {
            if (!_initialized)
            {
                return;
            }

            for (auto &[module_name, module] : _modules)
            {
                Py_XDECREF(module);
            }

            _modules.clear();

            if (Py_FinalizeEx() < 0)
            {
                print_error("Found python interpreter errors during finalization "
                            "(flushing buffered data)");
            }
        }

        bool Interpreter::IsInitialized() noexcept { return _initialized; }

        bool Interpreter::ImportModule(const std::string &module_name)
        {
            if (!_initialized)
            {
                return false;
            }

            PyObject *module = PyImport_ImportModule(module_name.c_str());

            if (module == nullptr)
            {
                if (PyErr_Occurred())
                {
                    PyErr_Print();
                }
                print_error("Failed to load module \"" + module_name + "\"");
                return false;
            }

            _modules[module_name] = module;

            return true;
        }

        std::expected<PyObject *, InterpreterError>
        Interpreter::RunFunction(const std::string &module_name, const std::string &function_name,
                                 std::vector<PyObject *> args, std::unordered_map<std::string, PyObject *> kwargs)
        {
            if (!_initialized || _modules.count(module_name) == 0)
            {
                return std::unexpected(InterpreterError::RunFunctionInterpNotInitialized);
            }

            // No clear reference
            PyObject *module = _modules[module_name];

            // New references
            PyObject *func = PyObject_GetAttrString(module, function_name.c_str());
            if (func == 0)
            {
                print_warning("Python object '" + module_name + "." + function_name +
                              "' can't be used (does it exist?).");
                return std::unexpected(InterpreterError::RunFunctionObjectDoesNotExist);
            }

            if (!PyCallable_Check(func))
            {
                Py_DECREF(func);
                print_warning("Python object '" + module_name + "." + function_name + "' is not callable.");
                return std::unexpected(InterpreterError::RunFunctionObjectIsNotCallable);
            }

            PyObject *py_args = PyTuple_New(args.size());
            for (u64 i = 0; i < args.size(); i++)
            {
                PyTuple_SetItem(py_args, i, args[i]);
            }

            PyObject *py_kwargs = PyDict_New();
            for (auto &[key, value] : kwargs)
            {
                PyObject *py_key = PyUnicode_FromString(key.c_str());
                if (py_key == 0)
                {
                    print_warning("Cannot convert key '" + key + "' to Python Unicode");
                }
                else
                {
                    PyDict_SetItem(py_kwargs, py_key, value);
                }
            }

            PyObject *result = PyObject_Call(func, py_args, py_kwargs);
            Py_DECREF(py_args);
            Py_DECREF(py_kwargs);
            Py_DECREF(func);
            if (result == 0)
            {
                if (PyErr_Occurred())
                {
                    PyErr_Print();
                }
                print_warning("Python function '" + module_name + "." + function_name + "' call failed.");
                return std::unexpected(InterpreterError::RunFunctionCallFailed);
            }

            return result;
        }
    } // namespace Python
} // namespace Sola
