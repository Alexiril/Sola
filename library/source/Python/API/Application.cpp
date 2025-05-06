#include "Python/API/Application.hpp"
#include "Application/Application.hpp"
#include "Python/API.hpp"

namespace Sola
{
    namespace Python
    {
        namespace API
        {
            namespace Application
            {
                PyObject *is_app_editor(PyObject *, PyObject *)
                {
                    auto application = Sola::Application::Application::get();
                    if (application == nullptr)
                    {
                        PyErr_SetString(PyExc_RuntimeError, application_is_not_initialized_error);
                        return nullptr;
                    }
                    PyObject *result = application->is_editor() ? Py_True : Py_False;
                    return result;
                }

                // I'm sorry about this
                // I had no choice
                // Hah just kidding
                // I'm not sorry.
#define GET_SOLA_APP_STRING_PARAM(app_function_name)                                                                   \
    auto application = Sola::Application::Application::get();                                                          \
    if (application == nullptr)                                                                                        \
    {                                                                                                                  \
        PyErr_SetString(PyExc_RuntimeError, application_is_not_initialized_error);                                     \
        return nullptr;                                                                                                \
    }                                                                                                                  \
    const std::string &value = application->app_function_name();                                                       \
    PyObject *result = PyUnicode_FromStringAndSize(value.c_str(), value.size());                                       \
    return result;

                PyObject *get_project_dir(PyObject *, PyObject *){GET_SOLA_APP_STRING_PARAM(get_project_dir)}

                PyObject *get_app_name(PyObject *, PyObject *){GET_SOLA_APP_STRING_PARAM(get_name)}

                PyObject *get_app_version(PyObject *, PyObject *){GET_SOLA_APP_STRING_PARAM(get_version)}

                PyObject *get_app_identifier(PyObject *, PyObject *){GET_SOLA_APP_STRING_PARAM(get_identifier)}

                PyObject *get_app_creator(PyObject *, PyObject *){GET_SOLA_APP_STRING_PARAM(get_creator)}

                PyObject *get_app_copyright(PyObject *, PyObject *){GET_SOLA_APP_STRING_PARAM(get_copyright)}

                PyObject *get_app_url(PyObject *, PyObject *){GET_SOLA_APP_STRING_PARAM(get_url)}

#undef GET_SOLA_APP_STRING_PARAM

                PyObject *get_project_configuration(PyObject *, PyObject *)
                {
                    auto application = Sola::Application::Application::get();
                    if (application == nullptr)
                    {
                        PyErr_SetString(PyExc_RuntimeError, application_is_not_initialized_error);
                        return nullptr;
                    }
                    PyObject *value = application->get_project_configuration();
                    if (value == nullptr)
                    {
                        return Py_None;
                    }
                    return value;
                }

                PyObject *set_project_configuration(PyObject *, PyObject *args, PyObject *kwds)
                {
                    PyObject *configuration = nullptr;
                    static const char *kwlist[] = {"config", nullptr};
                    auto application = Sola::Application::Application::get();
                    if (application == nullptr ||
                        !PyArg_ParseTupleAndKeywords(args, kwds, "O:set_project_configuration",
                                                      static_cast<const char *const *>(kwlist), &configuration) ||
                        configuration == nullptr || PyDict_Check(configuration) == 0)
                    {
                        PyErr_SetString(PyExc_RuntimeError, application == nullptr
                                                                ? application_is_not_initialized_error
                                                                : formatting_error);
                        return nullptr;
                    }
                    application->set_project_configuration(configuration);
                    return Py_None;
                }

                std::vector<ModuleHelper::NamedPythonObject> get_module_fields(PyObject *module)
                {
                    return {
                        ModuleHelper::NamedPythonObject("is_app_editor",
                                                        PyCFunction_NewEx(&is_app_editor_def, nullptr, module)),
                        ModuleHelper::NamedPythonObject("get_project_dir",
                                                        PyCFunction_NewEx(&get_project_dir_def, nullptr, module)),
                        ModuleHelper::NamedPythonObject("get_app_name",
                                                        PyCFunction_NewEx(&get_app_name_def, nullptr, module)),
                        ModuleHelper::NamedPythonObject("get_app_version",
                                                        PyCFunction_NewEx(&get_app_version_def, nullptr, module)),
                        ModuleHelper::NamedPythonObject("get_app_identifier",
                                                        PyCFunction_NewEx(&get_app_identifier_def, nullptr, module)),
                        ModuleHelper::NamedPythonObject("get_app_creator",
                                                        PyCFunction_NewEx(&get_app_creator_def, nullptr, module)),
                        ModuleHelper::NamedPythonObject("get_app_copyright",
                                                        PyCFunction_NewEx(&get_app_copyright_def, nullptr, module)),
                        ModuleHelper::NamedPythonObject("get_app_url",
                                                        PyCFunction_NewEx(&get_app_url_def, nullptr, module)),
                        ModuleHelper::NamedPythonObject(
                            "get_project_configuration",
                            PyCFunction_NewEx(&get_project_configuration_def, nullptr, module)),
                        ModuleHelper::NamedPythonObject(
                            "set_project_configuration",
                            PyCFunction_NewEx(&set_project_configuration_def, nullptr, module)),
                    };
                }
            } // namespace Application
        } // namespace API
    } // namespace Python
} // namespace Sola
