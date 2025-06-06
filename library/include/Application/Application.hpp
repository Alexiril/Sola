#ifndef APPLICATION_APPLICATION_HPP
#define APPLICATION_APPLICATION_HPP

#include "Application/Modules.hpp"
#include "Python/Interpreter.hpp"
#include "SolaCommon.hpp"

/// @brief This namespace contain all the general application code, including the Application singleton, and the
/// application modules enumeration.
namespace Sola::Application {
    /// @brief Enumeration for the possible errors that can occur during the application processes.
    enum class ApplicationError {
        AppIsAlreadyInitialized,
        PythonInitializationFailed,
        SolaModuleImportFailed,
        ProjectInitializationFailed,
        SDLInitializationFailed,
    };

    /// @brief This class is used to initialize the application and manage its state.
    /// @note This class is represented with a singleton object. Please, do not use this class directly, use the
    /// static methods instead.
    class Application final {
    public:
        /// @brief This is the entry point function for the application (Sola shared library).
        /// @param IsEditor true if the application is an editor, false if it is a runner.
        /// @param ProjectDir the directory with the current opened (or opening) project.
        /// @param Argc amount of command line arguments (usually taken from main function).
        /// @param Argv pointer to the command line arguments (usually taken from main function as well).
        /// @param AppName the name of the application (is used a lot via SDL, like in system menus).
        /// @param AppVersion the version of the application (any custom string, no validation, optional, can be
        /// empty).
        /// @param AppIdentifier the identifier of the application (should be unique, like a package name -
        /// com.company.project, optional).
        /// @param AppCreator the name of the application creator (optional).
        /// @param AppCopyright the copyright of the application (should be readable, like "© 2025 Company Ltd.").
        /// @param AppUrl the URL for the application (optional).
        /// @param PythonModules a vector of internal Python modules to be imported into the application.
        /// @return a pointer to the application object if everything is ok, an error code otherwise.
        /// @note **This function should be called only once**, otherwise it will return an error code.
        EXPORTED static auto initApplication(bool IsEditor, const std::string &ProjectDir, u64 Argc, char *const *Argv,
                                             const std::string &AppName, const std::string &AppVersion,
                                             const std::string &AppIdentifier, const std::string &AppCreator,
                                             const std::string &AppCopyright, const std::string &AppUrl,
                                             std::vector<Python::InternalModule> &PythonModules)
            -> std::expected<Application *, ApplicationError>;

        /// @brief Gets the current application instance.
        /// @return pointer to the current application instance (`nullptr` if the application is not initialized
        /// yet).
        /// @note Do not try to pass something to this function, it will not work :)
        EXPORTED static auto get() noexcept -> Application *;

        /// @brief Finalizes the application and cleans up all resources.
        /// @attention This function should be called only once, when the application is about to exit.
        EXPORTED static void quitApplication() noexcept;

        /// @brief No copy constructor, no copy assignment operator.
        Application(const Application &) = delete;
        /// @brief No copy constructor, no copy assignment operator.
        auto operator=(const Application &) -> Application & = delete;
        /// @brief No move constructor, no move assignment operator.
        Application(Application &&) = delete;
        /// @brief No move constructor, no move assignment operator.
        auto operator=(Application &&) -> Application & = delete;

        // getters

        /// @brief Simple getter for IsEditor variable. You can set it in the constructor only.
        /// @return Current value of IsEditor variable.
        /// @note This function is used to check if the application is in the editor or a runner mode.
        EXPORTED auto isEditor() const noexcept -> bool;
        /// @brief Simple getter for AppProjectDir variable. You can set it in the constructor only.
        /// @return Current value of AppProjectDir variable.
        EXPORTED auto getProjectDir() const noexcept -> const std::string &;
        /// @brief Simple getter for AppName variable. You can set it in the constructor only.
        /// @return Current value of AppName variable.
        EXPORTED auto getName() const noexcept -> const std::string &;
        /// @brief Simple getter for AppVersion variable. You can set it in the constructor only.
        /// @return Current value of AppVersion variable.
        EXPORTED auto getVersion() const noexcept -> const std::string &;
        /// @brief Simple getter for AppIdentifier variable. You can set it in the constructor only.
        /// @return Current value of AppIdentifier variable.
        EXPORTED auto getIdentifier() const noexcept -> const std::string &;
        /// @brief Simple getter for AppCreator variable. You can set it in the constructor only.
        /// @return Current value of AppCreator variable.
        EXPORTED auto getCreator() const noexcept -> const std::string &;
        /// @brief Simple getter for AppCopyright variable. You can set it in the constructor only.
        /// @return Current value of AppCopyright variable.
        EXPORTED auto getCopyright() const noexcept -> const std::string &;
        /// @brief Simple getter for AppUrl variable. You can set it in the constructor only.
        /// @return Current value of AppUrl variable.
        EXPORTED auto getUrl() const noexcept -> const std::string &;
        /// @brief Simple getter for ProjectConfiguration variable. You can set it in the setProjectConfiguration
        /// function.
        /// @return Current value of ProjectConfiguration variable.
        /// @note It may return nullptr if the project configuration is not set yet.
        EXPORTED auto getProjectConfiguration() const noexcept -> PyObject *;

        // setters

        /// @brief Sets the ProjectConfiguration member variable with a given PyObject pointer. The object should
        /// be (or at least, inherit from, to be compatible with) a dictionary.
        /// @param configuration PyObject pointer to the project configuration object (should be a dictionary).
        /// @note It doesn't return anything. You should trust it unconditionally, as I do.
        /// @note This function overwrites the previous value of the ProjectConfiguration variable, decreasing the
        /// previous reference count if it was not `nullptr`.
        EXPORTED void setProjectConfiguration(PyObject *configuration);

        /// @brief Gets the Python interpreter instance.
        /// @return Smart shared pointer to the Python interpreter instance.
        EXPORTED auto getPythonInterpreter() const noexcept -> std::weak_ptr<Python::Interpreter>;

    private:
        Application(bool IsEditor, std::string ProjectDir, u64 Argc, char *const *Argv, std::string AppName,
                    std::string AppVersion, std::string AppIdentifier, std::string AppCreator, std::string AppCopyright,
                    std::string AppUrl);
        ~Application() noexcept;

        auto initializePython(std::vector<Python::InternalModule> &InternalModules)
            -> std::expected<void, ApplicationError>;
        auto initializeProject() -> std::expected<void, ApplicationError>;
        auto initializeSDL() -> std::expected<void, ApplicationError>;

        static auto setSDLMetadata(const char *metadata_name, const std::string &value)
            -> std::expected<void, ApplicationError>;

        void quitPython();
        static void quitSDL();

        bool IsEditor;
        std::string AppName;
        std::string AppVersion;
        std::string AppIdentifier;
        std::string AppCreator;
        std::string AppCopyright;
        std::string AppUrl;
        std::vector<Module> Modules;
        u64 CMDArgumentsCount;
        char *const *CMDArguments;

        std::string AppProjectDir;
        PyObject *ProjectConfiguration;

        std::shared_ptr<Python::Interpreter> Interpreter;

        static Application *Instance;
    };
} // namespace Sola::Application

#endif
