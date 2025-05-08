#ifndef SOLA_PYTHON_API_APLICATION
#define SOLA_PYTHON_API_APLICATION

#include "Helpers/PythonModule.hpp"
#include "sola_common.hpp"

namespace Sola
{
    namespace Python
    {
        namespace API
        {
            namespace Application
            {
                static const char *module_name = "Application";

                static const char *application_is_not_initialized_error = "Sola application was not initialized";

                EXPORTED PyObject *is_app_editor(PyObject *self, PyObject *args);

                static PyMethodDef is_app_editor_def = {"is_app_editor", is_app_editor, METH_VARARGS,
                                                        "Returns if the application is in fact in the editor mode."};

                EXPORTED PyObject *get_project_dir(PyObject *self, PyObject *args);

                static PyMethodDef get_project_dir_def = {"get_project_dir", get_project_dir, METH_VARARGS,
                                                          "Returns the current opened project directory."};

                EXPORTED PyObject *get_app_name(PyObject *self, PyObject *args);

                static PyMethodDef get_app_name_def = {"get_app_name", get_app_name, METH_VARARGS,
                                                       "Returns the application name."};

                EXPORTED PyObject *get_app_version(PyObject *self, PyObject *args);

                static PyMethodDef get_app_version_def = {"get_app_version", get_app_version, METH_VARARGS,
                                                          "Returns the application version."};

                EXPORTED PyObject *get_app_identifier(PyObject *self, PyObject *args);

                static PyMethodDef get_app_identifier_def = {"get_app_identifier", get_app_identifier, METH_VARARGS,
                                                             "Returns the application identifier."};

                EXPORTED PyObject *get_app_creator(PyObject *self, PyObject *args);

                static PyMethodDef get_app_creator_def = {"get_app_creator", get_app_creator, METH_VARARGS,
                                                          "Returns the application creator."};

                EXPORTED PyObject *get_app_copyright(PyObject *self, PyObject *args);

                static PyMethodDef get_app_copyright_def = {"get_app_copyright", get_app_copyright, METH_VARARGS,
                                                            "Returns the application copyright."};

                EXPORTED PyObject *get_app_url(PyObject *self, PyObject *args);

                static PyMethodDef get_app_url_def = {"get_app_url", get_app_url, METH_VARARGS,
                                                      "Returns the application url."};

                EXPORTED PyObject *get_project_configuration(PyObject *self, PyObject *args);

                static PyMethodDef get_project_configuration_def = {"get_project_configuration",
                                                                    get_project_configuration, METH_VARARGS,
                                                                    "Returns the current project configuration."};

                EXPORTED PyObject *set_project_configuration(PyObject *self, PyObject *args, PyObject *kwds);

                static PyMethodDef set_project_configuration_def = {
                    "set_project_configuration", reinterpret_cast<PyCFunction>(set_project_configuration),
                    METH_VARARGS | METH_KEYWORDS, "Saves the current project configuration data"};

                EXPORTED std::vector<Helpers::PythonModule::NamedPythonObject> get_module_fields(PyObject *module);
            } // namespace Application
        } // namespace API
    } // namespace Python
} // namespace Sola

#endif
