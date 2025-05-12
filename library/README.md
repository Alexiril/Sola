# Sola library

It is the main page for the documentation.

Please, fill me! :)

### Profiling

Sola uses two profiling sections.

- The first section is responsible for profiling the library and application itself (for example, the editor or runner), and it is enabled by defining the `SOLA_PROFILER_INTERNAL_SECTION` macro. By default, it is enabled for debugging purposes, but for the release build, it should be disabled to improve performance.

- The second section is designed to study the performance directly inside the final application itself (it is mainly used inside the editor executable, for debugging and profiling, but may rarely be found in the library). This section is controlled by the `SOLA_PROFILER_EXTERNAL_SECTION` macro. It should be enabled for both debug and release builds to allow profiling of the final application without Sola profiling.

> [!caution]
> However, the use of the second section (`SOLA_PROFILER_EXTERNAL_SECTION`) is completely prohibited in the runner, as it can negatively affect the performance and security of the final product.