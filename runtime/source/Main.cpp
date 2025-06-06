#include "Runtime.hpp"

auto main(Sola::i32 ArgumentsCount, char **Arguments) -> Sola::i32 {
    static_assert(
        Sola::Runtime::Concepts::InitializerConcept<Sola::Runtime::Initializer, Sola::Runtime::InitializerError>,
        "Sola::Runtime::Initializer must satisfy Sola::Runtime::InitializerConcept");
    static_assert(Sola::Runtime::Concepts::FinalizerConcept<Sola::Runtime::Finalizer, Sola::Runtime::FinalizerError>,
                  "Sola::Runtime::Finalizer must satisfy Sola::Runtime::FinalizerConcept");

    auto InitResult = Sola::Runtime::Initializer::initializeApplication(ArgumentsCount, Arguments);
    if (!InitResult.has_value()) {
        printFatal(Sola::Runtime::Initializer::toString(InitResult.error()));
        return 1; // Return a non-zero exit code on failure
    }

    // Some application logic will go here

    auto FinalizeResult = Sola::Runtime::Finalizer::finalizeApplication();
    if (!FinalizeResult.has_value()) {
        printFatal(Sola::Runtime::Finalizer::toString(FinalizeResult.error()));
        return 1; // Return a non-zero exit code on failure
    }

    printInfo("Bye!");

    return 0;
}
