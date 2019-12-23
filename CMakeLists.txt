cmake_minimum_required(VERSION 3.15)
project(GLBootstrap)

set(CMAKE_CXX_STANDARD 14)

add_executable(GLBootstrap src/main.cpp)

# OPENGL
find_package(OpenGL REQUIRED)
if(OPENGL_FOUND)
    list(APPEND INCLUDE_DIRS ${OPENGL_INCLUDE_DIR})
    target_link_libraries(GLBootstrap ${OPENGL_gl_LIBRARY})
else()
    message(FATAL_ERROR "OpenGL Not Found!")
endif()

# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(lib/glfw)
target_link_libraries(GLBootstrap glfw)
list(APPEND INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/lib/glfw/include")

# GLAD
add_subdirectory(lib/glad)
target_link_libraries(GLBootstrap GLAD)

target_include_directories(GLBootstrap PUBLIC "${PROJECT_BINARY_DIR}" ${INCLUDE_DIRS})