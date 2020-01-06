#ifndef DOUBLESHIFT_SHADERPROGRAM_H
#define DOUBLESHIFT_SHADERPROGRAM_H

#include "GLObject.h"
#include "Shader.h"

class ShaderProgram : public GLObject {
public:
    ShaderProgram(Shader& vshader, Shader& fshader);

    ShaderProgram(ShaderProgram&) = delete;
    ShaderProgram(ShaderProgram&&) noexcept;

    ~ShaderProgram();

    void Bind() override;
    void Unbind() override;
};


#endif //DOUBLESHIFT_SHADERPROGRAM_H
