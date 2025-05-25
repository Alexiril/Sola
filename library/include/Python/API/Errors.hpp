#ifndef PYTHON_API_ERRORS_HPP
#define PYTHON_API_ERRORS_HPP

#include "Helpers/PythonModule.hpp"
#include "SolaCommon.hpp"

namespace Sola::Python::API {
    /// @brief This namespace contains all the code related to the Sola Python API Errors module.
    namespace Errors {
        static const char *ModuleName = "Errors";

        /// @brief Raises a warning inside the C++ backend.
        /// @param Self not used.
        /// @param Args function arguments are used to get the warning text from the Python side to C++ backend.
        /// @param Kwds the key-value arguments may be used to pass the warning from Python to C++.
        /// @return A pointer to the Python None object.
        EXPORTED PyObject *raiseWarning(PyObject *Self, PyObject *Args, PyObject *Kwds);

        static PyMethodDef RaiseWarningDef = {"raiseWarning", reinterpret_cast<PyCFunction>(raiseWarning),
                                              METH_VARARGS | METH_KEYWORDS, "Raises warning inside C++ backend"};

        /// @brief Raises an error inside the C++ backend.
        /// @param Self not used.
        /// @param Args function arguments are used to get the error text from the Python side to C++ backend.
        /// @param Kwds the key-value arguments may be used to pass the error from Python to C++.
        /// @return A pointer to the Python None object.
        EXPORTED PyObject *raiseError(PyObject *Self, PyObject *Args, PyObject *Kwds);

        static PyMethodDef RaiseErrorDef = {"raiseError", reinterpret_cast<PyCFunction>(raiseError),
                                            METH_VARARGS | METH_KEYWORDS, "Raises error inside C++ backend"};

        /// @brief Raises an fatal error inside the C++ backend.
        /// @param Self not used.
        /// @param Args function arguments are used to get the error text from the Python side to C++ backend.
        /// @param Kwds the key-value arguments may be used to pass the error from Python to C++.
        /// @return A pointer to the Python None object.
        EXPORTED PyObject *raiseFatal(PyObject *Self, PyObject *Args, PyObject *Kwds);

        static PyMethodDef RaiseFatalDef = {"raiseFatal", reinterpret_cast<PyCFunction>(raiseFatal),
                                            METH_VARARGS | METH_KEYWORDS, "Raises fatal error inside C++ backend"};

        /// @brief This function makes an array of named python object which should be registered inside this
        /// module
        /// @param Module the actual module
        /// @return the vector of the name-object pointer pairs. May include functions, classes, values, etc.
        EXPORTED std::vector<Helpers::PythonModule::NamedPythonObject> getModuleFields(PyObject *Module);
    } // namespace Errors
} // namespace Sola::Python::API
#endif
