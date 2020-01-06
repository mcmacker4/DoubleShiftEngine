cmake_minimum_required(VERSION 3.15)
project(DoubleShift)

# option(USE_GLEW "Use GLEW instead of GLAD for OpenGL Bindings." OFF)

if(USE_GLEW)
    add_definitions(-DUSE_GLEW)
endif()

set(CMAKE_CXX_STANDARD 14)

add_executable(DoubleShift src/main.cpp src/Window.cpp src/Window.h src/error/DSError.h src/gl/VAO.cpp src/gl/VAO.h src/gl/GLObject.h src/gl/VBO.cpp src/gl/VBO.h src/gl/Shader.cpp src/gl/Shader.h src/gl/ShaderProgram.cpp src/gl/ShaderProgram.h)

# OPENGL
find_package(OpenGL REQUIRED)
if(OPENGL_FOUND)
    list(APPEND INCLUDE_DIRS ${OPENGL_INCLUDE_DIR})
    target_link_libraries(DoubleShift ${OPENGL_gl_LIBRARY})
else()
    message(FATAL_ERROR "OpenGL Not Found!")
endif()

# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(lib/glfw)
target_link_libraries(DoubleShift glfw)
list(APPEND INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/lib/glfw/include")

#if (USE_GLEW)
#    # GLEW
#    add_subdirectory(lib/glew/build/cmake)
#    target_link_libraries(DoubleShift glew_s)
#    list(APPEND INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/lib/glew/include")
#else()

# GLAD
add_subdirectory(lib/glad)
target_link_libraries(DoubleShift glad)

#endif()

# GLM
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(GLM_TEST_ENABLE OFF CACHE BOOL "" FORCE)

add_subdirectory(lib/glm)
target_link_libraries(DoubleShift glm_static)
list(APPEND INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/lib/glm")

# Include Directories
target_include_directories(DoubleShift PUBLIC "${PROJECT_BINARY_DIR}" ${INCLUDE_DIRS})