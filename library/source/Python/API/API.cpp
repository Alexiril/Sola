#include "Python/API/API.hpp"
#include "Helpers/PythonModule.hpp"
#include "Logger/Logger.hpp"

// NOLINTBEGIN(readability-named-parameter): Most of those unnamed parameters are Python API Self and Args that we do
// not need. Also, cppcheck and complier won't be happy with named, but unused parameters.

namespace Sola::Python::API {
    auto getEngineVersion(PyObject *, PyObject *) -> PyObject * {
        PyObject *Result = PyLong_FromLongLong(Sola::getEngineVersion());
        if (Result == nullptr) {
            PyErr_SetString(PyExc_RuntimeError, SolaAPIError);
            return nullptr;
        }
        Py_INCREF(Result);
        return Result;
    }

    auto getEngineVersionReadable(PyObject *, PyObject *) -> PyObject * {
        PyObject *Result = PyUnicode_FromString(Sola::getEngineVersionReadable().c_str());
        if (Result == nullptr) {
            PyErr_SetString(PyExc_RuntimeError, SolaAPIError);
            return nullptr;
        }
        Py_INCREF(Result);
        return Result;
    }

    auto createPythonModule() -> PyObject * {
        PyObject *MainModule = PyModule_Create(&APIModuleDef);
        if (MainModule == nullptr) {
            return nullptr;
        }

        PyObject *Submodule = nullptr;

        Submodule =
            Helpers::PythonModule::createPythonSubmodule(MainModule, Application::ModuleName).value_or(nullptr);
        Helpers::PythonModule::fillPythonModule(Submodule, Application::getModuleFields(Submodule));

        Submodule = Helpers::PythonModule::createPythonSubmodule(MainModule, Errors::ModuleName).value_or(nullptr);
        Helpers::PythonModule::fillPythonModule(Submodule, Errors::getModuleFields(Submodule));

        Submodule = Helpers::PythonModule::createPythonSubmodule(MainModule, Logger::ModuleName).value_or(nullptr);
        Helpers::PythonModule::fillPythonModule(Submodule, Logger::getModuleFields(Submodule));

        Submodule = Helpers::PythonModule::createPythonSubmodule(MainModule, Graphics::ModuleName).value_or(nullptr);
        Helpers::PythonModule::fillPythonModule(Submodule, Graphics::getModuleFields(Submodule));

        return MainModule;
    }
} // namespace Sola::Python::API

// NOLINTEND(readability-named-parameter)
