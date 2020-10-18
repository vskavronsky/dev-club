#include "Mohican.hpp"

Mohican::Mohican(const std::string& name, int age)
    : m_name(name), m_age(age) {
        m_mohicanList.push_back(this);
}

Mohican::Mohican(const Mohican& copy) {
    m_name = copy.m_name;
    m_age = copy.m_age;

    m_mohicanList.push_back(this);
}

Mohican::~Mohican() {
    m_mohicanList.remove(this);
}

const std::string& Mohican::getName() const {
    return m_name;
}

int Mohican::getAge() const {
    return m_age;
}

void Mohican::setName(const std::string &name) {
    m_name = name;
}

void Mohican::setAge(int age) {
    m_age = age;
}

std::list<Mohican*> Mohican::m_mohicanList;

const Mohican& Mohican::getLast() {
    return *m_mohicanList.back();
}

Mohican& Mohican::operator=(const Mohican &copy) {
    m_name = copy.m_name;
    m_age = copy.m_age;

    return *this;
}

std::ostream& operator<<(std::ostream& out, const Mohican& Mohican) {
    return out << "Name: " << Mohican.getName() << ". Age: " << Mohican.getAge() << ".";
}
