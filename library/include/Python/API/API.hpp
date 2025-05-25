#ifndef PYTHON_API_API_HPP
#define PYTHON_API_API_HPP

#include "SolaCommon.hpp"

/// @brief This namespace contains all the code related to the Sola Python API.
namespace Sola::Python::API {
    static const char *ModuleName = "SolaAPI";

    static const char *FormattingError = "Failed to parse arguments";

    static const char *SolaAPIError = "SolaAPI unknown error. This should not happen.";

    /// @brief Returns into Python the current engine version in number format.
    /// @param Self not used.
    /// @param Args not used.
    /// @return the Sola engine version in number format.
    EXPORTED PyObject *getEngineVersion(PyObject *Self, PyObject *Args);

    /// @brief Returns into Python the current engine version in human readable format.
    /// @param Self not used.
    /// @param Args not used.
    /// @return the Sola engine version in human readable format.
    EXPORTED PyObject *getEngineVersionReadable(PyObject *Self, PyObject *Args);

    static PyMethodDef Methods[] = {
        {"getEngineVersion", getEngineVersion, METH_VARARGS, "Returns the current engine version in number format."},
        {"getEngineVersionReadable", getEngineVersionReadable, METH_VARARGS,
         "Returns the current engine version in human readable format."},
        {NULL, NULL, 0, NULL}};

    static PyModuleDef APIModuleDef = {PyModuleDef_HEAD_INIT, ModuleName, NULL, -1, Methods, NULL, NULL, NULL, NULL};

    /// @brief Creates main SolaAPI module and all its submodules (Application, Graphics, Logger, etc.)
    /// @return The module pointer or nullptr if something gone wrong.
    EXPORTED PyObject *createPythonModule();
} // namespace Sola::Python::API

#include "Python/API/Application.hpp"
#include "Python/API/Errors.hpp"
#include "Python/API/Graphics.hpp"
#include "Python/API/Logger.hpp"

#endif
