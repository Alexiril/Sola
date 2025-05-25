#ifndef PYTHON_API_LOGGER_HPP
#define PYTHON_API_LOGGER_HPP

#include "Helpers/PythonModule.hpp"
#include "SolaCommon.hpp"

/// @brief This namespace contains all the code related to the Sola Python API Logger module.
namespace Sola::Python::API::Logger {
    static const char *ModuleName = "Logger";

    /// @brief Prints the debug log information. Wrapper for the `Sola::Logger::printDebug` function.
    /// @param Self
    /// @param Args the arguments are used to pass the text to the C++ backend.
    /// @param Kwds the key-value arguments may be used to pass the text from Python to C++.
    /// @return A pointer to the Python None object.
    EXPORTED auto pyPrintDebug(PyObject *Self, PyObject *Args, PyObject *Kwds) -> PyObject *;

    static PyMethodDef PrintDebugDef = {"printDebug", reinterpret_cast<PyCFunction>(pyPrintDebug),
                                        METH_VARARGS | METH_KEYWORDS, "Prints the debug log information."};

    /// @brief Prints the info log information. Wrapper for the `Sola::Logger::printInfo` function.
    /// @param Self
    /// @param Args the arguments are used to pass the text to the C++ backend.
    /// @param Kwds the key-value arguments may be used to pass the text from Python to C++.
    /// @return A pointer to the Python None object.
    EXPORTED auto pyPrintInfo(PyObject *Self, PyObject *Args, PyObject *Kwds) -> PyObject *;

    static PyMethodDef PrintInfoDef = {"printInfo", reinterpret_cast<PyCFunction>(pyPrintInfo),
                                       METH_VARARGS | METH_KEYWORDS, "Prints the info log information."};

    /// @brief Prints the warning log information. Wrapper for the `Sola::Logger::printWarning` function.
    /// @param Self
    /// @param Args the arguments are used to pass the text to the C++ backend.
    /// @param Kwds the key-value arguments may be used to pass the text from Python to C++.
    /// @return A pointer to the Python None object.
    EXPORTED auto pyPrintWarning(PyObject *Self, PyObject *Args, PyObject *Kwds) -> PyObject *;

    static PyMethodDef PrintWarningDef = {"printWarning", reinterpret_cast<PyCFunction>(pyPrintWarning),
                                          METH_VARARGS | METH_KEYWORDS, "Prints the warning log information."};

    /// @brief Prints the error log information. Wrapper for the `Sola::Logger::printError` function.
    /// @param Self
    /// @param Args the arguments are used to pass the text to the C++ backend.
    /// @param Kwds the key-value arguments may be used to pass the text from Python to C++.
    /// @return A pointer to the Python None object.
    EXPORTED auto pyPrintError(PyObject *Self, PyObject *Args, PyObject *Kwds) -> PyObject *;

    static PyMethodDef PrintErrorDef = {"printError", reinterpret_cast<PyCFunction>(pyPrintError),
                                        METH_VARARGS | METH_KEYWORDS, "Prints the error log information."};

    /// @brief Prints the fatal error log information. Wrapper for the `Sola::Logger::printFatal` function.
    /// @param Self
    /// @param Args the arguments are used to pass the text to the C++ backend.
    /// @param Kwds the key-value arguments may be used to pass the text from Python to C++.
    /// @return A pointer to the Python None object.
    EXPORTED auto pyPrintFatal(PyObject *Self, PyObject *Args, PyObject *Kwds) -> PyObject *;

    static PyMethodDef PrintFatalDef = {"printFatal", reinterpret_cast<PyCFunction>(pyPrintFatal),
                                        METH_VARARGS | METH_KEYWORDS, "Prints the fatal log information."};

    /// @brief This function makes an array of named python object which should be registered inside this
    /// module
    /// @param Module the actual module
    /// @return the vector of the name-object pointer pairs. May include functions, classes, values, etc.
    EXPORTED auto getModuleFields(PyObject *Module) -> std::vector<Helpers::PythonModule::NamedPythonObject>;
} // namespace Sola::Python::API::Logger
#endif
