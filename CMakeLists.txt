cmake_minimum_required(VERSION 3.30)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOLA_VERSION_MAJOR 0)
set(SOLA_VERSION_MINOR 1)
set(SOLA_VERSION_PATCH 0)
set(SOLA_VERSION_STRING "${SOLA_VERSION_MAJOR}.${SOLA_VERSION_MINOR}.${SOLA_VERSION_PATCH}")

set(SOLA_PROFILER_INTERNAL_SECTION ON)
set(SOLA_PROFILER_EXTERNAL_SECTION ON)

project(sola)

include(GNUInstallDirs)
find_package(Python3 REQUIRED COMPONENTS Interpreter)

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)
option(SOLA_DEBUG_LOG "Print debug logs" ON)
option(DO_INSTALL_LOCALLY "Install the built artifacts to the 'artifacts' folder in the build directory" ON)
option(UPDATE_VENDORED "Update vendored libraries if possible" ON)
option(TRACY_ENABLE "Enable Tracy" ON)

# Get vendored
if(!UPDATE_VENDORED)
    set(VENDORED_AUTO_LOADER_ARGS "${VENDORED_AUTO_LOADER_ARGS} --no-update")
endif()
execute_process(COMMAND ${Python3_EXECUTABLE} -u "${CMAKE_SOURCE_DIR}/scripts/auto_loader.py" ${VENDORED_AUTO_LOADER_ARGS} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR} COMMAND_ERROR_IS_FATAL ANY)

# For Windows Python embeddable package
# TODO#6
set(PYTHON_ARCH "amd64")

if(DO_INSTALL_LOCALLY)
    set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/artifacts)
endif()

set(SDL_INSTALL ON)
set(REBUILD_PYTHON 0)
set(BUILD_DOCS ON)

set(ZSTD_BUILD_STATIC OFF)
set(ZSTD_PROGRAMS_LINK_SHARED ON)
set(CAPSTONE_X86_ATT_DISABLE ON)
set(CAPSTONE_ALPHA_SUPPORT OFF)
set(CAPSTONE_HPPA_SUPPORT OFF)
set(CAPSTONE_LOONGARCH_SUPPORT OFF)
set(CAPSTONE_M680X_SUPPORT OFF)
set(CAPSTONE_M68K_SUPPORT OFF)
set(CAPSTONE_MIPS_SUPPORT OFF)
set(CAPSTONE_MOS65XX_SUPPORT OFF)
set(CAPSTONE_PPC_SUPPORT OFF)
set(CAPSTONE_SPARC_SUPPORT OFF)
set(CAPSTONE_SYSTEMZ_SUPPORT OFF)
set(CAPSTONE_XCORE_SUPPORT OFF)
set(CAPSTONE_TRICORE_SUPPORT OFF)
set(CAPSTONE_TMS320C64X_SUPPORT OF)
set(CAPSTONE_M680X_SUPPORT OFF)
set(CAPSTONE_EVM_SUPPORT OFF)
set(CAPSTONE_WASM_SUPPORT OFF)
set(CAPSTONE_BPF_SUPPORT OFF)
set(CAPSTONE_RISCV_SUPPORT OFF)
set(CAPSTONE_SH_SUPPORT OFF)
set(CAPSTONE_XTENSA_SUPPORT OFF)
set(CAPSTONE_BUILD_MACOS_THIN ON)
set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_DOCS OFF)
set(GLFW_INSTALL ON)
set(FT_DISABLE_HARFBUZZ ON)
set(FT_WITH_HARFBUZZ OFF)
set(NFD_INSTALL ON)

add_compile_definitions(IMGUI_ENABLE_FREETYPE)
add_compile_definitions(TRACY_ENABLE)

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

if(BUILD_DOCS)
    if((NOT DEFINED CMAKE_INSTALL_DOCDIR) OR (NOT DEFINED ${CMAKE_INSTALL_DOCDIR}) OR (CMAKE_INSTALL_DOCDIR STREQUAL ""))
        set(CMAKE_INSTALL_DOCDIR ${CMAKE_INSTALL_PREFIX}/docs)
    endif()

    find_package(Doxygen REQUIRED dot)
    set(DOXYGEN_CREATE_SUBDIRS YES)
    set(DOXYGEN_CREATE_SUBDIRS_LEVEL 0)
    set(DOXYGEN_ALLOW_UNICODE_NAMES YES)
    set(DOXYGEN_PYTHON_DOCSTRING NO)
    set(DOXYGEN_BUILTIN_STL_SUPPORT YES)
    set(DOXYGEN_CPP_CLI_SUPPORT YES)
    set(DOXYGEN_EXTENSION_MAPPING "pyi=Python")
    set(DOXYGEN_USE_MDFILE_AS_MAINPAGE "README.md")
    set(DOXYGEN_GENERATE_HTML YES)
    set(DOXYGEN_HTML_COLORSTYLE_HUE 0)
    set(DOXYGEN_HTML_COLORSTYLE_SAT 0)
    set(DOXYGEN_HTML_COLORSTYLE_GAMMA 85)
    set(DOXYGEN_HTML_DYNAMIC_SECTIONS YES)
    set(DOXYGEN_GENERATE_TREEVIEW YES)
    set(DOXYGEN_SEARCH_ENGINE YES)
    set(DOXYGEN_HIDE_UNDOC_RELATIONS NO)
    set(DOXYGEN_HAVE_DOT YES)
    set(DOXYGEN_CALL_GRAPH YES)
    set(DOXYGEN_CALLER_GRAPH YES)
    set(DOXYGEN_QUIET YES)
    set(DOXYGEN_WARNINGS YES)
    set(DOXYGEN_WARN_AS_ERROR YES)
endif()

# Add vendored
include(scripts/CPM.cmake)
add_subdirectory(vendor/cpython)          # python interpreter
add_subdirectory(vendor/capstone)         # disassembler framework (for Tracy only)
add_subdirectory(vendor/glfw)             # media library (for Tracy only, Tracy uses GLFW, not SDL)
add_subdirectory(vendor/zstd/build/cmake) # fast compression algorithm
add_subdirectory(vendor/freetype)         # library for fonts
# There should also be ImGui here, but there is no point in building it without an application
add_subdirectory(vendor/nfd)
add_subdirectory(vendor/ppqsort)          # parallel pattern quicksort algorithm
add_subdirectory(vendor/sdl)              # media library for Sola
add_subdirectory(vendor/tracy)            # profiler client (into profiled apps)
add_subdirectory(vendor/tracy/profiler)   # profiler server (profiler application)
add_subdirectory(vendor/tracy/capture)    # profile server no GUI, just saving

add_subdirectory(library)
add_subdirectory(editor)

install(CODE "execute_process(COMMAND ${Python3_EXECUTABLE} \"${CMAKE_SOURCE_DIR}/scripts/build_final_structure.py\" \"${PYTHON_ARCH}\" \"${CMAKE_BINARY_DIR}\" \"${CMAKE_INSTALL_PREFIX}\" \"${CMAKE_INSTALL_LIBDIR}\" \"${CMAKE_INSTALL_BINDIR}\" \"${CMAKE_SOURCE_DIR}/vendor\")")
