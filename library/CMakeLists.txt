# Sola C++ dynamic linked (shared) library & Sola Python module

message("Working on Sola C++ / Python Library")

# Don't mention this, please. This is just to feed my ego.
execute_process(COMMAND ${Python3_EXECUTABLE} ${CMAKE_SOURCE_DIR}/scripts/lines_counter.py ${CMAKE_CURRENT_SOURCE_DIR} ".py" ".pyi" ".hpp" ".cpp"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    ERROR_QUIET
)

# -- Independent definitions --

set(SOLA_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOLA_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/source)
set(SOLA_PYTHON  ${CMAKE_CURRENT_SOURCE_DIR}/Sola)
set(SOLA_PYTHON_MODULE_NAME Sola)

set(PUBLIC_HEADERS
    # General
    ${SOLA_INCLUDE_DIR}/sola.hpp ${SOLA_INCLUDE_DIR}/sola_common.hpp
    # Application
    ${SOLA_INCLUDE_DIR}/Application/Application.hpp ${SOLA_INCLUDE_DIR}/Application/Modules.hpp
    # Exception
    ${SOLA_INCLUDE_DIR}/Exception/GeneralException.hpp
    # Graphics
    ${SOLA_INCLUDE_DIR}/Graphics/WindowsManager.hpp ${SOLA_INCLUDE_DIR}/Graphics/Color.hpp
    # Helpers
    ${SOLA_INCLUDE_DIR}/Helpers/FileSystem.hpp ${SOLA_INCLUDE_DIR}/Helpers/PythonModule.hpp
    # Logger
    ${SOLA_INCLUDE_DIR}/Logger/Logger.hpp ${SOLA_INCLUDE_DIR}/Logger/Severity.hpp
    # Python
    ${SOLA_INCLUDE_DIR}/Python/Interpreter.hpp
    ${SOLA_INCLUDE_DIR}/Python/API.hpp
    ${SOLA_INCLUDE_DIR}/Python/API/Errors.hpp ${SOLA_INCLUDE_DIR}/Python/API/Logger.hpp
    ${SOLA_INCLUDE_DIR}/Python/API/Application.hpp ${SOLA_INCLUDE_DIR}/Python/API/Graphics.hpp
)

set(SOLA_SOURCES
    # General
    ${SOLA_SOURCE_DIR}/sola_common.cpp
    # Application
    ${SOLA_SOURCE_DIR}/Application/Application.cpp ${SOLA_SOURCE_DIR}/Application/Modules.cpp
    # Graphics
    ${SOLA_SOURCE_DIR}/Graphics/WindowsManager.cpp
    # Helpers
    ${SOLA_SOURCE_DIR}/Helpers/FileSystem.cpp ${SOLA_SOURCE_DIR}/Helpers/PythonModule.cpp
    # Logger
    ${SOLA_SOURCE_DIR}/Logger/Logger.cpp ${SOLA_SOURCE_DIR}/Logger/Severity.cpp
    # Python
    ${SOLA_SOURCE_DIR}/Python/Interpreter.cpp
    ${SOLA_SOURCE_DIR}/Python/API.cpp
    ${SOLA_SOURCE_DIR}/Python/API/Errors.cpp ${SOLA_SOURCE_DIR}/Python/API/Logger.cpp
    ${SOLA_SOURCE_DIR}/Python/API/Application.cpp ${SOLA_SOURCE_DIR}/Python/API/Graphics.cpp
)

# -- Includes --

include(GNUInstallDirs)

# -- Project --

project(sola VERSION ${SOLA_VERSION_MAJOR}.${SOLA_VERSION_MINOR}.${SOLA_VERSION_PATCH} DESCRIPTION "Sola C++ dynamic linked (shared) library")

# -- Artifacts --

add_library(${PROJECT_NAME})

# -- Target properties --

set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    FRAMEWORK TRUE
)

# -- Target compile definitions --

set(CMAKE_COMPILE_WARNING_AS_ERROR ON)

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wpedantic -Wall -Wextra -Wconversion
        -Warith-conversion -Wshadow -Wnull-dereference -Wformat=2 -Wfloat-equal -Wsign-conversion -Wfloat-conversion)
endif()

target_compile_options(${PROJECT_NAME} PRIVATE ${MAX_WARNINGS_OPTION})

target_compile_definitions(${PROJECT_NAME} PRIVATE
    SOLA_VERSION_MAJOR=${SOLA_VERSION_MAJOR}
    SOLA_VERSION_MINOR=${SOLA_VERSION_MINOR}
    SOLA_VERSION_PATCH=${SOLA_VERSION_PATCH}
    SOLA_VERSION_STRING="${SOLA_VERSION_STRING}"
    EXPORT
)

if (SOLA_DEBUG_LOG)
    target_compile_definitions(${PROJECT_NAME} PRIVATE SOLA_DEBUG_LOG)
endif()

if(SOLA_PROFILER_INTERNAL_SECTION)
    target_compile_definitions(${PROJECT_NAME} PRIVATE SOLA_PROFILER_INTERNAL_SECTION)
endif()

if(SOLA_PROFILER_EXTERNAL_SECTION)
    target_compile_definitions(${PROJECT_NAME} PRIVATE SOLA_PROFILER_EXTERNAL_SECTION)
endif()

# -- Dependencies / PRE_BUILD --

add_dependencies(${PROJECT_NAME} python)

target_link_libraries(${PROJECT_NAME} PUBLIC python)

add_custom_target(solalib_python_cache COMMAND py -m compileall -j 0 -o 1 "${SOLA_PYTHON}")

add_dependencies(${PROJECT_NAME} solalib_python_cache)

target_link_libraries(${PROJECT_NAME} PUBLIC SDL3::SDL3)

add_dependencies(${PROJECT_NAME} TracyClient)

target_link_libraries(${PROJECT_NAME} PUBLIC TracyClient)

add_dependencies(${PROJECT_NAME} cppcheck)

if(BUILD_DOCS)
    set(DOXYGEN_PROJECT_NAME "Sola")
    set(DOXYGEN_PROJECT_BRIEF "Sola is a software suite designed to help developers easily create multi-platform windowed applications using familiar tools and efficient systems.")
    set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/docs)
    set(DOXYGEN_FILE_PATTERNS "*.hpp" "*.cpp" "*.md")
    doxygen_add_docs(solalib_docs ${CMAKE_CURRENT_SOURCE_DIR} ALL)
    add_dependencies(${PROJECT_NAME} solalib_docs)

    set(DOXYGEN_PROJECT_NAME "Sola Python Library")
    set(DOXYGEN_PROJECT_BRIEF "Sola is a software suite designed to help developers easily create multi-platform windowed applications using familiar tools and efficient systems.")
    set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/docs_python)
    set(DOXYGEN_FILE_PATTERNS "*.py" "*.pyi" "*.md")
    set(DOXYGEN_OPTIMIZE_OUTPUT_JAVA YES)
    doxygen_add_docs(sola_pythonlib_docs ${CMAKE_CURRENT_SOURCE_DIR} ALL)
    add_dependencies(${PROJECT_NAME} sola_pythonlib_docs)
endif()

# This is not really neeeded for the library to build or run,
# but it is much more convinient for building the entire Sola framework

add_dependencies(${PROJECT_NAME} tracy-profiler)
add_dependencies(${PROJECT_NAME} tracy-capture)

# -- Sources / Headers --

target_include_directories(${PROJECT_NAME} PRIVATE ${SOLA_INCLUDE_DIR})

target_sources(${PROJECT_NAME} PRIVATE "${SOLA_SOURCES}")

target_sources(${PROJECT_NAME} INTERFACE FILE_SET public_headers TYPE HEADERS BASE_DIRS ${SOLA_INCLUDE_DIR} FILES "${PUBLIC_HEADERS}")

# -- POST_BUILD --

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${SOLA_PYTHON} $<TARGET_FILE_DIR:${PROJECT_NAME}>/${SOLA_PYTHON_MODULE_NAME}
)

# -- Configuration --

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}.pkgconfig.in ${PROJECT_NAME}.pc @ONLY)

# -- Installing --

install(DIRECTORY $<TARGET_FILE_DIR:${PROJECT_NAME}>/${SOLA_PYTHON_MODULE_NAME} DESTINATION ${CMAKE_INSTALL_BINDIR}/Lib)

install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    FILE_SET public_headers DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.pc
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig
)

if(BUILD_DOCS)
    install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/docs/html/
        DESTINATION ${CMAKE_INSTALL_DOCDIR}/${PROJECT_NAME}
    )
    install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/docs_python/html/
        DESTINATION ${CMAKE_INSTALL_DOCDIR}/${PROJECT_NAME}_python
    )
endif()