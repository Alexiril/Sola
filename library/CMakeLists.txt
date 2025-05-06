# Sola C++ dynamic linked (shared) library & Sola Python module

message("Working on Sola C++ / Python Library")

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
    ${SOLA_INCLUDE_DIR}/Exception/BasicException.hpp ${SOLA_INCLUDE_DIR}/Exception/ApplicationException.hpp
    ${SOLA_INCLUDE_DIR}/Exception/SDLException.hpp
    # Graphics
    ${SOLA_INCLUDE_DIR}/Graphics/WindowsManager.hpp 
    # Helpers
    ${SOLA_INCLUDE_DIR}/Helpers/FileSystem.hpp
    # Logger
    ${SOLA_INCLUDE_DIR}/Logger/Logger.hpp ${SOLA_INCLUDE_DIR}/Logger/Severity.hpp
    # Python
    ${SOLA_INCLUDE_DIR}/Python/Interpreter.hpp ${SOLA_INCLUDE_DIR}/Python/ModuleHelper.hpp
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
    ${SOLA_SOURCE_DIR}/Helpers/FileSystem.cpp
    # Logger
    ${SOLA_SOURCE_DIR}/Logger/Logger.cpp ${SOLA_SOURCE_DIR}/Logger/Severity.cpp
    # Python
    ${SOLA_SOURCE_DIR}/Python/Interpreter.cpp ${SOLA_SOURCE_DIR}/Python/ModuleHelper.cpp
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

if(MSVC)
    set(MAX_WARNINGS_OPTION /W4)
else()
    set(MAX_WARNINGS_OPTION -Wpedantic -Wall -Wextra)
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

# -- Dependencies / PRE_BUILD --

# find_package(Python REQUIRED COMPONENTS Development.Embed)

# target_link_libraries(${PROJECT_NAME} PRIVATE Python::Python)

add_dependencies(${PROJECT_NAME} python)

target_link_libraries(${PROJECT_NAME} PRIVATE python)

add_custom_target(solalib_python_cache COMMAND py -m compileall -j 0 -o 1 "${SOLA_PYTHON}")

add_dependencies(${PROJECT_NAME} solalib_python_cache)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)

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
