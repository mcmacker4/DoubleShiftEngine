//
// Created by McMacker4 on 03/01/2020.
//

#ifndef DOUBLESHIFT_WINDOW_H
#define DOUBLESHIFT_WINDOW_H

#ifdef USE_GLEW
#include <GL/glew.h>
#else
#include <glad/glad.h>
#endif
#include <GLFW/glfw3.h>

class Window {
    static GLFWwindow* window;
public:
    Window() = delete;

    static void Create(int width, int height);

    static void Destroy();

    static bool ShouldClose();
    static void SwapBuffers();
};


#endif //DOUBLESHIFT_WINDOW_H
