#include <iostream>

int main(int nNumberOfArgs, char* pszArgs[]) {
	std::cout.setf(std::cout.boolalpha);  // prints bool  

	int arg1, arg2;
	bool isEqual;
	
	std::cout << "Enter first number: ";
	std::cin >> arg1;

	std::cout << "Enter second number: ";
	std::cin >> arg2;

	isEqual = arg1 == arg2;

	if ( isEqual ) {
		std::cout << "Statment " << arg1 << " == " << arg2 << " -> " << isEqual << std::endl;
	} else {
		std::cout << "Statment " << arg1 << " == " << arg2 << " -> " << isEqual << std::endl;
	}

	return 0;
}
