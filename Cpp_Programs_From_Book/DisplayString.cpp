#include <iostream>
#include <cstring>

void displayStringByNullTerm(const char arr[]);
void displayStringByIndex(const char arr[], const int sizeOfArray);
void displayStringByPointer(const char* arr);

int main() {
	// C-strings - with null terminator, not mutable;
	// std::strings - without null terminator, they are "counted" strings - their length is stored as an integer,
	// and they can contain any character, mutable
	//
	// strlen - calculate characters till null terminator
	// char arr[128] - will allocate memory for 128 bytes, arr - const pointer
	// C-string will copy to arr2 using strcpy(arr2, "Vitalii Skavronskyi")

	const char arr[] = {'\0', '\0', '\0'}; // '\0' - ignore by compiler, size = 0
	const char arr1[] = { 'V', 'i', 't', 'a', 'l', 'i', 'i', ' ', 'S', 'k', 'a', 'v', 'r', 'o', 'n', 's', 'k', 'y', 'i', '\0' };
	const char arr2[] = "Vitalii Skavronskyi";
	const char* arr3 = "Vitalii Skavronskyi"; // size = 20 with null terminator
	
	std::cout << "String: '" << arr3 << "' (length: " << strlen(arr3) << ")" << std::endl;
	
	std::cout << std::endl;
	
	displayStringByNullTerm(arr3);

	std::cout << std::endl;

	displayStringByIndex(arr3, strlen(arr3));

	std::cout << std::endl;
	
	displayStringByPointer(arr3);

	//displayStringByIndex(arr2, sizeof(arr2) / sizeof(arr2[0]));

	return 0;
}

void displayStringByNullTerm(const char arr[]) {
	std::cout << "The characters in array using null terminator:" << std::endl;

	for ( int i = 0; arr[i] != '\0'; ++i ) {
		std::cout << arr[i];
	}
	std::cout << std::endl;
}

void displayStringByIndex(const char arr[], const int sizeOfArray) {
	std::cout << "The characters in array using index:" << std::endl;

	for ( int i = 0; i < sizeOfArray; ++i ) {
		std::cout << arr[i];
	}
	std::cout << std::endl;
}

void displayStringByPointer(const char* arr) {
	std::cout << "The characters in array using pointer arithmetics:" << std::endl;
	// *i++ -> shift pointer then show value 
	
	/*for ( ; *arr; ++arr ) {
		std::cout << *arr;
	}*/
	for ( const char* i = arr; *i; ++i ) {
		std::cout << *i;
	}
	std::cout << std::endl;
}
