TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ability/Ability.cpp \
        ability/DefaultAbility.cpp \
        ability/MagicAbility.cpp \
        ability/RogueAbility.cpp \
        main.cpp \
        spell/Blessing.cpp \
        spell/FireBall.cpp \
        spell/HandOfDeath.cpp \
        spell/Heal.cpp \
        spell/Lightning.cpp \
        spell/Spell.cpp \
        spell/SpellBook.cpp \
        spellcaster/Healer.cpp \
        spellcaster/Necromancer.cpp \
        spellcaster/Priest.cpp \
        spellcaster/SpellCaster.cpp \
        spellcaster/Warlock.cpp \
        spellcaster/Wizard.cpp \
        state/MagicState.cpp \
        state/State.cpp \
        unit/Berserker.cpp \
        unit/Rogue.cpp \
        unit/Soldier.cpp \
        unit/Unit.cpp \
        unit/Vampire.cpp \
        unit/Werewolf.cpp

DISTFILES +=

HEADERS += \
    ability/Ability.h \
    ability/DefaultAbility.h \
    ability/MagicAbility.h \
    ability/RogueAbility.h \
    exceptions.h \
    spell/Blessing.h \
    spell/FireBall.h \
    spell/HandOfDeath.h \
    spell/Heal.h \
    spell/Lightning.h \
    spell/Spell.h \
    spell/SpellBook.h \
    spell/SpellEnum.h \
    spellcaster/Healer.h \
    spellcaster/Necromancer.h \
    spellcaster/Priest.h \
    spellcaster/SpellCaster.h \
    spellcaster/Warlock.h \
    spellcaster/Wizard.h \
    state/MagicState.h \
    state/State.h \
    unit/Berserker.h \
    unit/Rogue.h \
    unit/Soldier.h \
    unit/Unit.h \
    unit/Vampire.h \
    unit/Werewolf.h
