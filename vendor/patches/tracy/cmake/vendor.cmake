# Vendor Specific CMake
# The Tracy project keeps most vendor source locally

set (ROOT_DIR "${CMAKE_CURRENT_LIST_DIR}/../")

# capstone

add_library(TracyCapstone INTERFACE)
target_include_directories(TracyCapstone INTERFACE ${CMAKE_SOURCE_DIR}/vendor/capstone/include/capstone)
target_link_libraries(TracyCapstone INTERFACE capstone_static)

# GLFW

if(NOT USE_WAYLAND AND NOT EMSCRIPTEN)
    add_library(TracyGlfw3 INTERFACE)
    target_include_directories(TracyGlfw3 INTERFACE ${CMAKE_SOURCE_DIR}/vendor/glfw/include/GLFW)
    target_link_libraries(TracyGlfw3 INTERFACE glfw)
endif()

# freetype

add_library(TracyFreetype INTERFACE)
target_include_directories(TracyFreetype INTERFACE ${CMAKE_SOURCE_DIR}/vendor/freetype/include/freetype)
target_link_libraries(TracyFreetype INTERFACE freetype)

# Diff Template Library

set(DTL_DIR "${ROOT_DIR}/dtl")
file(GLOB_RECURSE DTL_HEADERS CONFIGURE_DEPENDS RELATIVE ${DTL_DIR} "*.hpp")
add_library(TracyDtl INTERFACE)
target_sources(TracyDtl INTERFACE ${DTL_HEADERS})
target_include_directories(TracyDtl INTERFACE ${DTL_DIR})


# Get Opt

set(GETOPT_DIR "${ROOT_DIR}/getopt")
set(GETOPT_SOURCES ${GETOPT_DIR}/getopt.c)
set(GETOPT_HEADERS ${GETOPT_DIR}/getopt.h)
add_library(TracyGetOpt STATIC EXCLUDE_FROM_ALL ${GETOPT_SOURCES} ${GETOPT_HEADERS})
target_include_directories(TracyGetOpt PUBLIC ${GETOPT_DIR})


# ImGui

# From CPM.cmake patch script
find_program(PATCH_EXECUTABLE patch)
if(WIN32 AND NOT PATCH_EXECUTABLE)
    find_package(Git QUIET)
    if(GIT_EXECUTABLE)
        get_filename_component(extra_search_path ${GIT_EXECUTABLE} DIRECTORY)
        get_filename_component(extra_search_path_1up ${extra_search_path} DIRECTORY)
        get_filename_component(extra_search_path_2up ${extra_search_path_1up} DIRECTORY)
        find_program(
        PATCH_EXECUTABLE patch HINTS "${extra_search_path_1up}/usr/bin"
                                        "${extra_search_path_2up}/usr/bin"
        )
    endif()
endif()
if(NOT PATCH_EXECUTABLE)
    message(FATAL_ERROR "Couldn't find `patch` executable to use with PATCHES keyword.")
endif()

execute_process(COMMAND ${PATCH_EXECUTABLE} "${CMAKE_SOURCE_DIR}/vendor/imgui/imconfig.h" "${CMAKE_CURRENT_LIST_DIR}/imgui-emscripten.patch")
execute_process(COMMAND ${PATCH_EXECUTABLE} "${CMAKE_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_opengl3_loader.h" "${CMAKE_CURRENT_LIST_DIR}/imgui-loader.patch")

set(ImGui_SOURCE_DIR "${CMAKE_SOURCE_DIR}/vendor/imgui/")

set(IMGUI_SOURCES
    imgui_widgets.cpp
    imgui_draw.cpp
    imgui_demo.cpp
    imgui.cpp
    imgui_tables.cpp
    misc/freetype/imgui_freetype.cpp
    backends/imgui_impl_opengl3.cpp
)

list(TRANSFORM IMGUI_SOURCES PREPEND "${ImGui_SOURCE_DIR}")

add_library(TracyImGui STATIC EXCLUDE_FROM_ALL ${IMGUI_SOURCES})
target_include_directories(TracyImGui PUBLIC ${ImGui_SOURCE_DIR})
target_link_libraries(TracyImGui PUBLIC TracyFreetype)
target_compile_definitions(TracyImGui PRIVATE "IMGUI_ENABLE_FREETYPE")

if(NOT CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(TracyImGui PRIVATE "IMGUI_DISABLE_DEBUG_TOOLS")
endif()