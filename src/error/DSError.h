#ifndef DOUBLESHIFT_DSERROR_H
#define DOUBLESHIFT_DSERROR_H

#include <string>
#include <exception>
#include <utility>

class DSError : public std::exception {
    std::string message;
public:
    explicit DSError(std::string message) : exception(), message(std::move(message)) {}

    const char * what() const noexcept override {
        return message.c_str();
    }
};


#endif //DOUBLESHIFT_DSERROR_H
