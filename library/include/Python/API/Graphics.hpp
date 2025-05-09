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
            /// @brief This namespace contains all the code related to the Sola Python API Graphics module.
            namespace Graphics
            {
                static const char *module_name = "Graphics";

                static const char *incorrect_button_data =
                    "Incorrect button data. Expected an object with these items: "
                    "button_id: int, text: str, "
                    "is_enter_default: bool, is_escape_default: bool.";

                /// @brief This function is used to show a message box window. It is a wrapper for the
                /// `Sola::Graphics::WindowsManager::show_message_box` function. It takes the message box severity,
                /// title, message, buttons, and callback.
                /// @param self
                /// @param args the arguments should contain the values for the message box severity, title, message,
                /// buttons, and callback.
                /// @param kwds the key-value arguments may contain the values for the message box severity, title,
                /// message, buttons, and callback.
                /// @return A pointer to the Python None object.
                EXPORTED PyObject *show_message_box(PyObject *self, PyObject *args, PyObject *kwds);

                static PyMethodDef show_message_box_def = {"show_message_box",
                                                           reinterpret_cast<PyCFunction>(show_message_box),
                                                           METH_VARARGS | METH_KEYWORDS, "Opens message box window"};

                /// @brief Python analogue for Sola::Graphics::WindowsManager::ButtonData. It's used to transfer the
                /// message box buttons data from Python to C++ backend.
                /// @ref Sola::Graphics::WindowsManager::ButtonData
                class ButtonData
                {
                public:
                    /// @brief The button identifier. It is used to identify the button in the callback function.
                    PyObject_HEAD i32 button_id;
                    /// @brief The flag that indicates if the button is the default button for the escape key.
                    bool is_escape_default;
                    /// @brief The flag that indicates if the button is the default button for the Enter key.
                    bool is_enter_default;
                    /// @brief The text on the button.
                    std::string text;

                    ~ButtonData() = default;

                    /// @brief The function that is called when the object is created in Python. Allocates memory for
                    /// this class and clears the members with zeroes. Python analogue is __new__.
                    /// @param type ButtonData_type pointer
                    /// @param args should be nothing. It's needed for compatibility with standard Python `newfunc`
                    /// @param kwds should be nothing as well.
                    /// @return A pointer to the allocated object.
                    static EXPORTED PyObject *new_object(PyTypeObject *type, PyObject *args, PyObject *kwds);
                    /// @brief Sets the members of the class. Python analogue is __init__.
                    /// @param self the object itself.
                    /// @param args arguments should contain values for the members
                    /// @param kwds key-value arguments may contain the values for the members as well
                    /// @return A pointer to the allocated object.
                    static EXPORTED i32 init(PyObject *self, PyObject *args, PyObject *kwds);
                    /// @brief Calls the destructor of the object and deallocates the memory allocated by `new_object`
                    /// @param self the object itself.
                    static EXPORTED void dealloc(PyObject *self);
                    /// @brief Makes text representation of the object. Mostly used for debugging.
                    /// @param self the object pointer itself
                    /// @return Unicode string representing the current object
                    static EXPORTED PyObject *repr(PyObject *self);
                };

                /// @brief Python type definition for the ButtonData class
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

                /// @brief This function makes an array of named python object which should be registered inside this
                /// module
                /// @param module the actual module
                /// @return the vector of the name-object pointer pairs. May include functions, classes, values, etc.
                EXPORTED std::vector<Helpers::PythonModule::NamedPythonObject> get_module_fields(PyObject *module);
            } // namespace Graphics
        } // namespace API
    } // namespace Python
} // namespace Sola

#endif
