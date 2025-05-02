#ifndef SOLA_PYTHON_API_ERRORS
#define SOLA_PYTHON_API_ERRORS

#include "Python/ModuleHelper.hpp"
#include "sola_common.hpp"

namespace Sola
{
    namespace Python
    {
        namespace API
        {
            namespace Errors
            {
                static const char *module_name = "Errors";

                EXPORTED PyObject *raise_warning(PyObject *self, PyObject *args);

                static PyMethodDef raise_warning_def = {"raise_warning", raise_warning,
                                                        METH_VARARGS,
                                                        "Raises warning inside C++ backend"};

                EXPORTED PyObject *raise_error(PyObject *self, PyObject *args);

                static PyMethodDef raise_error_def = {"raise_error", raise_error, METH_VARARGS,
                                                      "Raises error inside C++ backend"};

                EXPORTED PyObject *raise_fatal(PyObject *self, PyObject *args);

                static PyMethodDef raise_fatal_def = {"raise_fatal", raise_fatal, METH_VARARGS,
                                                      "Raises fatal inside C++ backend"};

                EXPORTED std::vector<ModuleHelper::NamedPythonObject> get_module_fields(PyObject *module);
            } // namespace Errors
        } // namespace API
    } // namespace Python
} // namespace Sola

#endif
