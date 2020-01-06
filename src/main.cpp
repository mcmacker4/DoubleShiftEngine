#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Window.h"

#include "gl/VAO.h"
#include "gl/VBO.h"

#include "gl/Shader.h"
#include "gl/ShaderProgram.h"

#define WIDTH 1280
#define HEIGHT 720

static const char* vShaderSrcC =
        "#version 330 core\n"
        "in vec3 position;"
        "out vec3 _color;"
        "void main() {"
        "   gl_Position = vec4(position, 1.0);"
        "   _color = position + 0.5;"
        "}";

static const char* fShaderSrcC =
        "#version 330 core\n"
        "in vec3 _color;"
        "out vec4 color;"
        "void main() {"
        "   color = vec4(_color, 1.0);"
        "}";

int main() {

    std::cout << "Hello World!" << std::endl;

    Window::Create(WIDTH, HEIGHT);

    std::vector<float> vertices {
        0.0f, 0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f
    };

    VBO vbo(GL_ARRAY_BUFFER, vertices);

    VAO vao;
    vao.SetAttribute(POSITION, 3, vbo);

    std::string vShaderSrc(vShaderSrcC);
    Shader vShader(GL_VERTEX_SHADER, vShaderSrc);

    std::string fShaderSrc(fShaderSrcC);
    Shader fShader(GL_FRAGMENT_SHADER, fShaderSrc);

    ShaderProgram program(vShader, fShader);

    while (!Window::ShouldClose()) {
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        program.Bind();

        vao.Bind();
        glDrawArrays(GL_TRIANGLES, 0, vertices.size() / 3);
        vao.Unbind();

        program.Unbind();

        Window::SwapBuffers();
    }

    Window::Destroy();

    return 0;
}