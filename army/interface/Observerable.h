#ifndef OBSERVERABLE_H
#define OBSERVERABLE_H

#include <set>
#include "Observer.h"

class Observer;

class Observerable {
    protected:
        std::set<Observer*> observerList;

    public:
        Observerable();
        virtual ~Observerable();

        void addObserver(Observer* hunter);
        void removeObserver(Observer* hunter);
        void notifyObserver();

};

#endif // OBSERVERABLE_H
