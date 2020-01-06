//
// Created by McMacker4 on 05/01/2020.
//

#ifndef DOUBLESHIFT_VAO_H
#define DOUBLESHIFT_VAO_H

#include <vector>

#include "GLObject.h"
#include "VBO.h"

enum MeshAttribute {
    POSITION,
    NORMAL,
    UVCOORDS
};

class VAO : public GLObject {
public:
    VAO();

    VAO(VAO&) = delete;
    VAO(VAO&&) noexcept;

    void Bind() override;
    void Unbind() override;

    void SetAttribute(unsigned int index, unsigned int size, VBO& buffer);
};


#endif //DOUBLESHIFT_VAO_H
