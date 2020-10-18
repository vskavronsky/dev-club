#ifndef MOHICAN_H
#define MOHICAN_H

#include <iostream>
#include <list>

class Mohican {
    private:
        std::string m_name;
        int m_age;

        static std::list<Mohican*> m_mohicanList;

    public:
        Mohican(const std::string& name, int age);
        Mohican(const Mohican& copy);
        virtual ~Mohican();

        const std::string& getName() const;
        int getAge() const;

        void setName(const std::string& name);
        void setAge(int age);

        static const Mohican& getLast();

        Mohican& operator=(const Mohican& copy);

};

std::ostream& operator<<(std::ostream& out, const Mohican& mohican);

#endif // MOHICAN_H
