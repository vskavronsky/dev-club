#ifndef WIZARD_H
#define WIZARD_H

#include "SpellCaster.h"
#include "../spell/FireBall.h"

class Wizard : public SpellCaster {
    public:
        Wizard(const std::string& name, int hitPoints, int damage, int mana);
        virtual ~Wizard();
};

std::ostream& operator<<(std::ostream& out, const Wizard* wizard);

#endif // WIZARD_H
