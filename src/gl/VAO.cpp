#include "VAO.h"

#include <glad/glad.h>

VAO::VAO() : GLObject() {
    glGenVertexArrays(1, &id);
}

VAO::VAO(VAO&& mesh) noexcept {
    id = mesh.id;
    mesh.id = 0;
}

void VAO::Bind() {
    glBindVertexArray(id);
}

void VAO::Unbind() {
    glBindVertexArray(0);
}

void VAO::SetAttribute(unsigned int index, unsigned int size, VBO& buffer) {
    Bind();
    buffer.Bind();
    glVertexAttribPointer(index, size, GL_FLOAT, false, 0, nullptr);
    glEnableVertexAttribArray(index);
    Unbind();
}