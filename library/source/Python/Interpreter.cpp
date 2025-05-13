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

        bool Interpreter::is_initialized() noexcept { return _initialized; }

        bool Interpreter::import_module(const std::string &module_name)
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

        EXPORTED std::expected<PyObject *, InterpreterError>
        Interpreter::run_function(PyObject *object, const std::string &method_name, const std::vector<PyObject *> &args,
                                  const std::unordered_map<std::string, PyObject *> &kwargs)
        {
            if (!_initialized)
            {
                return std::unexpected(InterpreterError::InterpNotInitialized);
            }

            if (object == nullptr)
            {
                return std::unexpected(InterpreterError::ObjectDoesNotExist);
            }

            std::expected<PyObject *, InterpreterError> result = nullptr;

            PyObject *function = nullptr;
            std::expected<PyObject *, InterpreterError> attribute = get_attribute(object, method_name);
            if (!attribute.has_value() || (function = attribute.value()) == nullptr)
            {
                return attribute;
            }

            if (!PyCallable_Check(function))
            {
                Py_DECREF(function);
                print_warning("Python object '" + method_name + "' is not callable.");
                return std::unexpected(InterpreterError::ObjectIsNotCallable);
            }

            PyObject *py_args = PyTuple_New(args.size());
            PyObject *py_kwargs = PyDict_New();
            PyObject *py_key = nullptr;
            if (py_args == nullptr || py_kwargs == nullptr)
            {
                result = std::unexpected(InterpreterError::PythonObjectAllocationFailed);
                goto finish;
            }

            for (u64 i = 0; i < args.size(); i++)
            {
                PyTuple_SetItem(py_args, i, args[i]);
                if (PyErr_Occurred() != nullptr)
                {
                    PyErr_Print();
                    return std::unexpected(InterpreterError::FunctionCallFailed);
                }
            }

            for (auto &[key, value] : kwargs)
            {
                if ((py_key = PyUnicode_FromString(key.c_str())) == 0)
                {
                    print_warning("Cannot convert key '" + key + "' to Python Unicode");
                    result = std::unexpected(InterpreterError::FunctionCallFailed);
                    goto finish;
                }
                PyDict_SetItem(py_kwargs, py_key, value);
                if (PyErr_Occurred() != nullptr)
                {
                    PyErr_Print();
                    result = std::unexpected(InterpreterError::FunctionCallFailed);
                    goto finish;
                }
            }

            result = PyObject_Call(function, py_args, py_kwargs);

            if (result == nullptr)
            {
                if (PyErr_Occurred())
                {
                    PyErr_Print();
                }
                print_warning("Python function '" + method_name + "' call failed (returned null pointer).");
                result = std::unexpected(InterpreterError::FunctionCallFailed);
                goto finish;
            }

        finish:
            Py_DECREF(function);
            Py_XDECREF(py_args);
            Py_XDECREF(py_kwargs);
            return result;
        }

        std::expected<PyObject *, InterpreterError>
        Interpreter::run_function(const std::string &module_name, const std::string &function_name,
                                  const std::vector<PyObject *> &args, const std::unordered_map<std::string, PyObject *> &kwargs)
        {
            if (_modules.count(module_name) == 0)
            {
                return std::unexpected(InterpreterError::NoModulesAvailable);
            }

            PyObject *module = _modules[module_name];
            return run_function(module, function_name, args, kwargs);
        }

        EXPORTED std::expected<PyObject *, InterpreterError>
        Interpreter::get_attribute(PyObject *object, const std::string &attribute_name)
        {
            PyObject *result = nullptr;
            if (object == nullptr || PyObject_GetOptionalAttrString(object, attribute_name.c_str(), &result) != 1 ||
                result == nullptr)
            {
                return std::unexpected(InterpreterError::ObjectDoesNotExist);
            }

            return result;
        }

        EXPORTED std::expected<PyObject *, InterpreterError>
        Interpreter::get_attribute(const std::string &module_name, const std::string &attribute_name)
        {
            if (_modules.count(module_name) == 0)
            {
                return std::unexpected(InterpreterError::NoModulesAvailable);
            }

            PyObject *module = _modules[module_name];
            return get_attribute(module, attribute_name);
        }

        EXPORTED std::expected<PyObject *, InterpreterError>
        Interpreter::set_attribute(PyObject *object, const std::string &attribute_name, PyObject *value)
        {
            if (object == nullptr || value == nullptr)
            {
                return std::unexpected(InterpreterError::SetAttributeFailed);
            }
            PyObject *py_attribute_name = PyUnicode_FromString(attribute_name.c_str());
            if (py_attribute_name == nullptr)
            {
                return std::unexpected(InterpreterError::TransformStringToUnicodeFailed);
            }
            if (PyObject_SetAttr(object, py_attribute_name, value) != 0)
            {
                if (PyErr_Occurred() != nullptr)
                {
                    PyErr_Print();
                }
                return std::unexpected(InterpreterError::SetAttributeFailed);
            }
            return object;
        }

        EXPORTED std::expected<PyObject *, InterpreterError>
        Interpreter::set_attribute(PyObject *object, const std::string &attribute_name, const std::string &value)
        {
            PyObject *py_value = PyUnicode_FromString(value.c_str());
            if (py_value == nullptr)
            {
                return std::unexpected(InterpreterError::TransformStringToUnicodeFailed);
            }
            return set_attribute(object, attribute_name, py_value);
        }

        EXPORTED std::expected<PyObject *, InterpreterError>
        Interpreter::set_attribute(PyObject *object, const std::string &attribute_name, i64 value)
        {
            PyObject *py_value = PyLong_FromInt64(value);
            if (py_value == nullptr)
            {
                return std::unexpected(InterpreterError::SetAttributeFailed);
            }
            return set_attribute(object, attribute_name, py_value);
        }

        EXPORTED std::expected<PyObject *, InterpreterError>
        Interpreter::set_attribute(PyObject *object, const std::string &attribute_name, u64 value)
        {
            PyObject *py_value = PyLong_FromUInt64(value);
            if (py_value == nullptr)
            {
                return std::unexpected(InterpreterError::SetAttributeFailed);
            }
            return set_attribute(object, attribute_name, py_value);
        }

        EXPORTED std::expected<void, InterpreterError> Interpreter::delete_attribute(PyObject *object,
                                                                                     const std::string &attribute_name)
        {
            if (object == nullptr)
            {
                return std::unexpected(InterpreterError::SetAttributeFailed);
            }
            PyObject *py_attribute_name = PyUnicode_FromString(attribute_name.c_str());
            if (py_attribute_name == nullptr)
            {
                return std::unexpected(InterpreterError::TransformStringToUnicodeFailed);
            }
            if (PyObject_DelAttr(object, py_attribute_name) == -1)
            {
                if (PyErr_Occurred() != nullptr)
                {
                    PyErr_Print();
                }
                return std::unexpected(InterpreterError::DelAttributeFailed);
            }
            return {};
        }

    } // namespace Python
} // namespace Sola
