//
// Created by McMacker4 on 05/01/2020.
//

#include "VBO.h"

#include <glad/glad.h>

VBO::VBO(unsigned int target, std::vector<float>& data) : GLObject(), target(target) {
    glGenBuffers(1, &id);
    glBindBuffer(target, id);
    glBufferData(target, data.size() * sizeof(float), data.data(), GL_STATIC_DRAW);
    glBindBuffer(target, 0);
}

VBO::VBO(VBO&& buffer) noexcept {
    id = buffer.id;
    target = buffer.target;
    buffer.id = 0;
}

VBO::~VBO() {
    glDeleteBuffers(1, &id);
}

void VBO::Bind() {
    glBindBuffer(target, id);
}

void VBO::Unbind() {
    glBindBuffer(target, 0);
}