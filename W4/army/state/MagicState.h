#ifndef MAGIC_STATE_H
#define MAGIC_STATE_H

#include <iostream>
#include "../exceptions.h"

class MagicState {
    protected:
        int mana;
        int manaLimit;
        bool battleMagician;
        bool priest;

    public:
        MagicState(int mana, bool battleMagician, bool priest);
        virtual ~MagicState();

        int getMana() const;
        int getManaLimit() const;
        bool isBattleMagician() const;
        bool isPriest() const;

        void addMana(int extra);
        void spendMana(int cost);

};

#endif // MAGIC_STATE_H
