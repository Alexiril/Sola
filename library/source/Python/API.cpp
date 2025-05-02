#include "Python/API.hpp"
#include "Logger/Logger.hpp"
#include "Python/API/Application.hpp"
#include "Python/API/Errors.hpp"
#include "Python/API/Logger.hpp"
#include "Python/ModuleHelper.hpp"

namespace Sola
{
    namespace Python
    {
        namespace API
        {

            PyObject *init(PyObject *, PyObject *args)
            {
                // It literally doesn't do anything yet
                if (!PyArg_ParseTuple(args, ":init"))
                {
                    return nullptr;
                }
                print_debug("API initialization call");
                return Py_None;
            }

            PyObject *get_engine_version(PyObject *, PyObject *args)
            {
                if (!PyArg_ParseTuple(args, ":get_engine_version"))
                {
                    return nullptr;
                }
                PyObject *result = PyLong_FromLongLong(Sola::get_engine_version());
                Py_INCREF(result);
                return result;
            }

            PyObject *create_python_module(void)
            {
                PyObject *main_module = PyModule_Create(&Module);
                if (main_module == nullptr)
                {
                    return nullptr;
                }

                PyObject *submodule = nullptr;

                submodule = ModuleHelper::create_python_submodule(main_module, Application::module_name);
                ModuleHelper::fill_python_module(submodule, Application::get_module_fields(submodule));

                submodule = ModuleHelper::create_python_submodule(main_module, Errors::module_name);
                ModuleHelper::fill_python_module(submodule, Errors::get_module_fields(submodule));

                submodule = ModuleHelper::create_python_submodule(main_module, Logger::module_name);
                ModuleHelper::fill_python_module(submodule, Logger::get_module_fields(submodule));

                return main_module;
            }
        } // namespace API
    } // namespace Python
} // namespace Sola
