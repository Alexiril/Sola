#include "Logger/Logger.hpp"
#include "Python/API/API.hpp"

// NOLINTBEGIN(readability-named-parameter): Most of those unnamed parameters are Python API Self and Args that we do
// not need. Also, cppcheck and complier won't be happy with named, but unused parameters.

namespace Sola::Python::API::Logger {
    /// @brief Keyword list for the log printing functions.
    static const std::array<const char *, 2> Kwlist = {"What", nullptr};

    /// @brief Prints the log information.
    /// @param Args The arguments passed to the function.
    /// @param Kwds The keyword arguments passed to the function.
    /// @param FunctionName The name of the function being called.
    /// @param Severity the severity level of the log.
    /// @return A pointer to the Python None object.
    auto pyPrintLog(PyObject *Args, PyObject *Kwds, const std::string &FunctionName, Sola::Logger::Severity Severity)
        -> PyObject * {
        const char *What = nullptr;
        if (PyArg_ParseTupleAndKeywords(Args, Kwds, ("s:" + FunctionName).c_str(), Kwlist.data(), &What) == 0 ||
            What == nullptr) {
            PyErr_SetString(PyExc_RuntimeError, FormattingError);
            return nullptr;
        }
        print(What, Severity);
        return Py_None;
    }

    auto pyPrintDebug(PyObject *, PyObject *Args, PyObject *Kwds) -> PyObject * {
        return pyPrintLog(Args, Kwds, "printDebug", Sola::Logger::Severity::Debug);
    }

    auto pyPrintInfo(PyObject *, PyObject *Args, PyObject *Kwds) -> PyObject * {
        return pyPrintLog(Args, Kwds, "printInfo", Sola::Logger::Severity::Info);
    }

    auto pyPrintWarning(PyObject *, PyObject *Args, PyObject *Kwds) -> PyObject * {
        return pyPrintLog(Args, Kwds, "printWarning", Sola::Logger::Severity::Warning);
    }

    auto pyPrintError(PyObject *, PyObject *Args, PyObject *Kwds) -> PyObject * {
        return pyPrintLog(Args, Kwds, "printError", Sola::Logger::Severity::Error);
    }

    auto pyPrintFatal(PyObject *, PyObject *Args, PyObject *Kwds) -> PyObject * {
        return pyPrintLog(Args, Kwds, "printFatal", Sola::Logger::Severity::Fatal);
    }

    auto getModuleFields(PyObject *Module) -> std::vector<Helpers::PythonModule::NamedPythonObject> {
        return {
            Helpers::PythonModule::NamedPythonObject("printDebug", PyCFunction_NewEx(&PrintDebugDef, nullptr, Module)),
            Helpers::PythonModule::NamedPythonObject("printInfo", PyCFunction_NewEx(&PrintInfoDef, nullptr, Module)),
            Helpers::PythonModule::NamedPythonObject("printWarning",
                                                     PyCFunction_NewEx(&PrintWarningDef, nullptr, Module)),
            Helpers::PythonModule::NamedPythonObject("printError", PyCFunction_NewEx(&PrintErrorDef, nullptr, Module)),
            Helpers::PythonModule::NamedPythonObject("printFatal", PyCFunction_NewEx(&PrintFatalDef, nullptr, Module))};
    }
} // namespace Sola::Python::API::Logger

// NOLINTEND(readability-named-parameter)
