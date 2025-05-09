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
            /// @brief This namespace contains all the code related to the Sola Python API Application module.
            namespace Application
            {
                static const char *module_name = "Application";

                static const char *application_is_not_initialized_error = "Sola application was not initialized";

                /// @brief Gets the application singleton and returns if it is in the editor mode or not.
                /// @param self not used.
                /// @param args not used.
                /// @return A Python boolean indicating if the application is in editor mode.
                EXPORTED PyObject *is_app_editor(PyObject *self, PyObject *args);

                static PyMethodDef is_app_editor_def = {"is_app_editor", is_app_editor, METH_VARARGS,
                                                        "Returns if the application is in fact in the editor mode."};

                /// @brief Gets the current project directory.
                /// @param self not used.
                /// @param args not used.
                /// @return A Python Unicode string representing the current project directory.
                EXPORTED PyObject *get_project_dir(PyObject *self, PyObject *args);

                static PyMethodDef get_project_dir_def = {"get_project_dir", get_project_dir, METH_VARARGS,
                                                          "Returns the current opened project directory."};

                /// @brief Gets the application name.
                /// @param self not used.
                /// @param args not used.
                /// @return A Python Unicode string representing the application name.
                EXPORTED PyObject *get_app_name(PyObject *self, PyObject *args);

                static PyMethodDef get_app_name_def = {"get_app_name", get_app_name, METH_VARARGS,
                                                       "Returns the application name."};

                /// @brief Gets the application version.
                /// @param self not used.
                /// @param args not used.
                /// @return A Python Unicode string representing the application version.
                EXPORTED PyObject *get_app_version(PyObject *self, PyObject *args);

                static PyMethodDef get_app_version_def = {"get_app_version", get_app_version, METH_VARARGS,
                                                          "Returns the application version."};

                /// @brief Gets the application identifier.
                /// @param self not used.
                /// @param args not used.
                /// @return A Python Unicode string representing the application identifier.
                EXPORTED PyObject *get_app_identifier(PyObject *self, PyObject *args);

                static PyMethodDef get_app_identifier_def = {"get_app_identifier", get_app_identifier, METH_VARARGS,
                                                             "Returns the application identifier."};

                /// @brief Gets the application creator.
                /// @param self not used.
                /// @param args not used.
                /// @return A Python Unicode string representing the application creator.
                EXPORTED PyObject *get_app_creator(PyObject *self, PyObject *args);

                static PyMethodDef get_app_creator_def = {"get_app_creator", get_app_creator, METH_VARARGS,
                                                          "Returns the application creator."};

                /// @brief Gets the application copyright.
                /// @param self not used.
                /// @param args not used.
                /// @return A Python Unicode string representing the application copyright.
                EXPORTED PyObject *get_app_copyright(PyObject *self, PyObject *args);

                static PyMethodDef get_app_copyright_def = {"get_app_copyright", get_app_copyright, METH_VARARGS,
                                                            "Returns the application copyright."};

                /// @brief Gets the application URL.
                /// @param self not used.
                /// @param args not used.
                /// @return A Python Unicode string representing the application URL.
                EXPORTED PyObject *get_app_url(PyObject *self, PyObject *args);

                static PyMethodDef get_app_url_def = {"get_app_url", get_app_url, METH_VARARGS,
                                                      "Returns the application url."};

                /// @brief Gets the current project configuration.
                /// @param self not used.
                /// @param args not used.
                /// @return A Python dictionary representing the current project configuration.
                EXPORTED PyObject *get_project_configuration(PyObject *self, PyObject *args);

                static PyMethodDef get_project_configuration_def = {"get_project_configuration",
                                                                    get_project_configuration, METH_VARARGS,
                                                                    "Returns the current project configuration."};

                /// @brief Sets the current project configuration.
                /// @param self not used.
                /// @param args function arguments are used to get the configuration from the Python side to C++
                /// backend.
                /// @param kwds the key-value arguments may be used to pass the configuration from Python to C++.
                /// @return A pointer to the Python None object.
                EXPORTED PyObject *set_project_configuration(PyObject *self, PyObject *args, PyObject *kwds);

                static PyMethodDef set_project_configuration_def = {
                    "set_project_configuration", reinterpret_cast<PyCFunction>(set_project_configuration),
                    METH_VARARGS | METH_KEYWORDS, "Saves the current project configuration data"};

                /// @brief This function makes an array of named python object which should be registered inside this
                /// module
                /// @param module the actual module
                /// @return the vector of the name-object pointer pairs. May include functions, classes, values, etc.
                EXPORTED std::vector<Helpers::PythonModule::NamedPythonObject> get_module_fields(PyObject *module);
            } // namespace Application
        } // namespace API
    } // namespace Python
} // namespace Sola

#endif
