#include <string>
#include "Paper.h"

using namespace std;

Paper::Paper(int maxSymbols) {
    this->symbols = 0;
    this->maxSymbols = maxSymbols;    
}

Paper::~Paper() {
    
}

int Paper::getMaxSymbols() const {
    return this->maxSymbols;
}

int Paper::getSymbols() const {
    return this->symbols;
}

void Paper::addContent(const string& message) {
    int start = 0;
    
    if ( this->maxSymbols <= 0 ) {
        throw OutOfSpace();
    }
    string newMessage = message.substr(start, this->maxSymbols);
    this->maxSymbols -= newMessage.length();
    
    this->content += newMessage;
    this->symbols = this->content.length();
}

void Paper::show() const {
    cout << this->content << endl;
}
