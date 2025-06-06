#ifndef CONCEPTS_INITIALIZERCONCEPT_HPP
#define CONCEPTS_INITIALIZERCONCEPT_HPP

#include "SolaCommon.hpp"

namespace Sola::Runtime::Concepts {

    template <typename InitializerTypeName, typename InitializerErrorTypeName>
    concept InitializerConcept =
        std::is_enum_v<InitializerErrorTypeName> && requires(i32 ArgumentsCount, char **Arguments) {
            {
                InitializerTypeName::initializeApplication(ArgumentsCount, Arguments)
            } -> std::same_as<std::expected<void, InitializerErrorTypeName>>;
        } && requires(InitializerErrorTypeName error) {
            { InitializerTypeName::toString(error) } -> std::same_as<std::string>;
        };

} // namespace Sola::Runtime::Concepts

#endif // CONCEPTS_INITIALIZERCONCEPT_HPP
