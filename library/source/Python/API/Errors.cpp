#include "Graphics/WindowsManager.hpp"
#include "Logger/Logger.hpp"
#include "Python/API/API.hpp"

// NOLINTBEGIN(readability-named-parameter): Most of those unnamed parameters are Python API Self and Args that we do
// not need. Also, cppcheck and complier won't be happy with named, but unused parameters.

namespace Sola::Python::API::Errors {
    /// @brief Keywords for the error handling functions.
    static const std::array<const char *, 2> Kwlist = {"What", nullptr};

    /// @brief This function is used to parse the arguments for the functions in this Module.
    /// @param FunctionName The name of the function being called.
    /// @param Args The arguments passed to the function.
    /// @param Kwds The keyword arguments passed to the function.
    /// @return An optional string containing the parsed argument.
    auto parseArgs(const std::string &FunctionName, PyObject *Args, PyObject *Kwds) -> std::optional<std::string> {
        const char *What = nullptr;
        if (!PyArg_ParseTupleAndKeywords(Args, Kwds, ("s:" + FunctionName).c_str(), Kwlist.data(), &What) ||
            What == nullptr) {
            PyErr_SetString(PyExc_RuntimeError, FormattingError);
            return std::nullopt;
        }
        return std::string(What);
    }

    auto raiseWarning(PyObject *, PyObject *Args, PyObject *Kwds) -> PyObject * {
        std::optional<std::string> Text = parseArgs("raiseWarning", Args, Kwds);
        if (!Text.has_value()) {
            return nullptr;
        }
        printWarning(Text.value());
        Sola::Graphics::WindowsManager::showWarningMessageBox(Text.value());
        return Py_None;
    }

    auto raiseError(PyObject *, PyObject *Args, PyObject *Kwds) -> PyObject * {
        std::optional<std::string> Text = parseArgs("raiseError", Args, Kwds);
        if (!Text.has_value()) {
            return nullptr;
        }
        printError(Text.value());
        Sola::Graphics::WindowsManager::showErrorMessageBox(Text.value());
        return Py_None;
    }

    auto raiseFatal(PyObject *, PyObject *Args, PyObject *Kwds) -> PyObject * {
        std::optional<std::string> Text = parseArgs("raiseFatal", Args, Kwds);
        if (!Text.has_value()) {
            return nullptr;
        }
        printFatal(Text.value());
        Sola::Graphics::WindowsManager::showFatalMessageBox(Text.value());
        return Py_None;
    }

    auto getModuleFields(PyObject *Module) -> std::vector<Helpers::PythonModule::NamedPythonObject> {
        return {
            Helpers::PythonModule::NamedPythonObject("raiseWarning",
                                                     PyCFunction_NewEx(&RaiseWarningDef, nullptr, Module)),
            Helpers::PythonModule::NamedPythonObject("raiseError", PyCFunction_NewEx(&RaiseErrorDef, nullptr, Module)),
            Helpers::PythonModule::NamedPythonObject("raiseFatal", PyCFunction_NewEx(&RaiseFatalDef, nullptr, Module))};
    }
} // namespace Sola::Python::API::Errors

// NOLINTEND(readability-named-parameter)
