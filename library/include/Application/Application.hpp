#ifndef SOLA_APPLICATION_APPLICATION
#define SOLA_APPLICATION_APPLICATION

#include "Application/Modules.hpp"
#include "Python/Interpreter.hpp"
#include "sola_common.hpp"

namespace Sola
{
    /// @brief This namespace contain all the general application code, including the Application singleton, and the application modules enumeration.
    namespace Application
    {
        /// @brief Enumeration for the possible errors that can occur during the application processes.
        enum class ApplicationError
        {
            AppIsAlreadyInitialized,
            PythonInitializationFailed,
            SolaModuleImportFailed,
            ProjectInitializationFailed,
            SDLInitializationFailed,
        };

        /// @brief This class is used to initialize the application and manage its state.
        /// @note This class is represented with a singleton object. Please, do not use this class directly, use the
        /// static methods instead.
        class Application final
        {
        public:
            /// @brief This is the entry point function for the application (Sola shared library).
            /// @param is_editor true if the application is an editor, false if it is a runner.
            /// @param project_dir the directory with the current opened (or opening) project.
            /// @param argc amount of command line arguments (usually taken from main function).
            /// @param argv pointer to the command line arguments (usually taken from main function as well).
            /// @param app_name the name of the application (is used a lot via SDL, like in system menus).
            /// @param app_version the version of the application (any custom string, no validation, optional, can be
            /// empty).
            /// @param app_identifier the identifier of the application (should be unique, like a package name -
            /// com.company.project, optional).
            /// @param app_creator the name of the application creator (optional).
            /// @param app_copyright the copyright of the application (should be readable, like "© 2025 Company Ltd.").
            /// @param app_url the URL for the application (optional).
            /// @return a pointer to the application object if everything is ok, an error code otherwise.
            /// @note **This function should be called only once**, otherwise it will return an error code.
            EXPORTED static std::expected<Application *, ApplicationError>
            init_application(bool is_editor, const std::string &project_dir, u64 argc, char *const *argv,
                             const std::string &app_name, const std::string &app_version,
                             const std::string &app_identifier, const std::string &app_creator,
                             const std::string &app_copyright, const std::string &app_url);

            /// @brief Gets the current application instance.
            /// @return pointer to the current application instance (`nullptr` if the application is not initialized
            /// yet).
            /// @note Do not try to pass something to this function, it will not work :)
            EXPORTED static Application *get(void) noexcept;

            /// @brief No copy constructor, no copy assignment operator.
            Application(const Application &) = delete;
            /// @brief No copy constructor, no copy assignment operator.
            Application &operator=(const Application &) = delete;
            /// @brief No move constructor, no move assignment operator.
            Application(Application &&) = delete;
            /// @brief No move constructor, no move assignment operator.
            Application &operator=(Application &&) = delete;

            // getters

            /// @brief Simple getter for is_editor_ variable. You can set it in the constructor only.
            /// @return Current value of is_editor_ variable.
            /// @note This function is used to check if the application is in the editor or a runner mode.
            EXPORTED bool is_editor(void) const noexcept;
            /// @brief Simple getter for app_project_dir variable. You can set it in the constructor only.
            /// @return Current value of app_project_dir variable.
            EXPORTED const std::string &get_project_dir(void) const noexcept;
            /// @brief Simple getter for app_name variable. You can set it in the constructor only.
            /// @return Current value of app_name variable.
            EXPORTED const std::string &get_name(void) const noexcept;
            /// @brief Simple getter for app_version variable. You can set it in the constructor only.
            /// @return Current value of app_version variable.
            EXPORTED const std::string &get_version(void) const noexcept;
            /// @brief Simple getter for app_identifier variable. You can set it in the constructor only.
            /// @return Current value of app_identifier variable.
            EXPORTED const std::string &get_identifier(void) const noexcept;
            /// @brief Simple getter for app_creator variable. You can set it in the constructor only.
            /// @return Current value of app_creator variable.
            EXPORTED const std::string &get_creator(void) const noexcept;
            /// @brief Simple getter for app_copyright variable. You can set it in the constructor only.
            /// @return Current value of app_copyright variable.
            EXPORTED const std::string &get_copyright(void) const noexcept;
            /// @brief Simple getter for app_url variable. You can set it in the constructor only.
            /// @return Current value of app_url variable.
            EXPORTED const std::string &get_url(void) const noexcept;
            /// @brief Simple getter for project_configuration variable. You can set it in the set_project_configuration
            /// function.
            /// @return Current value of project_configuration variable.
            /// @note It may return nullptr if the project configuration is not set yet.
            EXPORTED PyObject *get_project_configuration(void) const noexcept;

            // setters

            /// @brief Sets the project_configuration member variable with a given PyObject pointer. The object should
            /// be (or at least, inherit from, to be compatible with) a dictionary.
            /// @param configuration PyObject pointer to the project configuration object (should be a dictionary).
            /// @note It doesn't return anything. You should trust it unconditionally, as I do.
            /// @note This function overwrites the previous value of the project_configuration variable, decreasing the
            /// previous reference count if it was not `nullptr`.
            EXPORTED void set_project_configuration(PyObject *configuration);

        private:
            Application(bool is_editor, const std::string &project_dir, u64 argc, char *const *argv,
                        const std::string &app_name, const std::string &app_version, const std::string &app_identifier,
                        const std::string &app_creator, const std::string &app_copyright, const std::string &app_url);
            ~Application(void) noexcept;

            std::expected<void, ApplicationError> initialize_python(void);
            std::expected<void, ApplicationError> initialize_project(void);
            std::expected<void, ApplicationError> initialize_sdl(void);

            std::expected<void, ApplicationError> set_sdl_metadata(const char *metadata_name, const std::string &value);

            void quit_python(void);
            void quit_sdl(void);

            bool is_editor_;
            std::string app_name;
            std::string app_version;
            std::string app_identifier;
            std::string app_creator;
            std::string app_copyright;
            std::string app_url;
            std::vector<Module> modules;
            u64 cmd_arguments_count;
            char *const *cmd_arguments;

            std::string app_project_dir;
            PyObject *project_configuration;

            std::unique_ptr<Python::Interpreter> interpreter;

            static Application *instance;
        };
    } // namespace Application

} // namespace Sola

#endif
