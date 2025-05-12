# This file is needed, because the original CMakeLists file in capture directory
# has a real issue: it's not possible to build tracy-profiler and tracy-capture
# executables together in one CMake process. That's because they both try to create
# the same CMake targets, and CMake obviously doesn't like this.
#
# So, this file is a simplified original file, that highly depends on tracy-profiler
# CMakeLists file to configure basic stuff and create all needed targets which this
# project is linked to.

include(${CMAKE_CURRENT_LIST_DIR}/../cmake/version.cmake)

project(
    tracy-capture
    LANGUAGES C CXX
    VERSION ${TRACY_VERSION_STRING}
)

include(${CMAKE_CURRENT_LIST_DIR}/../cmake/config.cmake)

set(PROGRAM_FILES
    src/capture.cpp
)

add_executable(${PROJECT_NAME} ${PROGRAM_FILES} ${COMMON_FILES} ${SERVER_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE TracyServer TracyGetOpt)
set_property(DIRECTORY ${CMAKE_CURRENT_LIST_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_BINDIR})