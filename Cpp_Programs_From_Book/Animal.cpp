#include <iostream>

int nextAnimalId = 1000;

class AnimalId {
    protected:
        int id;
    
    public:
        AnimalId() : id(nextAnimalId++)
        {
            std::cout << "AnimalId: " << this->id << std::endl;
        }

        // prevents converting 'int' to 'AnimalId', ex: AnimalId id = 1 == AnimalId id(1)
        explicit AnimalId(int id) : id(id)
        {
            std::cout << "AnimalId: " << this->id << std::endl;
        }

        ~AnimalId() {
            std::cout << "Desctruct AnimalId" << std::endl;
        }
};

class Animal {
    protected:
        const char* name;
        const char* breed;
        int age;
        AnimalId id;
    
    public:
        Animal(const char* name, const char* breed, int age, int id)
            : name(name), breed(breed), age(age), id(id)
        {
            std::cout << "Construct " << name << std::endl;
        }

        // delegating constructor
        Animal() : Animal("NoName", "NoName", 0, 0) {}
        // converting 'const char*' to 'Animal'
        Animal(const char* name) : Animal(name, "NoName", 0, 0) {}
        
        // leave default constructor (dc), dc initializes data with zeros
        // Animal() = default;
        
        // delete default constructor
        // Animal() = delete;

        ~Animal() {
            std::cout << "Destruct " << name << std::endl;
        }
};

int main() {
    Animal animals[2];
    std::cout << "---------------" << std::endl;

    Animal animals2[] {"Chuck", "Fred"};
    std::cout << "---------------" << std::endl;

    Animal animals3[] {{"April", "Chu", 2, 2357}, {"Sun", "Pit Bull", 3, 1389}};
    std::cout << "---------------" << std::endl;
    
    //Animal* noName = new Animal;
    //Animal* chuck = new Animal("Chuck");
    //Animal* bob = new Animal("Bob", "Pit Bull", 4, 1234);
    
    //delete noName;
    //delete chuck;
    //delete bob;

    return 0;
}
