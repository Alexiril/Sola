#ifndef PYTHON_INTERPRETER_HPP
#define PYTHON_INTERPRETER_HPP

#include "Logger/Logger.hpp"
#include "SolaCommon.hpp"

namespace Sola::Python {
    /// @brief This is a simple structure holding both the module name and the function pointer to the init
    /// function. It's used to register the internal modules that are needed for the interpreter to work.
    /// @todo Why don't I use std::pair or std::map again?..
    struct InternalModule {
    public:
        /// @brief The name of the module (like "numpy").
        const char *ModuleName;
        /// @brief The function pointer to the init function of the module.
        PyObject *(*moduleInit)();
    };

    /// @brief Possible errors that can occur in the interpreter.
    enum class InterpreterError {
        InterpNotInitialized,
        NoModulesAvailable,
        ObjectDoesNotExist,
        ObjectIsNotCallable,
        FunctionCallFailed,
        PythonObjectAllocationFailed,
        TransformStringToUnicodeFailed,
        SetAttributeFailed,
        DelAttributeFailed,
    };

    /// @brief The class that should be used to handle all the requests to the Python Interpreter (except for Sola
    /// Python API, there it is faster to not call the interpreter each time those functions need some PyObject
    /// pointer parsing, but do it in place with Python API).
    class Interpreter {
    public:
        /// @brief Constructor for the interpreter. It initializes the interpreter and registers the internal
        /// modules.
        /// @param Config The configuration for the interpreter. It should be initialized before calling this
        /// constructor.
        /// @param InternalModules The internal modules that should be registered. It should be an array of
        /// InternalModule structures. The array should be of size ModulesAmount.
        /// @note The modules are registered in the order they are passed to the constructor.
        /// @note ModulesAmount type is u8, so the maximum amount of modules is 255. That should be enough for the
        /// internal modules in a normal case. Also, it seems to simplify the life of some sast tools (yep,
        /// cppcheck). If it won't be enough, we can rebuild the library with u16.
        Interpreter(PyConfig &Config, const std::vector<InternalModule>& InternalModules);

        /// @brief No copy constructor for this class, only moves.
        Interpreter(const Interpreter &) = delete;

        /// @brief Move constructor is available if needed
        EXPORTED Interpreter(Interpreter &&) noexcept;

        EXPORTED ~Interpreter() noexcept;

        /// @brief Check if the interpreter is initialized.
        /// @return true if the interpreter successfully completed all initialization steps, otherwise false.
        /// @note Should be used to understand if the interpreter is ready, because the constructor does not throw
        EXPORTED auto isInitialized() const noexcept -> bool;

        /// @brief Calls PyImport_ImportModule to import a new module (it should be a module in Lib folder or where
        /// the interpreter can reach it).
        /// @param ModuleName The name of the module to import (like numpy or smth).
        /// @return true if the module was imported successfully, otherwise false.
        EXPORTED auto importModule(const std::string &ModuleName) -> bool;

        /// @brief Runs a method of an object inside the Python Interpreter
        /// @param Object the actual object with the callable method member
        /// @param MethodName the name of the function member that will be called
        /// @param Args a list of positional arguments which will be passed into the method
        /// @param Kwargs a dictionary (map) of named arguments
        /// @return Result of the function or error
        EXPORTED auto runFunction(PyObject *Object, const std::string &MethodName, const std::vector<PyObject *> &Args,
                                  const std::unordered_map<std::string, PyObject *> &Kwargs)
            -> std::expected<PyObject *, InterpreterError>;

        /// @brief Runs any function (that is registered inside some imported module) inside the Python Interpreter
        /// @param ModuleName the name of the module where the function is registered
        /// @param FunctionName actual name in Python of the called function (without the module name)
        /// @param Args a list of positional arguments which will be passed into the function
        /// @param Kwargs a dictionary (map) of named arguments
        /// @return Result of the function or error
        EXPORTED auto runFunction(const std::string &ModuleName, const std::string &FunctionName,
                                  const std::vector<PyObject *> &Args,
                                  const std::unordered_map<std::string, PyObject *> &Kwargs)
            -> std::expected<PyObject *, InterpreterError>;

        /// @brief It is a simple wrapper over PyObject_GetAttrString, to
        /// simplify the process of working with Python objects
        /// @param Object the Python object with some set attributes
        /// @param AttributeName the name of the attribute to get
        /// @return Python object representing the attribute value or the error
        EXPORTED auto getAttribute(PyObject *Object, const std::string &AttributeName)
            -> std::expected<PyObject *, InterpreterError>;

        /// @brief It is a simple wrapper over PyObject_GetAttrString for imported modules (imported via this class)
        /// @param ModuleName the name of the module to look for the attribute
        /// @param AttributeName the name of the attribute to get
        /// @return Python object representing the attribute value or the error
        EXPORTED auto getAttribute(const std::string &ModuleName, const std::string &AttributeName)
            -> std::expected<PyObject *, InterpreterError>;

        /// @brief Simple wrapper over PyObject_SetAttr
        /// @param Object the Python object pointer, where the attribute will be set
        /// @param AttributeName the name of the attribute
        /// @param Value the value of the attribute
        /// @return the original object where the attribute is now set or error
        EXPORTED auto setAttribute(PyObject *Object, const std::string &AttributeName, PyObject *Value)
            -> std::expected<PyObject *, InterpreterError>;

        /// @brief Simple wrapper over PyObject_SetAttr specifically for strings
        /// @param Object the Python object pointer, where the attribute will be set
        /// @param AttributeName the name of the attribute
        /// @param Value the string value of the attribute
        /// @return the original object where the attribute is now set or error
        EXPORTED auto setAttribute(PyObject *Object, const std::string &AttributeName, const std::string &Value)
            -> std::expected<PyObject *, InterpreterError>;

        /// @brief Simple wrapper over PyObject_SetAttr specifically for signed integers
        /// @param Object the Python object pointer, where the attribute will be set
        /// @param AttributeName the name of the attribute
        /// @param Value the integer value of the attribute
        /// @return the original object where the attribute is now set or error
        EXPORTED auto setAttribute(PyObject *Object, const std::string &AttributeName, i64 Value)
            -> std::expected<PyObject *, InterpreterError>;

        /// @brief Simple wrapper over PyObject_SetAttr specifically for unsigned integers
        /// @param Object the Python object pointer, where the attribute will be set
        /// @param AttributeName the name of the attribute
        /// @param Value the integer value of the attribute
        /// @return the original object where the attribute is now set or error
        EXPORTED auto setAttribute(PyObject *Object, const std::string &AttributeName, u64 Value)
            -> std::expected<PyObject *, InterpreterError>;

        /// @brief Simple wrapper over PyObject_DelAttr
        /// @param Object the object with the attribute to be deleted
        /// @param AttributeName the name of the attribute to be deleted
        /// @return the original object with no more attribute, or error
        EXPORTED auto deleteAttribute(PyObject *Object, const std::string &AttributeName)
            -> std::expected<void, InterpreterError>;

    private:
        bool Initialized;
        std::unordered_map<std::string, PyObject *> Modules;
    };

} // namespace Sola::Python
#endif
