#include "Date.hpp"

#define CURRENTYEAR 2020
#define MINAGE 16
#define MAXBIRTHYEAR CURRENTYEAR - MINAGE
#define MINBIRTHYEAR 1903
#define LEAPDIV 4
#define LEAPDIV2 400

void Date::validate(int day, int month, int year) {
    bool isLeap = false;

    enum Month {
        JANUARY = 1,
        FEBRUARY,
        MARCH,
        APRIL,
        MAY,
        JUNE,
        JULY,
        AUGUST,
        SEPTEMBER,
        OCTOBER,
        NOVEMBER,
        DECEMBER
    };
    
    if ( year >= MINBIRTHYEAR && year <= MAXBIRTHYEAR ) {
        
        if ( year % LEAPDIV == 0 || year % LEAPDIV2 == 0 ) {
            isLeap = true;        
        }
        if ( month < 1 || month > 12 ) {
            throw InvalidDate("Please, enter correct data! The month should be from 1 till 12.");
        }
        if ( month == FEBRUARY && !isLeap ) {
            if ( day < 1 || day > 28 ) {
                throw InvalidDate("Please, enter correct data! The day should be from 1 till 28.");
            }
        } else if ( month == FEBRUARY && isLeap ) {
            if ( day < 1 || day > 29 ) {
                throw InvalidDate("Please, enter correct data! The day should be from 1 till 29.");
            }
        } else if ( month == APRIL || month == JUNE || month == SEPTEMBER || month == NOVEMBER ) {
            if ( day < 1 || day > 30 ) {
                throw InvalidDate("Please, enter correct data! The day should be from 1 till 30.");
            }
        } else {
            if ( day < 1 || day > 31 ) {
                throw InvalidDate("Please, enter correct data! The day should be from 1 till 31.");
            }
        }
    } else {
        throw InvalidDate("Please, enter correct data! The year should be between 1903 and 2004.");
    }
}

Date::Date(int day, int month, int year) {
    this->validate(day, month, year);
    
    m_day = day;
    m_month = month;
    m_year = year;
}

Date::~Date() {}

int Date::getDay() const {
    return m_day;
}

int Date::getMonth() const {
    return m_month;
}

int Date::getYear() const {
    return m_year;
}

std::ostream& operator<<(std::ostream& out, const Date& date) {
    return out << "Day: " << date.getDay() << ". Month: " << date.getMonth() << ". Year: " << date.getYear() << ".";
}
