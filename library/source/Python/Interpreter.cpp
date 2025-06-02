#include "Python/Interpreter.hpp"

namespace Sola::Python {
    Interpreter::Interpreter(PyConfig &Config, const std::vector<InternalModule>& InternalModules) {
        for (auto &InternalModule : InternalModules) {
            PyImport_AppendInittab(InternalModule.ModuleName, InternalModule.moduleInit);
        }

        PyStatus Status = Py_InitializeFromConfig(&Config);
        PyConfig_Clear(&Config);
        if (PyStatus_Exception(Status) != 0) {
            if (PyStatus_IsError(Status) != 0) {
                printError(Status.err_msg);
            }
            return;
        }
        Initialized = true;
    }

    Interpreter::Interpreter(Interpreter &&Other) noexcept
        : Initialized(std::exchange(Other.Initialized, false)), Modules(std::move(Other.Modules)) {}

    Interpreter::~Interpreter() noexcept {
        if (!Initialized) {
            return;
        }

        for (auto &[ModuleName, Module] : Modules) {
            Py_XDECREF(Module);
        }

        Modules.clear();

        if (Py_FinalizeEx() < 0) {
            printError("Found python interpreter errors during finalization "
                       "(flushing buffered data)");
        }
    }

    auto Interpreter::isInitialized() const noexcept -> bool { return Initialized; }

    auto Interpreter::importModule(const std::string &ModuleName) -> bool {
        if (!Initialized) {
            return false;
        }

        PyObject *Module = PyImport_ImportModule(ModuleName.c_str());

        if (Module == nullptr) {
            if (PyErr_Occurred() != nullptr) {
                PyErr_Print();
            }
            printError("Failed to load Module \"" + ModuleName + "\"");
            return false;
        }

        this->Modules[ModuleName] = Module;

        return true;
    }

    auto Interpreter::runFunction(PyObject *Object, const std::string &MethodName, const std::vector<PyObject *> &Args,
                                  const std::unordered_map<std::string, PyObject *> &Kwargs)
        -> std::expected<PyObject *, InterpreterError> {
        if (!Initialized) {
            return std::unexpected(InterpreterError::InterpNotInitialized);
        }

        if (Object == nullptr) {
            return std::unexpected(InterpreterError::ObjectDoesNotExist);
        }

        std::expected<PyObject *, InterpreterError> Result = nullptr;

        PyObject *Function = nullptr;
        std::expected<PyObject *, InterpreterError> Attribute = getAttribute(Object, MethodName);
        if (!Attribute.has_value() || (Function = Attribute.value()) == nullptr) {
            return Attribute;
        }

        if (PyCallable_Check(Function) != 1) {
            Py_DECREF(Function);
            printWarning("Python object '" + MethodName + "' is not callable.");
            return std::unexpected(InterpreterError::ObjectIsNotCallable);
        }

        PyObject *PyArgs = PyTuple_New(Args.size());
        PyObject *PyKwargs = PyDict_New();
        PyObject *PyKey = nullptr;
        if (PyArgs == nullptr || PyKwargs == nullptr) {
            Result = std::unexpected(InterpreterError::PythonObjectAllocationFailed);
            goto Finish;
        }

        for (u64 i = 0; i < Args.size(); i++) {
            PyTuple_SetItem(PyArgs, i, Args[i]);
            if (PyErr_Occurred() != nullptr) {
                PyErr_Print();
                return std::unexpected(InterpreterError::FunctionCallFailed);
            }
        }

        for (const auto &[Key, Value] : Kwargs) {
            if ((PyKey = PyUnicode_FromString(Key.c_str())) == nullptr) {
                printWarning("Cannot convert Key '" + Key + "' to Python Unicode");
                Result = std::unexpected(InterpreterError::FunctionCallFailed);
                goto Finish;
            }
            PyDict_SetItem(PyKwargs, PyKey, Value);
            if (PyErr_Occurred() != nullptr) {
                PyErr_Print();
                Result = std::unexpected(InterpreterError::FunctionCallFailed);
                goto Finish;
            }
        }

        Result = PyObject_Call(Function, PyArgs, PyKwargs);

        if (Result == nullptr) {
            if (PyErr_Occurred() != nullptr) {
                PyErr_Print();
            }
            printWarning("Python Function '" + MethodName + "' call failed (returned null pointer).");
            Result = std::unexpected(InterpreterError::FunctionCallFailed);
            goto Finish;
        }

    Finish:
        Py_DECREF(Function);
        Py_XDECREF(PyArgs);
        Py_XDECREF(PyKwargs);
        return Result;
    }

    auto Interpreter::runFunction(const std::string &ModuleName, const std::string &function_name,
                                  const std::vector<PyObject *> &Args,
                                  const std::unordered_map<std::string, PyObject *> &Kwargs)
        -> std::expected<PyObject *, InterpreterError> {
        if (!this->Modules.contains(ModuleName)) {
            return std::unexpected(InterpreterError::NoModulesAvailable);
        }

        PyObject *Module = this->Modules[ModuleName];
        return runFunction(Module, function_name, Args, Kwargs);
    }

    auto Interpreter::getAttribute(PyObject *Object, const std::string &AttributeName)
        -> std::expected<PyObject *, InterpreterError> {
        PyObject *Result = nullptr;
        if (!this->Initialized || Object == nullptr || PyObject_GetOptionalAttrString(Object, AttributeName.c_str(), &Result) != 1 ||
            Result == nullptr) {
            return std::unexpected(InterpreterError::ObjectDoesNotExist);
        }

        return Result;
    }

    auto Interpreter::getAttribute(const std::string &ModuleName, const std::string &AttributeName)
        -> std::expected<PyObject *, InterpreterError> {
        if (!this->Initialized || !Modules.contains(ModuleName)) {
            return std::unexpected(InterpreterError::NoModulesAvailable);
        }

        PyObject *Module = Modules[ModuleName];
        return getAttribute(Module, AttributeName);
    }

    auto Interpreter::setAttribute(PyObject *Object, const std::string &AttributeName, PyObject *Value)
        -> std::expected<PyObject *, InterpreterError> {
        if (!this->Initialized || Object == nullptr || Value == nullptr) {
            return std::unexpected(InterpreterError::SetAttributeFailed);
        }
        PyObject *PyAttributeName = PyUnicode_FromString(AttributeName.c_str());
        if (PyAttributeName == nullptr) {
            return std::unexpected(InterpreterError::TransformStringToUnicodeFailed);
        }
        if (PyObject_SetAttr(Object, PyAttributeName, Value) != 0) {
            if (PyErr_Occurred() != nullptr) {
                PyErr_Print();
            }
            return std::unexpected(InterpreterError::SetAttributeFailed);
        }
        return Object;
    }

    auto Interpreter::setAttribute(PyObject *Object, const std::string &AttributeName, const std::string &Value)
        -> std::expected<PyObject *, InterpreterError> {
        PyObject *PyValue = PyUnicode_FromString(Value.c_str());
        if (!this->Initialized || PyValue == nullptr) {
            return std::unexpected(InterpreterError::TransformStringToUnicodeFailed);
        }
        return setAttribute(Object, AttributeName, PyValue);
    }

    auto Interpreter::setAttribute(PyObject *Object, const std::string &AttributeName, i64 Value)
        -> std::expected<PyObject *, InterpreterError> {
        PyObject *PyValue = PyLong_FromInt64(Value);
        if (!this->Initialized || PyValue == nullptr) {
            return std::unexpected(InterpreterError::SetAttributeFailed);
        }
        return setAttribute(Object, AttributeName, PyValue);
    }

    auto Interpreter::setAttribute(PyObject *Object, const std::string &AttributeName, u64 Value)
        -> std::expected<PyObject *, InterpreterError> {
        PyObject *PyValue = PyLong_FromUInt64(Value);
        if (!this->Initialized || PyValue == nullptr) {
            return std::unexpected(InterpreterError::SetAttributeFailed);
        }
        return setAttribute(Object, AttributeName, PyValue);
    }

    auto Interpreter::deleteAttribute(PyObject *Object, const std::string &AttributeName)
        -> std::expected<void, InterpreterError> {
        if (!this->Initialized || Object == nullptr) {
            return std::unexpected(InterpreterError::DelAttributeFailed);
        }
        PyObject *PyAttributeName = PyUnicode_FromString(AttributeName.c_str());
        if (PyAttributeName == nullptr) {
            return std::unexpected(InterpreterError::TransformStringToUnicodeFailed);
        }
        if (PyObject_DelAttr(Object, PyAttributeName) == -1) {
            if (PyErr_Occurred() != nullptr) {
                PyErr_Print();
            }
            return std::unexpected(InterpreterError::DelAttributeFailed);
        }
        return {};
    }

} // namespace Sola::Python
