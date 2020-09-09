#ifndef PRIEST_H
#define PRIEST_H

#include "SpellCaster.h"
#include "../spell/Blessing.h"

class Priest : public SpellCaster {
    public:
        Priest(const std::string& name, int hitPoints, int damage, int mana);
        virtual ~Priest();
};

std::ostream& operator<<(std::ostream& out, const Priest* priest);

#endif // PRIEST_H
