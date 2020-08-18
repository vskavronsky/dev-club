#include "Date.h"

#define STARTOFGREGCAL 1582
#define LEAPDIV 4
#define LEAPDIV2 400

using namespace std;

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
    
    if ( year >= STARTOFGREGCAL ) {
        
        if ( year % LEAPDIV == 0 || year % LEAPDIV2 == 0 ) {
            isLeap = true;        
        }
        if ( month < 1 || month > 12 ) {
            throw InvalidDate("Please, enter correct date! The month should be from 1 till 12.");
        }
        if ( month == FEBRUARY && !isLeap ) {
            if ( day < 1 || day > 28 ) {
                throw InvalidDate("Please, enter correct date! The day should be from 1 till 28.");
            }
        } else if ( month == FEBRUARY && isLeap ) {
            if ( day < 1 || day > 29 ) {
                throw InvalidDate("Please, enter correct date! The day should be from 1 till 29.");
            }
        } else if ( month == APRIL || month == JUNE || month == SEPTEMBER || month == NOVEMBER ) {
            if ( day < 1 || day > 30 ) {
                throw InvalidDate("Please, enter correct date! The day should be from 1 till 30.");
            }
        } else {
            if ( day < 1 || day > 31 ) {
                throw InvalidDate("Please, enter correct date! The day should be from 1 till 31.");
            }
        }
    } else {
        throw InvalidDate("Please, enter correct date! The year should be bigger or equal to 1582.");
    }
}

Date::Date(int day, int month, int year) {
    this->validate(day, month, year);
    
    this->day = day;
    this->month = month;
    this->year = year;
}

Date::~Date() {
    
}

int Date::getDay() const {
    return this->day;
}

int Date::getMonth() const {
    return this->month;
}

int Date::getYear() const {
    return this->year;
}

ostream& operator<<(ostream& out, const Date& date) {
    return out << "Entered date (" << date.getDay() << ", " << date.getMonth() << ", " << date.getYear() << ") is correct.";
}
