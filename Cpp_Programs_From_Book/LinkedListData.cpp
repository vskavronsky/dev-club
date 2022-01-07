#include <iostream>
#include <string>

class NameDataSet {
    public:
        NameDataSet() { std::cout << "Call constructor" << std::endl; }
        ~NameDataSet() { std::cout << "Call destructor" << std::endl; }
        std::string name;
        NameDataSet* next;
};

NameDataSet* head = nullptr;

void add(NameDataSet* value) {
    value->next = head;
    head = value;
}

NameDataSet* readData() {
    std::string name;
    std::cout << "Enter the name: ";
    std::cin >> name;

    if ( name == "exit" ) {
        return nullptr;
    }

    NameDataSet* member = new NameDataSet;
    member->name = name;
    member->next = nullptr;

    return member;
}

int main() {
    std::cout << "Enter students name, for exit enter 'exit'" << std::endl;

    NameDataSet* value;
    
    while ( value = readData() ) {
        add(value);
    }
    
    std::cout << "All recordings:" << std::endl;
    
    for (NameDataSet* pIter = head; pIter; pIter = pIter->next) {
        std::cout << pIter->name << std::endl;
    }

    for (; head != nullptr; ) {
        NameDataSet* nextItem = head->next;

        delete head;
        head = nextItem;
    }

    return 0;
}
