#include "Python/API/Errors.hpp"
#include "Graphics/WindowsManager.hpp"
#include "Logger/Logger.hpp"
#include "Python/API.hpp"

namespace Sola
{
    namespace Python
    {
        namespace API
        {
            namespace Errors
            {
                static const char *const kwlist[] = {"what", nullptr};

                /// @brief This function is used to parse the arguments for the functions in this module.
                /// @param function_name The name of the function being called.
                /// @param args The arguments passed to the function.
                /// @param kwds The keyword arguments passed to the function.
                /// @return An optional string containing the parsed argument.
                std::optional<std::string> parse_args(const std::string &function_name, PyObject *args, PyObject *kwds)
                {
                    const char *what = nullptr;
                    if (!PyArg_ParseTupleAndKeywords(args, kwds, ("s:" + function_name).c_str(), kwlist, &what) ||
                        what == nullptr)
                    {
                        PyErr_SetString(PyExc_RuntimeError, formatting_error);
                        return std::nullopt;
                    }
                    return std::string(what);
                }

                PyObject *raise_warning(PyObject *, PyObject *args, PyObject *kwds)
                {
                    std::optional<std::string> text = parse_args("raise_warning", args, kwds);
                    if (!text.has_value())
                    {
                        return nullptr;
                    }
                    print_warning(text.value());
                    Graphics::WindowsManager::show_warning_message_box(text.value());
                    return Py_None;
                }

                PyObject *raise_error(PyObject *, PyObject *args, PyObject *kwds)
                {
                    std::optional<std::string> text = parse_args("raise_error", args, kwds);
                    if (!text.has_value())
                    {
                        return nullptr;
                    }
                    print_error(text.value());
                    Graphics::WindowsManager::show_error_message_box(text.value());
                    return Py_None;
                }

                PyObject *raise_fatal(PyObject *, PyObject *args, PyObject *kwds)
                {
                    std::optional<std::string> text = parse_args("raise_fatal", args, kwds);
                    if (!text.has_value())
                    {
                        return nullptr;
                    }
                    print_fatal(text.value());
                    Graphics::WindowsManager::show_fatal_message_box(text.value());
                    return Py_None;
                }

                std::vector<Helpers::PythonModule::NamedPythonObject> get_module_fields(PyObject *module)
                {
                    return {Helpers::PythonModule::NamedPythonObject(
                                "raise_warning", PyCFunction_NewEx(&raise_warning_def, nullptr, module)),
                            Helpers::PythonModule::NamedPythonObject(
                                "raise_error", PyCFunction_NewEx(&raise_error_def, nullptr, module)),
                            Helpers::PythonModule::NamedPythonObject(
                                "raise_fatal", PyCFunction_NewEx(&raise_fatal_def, nullptr, module))};
                }
            } // namespace Errors
        } // namespace API
    } // namespace Python
} // namespace Sola
