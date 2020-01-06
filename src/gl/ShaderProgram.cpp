#include "ShaderProgram.h"
#include "../error/DSError.h"

#include <glad/glad.h>

void ValidateProgramStatus(unsigned int id, unsigned int status) {
    int result;
    glGetProgramiv(id, status, &result);
    if (result != GL_TRUE) {
#define MAX_LOG 256
        char message[MAX_LOG];
        glGetProgramInfoLog(id, MAX_LOG, nullptr, message);
        throw DSError(std::string(message));
#undef MAX_LOG
    }
}

ShaderProgram::ShaderProgram(Shader& vshader, Shader& fshader) : GLObject() {
    id = glCreateProgram();
    glAttachShader(id, vshader.id);
    glAttachShader(id, fshader.id);

    glLinkProgram(id);
    ValidateProgramStatus(id, GL_LINK_STATUS);
    glValidateProgram(id);
    ValidateProgramStatus(id, GL_VALIDATE_STATUS);
}

ShaderProgram::ShaderProgram(ShaderProgram&& program) noexcept {
    id = program.id;
    program.id = 0;
}

ShaderProgram::~ShaderProgram() {
    glDeleteProgram(id);
}

void ShaderProgram::Bind() {
    glUseProgram(id);
}

void ShaderProgram::Unbind() {
    glUseProgram(0);
}