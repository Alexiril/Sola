#ifndef PYTHON_API_GRAPHICS_HPP
#define PYTHON_API_GRAPHICS_HPP

#include "Helpers/PythonModule.hpp"
#include "SolaCommon.hpp"

namespace Sola::Python::API {
    /// @brief This namespace contains all the code related to the Sola Python API Graphics module.
    namespace Graphics {
        static const char *ModuleName = "Graphics";

        static const char *IncorrectButtonData = "Incorrect button data. Expected an object with these items: "
                                                 "ButtonID: int, Text: str, "
                                                 "IsEnterDefault: bool, IsEscapeDefault: bool.";

        /// @brief This function is used to show a message box window. It is a wrapper for the
        /// `Sola::Graphics::WindowsManager::showMessageBox` function. It takes the message box severity,
        /// title, message, buttons, and callback.
        /// @param Self
        /// @param Args the arguments should contain the values for the message box severity, title, message,
        /// buttons, and callback.
        /// @param Kwds the key-value arguments may contain the values for the message box severity, title,
        /// message, buttons, and callback.
        /// @return A pointer to the Python None object.
        EXPORTED PyObject *showMessageBox(PyObject *Self, PyObject *Args, PyObject *Kwds);

        static PyMethodDef ShowMessageBoxDef = {"showMessageBox", reinterpret_cast<PyCFunction>(showMessageBox),
                                                METH_VARARGS | METH_KEYWORDS, "Opens message box window"};

        /// @brief Python analogue for Sola::Graphics::WindowsManager::ButtonData. It's used to transfer the
        /// message box buttons data from Python to C++ backend.
        /// @ref Sola::Graphics::WindowsManager::ButtonData
        class ButtonData {
        public:
            /// @brief The button identifier. It is used to identify the button in the callback function.
            PyObject_HEAD i32 ButtonID;
            /// @brief The flag that indicates if the button is the default button for the escape key.
            bool IsEscapeDefault;
            /// @brief The flag that indicates if the button is the default button for the Enter key.
            bool IsEnterDefault;
            /// @brief The text on the button.
            std::string Text;

            ~ButtonData() = default;

            /// @brief The function that is called when the object is created in Python. Allocates memory for
            /// this class and clears the members with zeroes. Python analogue is __new__.
            /// @param Type ButtonDataType pointer
            /// @param Args should be nothing. It's needed for compatibility with standard Python `newfunc`
            /// @param Kwds should be nothing as well.
            /// @return A pointer to the allocated object.
            static EXPORTED auto newObject(PyTypeObject *Type, PyObject *Args, PyObject *Kwds) -> PyObject *;
            /// @brief Sets the members of the class. Python analogue is __init__.
            /// @param Self the object itself.
            /// @param Args arguments should contain values for the members
            /// @param Kwds key-value arguments may contain the values for the members as well
            /// @return A pointer to the allocated object.
            static EXPORTED auto initObject(PyObject *Self, PyObject *Args, PyObject *Kwds) -> i32;
            /// @brief Calls the destructor of the object and deallocates the memory allocated by `newObject`
            /// @param Self the object itself.
            static EXPORTED void deallocObject(PyObject *Self);
            /// @brief Makes text representation of the object. Mostly used for debugging.
            /// @param Self the object pointer itself
            /// @return Unicode string representing the current object
            static EXPORTED auto reprObject(const PyObject *Self) -> PyObject *;
        };

        /// @brief Python type definition for the ButtonData class
        static PyTypeObject ButtonDataType = {
            .ob_base = PyVarObject_HEAD_INIT(NULL, 0).tp_name = "SolaAPI.Graphics.ButtonData",
            .tp_basicsize = sizeof(ButtonData),
            .tp_dealloc = static_cast<destructor>(ButtonData::deallocObject),
            // static_cast doesn't like changing `const PyObject *` to `PyObject *`
            .tp_repr = reinterpret_cast<reprfunc>(ButtonData::reprObject),
            .tp_flags = Py_TPFLAGS_DEFAULT,
            .tp_doc = PyDoc_STR("Message box button data"),
            .tp_init = static_cast<initproc>(ButtonData::initObject),
            .tp_new = static_cast<newfunc>(ButtonData::newObject),
        };

        /// @brief This function makes an array of named python object which should be registered inside this
        /// module
        /// @param Module the actual module
        /// @return the vector of the name-object pointer pairs. May include functions, classes, values, etc.
        EXPORTED auto getModuleFields(PyObject *Module) -> std::vector<Helpers::PythonModule::NamedPythonObject>;
    } // namespace Graphics
} // namespace Sola::Python::API
#endif
