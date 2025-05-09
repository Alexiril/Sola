#ifndef SOLA_PYTHON_INTERPRETER
#define SOLA_PYTHON_INTERPRETER

#include "Logger/Logger.hpp"
#include "sola_common.hpp"

namespace Sola
{

    /// @brief This namespace contains all the code related to the Python Interpreter. It is used to run Python
    /// interpreter inside the Sola library and applications.
    namespace Python
    {
        /// @brief This is a simple structure holding both the module name and the function pointer to the init
        /// function. It's used to register the internal modules that are needed for the interpreter to work.
        struct InternalModule
        {
        public:
            /// @brief The name of the module (like "numpy").
            const char *module_name;
            /// @brief The function pointer to the init function of the module.
            PyObject *(*module_init)(void);
        };

        /// @brief Possible errors that can occur in the interpreter.
        enum class InterpreterError
        {
            RunFunctionInterpNotInitialized,
            RunFunctionObjectDoesNotExist,
            RunFunctionObjectIsNotCallable,
            RunFunctionCallFailed,
        };

        /// @brief The class that should be used to handle all the requests to the Python Interpreter (except for Sola
        /// Python API, there it is faster to not call the interpreter each time those functions need some PyObject
        /// pointer parsing, but do it in place with Python API).
        class Interpreter
        {
        public:
            /// @brief Constructor for the interpreter. It initializes the interpreter and registers the internal
            /// modules.
            /// @param config The configuration for the interpreter. It should be initialized before calling this
            /// constructor.
            /// @param internal_modules The internal modules that should be registered. It should be an array of
            /// InternalModule structures. The array should be of size ModulesAmount.
            /// @note The modules are registered in the order they are passed to the constructor.
            /// @note ModulesAmount type is u8, so the maximum amount of modules is 255. That should be enough for the
            /// internal modules in a normal case. Also, it seems to simplify the life of some sast tools (yep,
            /// cppcheck). If it won't be enough, we can rebuild the library with u16.
            template <u8 ModulesAmount>
            Interpreter(PyConfig &config, std::array<InternalModule, ModulesAmount> internal_modules)
            {
                for (u8 i = 0; i < ModulesAmount; i++)
                {
                    PyImport_AppendInittab(internal_modules[i].module_name, internal_modules[i].module_init);
                }

                PyStatus status = Py_InitializeFromConfig(&config);
                PyConfig_Clear(&config);
                if (PyStatus_Exception(status))
                {
                    if (PyStatus_IsError(status))
                    {
                        print_error(status.err_msg);
                    }
                    return;
                }
                _initialized = true;
            }

            /// @brief No copy constructor for this class, only moves.
            Interpreter(const Interpreter &) = delete;

            /// @brief Move constructor is available if needed
            EXPORTED Interpreter(Interpreter &&);

            EXPORTED ~Interpreter(void) noexcept;

            /// @brief Check if the interpreter is initialized.
            /// @return true if the interpreter successfully completed all initialization steps, otherwise false.
            /// @note Should be used to understand if the interpreter is ready, because the constructor does not throw
            EXPORTED bool IsInitialized(void) noexcept;

            /// @brief Calls PyImport_ImportModule to import a new module (it should be a module in Lib folder or where
            /// the interpreter can reach it).
            /// @param module_name The name of the module to import (like numpy or smth).
            /// @return true if the module was imported successfully, otherwise false.
            EXPORTED bool ImportModule(const std::string &module_name);

            /// @brief Runs any function (that is registered inside some imported module) inside the Python Interpreter
            /// @param module_name the name of the module where the function is registered
            /// @param function_name actual name in Python of the called function (without the module name)
            /// @param args a list of positional arguments which will be passed into the function
            /// @param kwargs a dictionary (map) of named arguments
            /// @return Result of the function or error
            EXPORTED std::expected<PyObject *, InterpreterError>
            RunFunction(const std::string &module_name, const std::string &function_name, std::vector<PyObject *> args,
                        std::unordered_map<std::string, PyObject *> kwargs);

        private:
            bool _initialized;
            std::unordered_map<std::string, PyObject *> _modules;
        };

    } // namespace Python
} // namespace Sola

#endif
