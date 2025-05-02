#include "application.hpp"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        print_info("Incorrect amount of arguments. \nUsage is sola-editor "
                   "\"path-to-project-dir\" [...]");
        return 1;
    }

    Sola::Application::Application::init_application(true, std::string(argv[1]), argc, argv, "Sola Editor",
                                                     SOLA_VERSION_STRING, "com.sola.editor", "Alex Kirel", "", "");

    print_info("Sola engine started");

    return 0;
}
