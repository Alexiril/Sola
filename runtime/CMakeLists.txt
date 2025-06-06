# Sola C++ runtime application

message("Working on Sola C++ Runtime Application")

# Don't mention this, please. This is just to feed my ego.
execute_process(COMMAND ${Python3_EXECUTABLE} ${CMAKE_SOURCE_DIR}/scripts/lines_counter.py ${CMAKE_CURRENT_SOURCE_DIR} ".py" ".pyi" ".hpp" ".cpp"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    ERROR_QUIET
)

# -- Independent definitions --

set(SOLA_EDITOR_PYTHON  ${CMAKE_CURRENT_SOURCE_DIR}/editor/SolaEditor)
set(SOLA_EDITOR_PYTHON_MODULE_NAME SolaEditor)

set(SOLA_PUBLIC_HEADERS ${CMAKE_SOURCE_DIR}/library/include)

set(EDITOR_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/editor/include)
set(EDITOR_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/editor/source)

set(RUNTIME_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(RUNTIME_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/source)

set(RUNTIME_SOURCES
    # Common
    ${RUNTIME_SOURCE_DIR}/Main.cpp
    # Editor
    ## EditorInitializer
    ${EDITOR_SOURCE_DIR}/EditorInitializer/EditorInitializer.cpp
    ## EditorFinalizer
    ${EDITOR_SOURCE_DIR}/EditorFinalizer/EditorFinalizer.cpp
)

# -- Includes --

include(GNUInstallDirs)

# -- Project --

set(APPLICATION_NAME sola-runtime)

if(MAKE_EDITOR_APPLICATION)
    set(APPLICATION_NAME ${APPLICATION_NAME}-editor)
endif()

project(${APPLICATION_NAME} VERSION ${SOLA_VERSION_MAJOR}.${SOLA_VERSION_MINOR}.${SOLA_VERSION_PATCH} DESCRIPTION "Sola C++ Runtime application")

# -- Artifacts --

add_executable(${PROJECT_NAME})

# -- Target properties --

set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    LINKER_LANGUAGE CXX
)

# -- Target compile definitions --

set(CMAKE_COMPILE_WARNING_AS_ERROR ON)

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wpedantic -Wall -Wextra -Wconversion
        -Warith-conversion -Wshadow -Wnull-dereference -Wformat=2 -Wfloat-equal -Wsign-conversion -Wfloat-conversion)
endif()

target_compile_definitions(${PROJECT_NAME} PRIVATE
    SOLA_VERSION_MAJOR=${SOLA_VERSION_MAJOR}
    SOLA_VERSION_MINOR=${SOLA_VERSION_MINOR}
    SOLA_VERSION_PATCH=${SOLA_VERSION_PATCH}
    SOLA_VERSION_STRING="${SOLA_VERSION_STRING}"
    SOLA_APP_IDENTIFIER="${SOLA_APP_IDENTIFIER}"
    SOLA_APP_CREATOR="${SOLA_APP_CREATOR}"
    SOLA_APP_COPYRIGHT="${SOLA_APP_COPYRIGHT}"
    SOLA_APP_URL="${SOLA_APP_URL}"
)

if(MAKE_EDITOR_APPLICATION)
    target_compile_definitions(${PROJECT_NAME} PRIVATE EDITOR_APPLICATION)
endif()

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

set(CMAKE_CXX_CLANG_TIDY clang-tidy --config-file=${CMAKE_SOURCE_DIR}/.clang-tidy)

add_dependencies(${PROJECT_NAME} sola)

target_link_libraries(${PROJECT_NAME} PRIVATE sola)

if(MAKE_EDITOR_APPLICATION)
    add_custom_target(sola-editor-python-cache COMMAND py -m compileall -j 0 -o 1 "${SOLA_EDITOR_PYTHON}")
    add_dependencies(${PROJECT_NAME} sola-editor-python-cache)
endif()

add_dependencies(${PROJECT_NAME} sola-lib-docs)
add_dependencies(${PROJECT_NAME} sola-pythonlib-docs)

# -- Sources / Headers --

target_include_directories(${PROJECT_NAME} PRIVATE ${RUNTIME_INCLUDE_DIR} ${EDITOR_INCLUDE_DIR} ${SOLA_PUBLIC_HEADERS})

target_sources(${PROJECT_NAME} PRIVATE "${RUNTIME_SOURCES}")

# -- POST_BUILD --

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${SOLA_EDITOR_PYTHON} $<TARGET_FILE_DIR:${PROJECT_NAME}>/${SOLA_EDITOR_PYTHON_MODULE_NAME}
)

# -- Installing --

install(DIRECTORY $<TARGET_FILE_DIR:${PROJECT_NAME}>/${SOLA_EDITOR_PYTHON_MODULE_NAME} DESTINATION ${CMAKE_INSTALL_BINDIR}/Lib)

install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

