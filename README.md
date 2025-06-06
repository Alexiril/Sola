# Sola

Sola is a software suite aimed at providing third-party software developers with a convenient and efficient process for implementing windowed multi-platform applications using familiar tools like Python, based on efficient computing systems like SDL and Vulkan.

Current version is 0.1.0

### Building

You need to have these executables installed and be accessible with `path` environment variable:

- Python version 3 (tested with version 3.12)
- CMake version 3.30 and higher (tested with CMake version 4.0.1)
- Git executable
- Any configured C++ compiler (developed with MSVC)
- Doxygen (for docs, tested with version 1.13.2)

Moreover, Graphviz might be used.

To actually build the framework, do the `install` CMake command in the repository directory.
```sh
cmake --install .
```

### Third-party software

#### Used libraries

- [SDL](https://www.libsdl.org) ([github](https://github.com/libsdl-org/SDL), [wiki](https://wiki.libsdl.org), [license](https://github.com/libsdl-org/SDL/blob/main/LICENSE.txt)) - a cross-platform development library designed to provide low level access to audio, keyboard, mouse, joystick, and graphics hardware via OpenGL and Direct3D.

    Sola uses these SDL libraries:

    - Core SDL3 library ([github](https://github.com/libsdl-org/SDL))
    - *in development... SDL3 Image library ([github](https://github.com/libsdl-org/SDL_image))*
    - *in development... SDL3 Mixer library ([github](https://github.com/libsdl-org/SDL_mixer))*
    - *in development... SDL3 TTF library ([github](https://github.com/libsdl-org/SDL_ttf))*

- [Vulkan](https://www.vulkan.org/) ([github](https://github.khronos.org/), [wiki](https://docs.vulkan.org/)) - *in development... Is not used yet. But it will be :)*

- [Python](https://www.python.org) ([github](https://github.com/python/cpython), [wiki](https://docs.python.org), [license](https://github.com/python/cpython/blob/main/LICENSE)) - a high-level, general-purpose programming language.

    Sola uses Python for plenty of things. Firstly, the Python interpreter is integrated into Sola to perform most of all runtime scripting tasks, to simplify the life of developers which are using Sola, or the developers of Sola itself. Moreover, Python is used for building process.

- [Tracy](https://tracy.nereid.pl/) ([github](https://github.com/wolfpld/tracy.git), [license](https://github.com/wolfpld/tracy/blob/master/LICENSE)) - a real time, nanosecond resolution, remote telemetry, hybrid frame and sampling profiler.

    Sola uses Tracy to profile everything inside of it, including CPU, GPU, memory, etc.

- [Capstone](https://www.capstone-engine.org/) ([github](https://github.com/capstone-engine/capstone), [license](https://github.com/capstone-engine/capstone/blob/next/LICENSES/LICENSE.TXT)) - a disassembly framework with the target of becoming the ultimate disasm engine for binary analysis and reversing in the security community.

- [FreeType](https://freetype.org/) ([gitlab](https://gitlab.freedesktop.org/freetype/freetype), [license](https://gitlab.freedesktop.org/freetype/freetype/-/blob/master/LICENSE.TXT)) - a freely available software library to render fonts.

- [GLFW](https://www.glfw.org/) ([github](https://github.com/glfw/glfw), [license](https://github.com/glfw/glfw/blob/master/LICENSE.md)) - an Open Source, multi-platform library for OpenGL, OpenGL ES and Vulkan application development.

    Tracy profiler application uses GLFW library to manage the user interface. Sola uses SDL for the same purposes.

- ImGui ([github](https://github.com/ocornut/imgui), [license](https://github.com/ocornut/imgui/blob/master/LICENSE.txt)) - a bloat-free graphical user interface library for C++.

- Native File Dialog Extended ([github](https://github.com/btzy/nativefiledialog-extended), [license](https://github.com/btzy/nativefiledialog-extended/blob/master/LICENSE)) - a small C library that portably invokes native file open, folder select and file save dialogs.

- PPQSort ([github](https://github.com/GabTux/PPQSort), [license](https://github.com/GabTux/PPQSort/blob/master/LICENSE)) - an efficient implementation of parallel quicksort algorithm.

- [Zstandard](http://www.zstd.net/) ([github](https://github.com/facebook/zstd), [license](https://github.com/facebook/zstd/blob/dev/LICENSE)) - a fast lossless compression algorithm, targeting real-time compression scenarios at zlib-level and better compression ratios.

- [Doxygen Awesome](https://jothepro.github.io/doxygen-awesome-css/index.html) ([github](https://github.com/jothepro/doxygen-awesome-css.git), [license](https://github.com/jothepro/doxygen-awesome-css/blob/main/LICENSE)) - a custom CSS theme for Doxygen HTML documentation with lots of customization parameters.

#### Source Code Analysis tools / SAST tools

- [Cppcheck](https://cppcheck.sourceforge.io) ([github](https://github.com/danmar/cppcheck)) - A tool for static C/C++ code analysis.

#### Other tools used

- [CMake](https://cmake.org/) ([gitlab](https://gitlab.kitware.com/cmake/cmake)) - A free, cross-platform, software development tool for building applications via compiler-independent instructions.

- [Doxygen](https://doxygen.nl) ([github](https://github.com/doxygen/doxygen)) - A widely-used documentation generator tool in software development.
