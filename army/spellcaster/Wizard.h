#ifndef WIZARD_H
#define WIZARD_H

#include "SpellCaster.h"
#include "../spell/FireBall.h"

class Wizard : public SpellCaster {
    public:
        Wizard(const std::string& name = "Rowena", int hitPoints = 150, int damage = 25, int mana = 500);
        virtual ~Wizard();

};

std::ostream& operator<<(std::ostream& out, const Wizard* wizard);

#endif // WIZARD_H
