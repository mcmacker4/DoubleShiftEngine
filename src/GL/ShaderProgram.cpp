//
// Created by McMacker4 on 23/12/2019.
//

#include "ShaderProgram.h"

static std::string GetInfoLog(unsigned int program) {
    char buffer[512];
    glGetProgramInfoLog(program, 512, nullptr, buffer);
    return std::string(buffer);
}

static void VerifyStatus(unsigned int program, unsigned int type) {
    int status = GL_FALSE;
    glGetProgramiv(program, type, &status);
    if (status != GL_TRUE) {
        throw ShaderProgramError(GetInfoLog(program));
    }
}

// class ShaderProgram

ShaderProgram::ShaderProgram(const Shader& vertex, const Shader& fragment)
        : id(glCreateProgram()) {
    glAttachShader(this->id, vertex.id);
    glAttachShader(this->id, fragment.id);
    glLinkProgram(this->id);
    VerifyStatus(this->id, GL_LINK_STATUS);
    glValidateProgram(this->id);
    VerifyStatus(this->id, GL_VALIDATE_STATUS);
}

ShaderProgram::~ShaderProgram() {
    glDeleteProgram(this->id);
}

void ShaderProgram::Start(const ShaderProgram &program) {
    glUseProgram(program.id);
}

void ShaderProgram::Stop() {
    glUseProgram(0);
}