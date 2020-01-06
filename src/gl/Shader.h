#ifndef DOUBLESHIFT_SHADER_H
#define DOUBLESHIFT_SHADER_H

#include "GLObject.h"

#include <string>

class Shader : public GLObject {
    unsigned int type;
public:
    Shader(unsigned int type, std::string& source);

    Shader(Shader&) = delete;
    Shader(Shader&&) noexcept;

    ~Shader();

    void Bind() override {}
    void Unbind() override {}

    friend class ShaderProgram;
};


#endif //DOUBLESHIFT_SHADER_H
