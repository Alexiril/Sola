# Sola

Sola is a software suite aimed at providing third-party software developers with a convenient and efficient process for implementing windowed multi-platform applications using familiar tools like Python, based on efficient computing systems like SDL and Vulkan.

Current version is 0.1.0

### Usage

### Building

### Third-party software

#### Linked into Sola

- [SDL](https://www.libsdl.org) ([github](https://github.com/libsdl-org/SDL), [wiki](https://wiki.libsdl.org)) - A cross-platform development library designed to provide low level access to audio, keyboard, mouse, joystick, and graphics hardware via OpenGL and Direct3D.

    Sola uses these SDL libraries:

    - Core SDL3 library ([github](https://github.com/libsdl-org/SDL))
    - SDL3 Image library ([github](https://github.com/libsdl-org/SDL_image))
    - SDL3 Mixer library ([github](https://github.com/libsdl-org/SDL_mixer))
    - SDL3 TTF library ([github](https://github.com/libsdl-org/SDL_ttf))

- Vulkan - *in development... Is not used yet. But it will be :)*

- [Python](https://www.python.org) ([github](https://github.com/python/cpython), [wiki](https://docs.python.org)) - A high-level, general-purpose programming language.

    Sola uses Python for plenty of things. Firstly, the Python interpreter is integrated into Sola to perform most of all runtime scripting tasks, to simplify the life of developers which are using Sola, or the developers of Sola itself. Moreover, Python is used for building process. 

#### Source Code Analysis tools / SAST tools

- [Cppcheck](https://cppcheck.sourceforge.io) ([github](https://github.com/danmar/cppcheck)) - A tool for static C/C++ code analysis.

#### Other tools used

- [CMake](https://cmake.org/) ([github](https://gitlab.kitware.com/cmake/cmake)) - A free, cross-platform, software development tool for building applications via compiler-independent instructions.

- [Doxygen](https://doxygen.nl) ([github](https://github.com/doxygen/doxygen)) - A widely-used documentation generator tool in software development.
