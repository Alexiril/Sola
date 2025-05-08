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
            namespace Logger
            {
                static const char *module_name = "Logger";

                EXPORTED PyObject *py_print_debug(PyObject *self, PyObject *args, PyObject *kwds);

                static PyMethodDef print_debug_def = {"print_debug", reinterpret_cast<PyCFunction>(py_print_debug),
                                                      METH_VARARGS | METH_KEYWORDS,
                                                      "Prints the debug log information."};

                EXPORTED PyObject *py_print_info(PyObject *self, PyObject *args, PyObject *kwds);

                static PyMethodDef print_info_def = {"print_info", reinterpret_cast<PyCFunction>(py_print_info),
                                                     METH_VARARGS | METH_KEYWORDS, "Prints the info log information."};

                EXPORTED PyObject *py_print_warning(PyObject *self, PyObject *args, PyObject *kwds);

                static PyMethodDef print_warning_def = {
                    "print_warning", reinterpret_cast<PyCFunction>(py_print_warning), METH_VARARGS | METH_KEYWORDS,
                    "Prints the warning log information."};

                EXPORTED PyObject *py_print_error(PyObject *self, PyObject *args, PyObject *kwds);

                static PyMethodDef print_error_def = {"print_error", reinterpret_cast<PyCFunction>(py_print_error),
                                                      METH_VARARGS | METH_KEYWORDS,
                                                      "Prints the error log information."};

                EXPORTED PyObject *py_print_fatal(PyObject *self, PyObject *args, PyObject *kwds);

                static PyMethodDef print_fatal_def = {"print_fatal", reinterpret_cast<PyCFunction>(py_print_fatal),
                                                      METH_VARARGS | METH_KEYWORDS,
                                                      "Prints the fatal log information."};

                EXPORTED std::vector<Helpers::PythonModule::NamedPythonObject> get_module_fields(PyObject *module);
            } // namespace Logger
        } // namespace API
    } // namespace Python
} // namespace Sola

#endif
