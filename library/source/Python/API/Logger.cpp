#include "Python/API.hpp"
#include "Python/API/Logger.hpp"
#include "Logger/Logger.hpp"

namespace Sola
{
    namespace Python
    {
        namespace API
        {
            namespace Logger
            {
                PyObject *py_print_log(PyObject *args, const std::string &function_name,
                                       Sola::Logger::Severity severity)
                {
                    char *text = nullptr;
                    if (!PyArg_ParseTuple(args, ("s:" + function_name).c_str(), &text) || text == nullptr)
                    {
                        PyErr_SetString(PyExc_RuntimeError, formatting_error);
                        return nullptr;
                    }
                    print(text, severity);
                    return Py_None;
                }

                PyObject *py_print_debug(PyObject *, PyObject *args)
                {
                    return py_print_log(args, "print_debug", Sola::Logger::Severity::debug);
                }

                PyObject *py_print_info(PyObject *, PyObject *args)
                {
                    return py_print_log(args, "print_info", Sola::Logger::Severity::info);
                }

                PyObject *py_print_warning(PyObject *, PyObject *args)
                {
                    return py_print_log(args, "print_warning", Sola::Logger::Severity::warning);
                }

                PyObject *py_print_error(PyObject *, PyObject *args)
                {
                    return py_print_log(args, "print_error", Sola::Logger::Severity::error);
                }

                PyObject *py_print_fatal(PyObject *, PyObject *args)
                {
                    return py_print_log(args, "print_fatal", Sola::Logger::Severity::fatal);
                }

                std::vector<ModuleHelper::NamedPythonObject> get_module_fields(PyObject *module)
                {
                    return {ModuleHelper::NamedPythonObject("print_debug",
                                                            PyCFunction_NewEx(&print_debug_def, nullptr, module)),
                            ModuleHelper::NamedPythonObject("print_info",
                                                            PyCFunction_NewEx(&print_info_def, nullptr, module)),
                            ModuleHelper::NamedPythonObject("print_warning",
                                                            PyCFunction_NewEx(&print_warning_def, nullptr, module)),
                            ModuleHelper::NamedPythonObject("print_error",
                                                            PyCFunction_NewEx(&print_error_def, nullptr, module)),
                            ModuleHelper::NamedPythonObject("print_fatal",
                                                            PyCFunction_NewEx(&print_fatal_def, nullptr, module))};
                }
            } // namespace Logger
        } // namespace API
    } // namespace Python
} // namespace Sola
