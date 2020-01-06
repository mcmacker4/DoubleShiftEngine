#ifndef DOUBLESHIFT_VBO_H
#define DOUBLESHIFT_VBO_H

#include "GLObject.h"

#include <vector>

class VBO : public GLObject {
    unsigned int target;
public:
    explicit VBO(unsigned int target, std::vector<float>& data);

    VBO(VBO& buffer) = delete;
    VBO(VBO&& buffer) noexcept;

    ~VBO();

    void Bind() override;
    void Unbind() override;
};


#endif //DOUBLESHIFT_VBO_H
