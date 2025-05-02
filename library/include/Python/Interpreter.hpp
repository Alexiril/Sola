#ifndef SOLA_PYTHON_INTERPRETER
#define SOLA_PYTHON_INTERPRETER

#include "Logger/Logger.hpp"
#include "sola_common.hpp"

namespace Sola
{

    namespace Python
    {

        struct EXPORTED InternalModule
        {
        public:
            const char *module_name;
            PyObject *(*module_init)(void);
        };

        class Interpreter
        {
        public:
            template <u64 ModulesAmount>
            Interpreter(PyConfig &config,
                        std::array<InternalModule, ModulesAmount> internal_modules)
            {
                for (u64 i = 0; i < ModulesAmount; i++)
                {
                    PyImport_AppendInittab(internal_modules[i].module_name,
                                           internal_modules[i].module_init);
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

            EXPORTED ~Interpreter(void) noexcept;

            EXPORTED bool IsInitialized(void) noexcept;

            EXPORTED bool ImportModule(const std::string &module_name);

            EXPORTED std::optional<PyObject *>
            RunFunction(const std::string &module_name, const std::string &function_name,
                        std::vector<PyObject *> args,
                        std::unordered_map<std::string, PyObject *> kwargs);

        private:
            bool _initialized;
            std::unordered_map<std::string, PyObject *> _modules;
        };

    } // namespace Python
} // namespace Sola

#endif
