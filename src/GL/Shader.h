//
// Created by McMacker4 on 23/12/2019.
//

#ifndef DOUBLESHIFT_SHADER_H
#define DOUBLESHIFT_SHADER_H

#include <string>
#include <exception>
#include <glad/glad.h>


class Shader {
    const unsigned int id;
public:
    Shader(unsigned int type, const char* source, int length);
    ~Shader();

    // Allow Move
    Shader(Shader&&) = default;
    // Disallow Copy
    Shader(const Shader&) = delete;

    friend class ShaderProgram;
};


class ShaderError : public std::exception {
    std::string message;
public:
    explicit ShaderError(std::string message)
        : std::exception(message.c_str()),
        message(std::move(message)) {}
};

#endif //DOUBLESHIFT_SHADER_H
