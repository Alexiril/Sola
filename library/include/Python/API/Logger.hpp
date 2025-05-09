#ifndef SOLA_PYTHON_API_LOGGER
#define SOLA_PYTHON_API_LOGGER

#include "Helpers/PythonModule.hpp"
#include "sola_common.hpp"

namespace Sola
{
    namespace Python
    {
        namespace API
        {
            /// @brief This namespace contains all the code related to the Sola Python API Logger module.
            namespace Logger
            {
                static const char *module_name = "Logger";

                /// @brief Prints the debug log information. Wrapper for the `Sola::Logger::print_debug` function.
                /// @param self
                /// @param args the arguments are used to pass the text to the C++ backend.
                /// @param kwds the key-value arguments may be used to pass the text from Python to C++.
                /// @return A pointer to the Python None object.
                EXPORTED PyObject *py_print_debug(PyObject *self, PyObject *args, PyObject *kwds);

                static PyMethodDef print_debug_def = {"print_debug", reinterpret_cast<PyCFunction>(py_print_debug),
                                                      METH_VARARGS | METH_KEYWORDS,
                                                      "Prints the debug log information."};

                /// @brief Prints the info log information. Wrapper for the `Sola::Logger::print_info` function.
                /// @param self
                /// @param args the arguments are used to pass the text to the C++ backend.
                /// @param kwds the key-value arguments may be used to pass the text from Python to C++.
                /// @return A pointer to the Python None object.
                EXPORTED PyObject *py_print_info(PyObject *self, PyObject *args, PyObject *kwds);

                static PyMethodDef print_info_def = {"print_info", reinterpret_cast<PyCFunction>(py_print_info),
                                                     METH_VARARGS | METH_KEYWORDS, "Prints the info log information."};

                /// @brief Prints the warning log information. Wrapper for the `Sola::Logger::print_warning` function.
                /// @param self
                /// @param args the arguments are used to pass the text to the C++ backend.
                /// @param kwds the key-value arguments may be used to pass the text from Python to C++.
                /// @return A pointer to the Python None object.
                EXPORTED PyObject *py_print_warning(PyObject *self, PyObject *args, PyObject *kwds);

                static PyMethodDef print_warning_def = {
                    "print_warning", reinterpret_cast<PyCFunction>(py_print_warning), METH_VARARGS | METH_KEYWORDS,
                    "Prints the warning log information."};

                /// @brief Prints the error log information. Wrapper for the `Sola::Logger::print_error` function.
                /// @param self
                /// @param args the arguments are used to pass the text to the C++ backend.
                /// @param kwds the key-value arguments may be used to pass the text from Python to C++.
                /// @return A pointer to the Python None object.
                EXPORTED PyObject *py_print_error(PyObject *self, PyObject *args, PyObject *kwds);

                static PyMethodDef print_error_def = {"print_error", reinterpret_cast<PyCFunction>(py_print_error),
                                                      METH_VARARGS | METH_KEYWORDS,
                                                      "Prints the error log information."};

                /// @brief Prints the fatal error log information. Wrapper for the `Sola::Logger::print_fatal` function.
                /// @param self
                /// @param args the arguments are used to pass the text to the C++ backend.
                /// @param kwds the key-value arguments may be used to pass the text from Python to C++.
                /// @return A pointer to the Python None object.
                EXPORTED PyObject *py_print_fatal(PyObject *self, PyObject *args, PyObject *kwds);

                static PyMethodDef print_fatal_def = {"print_fatal", reinterpret_cast<PyCFunction>(py_print_fatal),
                                                      METH_VARARGS | METH_KEYWORDS,
                                                      "Prints the fatal log information."};

                /// @brief This function makes an array of named python object which should be registered inside this
                /// module
                /// @param module the actual module
                /// @return the vector of the name-object pointer pairs. May include functions, classes, values, etc.
                EXPORTED std::vector<Helpers::PythonModule::NamedPythonObject> get_module_fields(PyObject *module);
            } // namespace Logger
        } // namespace API
    } // namespace Python
} // namespace Sola

#endif
