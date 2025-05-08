#include "Python/API.hpp"
#include "Helpers/PythonModule.hpp"
#include "Logger/Logger.hpp"
#include "Python/API/Application.hpp"
#include "Python/API/Errors.hpp"
#include "Python/API/Graphics.hpp"
#include "Python/API/Logger.hpp"

namespace Sola
{
    namespace Python
    {
        namespace API
        {
            PyObject *get_engine_version(PyObject *, PyObject *)
            {
                PyObject *result = PyLong_FromLongLong(Sola::get_engine_version());
                if (result == nullptr)
                {
                    PyErr_SetString(PyExc_RuntimeError, solaapi_error);
                    return nullptr;
                }
                Py_INCREF(result);
                return result;
            }

            PyObject *get_engine_version_readable(PyObject *, PyObject *)
            {
                PyObject *result = PyUnicode_FromString(Sola::get_engine_version_readable().c_str());
                if (result == nullptr)
                {
                    PyErr_SetString(PyExc_RuntimeError, solaapi_error);
                    return nullptr;
                }
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

                submodule = Helpers::PythonModule::create_python_submodule(main_module, Application::module_name).value_or(nullptr);
                Helpers::PythonModule::fill_python_module(submodule, Application::get_module_fields(submodule));

                submodule = Helpers::PythonModule::create_python_submodule(main_module, Errors::module_name).value_or(nullptr);
                Helpers::PythonModule::fill_python_module(submodule, Errors::get_module_fields(submodule));

                submodule = Helpers::PythonModule::create_python_submodule(main_module, Logger::module_name).value_or(nullptr);
                Helpers::PythonModule::fill_python_module(submodule, Logger::get_module_fields(submodule));

                submodule = Helpers::PythonModule::create_python_submodule(main_module, Graphics::module_name).value_or(nullptr);
                Helpers::PythonModule::fill_python_module(submodule, Graphics::get_module_fields(submodule));

                return main_module;
            }
        } // namespace API
    } // namespace Python
} // namespace Sola
