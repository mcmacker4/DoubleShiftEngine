//
// Created by McMacker4 on 06/01/2020.
//

#include "Shader.h"
#include "../error/DSError.h"

#include <glad/glad.h>

void ValidateShaderStatus(unsigned int id, unsigned int status) {
    int result;
    glGetShaderiv(id, status, &result);
    if (result != GL_TRUE) {
#define MAX_LOG 256
        char message[MAX_LOG];
        glGetShaderInfoLog(id, MAX_LOG, nullptr, message);
        throw DSError(std::string(message));
#undef MAX_LOG
    }
}

Shader::Shader(unsigned int type, std::string& source) : GLObject(), type(type) {
    id = glCreateShader(type);
    const char* src = source.c_str();
    const int len = source.length();
    glShaderSource(id, 1, &src, &len);

    glCompileShader(id);
    ValidateShaderStatus(id, GL_COMPILE_STATUS);
}

Shader::Shader(Shader&& shader) noexcept {
    id = shader.id;
    type = shader.type;
    shader.id = 0;
}

Shader::~Shader() {
    glDeleteShader(id);
}