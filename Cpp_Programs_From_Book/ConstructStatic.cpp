#include <iostream>

class DoNothing {
    protected:
        int initial;

    public:
        DoNothing(int initial) : initial(initial)
        {
            std::cout << "Construct DoNothing = " << this->initial << std::endl;
        }

        ~DoNothing() {
            std::cout << "Destruct DoNothing" << std::endl;
        }
};

void foo(int value) {
    std::cout << "foo call with " << value << std::endl;
    // constructs only ones
    static DoNothing dn(value);
}

int main() {
    foo(10);
    foo(20);
    
    return 0;
}
