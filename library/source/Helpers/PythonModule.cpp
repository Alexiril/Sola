#include "Helpers/PythonModule.hpp"
#include "Logger/Logger.hpp"

namespace Sola
{
    namespace Helpers
    {
        namespace PythonModule
        {
            std::expected<PyObject *, PythonModuleError> create_python_submodule(PyObject *main_module,
                                                                                 const std::string &submodule_name)
            {
                if (main_module == nullptr)
                {
                    return nullptr;
                }

                if (submodule_name.back() == '.')
                {
                    print_error(std::format("Submodule name cannot end with dot: {}", submodule_name));
                    return std::unexpected(PythonModuleError::SubmoduleNameEndsWithDot);
                }

                const std::string main_module_name = PyModule_GetName(main_module);

                std::string name = main_module_name + "." + submodule_name;

                u64 submodule_name_end = name.find('.', main_module_name.size() + 1);
                if (submodule_name_end == std::string::npos)
                {
                    submodule_name_end = name.size();
                }

                PyObject *submodule = main_module;

                for (u64 submodule_name_start = main_module_name.size() + 1; submodule_name_start < name.size();)
                {
                    const std::string current_submodule_name =
                        name.substr(submodule_name_start, submodule_name_end - submodule_name_start);

                    const std::string full_submodule_name = name.substr(0, submodule_name_end);

                    PyObject *main_module_dictionary = PyModule_GetDict(submodule);
                    submodule = PyDict_GetItemString(main_module_dictionary, current_submodule_name.c_str());
                    if (!submodule)
                    {
                        submodule = PyImport_AddModule(full_submodule_name.c_str());
                        if (!submodule)
                        {
                            return nullptr;
                        }
                        if (PyDict_SetItemString(main_module_dictionary, current_submodule_name.c_str(), submodule) < 0)
                        {
                            print_error(std::format("Can't register a submodule '{}' (full name: '{}')",
                                                    current_submodule_name, full_submodule_name));
                            return std::unexpected(PythonModuleError::SubmoduleRegistrationFailed);
                        }
                    }

                    submodule_name_start = submodule_name_end + 1;

                    submodule_name_end = name.find('.', submodule_name_start);
                    if (submodule_name_end == std::string::npos)
                    {
                        submodule_name_end = name.size();
                    }
                }

                return submodule;
            }

            PyObject *fill_python_module(PyObject *module, const std::vector<NamedPythonObject> &items)
            {
                if (module == nullptr)
                {
                    return nullptr;
                }
                PyObject *module_dictionary = PyModule_GetDict(module);
                for (auto &&item : items)
                {
                    if (item.value == nullptr)
                    {
                        PyErr_Print();
                        continue;
                    }
                    if (PyDict_SetItemString(module_dictionary, item.name.c_str(), item.value) < 0)
                    {
                        const std::string module_name = PyModule_GetName(module);
                        print_warning(std::format("Key {} cannot be set in the module {}", item.name, module_name));
                        return module;
                    }
                }

                return module;
            }
        } // namespace PythonModule
    } // namespace Helpers
} // namespace Sola
