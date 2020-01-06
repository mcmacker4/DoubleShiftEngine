//
// Created by McMacker4 on 05/01/2020.
//

#ifndef DOUBLESHIFT_GLOBJECT_H
#define DOUBLESHIFT_GLOBJECT_H


class GLObject {
protected:
    unsigned int id = 0;
public:
    virtual void Bind() = 0;
    virtual void Unbind() = 0;
};


#endif //DOUBLESHIFT_GLOBJECT_H
