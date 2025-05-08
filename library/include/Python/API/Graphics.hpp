#ifndef SOLA_PYTHON_API_GRAPHICS
#define SOLA_PYTHON_API_GRAPHICS

#include "Helpers/PythonModule.hpp"
#include "sola_common.hpp"

namespace Sola
{
    namespace Python
    {
        namespace API
        {
            namespace Graphics
            {
                static const char *module_name = "Graphics";

                static const char *incorrect_button_data =
                    "Incorrect button data. Expected an object with these items: "
                    "button_id: int, text: str, "
                    "is_enter_default: bool, is_escape_default: bool.";

                EXPORTED PyObject *show_message_box(PyObject *self, PyObject *args, PyObject *kwds);

                static PyMethodDef show_message_box_def = {"show_message_box",
                                                           reinterpret_cast<PyCFunction>(show_message_box),
                                                           METH_VARARGS | METH_KEYWORDS, "Opens message box window"};

                class ButtonData
                {
                public:
                    PyObject_HEAD i32 button_id;
                    bool is_escape_default;
                    bool is_enter_default;
                    std::string text;

                    ~ButtonData() = default;

                    static EXPORTED PyObject *new_object(PyTypeObject *type, PyObject *args, PyObject *kwds);
                    static EXPORTED i32 init(PyObject *self, PyObject *args, PyObject *kwds);
                    static EXPORTED void dealloc(PyObject *self);
                    static EXPORTED PyObject *repr(PyObject *self);
                };

                static PyTypeObject ButtonData_type = {
                    .ob_base = PyVarObject_HEAD_INIT(NULL, 0).tp_name = "SolaAPI.Graphics.ButtonData",
                    .tp_basicsize = sizeof(ButtonData),
                    .tp_dealloc = static_cast<destructor>(ButtonData::dealloc),
                    .tp_repr = static_cast<reprfunc>(ButtonData::repr),
                    .tp_flags = Py_TPFLAGS_DEFAULT,
                    .tp_doc = PyDoc_STR("Message box button data"),
                    .tp_init = static_cast<initproc>(ButtonData::init),
                    .tp_new = static_cast<newfunc>(ButtonData::new_object),
                };

                EXPORTED std::vector<Helpers::PythonModule::NamedPythonObject> get_module_fields(PyObject *module);
            } // namespace Graphics
        } // namespace API
    } // namespace Python
} // namespace Sola

#endif
