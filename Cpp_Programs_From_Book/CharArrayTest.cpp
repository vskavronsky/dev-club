#include <iostream>

void displayCharArray1(char arr[]);
void displayCharArray2(char arr[], int sizeOfArray);

int main() {
	// C-strings, with null terminator, not mutable;
	// std::strings - not, they are "counted" strings - their length is stored as an integer,
	// and they can contain any character, mutable
	
	char arr1[] = { 'V', 'i', 't', 'a', 'l', 'i', 'i', ' ', 'S', 'k', 'a', 'v', 'r', 'o', 'n', 's', 'k', 'y', 'i', '\0' };
	char arr2[] = "Vitalii Skavronskyi";
	
	displayCharArray1(arr1);
	
	std::cout << std::endl;
	
	displayCharArray2(arr2, sizeof(arr2) / sizeof(arr2[0]));

	return 0;
}

void displayCharArray1(char arr[]) {
	std::cout << "The characters in array with null terminator:" << std::endl;

	for ( int i = 0; arr[i] != '\0'; ++i ) {
		std::cout << arr[i];
	}
	std::cout << std::endl;
}

void displayCharArray2(char arr[], int sizeOfArray) {
	std::cout << "The characters in array with fix size:" << std::endl;

	for ( int i = 0; i < sizeOfArray; ++i ) {
		std::cout << arr[i];
	}
	std::cout << std::endl;
}
