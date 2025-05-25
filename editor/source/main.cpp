#include "application.hpp"

auto main(int argc, char *argv[]) -> int {
    if (argc < 2) {
        printInfo("Incorrect amount of arguments. \nUsage is sola-editor "
                  "\"path-to-project-dir\" [...]");
        return 1;
    }

    auto initResult = Sola::Application::Application::initApplication(true, std::string(argv[1]), argc, argv, "Sola Editor",
                                                    SOLA_VERSION_STRING, "com.sola.editor", "Alex Kirel", "", "");
    if (!initResult) {
        printInfo("Failed to initialize application.");
        return 1;
    }

    printInfo("Sola engine started");

    return 0;
}
