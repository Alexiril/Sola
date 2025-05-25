# Sola library

It is the main page for the documentation.

Please, fill me! :)

### Style and naming rules in sources

Since some developers (like me) have different habits regarding the format of names, I thought it was necessary to formulate some rules in the form of text. It is worth admitting right away - I did not formulate my code style, but only cruelly mocked [the good old LLVM style](https://llvm.org/docs/CodingStandards.html) (details of the mockery can be found in the .clang_format file). Regarding the names of objects in the Sola code, I generally try to adhere to [the original LLVM format](https://llvm.org/docs/CodingStandards.html#name-types-functions-variables-and-enumerators-properly):

- Type names (classes, structures, enumerations, unions, type declarations, you can name the rest yourself :)) - should be nouns in CamelCase (as suggested in the original documentation, for example, `TextFlieReader`).
- Variable names - nouns in CamelCase (like `Stuff`).
- Function names (methods, procedures, anything that can be called) - verb, action, also CamelCase, but starting with a lowercase letter - i.e., camelCase (`doStuff`, `isFoo`).
- Regarding Enumerators - please, let's do without prefixes if possible! If you have an enumeration like this (as in the original documentation):
    ```c++
    enum class ValueKind {
        Argument = 0, // or VK_Argument, if you follow the original LLVM style
        ...
    }
    ```
    Please write `ValueKind::Argument`, instead of `VK_Argument`, it's really more convenient.

The clarification in the original documentation about classes imitating STL is also true here, if necessary, you can use snake_case.

And yeah, no more 80 columns. I truly understand and agree with the original idea, but it's not really convenient to read and write highly structured code that is (automatically, thanks to clang-format) spread over plenty of unnecessary lines, instead of a logical few. Maybe I'm dumb, and I couldn't configure clang-format correctly, but… Thus, namespace indentation is also allowed.

About RTTI and Exceptions - yeah, don't use them, please. They are not totally prohibited, but it's crucial to use them as few times as possible - it's mainly the performance issue.

### Profiling

Sola uses two profiling sections.

- The first section is responsible for profiling the library and application itself (for example, the editor or runner), and it is enabled by defining the `SOLA_PROFILER_INTERNAL_SECTION` macro. By default, it is enabled for debugging purposes, but for the release build, it should be disabled to improve performance.

- The second section is designed to study the performance directly inside the final application itself (it is mainly used inside the editor executable, for debugging and profiling, but may rarely be found in the library). This section is controlled by the `SOLA_PROFILER_EXTERNAL_SECTION` macro. It should be enabled for both debug and release builds to allow profiling of the final application without Sola profiling.

> [!caution]
> However, the use of the second section (`SOLA_PROFILER_EXTERNAL_SECTION`) is completely prohibited in the runner, as it can negatively affect the performance and security of the final product.