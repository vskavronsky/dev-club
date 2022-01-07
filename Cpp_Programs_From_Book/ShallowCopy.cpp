#include <iostream>
#include <string>

// shallow copy - copy only elements of the class
// ex: two pointers points to one memory
// 
// deep copy - copy elements and hold them resources
// ex: each pointer has own memory

class Person {
    protected:
        // elements
        std::string* m_name;

    public:
        Person(const char* name) {
            std::cout << "Construct " << name << std::endl;
            m_name = new std::string(name);
        }

        Person(const Person& person) {
            std::cout << "Copy " << *person.m_name << std::endl;
            // deep copy
            m_name = new std::string(*person.m_name);
        }

        // delete copy constructor
        // Person(const Person& person) = delete;

        ~Person() {
            std::cout << "Destruct " << m_name << " (" << *m_name << ")" << std::endl;
            *m_name = "Freed memory";
            // delete m_name;
        }
};

void foo() {
    Person nick("NICK");
    Person nickCopy(nick);
}

int main() {
    std::cout << "Call foo()" << std::endl;
    foo();
    std::cout << "In main()" << std::endl;

    return 0;
}
