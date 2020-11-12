#include <iostream>
#include "TextHandler.hpp"

int main() {
    std::string inputPath = "D:/QTProjects/Statistic/Text/symbols.txt";
    std::string inputPath2 = "D:/QTProjects/Statistic/Text/elephantsStory.txt";
    std::string inputPath3 = "D:/QTProjects/Statistic/Text/theBirthOfStar.txt";

    std::string outPath = "D:/QTProjects/Statistic/Text/symbolsResult.txt";
    std::string outPath2 = "D:/QTProjects/Statistic/Text/elephantsStoryResult.txt";
    std::string outPath3 = "D:/QTProjects/Statistic/Text/theBirthOfStarResult.txt";

    std::ofstream out(outPath);

    TextHandler* handler = new TextHandler(inputPath);
    handler->parseText();
    std::cout << *handler << std::endl;

    out << *handler;
    out.close();

    delete handler;
    handler = nullptr;

    std::ofstream out2(outPath2);

    TextHandler* handler2 = new TextHandler(inputPath2);
    handler2->parseText();
    std::cout << *handler2 << std::endl;

    out2 << *handler2;
    out2.close();

    delete handler2;
    handler2 = nullptr;

    std::ofstream out3(outPath3);

    TextHandler* handler3 = new TextHandler(inputPath3);
    handler3->parseText();
    std::cout << *handler3 << std::endl;

    out3 << *handler3;
    out3.close();

    delete handler3;
    handler3 = nullptr;

    return 0;
}
