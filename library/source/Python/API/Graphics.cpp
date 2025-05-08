
#include "Python/API/Graphics.hpp"
#include "Graphics/WindowsManager.hpp"
#include "Logger/Logger.hpp"
#include "Python/API.hpp"

namespace Sola
{
    namespace Python
    {
        namespace API
        {
            namespace Graphics
            {
                static const char *const show_message_box_kwlist[] = {"severity", "title",    "message",
                                                                      "buttons",  "callback", nullptr};
                PyObject *Sola::Python::API::Graphics::show_message_box(PyObject *, PyObject *args, PyObject *kwds)
                {
                    const char *mb_severity = nullptr;
                    const char *mb_title = nullptr;
                    const char *mb_message = nullptr;
                    PyObject *py_mb_buttons = nullptr;
                    PyObject *py_mb_callback = nullptr;
                    PyObject *iter = nullptr;
                    PyObject *item = nullptr;
                    PyObject *result = nullptr;

                    if (!PyArg_ParseTupleAndKeywords(args, kwds, "sssOO:show_message_box", show_message_box_kwlist,
                                                     &mb_severity, &mb_title, &mb_message, &py_mb_buttons,
                                                     &py_mb_callback) ||
                        mb_severity == nullptr || mb_title == nullptr || mb_message == nullptr ||
                        py_mb_buttons == nullptr || py_mb_callback == nullptr ||
                        PyCallable_Check(py_mb_callback) == 0 || PyList_Check(py_mb_buttons) == 0 ||
                        (iter = PyObject_GetIter(py_mb_buttons)) == nullptr)
                    {
                        Py_XDECREF(iter);
                        if (!PyErr_Occurred())
                        {
                            PyErr_SetString(PyExc_RuntimeError, formatting_error);
                        }
                        return nullptr;
                    }

                    Logger::Severity actual_severity = Logger::SeverityFunctions::from_text(mb_severity);
                    std::vector<Sola::Graphics::WindowsManager::ButtonData> mb_buttons = {};

                    while ((item = PyIter_Next(iter)) != nullptr)
                    {
                        if (!PyObject_IsInstance(item, reinterpret_cast<PyObject *>(&ButtonData_type)))
                        {
                            PyErr_SetString(PyExc_RuntimeError, incorrect_button_data);
                            Py_XDECREF(item);
                            goto function_exit;
                        }
                        ButtonData *button_data = reinterpret_cast<ButtonData *>(item);
                        mb_buttons.emplace_back(Sola::Graphics::WindowsManager::ButtonData(
                            button_data->button_id, button_data->is_escape_default, button_data->is_enter_default,
                            button_data->text));
                        Py_DECREF(item);
                    }

                    Sola::Graphics::WindowsManager::show_message_box(actual_severity, mb_title, mb_message, mb_buttons,
                                                                     [py_mb_callback](i32 hit_button)
                                                                     {
                                                                         PyObject *arg = PyLong_FromInt32(hit_button);
                                                                         PyObject_CallOneArg(py_mb_callback, arg);
                                                                         Py_DECREF(arg);
                                                                     });
                    result = Py_None;
                function_exit:
                    Py_DECREF(iter);
                    return result;
                }

                PyObject *ButtonData::new_object(PyTypeObject *type, PyObject *, PyObject *)
                {
                    ButtonData *button_data = reinterpret_cast<ButtonData *>(type->tp_alloc(type, 0));
                    if (button_data == nullptr)
                    {
                        return nullptr;
                    }
                    button_data->button_id = 0;
                    button_data->is_escape_default = false;
                    button_data->is_enter_default = false;
                    button_data->text = "";
                    return reinterpret_cast<PyObject *>(button_data);
                }

                static const char *const ButtonData_init_kwlist[] = {"button_id", "is_escape_default",
                                                                     "is_enter_default", "text", nullptr};
                i32 ButtonData::init(PyObject *self, PyObject *args, PyObject *kwds)
                {
                    if (self == nullptr)
                    {
                        PyErr_SetString(PyExc_RuntimeError, incorrect_button_data);
                        return -1;
                    }
                    ButtonData *button_data = reinterpret_cast<ButtonData *>(self);
                    PyObject *py_text = nullptr;
                    if (!PyArg_ParseTupleAndKeywords(args, kwds, "ibbO:ButtonData", ButtonData_init_kwlist,
                                                     &(button_data->button_id), &(button_data->is_escape_default),
                                                     &(button_data->is_enter_default), &py_text) ||
                        PyUnicode_Check(py_text) == 0)
                    {
                        PyErr_SetString(PyExc_RuntimeError, incorrect_button_data);
                        return -1;
                    }
                    button_data->text = std::string(PyUnicode_AsUTF8(py_text));
                    return 0;
                }

                void ButtonData::dealloc(PyObject *self)
                {
                    if (self == nullptr)
                    {
                        return;
                    }
                    ButtonData *button_data = reinterpret_cast<ButtonData *>(self);
                    button_data->~ButtonData();
                    PyObject_Del(self);
                }

                PyObject *ButtonData::repr(PyObject *self)
                {
                    if (self == nullptr)
                    {
                        return nullptr;
                    }
                    const ButtonData *button_data = reinterpret_cast<ButtonData *>(self);
                    std::string repr = "ButtonData(" + std::to_string(button_data->button_id) + ", " +
                                       std::to_string(button_data->is_escape_default) + ", " +
                                       std::to_string(button_data->is_enter_default) + ", " + button_data->text + ")";
                    return PyUnicode_FromString(repr.c_str());
                }

                std::vector<Helpers::PythonModule::NamedPythonObject> get_module_fields(PyObject *module)
                {
                    if (PyType_Ready(&ButtonData_type) < 0)
                    {
                        print_error("Failed to initialize ButtonData type.");
                        return {};
                    }

                    return {Helpers::PythonModule::NamedPythonObject(
                                "show_message_box", PyCFunction_NewEx(&show_message_box_def, nullptr, module)),
                            Helpers::PythonModule::NamedPythonObject("ButtonData",
                                                                     reinterpret_cast<PyObject *>(&ButtonData_type))};
                }
            } // namespace Graphics
        } // namespace API
    } // namespace Python
} // namespace Sola
