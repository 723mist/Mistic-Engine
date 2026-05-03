cmake_minimum_required(VERSION 4.3)

project(MisticEngine
        VERSION 0.0.1
        DESCRIPTION "OpenGL MisticEngine"
        LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCES
        main.cpp
        src/engine.h
        src/window/window.cpp
        src/window/window.h
        src/render/render.cpp
        src/render/render.h
        src/render/mesh.cpp
        src/render/mesh.h
)

include(FetchContent)

FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.4
)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(glfw)

FetchContent_Declare(
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_TAG 1.0.3
)
FetchContent_MakeAvailable(glm)

FetchContent_Declare(
        glad
        GIT_REPOSITORY https://github.com/Dav1dde/glad.git
        GIT_TAG v2.0.8
        SOURCE_SUBDIR cmake
)
FetchContent_MakeAvailable(glad)

glad_add_library(glad STATIC API gl:core=4.6)

add_executable(MisticEngine ${PROJECT_SOURCES})

target_include_directories(MisticEngine PRIVATE
        src/
        ${GLAD_INCLUDE_DIRS}
)

target_link_libraries(MisticEngine PRIVATE
        glfw
        glm::glm
        glad
)

if(WIN32)
    target_link_libraries(MisticEngine PRIVATE opengl32)
    if(MSVC)
        set_property(TARGET MisticEngine PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    endif()
endif()