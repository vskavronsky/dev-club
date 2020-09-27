#ifndef DEMON_H
#define DEMON_H

#include "Soldier.h"

class Warlock;

class Demon : public Soldier {
    public:
        Demon(const std::string& name = "Crowley", int hitPoints = 250, int damage = 40);
        virtual ~Demon();

        virtual void attack(Unit* enemy);

};

#endif // DEMON_H
