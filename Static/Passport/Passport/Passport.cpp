#include "Passport.hpp"

#define MAXNUMBER 999999
#define MINNUMBER 100000
#define SERIESLENGTH 2
#define MAXSERIESLETTER 'Z'
#define MINSERIESLETTER 'A'

Passport::Passport(const std::string& firstName, const std::string& secondName, Date* birthDates)
    : m_firstName(firstName), m_secondName(secondName), m_birthDates(birthDates) {

        counter();
        m_series = m_passportSeries;
        m_number = m_passportNumber;
        m_totalPassports += 1;
        m_passports.insert(this);
}

Passport::~Passport() {
    delete m_birthDates;
    m_birthDates = nullptr;

    m_passports.erase(this);
}

const std::string& Passport::getSeries() const {
    return m_series;
}

int Passport::getNumber() const {
    return m_number;
}

const std::string& Passport::getFirstName() const {
    return m_firstName;
}

const std::string& Passport::getSecondName() const {
    return m_secondName;
}

const Date& Passport::getBirthDates() const {
    return *m_birthDates;
}

void Passport::setFirstName(const std::string& newFirstName) {
    m_firstName = newFirstName;
}

void Passport::setSecondName(const std::string& newSecondName) {
    m_secondName = newSecondName;
}

void Passport::setBirthDates(Date* newBirthDates) {
    delete m_birthDates;
    m_birthDates = newBirthDates;
}

std::string Passport::m_passportSeries = SERIESBEGIN;

int Passport::m_passportNumber = STARTNUMBER;

int Passport::m_totalPassports = 0;

std::set<Passport*> Passport::m_passports;

void Passport::counter() {
    if ( m_passportNumber < MAXNUMBER ) {
        m_passportNumber += 1;
    } else {
        m_passportNumber = MINNUMBER;

        if ( m_passportSeries[1] < MAXSERIESLETTER ) {
            m_passportSeries[1] += 1;
        } else {
            m_passportSeries[1] = MINSERIESLETTER;

            if ( m_passportSeries[0] < MAXSERIESLETTER ) {
                m_passportSeries[0] += 1;
            } else {
                throw ReachedLimit();
            }
        }
    }
}

void Passport::verify(const std::string& passportSeries, int passportNumber) {
    if ( passportSeries.length() > SERIESLENGTH ) {
        throw SeriesLengthExceeded();
    }

    if ( !isupper(passportSeries[0]) ) {
        throw InvalidUpperCase();
    } else {
        if ( !isupper(passportSeries[1]) ) {
            throw InvalidUpperCase();
        }
    }

    if ( passportSeries.compare(m_passportSeries) <= 0 ) {
        throw InvalidNewSeries();
    }

    if ( passportNumber > MAXNUMBER || passportNumber < STARTNUMBER) {
        throw InvalidPassportNumber();
    }
}

const std::string& Passport::getPassportSeries() {
    return m_passportSeries;
}

int Passport::getPassportNumber() {
    return m_passportNumber;
}

int Passport::getTotalPassports() {
    return m_totalPassports;
}

void Passport::setNewSeries(const std::string& newPassportSeries, int newPassportNumber) {
    verify(newPassportSeries, newPassportNumber);

    m_passportSeries = newPassportSeries;
    m_passportNumber = newPassportNumber;
}

void Passport::findPassport(Passport* passport) {
    auto it = m_passports.find(passport);

    if ( it == m_passports.end() ) {
        throw PassportNotFound();
    }
    std::cout << *(*it) << std::endl;
}

void Passport::getAllPassports() {
    for ( Passport* passport : m_passports ) {
        std::cout << *passport << std::endl;
    }
}

std::ostream& operator<<(std::ostream& out, const Passport& passport) {
    out << "Passport: " << passport.getSeries() << passport.getNumber() << std::endl
        << "  First Name: " << passport.getFirstName() << ". Second Name: " << passport.getSecondName()<< "." << std::endl
        << "  " << passport.getBirthDates() << std::endl;

    return out;
}
