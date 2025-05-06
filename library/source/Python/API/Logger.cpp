#include "Python/API/Logger.hpp"
#include "Logger/Logger.hpp"
#include "Python/API.hpp"

namespace Sola
{
    namespace Python
    {
        namespace API
        {
            namespace Logger
            {
                PyObject *py_print_log(PyObject *args, PyObject *kwds, const std::string &function_name,
                                       Sola::Logger::Severity severity)
                {
                    static const char *kwlist[] = {"what", nullptr};
                    const char *what = nullptr;
                    if (!PyArg_ParseTupleAndKeywords(args, kwds, ("s:" + function_name).c_str(),
                                                     static_cast<const char *const *>(kwlist), &what) ||
                        what == nullptr)
                    {
                        PyErr_SetString(PyExc_RuntimeError, formatting_error);
                        return nullptr;
                    }
                    print(what, severity);
                    return Py_None;
                }

                PyObject *py_print_debug(PyObject *, PyObject *args, PyObject *kwds)
                {
                    return py_print_log(args, kwds, "print_debug", Sola::Logger::Severity::debug);
                }

                PyObject *py_print_info(PyObject *, PyObject *args, PyObject *kwds)
                {
                    return py_print_log(args, kwds, "print_info", Sola::Logger::Severity::info);
                }

                PyObject *py_print_warning(PyObject *, PyObject *args, PyObject *kwds)
                {
                    return py_print_log(args, kwds, "print_warning", Sola::Logger::Severity::warning);
                }

                PyObject *py_print_error(PyObject *, PyObject *args, PyObject *kwds)
                {
                    return py_print_log(args, kwds, "print_error", Sola::Logger::Severity::error);
                }

                PyObject *py_print_fatal(PyObject *, PyObject *args, PyObject *kwds)
                {
                    return py_print_log(args, kwds, "print_fatal", Sola::Logger::Severity::fatal);
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
