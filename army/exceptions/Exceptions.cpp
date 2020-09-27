#include "Exceptions.h"

OutOfHitPointsException::OutOfHitPointsException(const std::string& unitName, const char* msg) : std::exception() {
    this->unitName = unitName;
    this->msg = msg;
}

OutOfHitPointsException::~OutOfHitPointsException() {}

const std::string& OutOfHitPointsException::getUnitName() const {
    return this->unitName;
}

const char* OutOfHitPointsException::what() const noexcept {
    return this->msg;
}


InvalidAddHitPointsException::InvalidAddHitPointsException(const char* msg) : std::exception() {
    this->msg = msg;
}

InvalidAddHitPointsException::~InvalidAddHitPointsException() {}

const char* InvalidAddHitPointsException::what() const noexcept {
    return this->msg;
}


OutOfManaException::OutOfManaException(const char* msg) : std::exception() {
    this->msg = msg;
}

OutOfManaException::~OutOfManaException() {}

const char* OutOfManaException::what() const noexcept {
    return this->msg;
}


CanNotTurnException::CanNotTurnException(const char* msg) : std::exception() {
    this->msg = msg;
}

CanNotTurnException::~CanNotTurnException() {}

const char* CanNotTurnException::what() const noexcept {
    return this->msg;
}


CanNotTransformException::CanNotTransformException(const char* msg) : std::exception() {
    this->msg = msg;
}

CanNotTransformException::~CanNotTransformException() {}

const char* CanNotTransformException::what() const noexcept {
    return this->msg;
}


CanNotAttackOwnerException::CanNotAttackOwnerException(const char* msg) : std::exception() {
    this->msg = msg;
}

CanNotAttackOwnerException::~CanNotAttackOwnerException() {}

const char* CanNotAttackOwnerException::what() const noexcept {
    return this->msg;
}
