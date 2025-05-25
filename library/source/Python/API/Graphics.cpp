#include "Graphics/WindowsManager.hpp"
#include "Logger/Logger.hpp"
#include "Python/API/API.hpp"

// NOLINTBEGIN(readability-named-parameter): Most of those unnamed parameters are Python API Self and Args that we do
// not need. Also, cppcheck and complier won't be happy with named, but unused parameters.

namespace Sola::Python::API::Graphics {

    /// @brief Keyword list for the showMessageBox function
    const std::array<const char *, 6> ShowMessageBoxKwlist = {"Severity", "Title",    "Message",
                                                              "Buttons",  "Callback", nullptr};
    auto showMessageBox(PyObject *, PyObject *Args, PyObject *Kwds) -> PyObject * {
        const char *MBSeverity = nullptr;
        const char *MBTitle = nullptr;
        const char *MBMessage = nullptr;
        PyObject *PyMBButtons = nullptr;
        PyObject *PyMBCallback = nullptr;
        PyObject *Iter = nullptr;
        PyObject *Item = nullptr;
        PyObject *Result = nullptr;

        if (PyArg_ParseTupleAndKeywords(Args, Kwds, "sssOO:showMessageBox", ShowMessageBoxKwlist.data(), &MBSeverity,
                                        &MBTitle, &MBMessage, &PyMBButtons, &PyMBCallback) == 0 ||
            MBSeverity == nullptr || MBTitle == nullptr || MBMessage == nullptr || PyMBButtons == nullptr ||
            PyMBCallback == nullptr || PyCallable_Check(PyMBCallback) == 0 || PyList_Check(PyMBButtons) == 0 ||
            (Iter = PyObject_GetIter(PyMBButtons)) == nullptr) {
            Py_XDECREF(Iter);
            if (PyErr_Occurred() == nullptr) {
                PyErr_SetString(PyExc_RuntimeError, FormattingError);
            }
            return nullptr;
        }

        Sola::Logger::Severity ActualSeverity = Sola::Logger::SeverityFunctions::fromText(MBSeverity);
        std::vector<Sola::Graphics::WindowsManager::ButtonData> MBButtons = {};

        Graphics::ButtonData *ButtonData = nullptr;
        std::expected<void, Sola::Graphics::WindowsManager::WindowsManagerError> MBShowed = {};

        while ((Item = PyIter_Next(Iter)) != nullptr) {
            if (PyObject_IsInstance(Item, reinterpret_cast<PyObject *>(&ButtonDataType)) != 1) {
                PyErr_SetString(PyExc_RuntimeError, IncorrectButtonData);
                Py_XDECREF(Item);
                goto FunctionExit;
            }
            ButtonData = reinterpret_cast<Graphics::ButtonData *>(Item);
            MBButtons.emplace_back(ButtonData->ButtonID, ButtonData->IsEscapeDefault, ButtonData->IsEnterDefault,
                                   ButtonData->Text);
            Py_DECREF(Item);
        }

        MBShowed = Sola::Graphics::WindowsManager::showMessageBox(ActualSeverity, MBTitle, MBMessage, MBButtons,
                                                                  [PyMBCallback](i32 HitButton) {
                                                                      PyObject *Arg = PyLong_FromInt32(HitButton);
                                                                      PyObject_CallOneArg(PyMBCallback, Arg);
                                                                      Py_DECREF(Arg);
                                                                  });

        if (!MBShowed.has_value() &&
            MBShowed.error() == Sola::Graphics::WindowsManager::WindowsManagerError::ShowMessageBoxFailed) {
            PyErr_SetString(PyExc_RuntimeError, "Failed to show message box.");
        }
        Result = Py_None;
    FunctionExit:
        Py_DECREF(Iter);
        return Result;
    }

    auto ButtonData::newObject(PyTypeObject *type, PyObject *, PyObject *) -> PyObject * {
        auto *ButtonData = reinterpret_cast<Graphics::ButtonData *>(type->tp_alloc(type, 0));
        if (ButtonData == nullptr) {
            return nullptr;
        }
        ButtonData->ButtonID = 0;
        ButtonData->IsEscapeDefault = false;
        ButtonData->IsEnterDefault = false;
        ButtonData->Text = "";
        return reinterpret_cast<PyObject *>(ButtonData);
    }

    /// @brief Keyword list for the ButtonData class initializer
    const std::array<const char *, 5> ButtonDataInitKwlist = {"ButtonID", "IsEscapeDefault", "IsEnterDefault", "Text",
                                                              nullptr};
    auto ButtonData::initObject(PyObject *Self, PyObject *Args, PyObject *Kwds) -> i32 {
        if (Self == nullptr) {
            PyErr_SetString(PyExc_RuntimeError, IncorrectButtonData);
            return -1;
        }
        auto *ButtonData = reinterpret_cast<Graphics::ButtonData *>(Self);
        PyObject *PyText = nullptr;
        if (!PyArg_ParseTupleAndKeywords(Args, Kwds, "ibbO:ButtonData", ButtonDataInitKwlist.data(),
                                         &(ButtonData->ButtonID), &(ButtonData->IsEscapeDefault),
                                         &(ButtonData->IsEnterDefault), &PyText) ||
            PyUnicode_Check(PyText) == 0) {
            PyErr_SetString(PyExc_RuntimeError, IncorrectButtonData);
            return -1;
        }
        ButtonData->Text = std::string(PyUnicode_AsUTF8(PyText));
        return 0;
    }

    void ButtonData::deallocObject(PyObject *Self) {
        if (Self == nullptr) {
            return;
        }
        auto *ButtonData = reinterpret_cast<Graphics::ButtonData *>(Self);
        ButtonData->~ButtonData();
        PyObject_Del(Self);
    }

    auto ButtonData::reprObject(const PyObject *Self) -> PyObject * {
        if (Self == nullptr) {
            return nullptr;
        }
        auto ButtonData = reinterpret_cast<const Graphics::ButtonData *>(Self);
        std::string ReprObject = "ButtonData(" + std::to_string(ButtonData->ButtonID) + ", " +
                                 std::to_string(ButtonData->IsEscapeDefault) + ", " +
                                 std::to_string(ButtonData->IsEnterDefault) + ", " + ButtonData->Text + ")";
        return PyUnicode_FromString(ReprObject.c_str());
    }

    auto getModuleFields(PyObject *Module) -> std::vector<Helpers::PythonModule::NamedPythonObject> {
        if (PyType_Ready(&ButtonDataType) < 0) {
            printError("Failed to initialize ButtonData type.");
            return {};
        }

        return {Helpers::PythonModule::NamedPythonObject("showMessageBox",
                                                         PyCFunction_NewEx(&ShowMessageBoxDef, nullptr, Module)),
                Helpers::PythonModule::NamedPythonObject("ButtonData", reinterpret_cast<PyObject *>(&ButtonDataType))};
    }
} // namespace Sola::Python::API::Graphics

// NOLINTEND(readability-named-parameter)
