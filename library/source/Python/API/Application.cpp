#include "Application/Application.hpp"
#include "Python/API/API.hpp"

// NOLINTBEGIN(readability-named-parameter): Most of those unnamed parameters are Python API Self and Args that we do
// not need. Also, cppcheck and complier won't be happy with named, but unused parameters.

namespace Sola::Python::API::Application {
    auto isAppEditor(PyObject *, PyObject *) -> PyObject * {
        const Sola::Application::Application *Application = Sola::Application::Application::get();
        if (Application == nullptr) {
            PyErr_SetString(PyExc_RuntimeError, ApplicationIsNotInitializedError);
            return nullptr;
        }
        PyObject *result = Application->isEditor() ? Py_True : Py_False;
        return result;
    }

    // I'm sorry about this
    // I had no choice
    // Hah just kidding
    // I'm not sorry.
#define GET_SOLA_APP_STRING_PARAM(app_function_name)                                                                   \
    auto Application = Sola::Application::Application::get();                                                          \
    if (Application == nullptr) {                                                                                      \
        PyErr_SetString(PyExc_RuntimeError, ApplicationIsNotInitializedError);                                         \
        return nullptr;                                                                                                \
    }                                                                                                                  \
    const std::string &value = Application->app_function_name();                                                       \
    PyObject *result = PyUnicode_FromStringAndSize(value.c_str(), value.size());                                       \
    return result;

    auto getProjectDir(PyObject *, PyObject *) -> PyObject * { GET_SOLA_APP_STRING_PARAM(getProjectDir) }

    auto getAppName(PyObject *, PyObject *) -> PyObject * { GET_SOLA_APP_STRING_PARAM(getName) }

    auto getAppVersion(PyObject *, PyObject *) -> PyObject * { GET_SOLA_APP_STRING_PARAM(getVersion) }

    auto getAppIdentifier(PyObject *, PyObject *) -> PyObject * { GET_SOLA_APP_STRING_PARAM(getIdentifier) }

    auto getAppCreator(PyObject *, PyObject *) -> PyObject * { GET_SOLA_APP_STRING_PARAM(getCreator) }

    auto getAppCopyright(PyObject *, PyObject *) -> PyObject * { GET_SOLA_APP_STRING_PARAM(getCopyright) }

    auto getAppURL(PyObject *, PyObject *) -> PyObject * { GET_SOLA_APP_STRING_PARAM(getUrl) }

#undef GET_SOLA_APP_STRING_PARAM

    auto getProjectConfiguration(PyObject *, PyObject *) -> PyObject * {
        const Sola::Application::Application *Application = Sola::Application::Application::get();
        if (Application == nullptr) {
            PyErr_SetString(PyExc_RuntimeError, ApplicationIsNotInitializedError);
            return nullptr;
        }
        PyObject *value = Application->getProjectConfiguration();
        if (value == nullptr) {
            return Py_None;
        }
        return value;
    }

    /// @brief Keyword list for the setProjectConfiguration function.
    static const std::array<const char *, 2> SetProjectConfigurationKwlist = {"Config", nullptr};
    auto setProjectConfiguration(PyObject *, PyObject *Args, PyObject *Kwds) -> PyObject * {
        PyObject *Configuration = nullptr;
        Sola::Application::Application *Application = Sola::Application::Application::get();
        if (Application == nullptr ||
            PyArg_ParseTupleAndKeywords(Args, Kwds, "O:setProjectConfiguration", SetProjectConfigurationKwlist.data(),
                                        &Configuration) != 1 ||
            Configuration == nullptr || PyDict_Check(Configuration) == 0) {
            PyErr_SetString(PyExc_RuntimeError,
                            Application == nullptr ? ApplicationIsNotInitializedError : FormattingError);
            return nullptr;
        }
        Application->setProjectConfiguration(Configuration);
        return Py_None;
    }

    auto getModuleFields(PyObject *Module) -> std::vector<Helpers::PythonModule::NamedPythonObject> {
        return {
            Helpers::PythonModule::NamedPythonObject("is_app_editor",
                                                     PyCFunction_NewEx(&IsAppEditorDef, nullptr, Module)),
            Helpers::PythonModule::NamedPythonObject("getProjectDir",
                                                     PyCFunction_NewEx(&GetProjectDirDef, nullptr, Module)),
            Helpers::PythonModule::NamedPythonObject("get_app_name",
                                                     PyCFunction_NewEx(&GetAppNameDef, nullptr, Module)),
            Helpers::PythonModule::NamedPythonObject("get_app_version",
                                                     PyCFunction_NewEx(&GetAppVersionDef, nullptr, Module)),
            Helpers::PythonModule::NamedPythonObject("get_app_identifier",
                                                     PyCFunction_NewEx(&GetAppIdentifierDef, nullptr, Module)),
            Helpers::PythonModule::NamedPythonObject("get_app_creator",
                                                     PyCFunction_NewEx(&GetAppCreatorDef, nullptr, Module)),
            Helpers::PythonModule::NamedPythonObject("get_app_copyright",
                                                     PyCFunction_NewEx(&GetAppCopyrightDef, nullptr, Module)),
            Helpers::PythonModule::NamedPythonObject("get_app_url", PyCFunction_NewEx(&GetAppURLDef, nullptr, Module)),
            Helpers::PythonModule::NamedPythonObject("getProjectConfiguration",
                                                     PyCFunction_NewEx(&GetProjectConfigurationDef, nullptr, Module)),
            Helpers::PythonModule::NamedPythonObject("setProjectConfiguration",
                                                     PyCFunction_NewEx(&SetProjectConfigurationDef, nullptr, Module)),
        };
    }
} // namespace Sola::Python::API::Application

// NOLINTEND(readability-named-parameter)
