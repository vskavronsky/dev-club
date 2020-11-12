#include "TextHandler.hpp"

#define MIN_STR_SIZE 2
#define APOSTROPHE 39
#define HYPHEN_MINUS 45

TextHandler::TextHandler(const std::string& filename) : filename(filename) {
    mCharacters = new std::set<char>();
    mCharactersStatistics = new std::map<char, int>();

    mNumbers = new std::set<char>();
    mNumbersStatistics = new std::map<char, int>();

    mSpecialSymbols = new std::set<char>();
    mSpecialSymbolsStatistics = new std::map<char, int>();

    mWords = new std::set<std::string>();
    mWordsStatistics = new std::map<std::string, int>();

    mTotalQuantity = 0;
    mWordsQuantity = 0;
}

TextHandler::~TextHandler() {
    delete mCharacters;
    delete mCharactersStatistics;

    delete mNumbers;
    delete mNumbersStatistics;

    delete mSpecialSymbols;
    delete mSpecialSymbolsStatistics;

    delete mWords;
    delete mWordsStatistics;
}

const std::set<char>& TextHandler::getCharacters() const {
    return *mCharacters;
}

const std::map<char, int>& TextHandler::getCharactersStatistics() const {
    return *mCharactersStatistics;
}

const std::set<char>& TextHandler::getNumbers() const {
    return *mNumbers;
}

const std::map<char, int>& TextHandler::getNumbersStatistics() const {
    return *mNumbersStatistics;
}

const std::set<char>& TextHandler::getSpecialSymbols() const {
    return *mSpecialSymbols;
}

const std::map<char, int>& TextHandler::getSpecialSymbolsStatistics() const {
    return *mSpecialSymbolsStatistics;
}

const std::set<std::string>& TextHandler::getWords() const {
    return *mWords;
}

const std::map<std::string, int>& TextHandler::getWordsStatistics() const {
    return *mWordsStatistics;
}

long long TextHandler::getTotalQuantity() const {
    return mTotalQuantity;
}

long long TextHandler::getWordsQuantity() const {
    return mWordsQuantity;
}

void TextHandler::insert(char symbol, std::set<char>* lst) {
    lst->insert(symbol);
}

void TextHandler::insert(char symbol, std::map<char, int>* lst) {
    if ( lst->find(symbol) == lst->end() ) {
        lst->insert(std::pair<char, int>(symbol, 0));
    }
    lst->at(symbol) += 1;
}

void TextHandler::insert(std::string word, std::set<std::string>* lst) {
    lst->insert(word);
}

void TextHandler::insert(std::string word, std::map<std::string, int>* lst) {
    if ( lst->find(word) == lst->end() ) {
        lst->insert(std::pair<std::string, int>(word, 0));
    }
    lst->at(word) += 1;
}

bool TextHandler::isLetter(char symbol) {
    return ( symbol >= 'A' && symbol <= 'Z' ) || ( symbol >= 'a' && symbol <= 'z' );
}

bool TextHandler::isNumber(char symbol) {
    return symbol >= '0' && symbol <= '9';
}

bool TextHandler::isSpecial(char symbol) {
    bool special = false;

    if ( ( symbol > ' ' && symbol < '0' ) || ( symbol > '9' && symbol < 'A' ) ) {
        special = true;
    }
    if ( ( symbol > 'Z' && symbol < 'a' ) || ( symbol > 'z' && symbol <= '~' ) ) {
        special = true;
    }

    return special;
}

void TextHandler::parseText() {
    std::ifstream file(filename);
    std::string word;
    int diff = 'a' - 'A';
    char symbol;

    for ( ; file.get(symbol) ; ) {
        if ( isLetter(symbol) ) {
            if ( symbol < 'a' ) {
                symbol += diff;
            }
            insert(symbol, mCharacters);
            insert(symbol, mCharactersStatistics);
            word.push_back(symbol);
            mTotalQuantity += 1;
            continue;
        }
        if ( isSpecial(symbol) ) {
            insert(symbol, mSpecialSymbols);
            insert(symbol, mSpecialSymbolsStatistics);
            mTotalQuantity += 1;

            if ( symbol == APOSTROPHE || symbol == HYPHEN_MINUS ) {
                word.push_back(symbol);
            }
            continue;
        }
        if ( word.size() >= MIN_STR_SIZE ) {
            if ( word.front() == APOSTROPHE || word.front() == HYPHEN_MINUS ) {
                word.erase(word.begin());
            }
            if ( word.back() == APOSTROPHE || word.back() == HYPHEN_MINUS ) {
                word.pop_back();
            }
            if ( word.size() >= MIN_STR_SIZE ) {
                insert(word, mWords);
                insert(word, mWordsStatistics);
                mWordsQuantity += 1;
            }
            word = "";
            continue;
        } else {
            word = "";
        }
        if ( isNumber(symbol) ) {
            insert(symbol, mNumbers);
            insert(symbol, mNumbersStatistics);
            mTotalQuantity += 1;
        }
    }
    file.close();
}

std::ostream& operator<<(std::ostream& out, const TextHandler& handler) {
    out << "Symbols found: " << handler.getTotalQuantity() << std::endl;
    out << "Words found: " << handler.getWordsQuantity() << std::endl << std::endl;
    out << "Letters statistic:" << std::endl;
    out << "Unique: " << handler.getCharacters() << std::endl;
    out << "Matches in text: " << std::endl;
    out << handler.getCharactersStatistics() << std::endl;

    out << "Numbers statistic:" << std::endl;
    out << "Unique: " << handler.getNumbers() << std::endl;
    out << "Matches in text: " << std::endl;
    out << handler.getNumbersStatistics() << std::endl;

    out << "Special symbols statistic:" << std::endl;
    out << "Unique: " << handler.getSpecialSymbols() << std::endl;
    out << "Matches in text: " << std::endl;
    out << handler.getSpecialSymbolsStatistics() << std::endl;

    out << "Words statistic:" << std::endl;
    out << "Unique: " << handler.getWords() << std::endl;
    out << "Matches in text: " << std::endl;
    out << handler.getWordsStatistics() << std::endl;

    return out;
}
