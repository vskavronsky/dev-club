#ifndef DATE_HPP
#define DATE_HPP

#include "../Exceptions/Exceptions.hpp"

class Date {
    private:
        int m_day;
        int m_month;
        int m_year;

        void validate(int day, int month, int year);
    public:
        Date(int day, int month, int year);
        virtual ~Date();

        int getDay() const;
        int getMonth() const;
        int getYear() const;

};

std::ostream& operator<<(std::ostream& out, const Date& date);

#endif //DATE_HPP
