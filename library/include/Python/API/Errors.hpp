#ifndef SOLA_PYTHON_API_ERRORS
#define SOLA_PYTHON_API_ERRORS

#include "Helpers/PythonModule.hpp"
#include "sola_common.hpp"

namespace Sola
{
    namespace Python
    {
        namespace API
        {
            /// @brief This namespace contains all the code related to the Sola Python API Errors module.
            namespace Errors
            {
                static const char *module_name = "Errors";

                /// @brief Raises a warning inside the C++ backend.
                /// @param self not used.
                /// @param args function arguments are used to get the warning text from the Python side to C++ backend.
                /// @param kwds the key-value arguments may be used to pass the warning from Python to C++.
                /// @return A pointer to the Python None object.
                EXPORTED PyObject *raise_warning(PyObject *self, PyObject *args, PyObject *kwds);

                static PyMethodDef raise_warning_def = {"raise_warning", reinterpret_cast<PyCFunction>(raise_warning),
                                                        METH_VARARGS | METH_KEYWORDS,
                                                        "Raises warning inside C++ backend"};

                /// @brief Raises an error inside the C++ backend.
                /// @param self not used.
                /// @param args function arguments are used to get the error text from the Python side to C++ backend.
                /// @param kwds the key-value arguments may be used to pass the error from Python to C++.
                /// @return A pointer to the Python None object.
                EXPORTED PyObject *raise_error(PyObject *self, PyObject *args, PyObject *kwds);

                static PyMethodDef raise_error_def = {"raise_error", reinterpret_cast<PyCFunction>(raise_error),
                                                      METH_VARARGS | METH_KEYWORDS, "Raises error inside C++ backend"};

                /// @brief Raises an fatal error inside the C++ backend.
                /// @param self not used.
                /// @param args function arguments are used to get the error text from the Python side to C++ backend.
                /// @param kwds the key-value arguments may be used to pass the error from Python to C++.
                /// @return A pointer to the Python None object.
                EXPORTED PyObject *raise_fatal(PyObject *self, PyObject *args, PyObject *kwds);

                static PyMethodDef raise_fatal_def = {"raise_fatal", reinterpret_cast<PyCFunction>(raise_fatal),
                                                      METH_VARARGS | METH_KEYWORDS, "Raises fatal inside C++ backend"};

                /// @brief This function makes an array of named python object which should be registered inside this
                /// module
                /// @param module the actual module
                /// @return the vector of the name-object pointer pairs. May include functions, classes, values, etc.
                EXPORTED std::vector<Helpers::PythonModule::NamedPythonObject> get_module_fields(PyObject *module);
            } // namespace Errors
        } // namespace API
    } // namespace Python
} // namespace Sola

#endif
