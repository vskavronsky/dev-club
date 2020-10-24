#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <iostream>
#include <exception>

class Exceptions : public std::exception {};

class InvalidDate : public Exceptions {
    private:
        const char* m_msg;

    public:
        InvalidDate(const char* msg);
        virtual ~InvalidDate();

        const char* what() const noexcept;

};

class ReachedLimit : public Exceptions {
    public:
        const char* what() const noexcept;

};

class SeriesLengthExceeded : public Exceptions {
    public:
        const char* what() const noexcept;

};

class InvalidUpperCase : public Exceptions {
    public:
        const char* what() const noexcept;

};

class InvalidNewSeries : public Exceptions {
    public:
        const char* what() const noexcept;

};

class InvalidPassportNumber : public Exceptions {
    public:
        const char* what() const noexcept;

};

class PassportNotFound : public Exceptions {
    public:
        const char* what() const noexcept;

};

#endif // EXCEPTIONS_HPP
