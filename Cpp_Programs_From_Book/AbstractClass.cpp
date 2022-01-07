#include <iostream>
#include <string>
#include <memory>

// abstract class
class Animal {
    protected:
        std::string m_name;
        int m_age;

    public:
        Animal(const std::string& name, int age)
            : m_name(name), m_age(age) {}

        virtual ~Animal() {}

        const std::string& getName() const {
            return m_name;
        }

        int getAge() const {
            return m_age;
        }

        void setName(const std::string& name) {
            m_name = name;
        }

        void setAge(const int age) {
            m_age = age;
        }

        // pure virtual method
        virtual void talk() = 0;
};

class Cat : public Animal {
    public:
        Cat(const std::string& name, int age) : Animal(name, age) {}

        virtual ~Cat() {}

        virtual void talk() override {
            std::cout << "Mur-Mur" << std::endl;
        }
};

class Dog : public Animal {
    public:
        Dog(const std::string& name, int age) : Animal(name, age) {}

        virtual ~Dog() {}

        virtual void talk() override {
            std::cout << "Guf-Guf" << std::endl;
        }
};

int main() {
    std::unique_ptr<Animal> murka(new Cat("Murka", 2));
    std::unique_ptr<Animal> baron(new Dog("Baron", 4));

    murka->setName("Black");
    murka->setAge(3);
    
    murka->talk();

    std::cout << murka->getName() << std::endl;
    std::cout << murka->getAge() << std::endl;
    
    std::cout << std::endl;

    baron->setName("White");
    baron->setAge(5);

    baron->talk();

    std::cout << baron->getName() << std::endl;
    std::cout << baron->getAge() << std::endl;
    
    return 0;
}
