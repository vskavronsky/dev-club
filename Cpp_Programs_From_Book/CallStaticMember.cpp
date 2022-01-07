#include <iostream>
#include <string>

class Student {
    protected:
        std::string m_name;
        static int m_numOfStudents;
    public:
        Student(const char* name) : m_name(name) {
            m_numOfStudents += 1;
        }

        ~Student() {
            m_numOfStudents -= 1;
        }

        const std::string& getName() {
            return m_name;
        }

        // cannot call elements implicit, need object
        static int getNumOfStudents() {
            return m_numOfStudents;
        }
};

int Student::m_numOfStudents = 0;

int main() {
    Student s1("bob");
    Student s2("chuck");

    std::cout << "Numer of the students: " << s1.getNumOfStudents() << std::endl;
    std::cout << "Numer of the students: " << Student::getNumOfStudents() << std::endl;
    
    return 0;
}
