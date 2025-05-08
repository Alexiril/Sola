#ifndef SOLA_HELPERS_PYTHONMODULE
#define SOLA_HELPERS_PYTHONMODULE

#include "sola_common.hpp"

namespace Sola
{
    namespace Helpers
    {
        namespace PythonModule
        {
            enum class PythonModuleError
            {
                SubmoduleNameEndsWithDot,
                SubmoduleRegistrationFailed,
            };

            struct NamedPythonObject
            {
            public:
                NamedPythonObject(const std::string &name, PyObject *value) : name(name), value(value)
                {
                    Py_XINCREF(value);
                }

                ~NamedPythonObject(void) { Py_XDECREF(value); }

                std::string name;
                PyObject *value;
            };

            EXPORTED std::expected<PyObject *, PythonModuleError>
            create_python_submodule(PyObject *main_module, const std::string &submodule_name);

            EXPORTED PyObject *fill_python_module(PyObject *module, const std::vector<NamedPythonObject> &items);
        } // namespace PythonModule
    } // namespace Helpers
} // namespace Sola

#endif
