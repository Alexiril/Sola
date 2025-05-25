#ifndef HELPERS_PYTHONMODULE_HPP
#define HELPERS_PYTHONMODULE_HPP

#include "SolaCommon.hpp"

namespace Sola::Helpers {
    /// @brief This namespace contains all the helper functions related to the Python module creation and
    /// registration.
    namespace PythonModule {
        /// @brief Possible Python module processing errors
        enum class PythonModuleError {
            SubmoduleNameEndsWithDot,
            SubmoduleRegistrationFailed,
        };

        /// @brief A structure representing a pair of a string and PyObject pointer (object with its name).
        /// @todo Why didn't I use std::pair again?... Or just replace all of it with std::unordered_map?
        struct NamedPythonObject {
        public:
            /// @brief A structure representing a named Python object. Increments the reference counter of the value
            /// if it's not `nullptr`
            /// @param Name The name of the object.
            /// @param Value The value of the object.
            NamedPythonObject(const std::string &Name, PyObject *Value) : Name(Name), Value(Value) {
                Py_XINCREF(Value);
            }

            /// @brief Destructor for the named Python object. Decrements the reference counter of the value if it's
            /// not `nullptr`
            ~NamedPythonObject() { Py_XDECREF(Value); }

            /// @brief Name of the object
            std::string Name;
            /// @brief The value of the object.
            PyObject *Value;
        };

        /// @brief Creates a new Python module and registers it inside all parent modules.
        /// @param MainModule PyObject pointer that points to the root module of the submodule. Might be
        /// `nullptr`, but it is not recommended.
        /// @param SubmoduleName that's exactly how the module will be called in Python. Without the root module.
        /// It must not end with dot.
        /// @return The PyObject pointer to the newly created module, or the error, if something inside gone wrong.
        EXPORTED auto createPythonSubmodule(PyObject *MainModule, const std::string &SubmoduleName)
            -> std::expected<PyObject *, PythonModuleError>;

        /// @brief Registers the items into the Python module (like into it's dictionary)
        /// @param Module PyObject pointer to the module
        /// @param Items a list of named PyObject pointers which will be registered into the module (objects can be
        /// any PyObject things, types, functions, values, etc)
        EXPORTED void fillPythonModule(PyObject *Module, const std::vector<NamedPythonObject> &Items);
    } // namespace PythonModule
} // namespace Sola::Helpers

#endif
