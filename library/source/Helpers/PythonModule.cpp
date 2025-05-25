#include "Helpers/PythonModule.hpp"
#include "Logger/Logger.hpp"

namespace Sola::Helpers::PythonModule {
    auto createPythonSubmodule(PyObject *MainModule, const std::string &SubmoduleName)
        -> std::expected<PyObject *, PythonModuleError> {
        if (MainModule == nullptr) {
            return nullptr;
        }

        if (SubmoduleName.back() == '.') {
            printError(std::format("Submodule name cannot end with dot: {}", SubmoduleName));
            return std::unexpected(PythonModuleError::SubmoduleNameEndsWithDot);
        }

        const std::string MainModuleName = PyModule_GetName(MainModule);

        std::string Name = MainModuleName + "." + SubmoduleName;

        u64 SubmoduleNameEnd = Name.find('.', MainModuleName.size() + 1);
        if (SubmoduleNameEnd == std::string::npos) {
            SubmoduleNameEnd = Name.size();
        }

        PyObject *Submodule = MainModule;

        for (u64 SubmoduleNameStart = MainModuleName.size() + 1; SubmoduleNameStart < Name.size();) {
            const std::string CurrentSubmoduleName =
                Name.substr(SubmoduleNameStart, SubmoduleNameEnd - SubmoduleNameStart);

            const std::string FullSubmoduleName = Name.substr(0, SubmoduleNameEnd);

            PyObject *MainModuleDictionary = PyModule_GetDict(Submodule);
            Submodule = PyDict_GetItemString(MainModuleDictionary, CurrentSubmoduleName.c_str());
            if (Submodule == nullptr) {
                Submodule = PyImport_AddModule(FullSubmoduleName.c_str());
                if (Submodule == nullptr) {
                    return nullptr;
                }
                if (PyDict_SetItemString(MainModuleDictionary, CurrentSubmoduleName.c_str(), Submodule) < 0) {
                    printError(std::format("Can't register a Submodule '{}' (full name: '{}')", CurrentSubmoduleName,
                                           FullSubmoduleName));
                    return std::unexpected(PythonModuleError::SubmoduleRegistrationFailed);
                }
            }

            SubmoduleNameStart = SubmoduleNameEnd + 1;

            SubmoduleNameEnd = Name.find('.', SubmoduleNameStart);
            if (SubmoduleNameEnd == std::string::npos) {
                SubmoduleNameEnd = Name.size();
            }
        }

        return Submodule;
    }

    void fillPythonModule(PyObject *Module, const std::vector<NamedPythonObject> &Items) {
        if (Module == nullptr) {
            return;
        }
        PyObject *ModuleDictionary = PyModule_GetDict(Module);
        for (auto &&Item : Items) {
            if (Item.Value == nullptr) {
                PyErr_Print();
                continue;
            }
            if (PyDict_SetItemString(ModuleDictionary, Item.Name.c_str(), Item.Value) < 0) {
                const std::string ModuleName = PyModule_GetName(Module);
                printWarning(std::format("Key {} cannot be set in the module {}", Item.Name, ModuleName));
                return;
            }
        }
    }
} // namespace Sola::Helpers::PythonModule
