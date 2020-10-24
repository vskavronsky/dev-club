#ifndef PASSPORT_HPP
#define PASSPORT_HPP

#define STARTNUMBER 99999
#define SERIESBEGIN "AA"

#include "Date.hpp"
#include <set>
#include <cctype>

class Passport {
    private:
        std::string m_series;
        int m_number;
        std::string m_firstName;
        std::string m_secondName;
        Date* m_birthDates;

        static std::string m_passportSeries;
        static int m_passportNumber;
        static int m_totalPassports;
        static std::set<Passport*> m_passports;

        static void counter();
        static void verify(const std::string& passportSeries, int passportNumber);

    public:
        Passport(const std::string& firstName, const std::string& secondName, Date* birthDates);
        virtual ~Passport();

        const std::string& getSeries() const;
        int getNumber() const;
        const std::string& getFirstName() const;
        const std::string& getSecondName() const;
        const Date& getBirthDates() const;

        void setFirstName(const std::string& newFirstName);
        void setSecondName(const std::string& newSecondName);
        void setBirthDates(Date* newBirthDates);

        static const std::string& getPassportSeries();
        static int getPassportNumber();
        static int getTotalPassports();

        static void setNewSeries(const std::string& passportSeries, int passportNumber = STARTNUMBER);
        static void findPassport(Passport* passport);
        static void getAllPassports();

};

std::ostream& operator<<(std::ostream& out, const Passport& passport);

#endif // PASSPORT_HPP
