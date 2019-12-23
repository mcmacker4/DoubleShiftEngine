//
// Created by McMacker4 on 23/12/2019.
//

#include "Shader.h"

static std::string GetInfoLog(unsigned int program) {
    char buffer[512];
    glGetShaderInfoLog(program, 512, nullptr, buffer);
    return std::string(buffer);
}

static void VerifyStatus(unsigned int program, unsigned int type) {
    int status = GL_FALSE;
    glGetShaderiv(program, type, &status);
    if (status != GL_TRUE) {
        throw ShaderError(GetInfoLog(program));
    }
}

// class Shader

Shader::Shader(unsigned int type, const char* source, int length)
        : id(glCreateShader(type)) {
    glShaderSource(this->id, 1, &source, &length);
    glCompileShader(this->id);
    VerifyStatus(this->id, GL_COMPILE_STATUS);
}

Shader::~Shader() {
    glDeleteShader(this->id);
}