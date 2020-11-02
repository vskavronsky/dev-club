#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>

class Exceptions : public std::exception {};

class ReadError : public Exceptions {
    public:
        const char* what() const noexcept;

};

#endif // EXCEPTIONS_HPP
