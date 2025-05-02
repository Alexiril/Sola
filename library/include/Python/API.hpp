#ifndef SOLA_PYTHON_API
#define SOLA_PYTHON_API

#include "sola_common.hpp"

namespace Sola
{
    namespace Python
    {
        namespace API
        {
            static const char *module_name = "SolaAPI";

            static const char *formatting_error = "Failed to parse arguments";

            EXPORTED PyObject *init(PyObject *self, PyObject *args);

            EXPORTED PyObject *get_engine_version(PyObject *self, PyObject *args);

            static PyMethodDef Methods[] = {{"init", init, METH_VARARGS, "Initializes the API internals."},
                                            {"get_engine_version", get_engine_version, METH_VARARGS,
                                             "Returns the current engine version in number format."},
                                            {NULL, NULL, 0, NULL}};

            static PyModuleDef Module = {PyModuleDef_HEAD_INIT, module_name, NULL, -1, Methods, NULL, NULL, NULL, NULL};

            EXPORTED PyObject *create_python_module(void);
        } // namespace API
    } // namespace Python
} // namespace Sola

#endif
