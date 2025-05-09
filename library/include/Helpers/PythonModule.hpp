#ifndef SOLA_HELPERS_PYTHONMODULE
#define SOLA_HELPERS_PYTHONMODULE

#include "sola_common.hpp"

namespace Sola
{
    namespace Helpers
    {
        /// @brief This namespace contains all the helper functions related to the Python module creation and
        /// registration.
        namespace PythonModule
        {
            /// @brief Possible Python module processing errors
            enum class PythonModuleError
            {
                SubmoduleNameEndsWithDot,
                SubmoduleRegistrationFailed,
            };

            /// @brief A structure representing a pair of a string and PyObject pointer (object with its name).
            /// @todo Why didn't I use std::pair again?... Or just replace all of it with std::unordered_map?
            struct NamedPythonObject
            {
            public:
                /// @brief A structure representing a named Python object. Increments the reference counter of the value
                /// if it's not `nullptr`
                /// @param name The name of the object.
                /// @param value The value of the object.
                NamedPythonObject(const std::string &name, PyObject *value) : name(name), value(value)
                {
                    Py_XINCREF(value);
                }

                /// @brief Destructor for the named Python object. Decrements the reference counter of the value if it's
                /// not `nullptr`
                ~NamedPythonObject(void) { Py_XDECREF(value); }

                /// @brief Name of the object
                std::string name;
                /// @brief The value of the object.
                PyObject *value;
            };

            /// @brief Creates a new Python module and registers it inside all parent modules.
            /// @param main_module PyObject pointer that points to the root module of the submodule. Might be
            /// `nullptr`, but it is not recommended.
            /// @param submodule_name that's exactly how the module will be called in Python. Without the root module.
            /// It must not end with dot.
            /// @return The PyObject pointer to the newly created module, or the error, if something inside gone wrong.
            EXPORTED std::expected<PyObject *, PythonModuleError>
            create_python_submodule(PyObject *main_module, const std::string &submodule_name);

            /// @brief Registers the items into the Python module (like into it's dictionary)
            /// @param module PyObject pointer to the module
            /// @param items a list of named PyObject pointers which will be registered into the module (objects can be
            /// any PyObject things, types, functions, values, etc)
            EXPORTED void fill_python_module(PyObject *module, const std::vector<NamedPythonObject> &items);
        } // namespace PythonModule
    } // namespace Helpers
} // namespace Sola

#endif
