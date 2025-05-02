#ifndef SOLA_PYTHON_MODULEHELPER
#define SOLA_PYTHON_MODULEHELPER

#include "sola_common.hpp"

namespace Sola
{
    namespace Python
    {
        namespace ModuleHelper
        {
            struct NamedPythonObject
            {
            public:
                NamedPythonObject(const std::string &name, PyObject *value)
                    : name(name), value(value)
                {
                    Py_XINCREF(value);
                }

                ~NamedPythonObject(void) { Py_XDECREF(value); }

                std::string name;
                PyObject *value;
            };

            EXPORTED PyObject *create_python_submodule(PyObject *main_module,
                                                       const std::string &submodule_name);

            EXPORTED PyObject *fill_python_module(PyObject *module,
                                                  const std::vector<NamedPythonObject> &items);
        } // namespace ModuleHelper
    } // namespace Python
} // namespace Sola

#endif
