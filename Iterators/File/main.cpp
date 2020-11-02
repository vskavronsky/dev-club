#include <iostream>
#include "FileIter.hpp"

int main() {
    std::string inputFilePath = "D:/QTProjects/Iterators/File/Input.txt";
    std::string outputFilePath = "D:/QTProjects/Iterators/File/Output.txt";

    try {
        FileIter* fileIter = new FileIter(inputFilePath, outputFilePath);

        std::cout << "Start of the copying..." << std::endl;
        for ( ; !fileIter->end(); ++(*fileIter) ) {
            fileIter->write();
        }
        std::cout << "End of the copying!" << std::endl;

        delete fileIter;
        fileIter = nullptr;
    }
    catch ( const ReadError& ex ) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}
