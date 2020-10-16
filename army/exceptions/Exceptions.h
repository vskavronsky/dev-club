#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>
#include <exception>

class OutOfHitPointsException : std::exception {
    private:
        std::string unitName;
        const char* msg;

    public:
        OutOfHitPointsException(const std::string& unitName, const char* msg);
        virtual ~OutOfHitPointsException();

        const std::string& getUnitName() const;
        const char* what() const noexcept;

};

class InvalidAddHitPointsException : std::exception {
    private:
        const char* msg;

    public:
        InvalidAddHitPointsException(const char* msg);
        virtual ~InvalidAddHitPointsException();

        const char* what() const noexcept;

};

class OutOfManaException : std::exception {
    private:
        const char* msg;

    public:
        OutOfManaException(const char* msg);
        virtual ~OutOfManaException();

        const char* what() const noexcept;

};

class CanNotTurnException : std::exception {
    private:
        const char* msg;

    public:
        CanNotTurnException(const char* msg);
        virtual ~CanNotTurnException();

        const char* what() const noexcept;

};

class CanNotTransformException : std::exception {
    private:
        const char* msg;

    public:
        CanNotTransformException(const char* msg);
        virtual ~CanNotTransformException();

        const char* what() const noexcept;

};

class CanNotAttackOwnerException : std::exception {
    private:
        const char* msg;

    public:
        CanNotAttackOwnerException(const char* msg);
        virtual ~CanNotAttackOwnerException();

        const char* what() const noexcept;

};

#endif // EXCEPTIONS_H
