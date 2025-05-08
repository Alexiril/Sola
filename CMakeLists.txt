cmake_minimum_required(VERSION 3.30)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_COMPILE_WARNING_AS_ERROR ON)

set(SOLA_VERSION_MAJOR 0)
set(SOLA_VERSION_MINOR 1)
set(SOLA_VERSION_PATCH 0)
set(SOLA_VERSION_STRING "${SOLA_VERSION_MAJOR}.${SOLA_VERSION_MINOR}.${SOLA_VERSION_PATCH}")

project(sola)

include(GNUInstallDirs)
find_package(Python3 REQUIRED COMPONENTS Interpreter)

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)
option(SOLA_DEBUG_LOG "Print debug logs" ON)
option(DO_INSTALL_LOCALLY "Install the built artifacts to the 'artifacts' folder in the build directory" ON)
option(UPDATE_VENDORED "Update vendored libraries if possible" ON)

# Get vendored
if(!UPDATE_VENDORED)
    set(VENDORED_AUTO_LOADER_ARGS "${VENDORED_AUTO_LOADER_ARGS} --no-update")
endif()
execute_process(COMMAND ${Python3_EXECUTABLE} "${CMAKE_SOURCE_DIR}/scripts/auto_loader.py" ${VENDORED_AUTO_LOADER_ARGS} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR} COMMAND_ERROR_IS_FATAL ANY)

# For Windows Python embeddable package
# TODO#6
set(PYTHON_ARCH "amd64")

if(DO_INSTALL_LOCALLY)
    set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/artifacts)
endif()

set(SDL_INSTALL ON)
set(REBUILD_PYTHON 0)

find_program(CMAKE_CXX_CPPCHECK cppcheck)
    
if(CMAKE_CXX_CPPCHECK)
    set(CPP_CHECK_CMD ${CMAKE_CXX_CPPCHECK} --version)
    execute_process(COMMAND ${CPP_CHECK_CMD}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    RESULT_VARIABLE CPP_CHECK_RESULT
    OUTPUT_VARIABLE CPP_CHECK_VERSION
    ERROR_VARIABLE CPP_CHECK_ERROR)
    if(CPP_CHECK_RESULT EQUAL 0)
        file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/cppcheck)
        include(ProcessorCount)
        ProcessorCount(CPU_CORES)
        list(
            APPEND CMAKE_CXX_CPPCHECK
            "--template=\"${CMAKE_SOURCE_DIR}/{file}({line}): {severity} ({id}): {message}\"" 
            "--quiet" 
            "--enable=all"
            "--std=c++20"
            "--suppressions-list=${CMAKE_SOURCE_DIR}/cppcheck_suppressions.txt"
            "--inline-suppr"
            "--cppcheck-build-dir=${CMAKE_BINARY_DIR}/cppcheck"
            "--addon-python=${Python_EXECUTABLE}"
            "--addon=threadsafety.py"
            "--checkers-report=${CMAKE_BINARY_DIR}/cppcheck/report.xml"
            "-j${CPU_CORES}" 
            "-i./vendor"
            "-i./test"
            "-i./scripts"
            "-i./build"
            "-i./.vscode"
            "-I./library/include"
            "-I./editor/include"
            "."
            )
        add_custom_target(cppcheck
            COMMAND ${CMAKE_CXX_CPPCHECK}
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
            COMMENT "Static code analysis using ${CPP_CHECK_VERSION}"
        )
    endif()
else()
    message(WARNING "Cppcheck not found. Please install cppcheck for better code quality checks.")
endif()

# Add vendored
add_subdirectory(vendor/sdl)
add_subdirectory(vendor/cpython)

add_subdirectory(library)
add_subdirectory(editor)

install(CODE "execute_process(COMMAND ${Python3_EXECUTABLE} \"${CMAKE_SOURCE_DIR}/scripts/build_final_structure.py\" \"${PYTHON_ARCH}\" \"${CMAKE_BINARY_DIR}\" \"${CMAKE_INSTALL_PREFIX}\" \"${CMAKE_INSTALL_LIBDIR}\" \"${CMAKE_INSTALL_BINDIR}\")")
