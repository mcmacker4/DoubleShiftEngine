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
        : message(std::move(message)) {}

    const char * what() const noexcept override {
        return message.c_str();
    }
};

#endif //DOUBLESHIFT_SHADER_H
