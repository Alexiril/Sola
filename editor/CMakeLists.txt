# Sola C++ editor application

message("Working on Sola C++ Editor Application")

# Don't mention this, please. This is just to feed my ego.
execute_process(COMMAND ${Python3_EXECUTABLE} ${CMAKE_SOURCE_DIR}/scripts/lines_counter.py ${CMAKE_CURRENT_SOURCE_DIR} ".py" ".pyi" ".hpp" ".cpp"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    ERROR_QUIET
)

# -- Independent definitions --

set(SOLA_PUBLIC_HEADERS ${CMAKE_SOURCE_DIR}/library/include)

set(EDITOR_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(EDITOR_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/source)

set(EDITOR_SOURCES
    # Common
    ${EDITOR_SOURCE_DIR}/main.cpp
)

# -- Includes --

include(GNUInstallDirs)

# -- Project --

project(sola-editor VERSION ${SOLA_VERSION_MAJOR}.${SOLA_VERSION_MINOR}.${SOLA_VERSION_PATCH} DESCRIPTION "Sola C++ editor application")

# -- Artifacts --

add_executable(${PROJECT_NAME})

# -- Target properties --

set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    LINKER_LANGUAGE CXX
)

# -- Target compile definitions --

target_compile_definitions(${PROJECT_NAME} PRIVATE
    SOLA_VERSION_MAJOR=${SOLA_VERSION_MAJOR}
    SOLA_VERSION_MINOR=${SOLA_VERSION_MINOR}
    SOLA_VERSION_PATCH=${SOLA_VERSION_PATCH}
    SOLA_VERSION_STRING="${SOLA_VERSION_STRING}"
)

if (SOLA_DEBUG_LOG)
    target_compile_definitions(${PROJECT_NAME} PRIVATE SOLA_DEBUG_LOG)
endif()

# -- Dependencies / PRE_BUILD --

find_package(Python REQUIRED COMPONENTS Development.Embed)

target_link_libraries(${PROJECT_NAME} PRIVATE Python::Python)

add_dependencies(${PROJECT_NAME} sola)

target_link_libraries(${PROJECT_NAME} PRIVATE sola)

# -- Sources / Headers --

target_include_directories(${PROJECT_NAME} PRIVATE ${EDITOR_INCLUDE_DIR} ${SOLA_PUBLIC_HEADERS})

target_sources(${PROJECT_NAME} PRIVATE "${EDITOR_SOURCES}")

target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)

# -- Installing --

install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
