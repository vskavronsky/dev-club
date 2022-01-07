#include <iostream>

int main() {
    int loopCount;
    std::cout << "Enter the loop count: ";
    std::cin >> loopCount;

    for ( int i = 1; i <= loopCount; i++ ) {
        std::cout << "Have run " << i << " cicle(s)" << std::endl;
    }

    // not to change loopCount itself, we assign her to i
    //for ( int i = loopCount; i > 0; ) {
    //    i--;
    //    std::cout << "Have run " << i << " cicle(s)" << std::endl;
    //}
    
    // for each
    //std::cout << "The prime numbers till 20:" << std::endl;
    //for ( int i : {1, 2, 3, 5, 7, 11, 13, 17, 19} ) {
    //    std::cout << i << " ";
    //}
    //std::cout << std::endl;

    return 0;
}
