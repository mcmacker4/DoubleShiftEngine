#include <iostream>

#ifdef USE_GLEW
    #include <GL/glew.h>
#else
    #include <glad/glad.h>
#endif

#include <GLFW/glfw3.h>
#include <glm/vec2.hpp>

#include "Window.h"

#define WIDTH 1280
#define HEIGHT 720

int main() {

    std::cout << "Hello World!" << std::endl;

    glm::ivec2 res(WIDTH, HEIGHT);

    Window::Create(res.x, res.y);

    while (!Window::ShouldClose()) {
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        Window::SwapBuffers();
    }

    Window::Destroy();

    return 0;
}