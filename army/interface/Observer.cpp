#include "Observer.h"

Observer::Observer() {}

Observer::~Observer() {}

void Observer::addObserverable(Observerable *victim) {
    this->observerableList.insert(victim);
}

void Observer::notifyObserverable() {
    for ( auto it : observerableList ) {
        it->removeObserver(this);
    }
    observerableList.clear();
}

void Observer::update(Observerable* victim) {
    this->observerableList.erase(victim);
}
