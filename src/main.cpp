#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define WIDTH 1280
#define HEIGHT 720

inline void fatal(const char* message) {
    std::cerr << message << std::endl;
    exit(1);
}

void error_callback(int code, const char* message) {
    std::cerr << message << std::endl;
}

int main() {

    std::cout << "Hello World!" << std::endl;

    if (glfwInit() != GLFW_TRUE)
        fatal("Could not initialize GLFW.");

    glfwSetErrorCallback(error_callback);

    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Hello Native World!", nullptr, nullptr);
    if (window == nullptr)
        fatal("Could not create GLFW Window.");

    const GLFWvidmode* vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    glfwSetWindowPos(window, (vidmode->width - WIDTH) / 2, (vidmode->height - HEIGHT) / 2);

    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
        fatal("Could not initialize GLAD.");

    glClearColor(0.3f, 0.6f, 0.9f, 1.0f);

    glfwShowWindow(window);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);

    return 0;
}