#ifndef PRIEST_H
#define PRIEST_H

#include "SpellCaster.h"
#include "../spell/Blessing.h"

class Priest : public SpellCaster {
    public:
        Priest(const std::string& name = "Jack", int hitPoints = 150, int damage = 25, int mana = 500);
        virtual ~Priest();

};

std::ostream& operator<<(std::ostream& out, const Priest* priest);

#endif // PRIEST_H
