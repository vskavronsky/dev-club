#include <iostream>

int main() {
    int loopCount;
    std::cout << "Enter the loop count: ";
    std::cin >> loopCount;

    while ( loopCount > 0 ) {
        loopCount -= 1;
        std::cout << "Remain to run " << loopCount << " cicles" << std::endl;
    }

    // loopCount = 5 -> 4,3,2,1,0
    //while (loopCount-- > 0) {
    //    std::cout << "Remain to run " << loopCount << " cicles" << std::endl;
    //}

    // loopCount = 5 -> 4,3,2,1
    //while (--loopCount > 0) {
    //    std::cout << "Remain to run " << loopCount << " cicles" << std::endl;
    //}

    return 0;
}
