#ifndef CONCEPTS_FINALIZERCONCEPT_HPP
#define CONCEPTS_FINALIZERCONCEPT_HPP

#include "SolaCommon.hpp"

namespace Sola::Runtime::Concepts {

    template <typename FinalizerTypeName, typename FinalizerErrorTypeName>
    concept FinalizerConcept =
        std::is_enum_v<FinalizerErrorTypeName> && requires() {
            {
                FinalizerTypeName::finalizeApplication()
            } -> std::same_as<std::expected<void, FinalizerErrorTypeName>>;
        } && requires(FinalizerErrorTypeName error) {
            { FinalizerTypeName::toString(error) } -> std::same_as<std::string>;
        };

} // namespace Sola::Runtime::Concepts

#endif // CONCEPTS_FINALIZERCONCEPT_HPP
