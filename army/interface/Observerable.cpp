#include "Observerable.h"

Observerable::Observerable() {}

Observerable::~Observerable() {}

void Observerable::addObserver(Observer* hunter) {
    this->observerList.insert(hunter);
}

void Observerable::removeObserver(Observer* hunter) {
    this->observerList.erase(hunter);
}

void Observerable::notifyObserver() {
    for ( auto it : observerList ) {
        it->update(this);
    }
    observerList.clear();
}
