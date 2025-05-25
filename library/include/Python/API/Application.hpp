#ifndef PYTHON_API_APPLICATION_HPP
#define PYTHON_API_APPLICATION_HPP

#include "Helpers/PythonModule.hpp"
#include "SolaCommon.hpp"

namespace Sola::Python::API {
            /// @brief This namespace contains all the code related to the Sola Python API Application module.
            namespace Application {
                static const char *ModuleName = "Application";

                static const char *ApplicationIsNotInitializedError = "Sola application was not initialized";

                /// @brief Gets the application singleton and returns if it is in the editor mode or not.
                /// @param Self not used.
                /// @param Args not used.
                /// @return A Python boolean indicating if the application is in editor mode.
                EXPORTED auto isAppEditor(PyObject *Self, PyObject *Args) -> PyObject *;

                static PyMethodDef IsAppEditorDef = {"IsAppEditor", isAppEditor, METH_VARARGS,
                                                     "Returns if the application is in fact in the editor mode."};

                /// @brief Gets the current project directory.
                /// @param Self not used.
                /// @param Args not used.
                /// @return A Python Unicode string representing the current project directory.
                EXPORTED auto getProjectDir(PyObject *Self, PyObject *Args) -> PyObject *;

                static PyMethodDef GetProjectDirDef = {"getProjectDir", getProjectDir, METH_VARARGS,
                                                       "Returns the current opened project directory."};

                /// @brief Gets the application name.
                /// @param Self not used.
                /// @param Args not used.
                /// @return A Python Unicode string representing the application name.
                EXPORTED auto getAppName(PyObject *Self, PyObject *Args) -> PyObject *;

                static PyMethodDef GetAppNameDef = {"getAppName", getAppName, METH_VARARGS,
                                                    "Returns the application name."};

                /// @brief Gets the application version.
                /// @param Self not used.
                /// @param Args not used.
                /// @return A Python Unicode string representing the application version.
                EXPORTED auto getAppVersion(PyObject *Self, PyObject *Args) -> PyObject *;

                static PyMethodDef GetAppVersionDef = {"getAppVersion", getAppVersion, METH_VARARGS,
                                                       "Returns the application version."};

                /// @brief Gets the application identifier.
                /// @param Self not used.
                /// @param Args not used.
                /// @return A Python Unicode string representing the application identifier.
                EXPORTED auto getAppIdentifier(PyObject *Self, PyObject *Args) -> PyObject *;

                static PyMethodDef GetAppIdentifierDef = {"getAppIdentifier", getAppIdentifier, METH_VARARGS,
                                                          "Returns the application identifier."};

                /// @brief Gets the application creator.
                /// @param Self not used.
                /// @param Args not used.
                /// @return A Python Unicode string representing the application creator.
                EXPORTED auto getAppCreator(PyObject *Self, PyObject *Args) -> PyObject *;

                static PyMethodDef GetAppCreatorDef = {"getAppCreator", getAppCreator, METH_VARARGS,
                                                       "Returns the application creator."};

                /// @brief Gets the application copyright.
                /// @param Self not used.
                /// @param Args not used.
                /// @return A Python Unicode string representing the application copyright.
                EXPORTED auto getAppCopyright(PyObject *Self, PyObject *Args) -> PyObject *;

                static PyMethodDef GetAppCopyrightDef = {"getAppCopyright", getAppCopyright, METH_VARARGS,
                                                         "Returns the application copyright."};

                /// @brief Gets the application URL.
                /// @param Self not used.
                /// @param Args not used.
                /// @return A Python Unicode string representing the application URL.
                EXPORTED auto getAppURL(PyObject *Self, PyObject *Args) -> PyObject *;

                static PyMethodDef GetAppURLDef = {"getAppURL", getAppURL, METH_VARARGS,
                                                   "Returns the application url."};

                /// @brief Gets the current project configuration.
                /// @param Self not used.
                /// @param Args not used.
                /// @return A Python dictionary representing the current project configuration.
                EXPORTED auto getProjectConfiguration(PyObject *Self, PyObject *Args) -> PyObject *;

                static PyMethodDef GetProjectConfigurationDef = {"getProjectConfiguration", getProjectConfiguration,
                                                                 METH_VARARGS,
                                                                 "Returns the current project configuration."};

                /// @brief Sets the current project configuration.
                /// @param Self not used.
                /// @param Args function arguments are used to get the configuration from the Python side to C++
                /// backend.
                /// @param kwds the key-value arguments may be used to pass the configuration from Python to C++.
                /// @return A pointer to the Python None object.
                EXPORTED auto setProjectConfiguration(PyObject *Self, PyObject *Args, PyObject *kwds) -> PyObject *;

                static PyMethodDef SetProjectConfigurationDef = {
                    "setProjectConfiguration", reinterpret_cast<PyCFunction>(setProjectConfiguration),
                    METH_VARARGS | METH_KEYWORDS, "Saves the current project configuration data"};

                /// @brief This function makes an array of named python object which should be registered inside this
                /// module
                /// @param Module the actual module
                /// @return the vector of the name-object pointer pairs. May include functions, classes, values, etc.
                EXPORTED auto getModuleFields(PyObject *Module)
                    -> std::vector<Helpers::PythonModule::NamedPythonObject>;
            } // namespace Application
        } // namespace Sola::Python::API

#endif
