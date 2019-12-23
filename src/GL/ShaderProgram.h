//
// Created by McMacker4 on 23/12/2019.
//

#ifndef DOUBLESHIFT_SHADERPROGRAM_H
#define DOUBLESHIFT_SHADERPROGRAM_H

#include <exception>
#include "Shader.h"

class ShaderProgram {
    const unsigned int id;
public:
    ShaderProgram(const Shader &vertex, const Shader& fragment);
    ~ShaderProgram();

    //Allow Move
    ShaderProgram(ShaderProgram&&) = default;

    // Disallow Copy
    ShaderProgram(const ShaderProgram&) = delete;

    static void Start(const ShaderProgram& program);
    static void Stop();
};

class ShaderProgramError : public std::exception {
    std::string message;
public:
    explicit ShaderProgramError(std::string message) : message(std::move(message)) {}
};


#endif //DOUBLESHIFT_SHADERPROGRAM_H
