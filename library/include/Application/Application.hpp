#ifndef SOLA_APPLICATION_APPLICATION
#define SOLA_APPLICATION_APPLICATION

#include "Graphics/SDLModules.hpp"
#include "Python/Interpreter.hpp"
#include "sola_common.hpp"

namespace Sola
{
    namespace Application
    {
        class Application
        {
        public:
            EXPORTED static Application *init_application(bool is_editor, const std::string &project_dir, u64 argc,
                                                          char *const *argv, const std::string &app_name,
                                                          const std::string &app_version,
                                                          const std::string &app_identifier,
                                                          const std::string &app_creator,
                                                          const std::string &app_copyright, const std::string &app_url);

            EXPORTED static Application *get(void) noexcept;

            Application(const Application &) = delete;
            Application &operator=(const Application &) = delete;

            // getters
            EXPORTED bool is_editor(void) const;
            EXPORTED const std::string &get_project_dir(void) const noexcept;
            EXPORTED const std::string &get_name(void) const noexcept;
            EXPORTED const std::string &get_version(void) const noexcept;
            EXPORTED const std::string &get_identifier(void) const noexcept;
            EXPORTED const std::string &get_creator(void) const noexcept;
            EXPORTED const std::string &get_copyright(void) const noexcept;
            EXPORTED const std::string &get_url(void) const noexcept;
            EXPORTED PyObject *get_project_configuration(void) const noexcept;
            
            // setters
            EXPORTED void set_project_configuration(PyObject *configuration);

        private:
            Application(bool is_editor, const std::string &project_dir, u64 argc, char *const *argv,
                        const std::string &app_name, const std::string &app_version, const std::string &app_identifier,
                        const std::string &app_creator, const std::string &app_copyright, const std::string &app_url);
            ~Application(void) noexcept;

            void initialize_python(void);
            void initialize_project(void);
            void initialize_sdl(void);

            void set_sdl_metadata(const char *metadata_name, const std::string &value);

            void quit_python(void);
            void quit_sdl(void);

            bool is_editor_;
            std::string app_name;
            std::string app_version;
            std::string app_identifier;
            std::string app_creator;
            std::string app_copyright;
            std::string app_url;
            std::vector<Graphics::SDLModule> sdl_modules;
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
