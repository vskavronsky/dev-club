#ifndef HEALER_H
#define HEALER_H

#include "SpellCaster.h"
#include "../spell/Heal.h"

class Healer : public SpellCaster {
    public:
        Healer(const std::string& name = "Castiel", int hitPoints = 150, int damage = 25, int mana = 500);
        virtual ~Healer();

};

std::ostream& operator<<(std::ostream& out, const Healer* healer);

#endif // HEALER_H
