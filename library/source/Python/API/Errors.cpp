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
                std::optional<std::string> parse_args(const std::string &function_name, PyObject *args, PyObject *kwds)
                {
                    static const char *kwlist[] = {"what", nullptr};
                    const char *what = nullptr;
                    if (!PyArg_ParseTupleAndKeywords(args, kwds, ("s:" + function_name).c_str(),
                                                     static_cast<const char *const *>(kwlist), &what) ||
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

                std::vector<ModuleHelper::NamedPythonObject> get_module_fields(PyObject *module)
                {
                    return {ModuleHelper::NamedPythonObject("raise_warning",
                                                            PyCFunction_NewEx(&raise_warning_def, nullptr, module)),
                            ModuleHelper::NamedPythonObject("raise_error",
                                                            PyCFunction_NewEx(&raise_error_def, nullptr, module)),
                            ModuleHelper::NamedPythonObject("raise_fatal",
                                                            PyCFunction_NewEx(&raise_fatal_def, nullptr, module))};
                }
            } // namespace Errors
        } // namespace API
    } // namespace Python
} // namespace Sola
