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

                EXPORTED PyObject *raise_warning(PyObject *self, PyObject *args, PyObject *kwds);

                static PyMethodDef raise_warning_def = {"raise_warning", reinterpret_cast<PyCFunction>(raise_warning),
                                                        METH_VARARGS | METH_KEYWORDS,
                                                        "Raises warning inside C++ backend"};

                EXPORTED PyObject *raise_error(PyObject *self, PyObject *args, PyObject *kwds);

                static PyMethodDef raise_error_def = {"raise_error", reinterpret_cast<PyCFunction>(raise_error),
                                                      METH_VARARGS | METH_KEYWORDS, "Raises error inside C++ backend"};

                EXPORTED PyObject *raise_fatal(PyObject *self, PyObject *args, PyObject *kwds);

                static PyMethodDef raise_fatal_def = {"raise_fatal", reinterpret_cast<PyCFunction>(raise_fatal),
                                                      METH_VARARGS | METH_KEYWORDS, "Raises fatal inside C++ backend"};

                EXPORTED std::vector<ModuleHelper::NamedPythonObject> get_module_fields(PyObject *module);
            } // namespace Errors
        } // namespace API
    } // namespace Python
} // namespace Sola

#endif
