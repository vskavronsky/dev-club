#include "Exceptions.hpp"

InvalidDate::InvalidDate(const char* msg) : m_msg(msg) {}

InvalidDate::~InvalidDate() {}

const char* InvalidDate::what() const noexcept {
    return m_msg;
}

const char* ReachedLimit::what() const noexcept {
    return "No free variations of the series and numbers!";
}

const char* SeriesLengthExceeded::what() const noexcept {
    return "Series length should be only two uppercase characters!";
}

const char* InvalidUpperCase::what() const noexcept {
    return "Make sure that series has two uppercase characters!";
}

const char* InvalidNewSeries::what() const noexcept {
    return "Please, choose next series!";
}

const char* InvalidPassportNumber::what() const noexcept {
    return "Please, enter correct data! The number should be from 99999 till 999999.";
}

const char* PassportNotFound::what() const noexcept {
    return "Passport was not found!";
}
