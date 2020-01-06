//
// Created by McMacker4 on 03/01/2020.
//

#include <iostream>

#include "Window.h"
#include "error/DSError.h"


GLFWwindow* Window::window = nullptr;

void Window::Create(int w, int h) {

    if (window != nullptr)
        throw DSError(std::string("Window::Create() called more than once."));

    glfwSetErrorCallback(Window::OnError);

    //Iintialize GLFW
    if (glfwInit() != GLFW_TRUE)
        throw DSError(std::string("Could not initialize GLFW."));

    //Window hints
    glfwDefaultWindowHints();
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(w, h, "DoubleShift Engine", nullptr, nullptr);
    if (window == nullptr)
        throw DSError(std::string("Could not create GLFW Window."));

    const GLFWvidmode* vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    glfwSetWindowPos(window, (vidmode->width - w) / 2, (vidmode->height - h) / 2);

    glfwSetWindowSizeCallback(window, Window::OnResize);

    glfwMakeContextCurrent(window);

#ifdef USE_GLEW
    if (glewInit() != GLEW_OK)
        throw DSError(std::string("Could not initialize GLEW."));
#else
    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
        throw DSError(std::string("Could not initialize GLAD."));
#endif

    glViewport(0, 0, w, h);

    glClearColor(0.3f, 0.6f, 0.9f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glfwShowWindow(window);
}

bool Window::ShouldClose() {
    return glfwWindowShouldClose(window) == GLFW_TRUE;
}

void Window::SwapBuffers() {
    glfwSwapBuffers(window);
}

void Window::Destroy() {
    glfwDestroyWindow(window);
}

void Window::OnError(int code, const char* message) {
    std::cerr << "[GLFW Error] " << message << " (" << code << ")" << std::endl;
}

void Window::OnResize(GLFWwindow*, int width, int height) {
    glViewport(0, 0, width, height);
}