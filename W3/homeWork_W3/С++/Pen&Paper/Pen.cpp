#include <string>
#include "Pen.h"

using namespace std;

Pen::Pen(int inkCapacity) {
    this->inkAmount = 0;
    this->inkCapacity = inkCapacity;
}

Pen::~Pen() {
    
}

int Pen::getInkAmount() const {
    return this->inkAmount;
}

int Pen::getInkCapacity() const {
    return this->inkCapacity;
}

void Pen::write(Paper& paper, const string& message) {
    int start = 0;
    
    if ( this->inkAmount == 0 ) {
        throw OutOfInk();
    }
    string newMessage = message.substr(start, this->inkAmount);
    paper.addContent(newMessage);
    this->inkAmount = this->inkCapacity - paper.getSymbols();
}

void Pen::refill() {
    if ( this->inkCapacity <= 0 ) {
        cout << "You entered incorect pen capacity" << endl;
        return;  
    }
    this->inkAmount = this->inkCapacity;
}
