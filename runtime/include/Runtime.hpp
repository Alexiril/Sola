#ifndef RUNTIME_HPP
#define RUNTIME_HPP

#include "Sola.hpp"

#include "Concepts/FinalizerConcept.hpp"
#include "Concepts/InitializerConcept.hpp"

/// @brief This namespace contains all the runtime-related functionality.
namespace Sola::Runtime {};

/// @brief This namespace contains all the editor-related functionality.
namespace Sola::Runtime::Editor {}

#ifndef EDITOR_APPLICATION
#    include "Finalizer/Finalizer.hpp"
#    include "Initializer/Initializer.hpp"

namespace Sola::Runtime {
    /// @brief Alias for the runtime initializer type.
    using Initializer = Sola::Runtime::InitializerType;
    /// @brief Alias for the runtime initializer error type.
    using InitializerError = Sola::Runtime::InitializerError;
    /// @brief Alias for the runtime finalizer type.
    using Finalizer = Sola::Runtime::FinalizerType;
    /// @brief Alias for the runtime finalizer error type.
    using FinalizerError = Sola::Runtime::FinalizerError;
}; // namespace Sola::Runtime

#else // It's editor application
#    include "EditorFinalizer/EditorFinalizer.hpp"
#    include "EditorInitializer/EditorInitializer.hpp"

namespace Sola::Runtime {
    using Initializer = Sola::Runtime::Editor::InitializerType;
    using InitializerError = Sola::Runtime::Editor::InitializerError;
    using Finalizer = Sola::Runtime::Editor::FinalizerType;
    using FinalizerError = Sola::Runtime::Editor::FinalizerError;
} // namespace Sola::Runtime

#endif

#endif // RUNTIME_HPP
