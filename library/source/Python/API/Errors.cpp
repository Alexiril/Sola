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
                PyObject *raise_warning(PyObject *, PyObject *args)
                {
                    const char *text = nullptr;
                    if (!PyArg_ParseTuple(args, "s:raise_warning", &text) || text == nullptr)
                    {
                        PyErr_SetString(PyExc_RuntimeError, formatting_error);
                        return nullptr;
                    }
                    print_warning(text);
                    Graphics::WindowsManager::show_warning_message_box(text);
                    return Py_None;
                }

                PyObject *raise_error(PyObject *, PyObject *args)
                {
                    const char *text = nullptr;
                    if (!PyArg_ParseTuple(args, "s:raise_error", &text) || text == nullptr)
                    {
                        PyErr_SetString(PyExc_RuntimeError, formatting_error);
                        return nullptr;
                    }
                    print_error(text);
                    Graphics::WindowsManager::show_error_message_box(text);
                    return Py_None;
                }

                PyObject *raise_fatal(PyObject *, PyObject *args)
                {
                    const char *text = nullptr;
                    if (!PyArg_ParseTuple(args, "s:raise_fatal", &text) || text == nullptr)
                    {
                        PyErr_SetString(PyExc_RuntimeError, formatting_error);
                        return nullptr;
                    }
                    print_fatal(text);
                    Graphics::WindowsManager::show_fatal_message_box(text);
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
