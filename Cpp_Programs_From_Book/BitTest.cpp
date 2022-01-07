#include <iostream>
#include <bitset>

int main(int nNumberOfArgs, char* pszArgs[]) {
	int num1, num2;

	std::cout << "Enter first number: ";
	std::cin >> num1;
	
	std::cout << "Enter second number: ";
	std::cin >> num2;

	std::bitset<8> binary1(num1);  // 8 means - 8 bit, 01100001
	std::bitset<8> binary2(num2);

	int resNorInt1 = ~num1;
	std::bitset<8> resNorBin1(~num1);
	
	int resNorInt2 = ~num2;
	std::bitset<8> resNorBin2(~num2);

	int resAndInt = num1 & num2;
	std::bitset<8> resAndBin(num1 & num2);
	
	int resOrInt = num1 | num2;
	std::bitset<8> resOrBin(num1 | num2);
	
	int resXorInt = num1 ^ num2;
	std::bitset<8> resXorBin(num1 ^ num2);

	std::cout << " num1 = " << num1 << " (" << binary1 << ")" << std::endl;
	std::cout << "~num1 = " << resNorInt1 << " (" << resNorBin1 << ")" << std::endl << std::endl;

	std::cout << " num2 = " << num2 << " (" << binary2 << ")" << std::endl;
	std::cout << "~num2 = " << resNorInt2 << " (" << resNorBin2 << ")" << std::endl << std::endl;

	std::cout << "  " << num1 << " (" << binary1 << ")" << std::endl;
	std::cout << "& " << num2 << " (" << binary2 << ")" << std::endl;
	std::cout << "---------------" << std::endl;
	std::cout << "  " << resAndInt << " (" << resAndBin << ")" << std::endl << std::endl;

	std::cout << "  " << num1 << " (" << binary1 << ")" << std::endl;
	std::cout << "| " << num2 << " (" << binary2 << ")" << std::endl;
	std::cout << "---------------" << std::endl;
	std::cout << "  " << resOrInt << " (" << resOrBin << ")" << std::endl << std::endl;

	std::cout << "  " << num1 << " (" << binary1 << ")" << std::endl;
	std::cout << "^ " << num2 << " (" << binary2 << ")" << std::endl;
	std::cout << "---------------" << std::endl;
	std::cout << "  " << resXorInt << " (" << resXorBin << ")" << std::endl << std::endl;

	return 0;
}
