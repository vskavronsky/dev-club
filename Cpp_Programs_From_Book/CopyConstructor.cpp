#include <iostream>
#include <string>

class Student {
    protected:
        std::string m_name;
        int m_id;

    public:
        Student(const std::string& name = "NoName", int id = 0)
            : m_name(name), m_id(id)
        {
            std::cout << "Construct " << m_name << std::endl;
        }

        // copy constructor
        Student(const Student& student)
            : m_name("Copy " + student.m_name), m_id(student.m_id)
        {
            std::cout << "Construct " << m_name << std::endl;
        }

        ~Student() {
            std::cout << "Destruct " << m_name << std::endl;
        }
};

class Tutor {
    protected:
        // to create copy of the Tutor,
        // C++ will automatically call copy constructor for each element 
        Student m_student;
        int m_id;

    public:
        Tutor(Student& student)
            // C++ will create copy of the student
            : m_student(student), m_id(0)
        {
            std::cout << "Construct object Tutor" << std::endl;
        }

        ~Tutor() {
            std::cout << "Destruct object Tutor" << std::endl;
        }
};

void foo(Tutor copy) {
    std::cout << "In foo()" << std::endl;
}

int main() {
    Student* chester = new Student("Chester", 1234);
    Tutor* adam = new Tutor(*chester);

    std::cout << "Call foo()" << std::endl;
    foo(*adam);
    std::cout << "In main()" << std::endl;
    
    delete chester;
    delete adam;

    return 0;
}
