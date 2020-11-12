#ifndef TEXT_HANDLER_HPP
#define TEXT_HANDLER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>
#include "templates.cpp"

class TextHandler {
    private:
        std::string filename;

        std::set<char>* mCharacters;
        std::map<char, int>* mCharactersStatistics;

        std::set<char>* mNumbers;
        std::map<char, int>* mNumbersStatistics;

        std::set<char>* mSpecialSymbols;
        std::map<char, int>* mSpecialSymbolsStatistics;

        std::set<std::string>* mWords;
        std::map<std::string, int>* mWordsStatistics;

        long long mTotalQuantity;
        long long mWordsQuantity;

        void insert(char symbol, std::set<char>* lst);
        void insert(char symbol, std::map<char, int>* lst);
        void insert(std::string word, std::set<std::string>* lst);
        void insert(std::string word, std::map<std::string, int>* lst);

        bool isLetter(char symbol);
        bool isNumber(char symbol);
        bool isSpecial(char symbol);

    public:
        explicit TextHandler(const std::string& filename);
        virtual ~TextHandler();

        const std::set<char>& getCharacters() const;
        const std::map<char, int>& getCharactersStatistics() const;

        const std::set<char>& getNumbers() const;
        const std::map<char, int>& getNumbersStatistics() const;

        const std::set<char>& getSpecialSymbols() const;
        const std::map<char, int>& getSpecialSymbolsStatistics() const;

        const std::set<std::string>& getWords() const;
        const std::map<std::string, int>& getWordsStatistics() const;

        long long getTotalQuantity() const;
        long long getWordsQuantity() const;

        void parseText();

};

std::ostream& operator<<(std::ostream& out, const TextHandler& handler);

#endif //TEXT_HANDLER_HPP
