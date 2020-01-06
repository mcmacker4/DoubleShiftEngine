//
// Created by McMacker4 on 03/01/2020.
//

#ifndef DOUBLESHIFT_WINDOW_H
#define DOUBLESHIFT_WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window {
    static GLFWwindow* window;
public:
    Window() = delete;

    static void Create(int width, int height);

    static void Destroy();

    static bool ShouldClose();
    static void SwapBuffers();

    static void OnError(int, const char*);
    static void OnResize(GLFWwindow*, int, int);
};


#endif //DOUBLESHIFT_WINDOW_H
