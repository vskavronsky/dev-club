#include <catch.hpp>
#include "../unit/Vampire.h"
#include "../unit/Werewolf.h"
#include "../unit/Soldier.h"
#include "../spellcaster/Wizard.h"

TEST_CASE("Test Vampire class", "[vampire]") {
    Vampire* vampire = new Vampire("Vampire", -100, -20);
    REQUIRE(vampire->getName() == "Vampire");
    REQUIRE(vampire->getHitPointsLimit() == 0);
    REQUIRE(vampire->getHitPoints() == 0);
    REQUIRE(vampire->getDamage() == 0);

    Vampire* dean = new Vampire();
    REQUIRE(dean->getName() == "Dean");
    REQUIRE(dean->getHitPointsLimit() == 250);
    REQUIRE(dean->getHitPoints() == 250);
    REQUIRE(dean->getDamage() == 40);

    Vampire* den = new Vampire("Den", 150, 30);
    REQUIRE(den->getName() == "Den");
    REQUIRE(den->getHitPointsLimit() == 150);
    REQUIRE(den->getHitPoints() == 150);
    REQUIRE(den->getDamage() == 30);

    SECTION( "Vampire::takeDamage test" ) {
        int damage = 50;

        den->takeDamage(damage);
        REQUIRE(den->getHitPoints() == 100);
        REQUIRE(den->getHitPointsLimit() == 150);

        den->takeDamage(damage);
        REQUIRE(den->getHitPoints() == 50);
        REQUIRE(den->getHitPointsLimit() == 150);

        den->takeDamage(damage);
        REQUIRE(den->getHitPoints() == 0);
        REQUIRE(den->getHitPointsLimit() == 150);

        try {
            den->takeDamage(damage);
            REQUIRE_THROWS_AS(den->takeDamage(damage), const OutOfHitPointsException& ex);
        }
        catch (const OutOfHitPointsException& ex) {
            REQUIRE(ex.getUnitName() + ex.what() == den->getName() + " is dead. Game over!");
            REQUIRE(den->getHitPoints() == 0);
        }

        try {
            den->addHitPoints(damage);
            REQUIRE_THROWS_AS(den->addHitPoints(damage), const OutOfHitPointsException& ex);
        }
        catch (const OutOfHitPointsException& ex) {
            REQUIRE(ex.getUnitName() + ex.what() == den->getName() + " is dead. Game over!");
            REQUIRE(den->getHitPoints() == 0);
        }
    }

    SECTION("Vampire::takeMagicDamage test") {
        int damage = 50;

        den->takeMagicDamage(damage);
        REQUIRE(den->getHitPoints() == 100);
        REQUIRE(den->getHitPointsLimit() == 150);

        den->takeMagicDamage(damage);
        REQUIRE(den->getHitPoints() == 50);
        REQUIRE(den->getHitPointsLimit() == 150);

        den->takeMagicDamage(damage);
        REQUIRE(den->getHitPoints() == 0);
        REQUIRE(den->getHitPointsLimit() == 150);

        try {
            den->takeMagicDamage(damage);
            REQUIRE_THROWS_AS(den->takeMagicDamage(damage), const OutOfHitPointsException& ex);
        }
        catch (const OutOfHitPointsException& ex) {
            REQUIRE(ex.getUnitName() + ex.what() == den->getName() + " is dead. Game over!");
            REQUIRE(den->getHitPoints() == 0);
        }

        try {
            den->addHitPoints(damage);
            REQUIRE_THROWS_AS(den->addHitPoints(damage), const OutOfHitPointsException& ex);
        }
        catch (const OutOfHitPointsException& ex) {
            REQUIRE(ex.getUnitName() + ex.what() == den->getName() + " is dead. Game over!");
            REQUIRE(den->getHitPoints() == 0);
        }
    }

    SECTION("Vampire::addHitPoints test") {
        den->takeDamage(60);
        REQUIRE(den->getHitPoints() == 90);
        REQUIRE(den->getHitPointsLimit() == 150);

        den->addHitPoints(50);
        REQUIRE(den->getHitPoints() == 140);
        REQUIRE(den->getHitPointsLimit() == 150);

        den->addHitPoints(40);
        REQUIRE(den->getHitPoints() == 150);
        REQUIRE(den->getHitPointsLimit() == 150);

        den->addHitPoints(30);
        REQUIRE(den->getHitPoints() == 150);
        REQUIRE(den->getHitPointsLimit() == 150);
    }

    SECTION("Vampire::attack test") {
        Wizard* enemy = new Wizard("Enemy", 100, 40, 500);
        REQUIRE(enemy->getName() == "Enemy");
        REQUIRE(enemy->getHitPointsLimit() == 100);
        REQUIRE(enemy->getHitPoints() == 100);
        REQUIRE(enemy->getManaLimit() == 500);
        REQUIRE(enemy->getMana() == 500);
        REQUIRE(enemy->getDamage() == 40);

        den->attack(enemy);
        REQUIRE(enemy->getHitPoints() == 70);
        REQUIRE(den->getHitPoints() == 145);

        den->attack(enemy);
        den->attack(enemy);
        REQUIRE(enemy->getHitPoints() == 10);
        REQUIRE(den->getHitPoints() == 135);

        try {
            den->attack(enemy);
            REQUIRE_THROWS_AS(den->attack(enemy), const OutOfHitPointsException& ex);
        }
        catch (const OutOfHitPointsException& ex) {
            REQUIRE(ex.getUnitName() + ex.what() == enemy->getName() + " is dead. Game over!");
            REQUIRE(enemy->getHitPoints() == 0);
            REQUIRE(den->getHitPoints() == 135);
        }

        try {
            enemy->attack(den);
            REQUIRE_THROWS_AS(enemy->attack(den), const OutOfHitPointsException& ex);
        }
        catch (const OutOfHitPointsException& ex) {
            REQUIRE(ex.getUnitName() + ex.what() == enemy->getName() + " is dead. Game over!");
            REQUIRE(enemy->getHitPoints() == 0);
            REQUIRE(den->getHitPoints() == 135);
        }
    }

    SECTION("Vampire::counterAttack test") {
        Soldier* enemy = new Soldier("Enemy", 100, 20);
        REQUIRE(enemy->getName() == "Enemy");
        REQUIRE(enemy->getHitPoints() == 100);
        REQUIRE(enemy->getHitPointsLimit() == 100);
        REQUIRE(enemy->getDamage() == 20);

        enemy->attack(den);
        REQUIRE(den->getHitPoints() == 145);
        REQUIRE(enemy->getHitPoints() == 85);

        enemy->attack(den);
        enemy->attack(den);
        REQUIRE(den->getHitPoints() == 135);
        REQUIRE(enemy->getHitPoints() == 55);

        enemy->takeDamage(50);
        enemy->attack(den);
        REQUIRE(enemy->getHitPoints() == 0);
        REQUIRE(den->getHitPoints() == 130);

        try {
            enemy->attack(den);
            REQUIRE_THROWS_AS(enemy->attack(den), const OutOfHitPointsException& ex);
        }
        catch (const OutOfHitPointsException& ex) {
            REQUIRE(ex.getUnitName() + ex.what() == enemy->getName() + " is dead. Game over!");
            REQUIRE(enemy->getHitPoints() == 0);
            REQUIRE(den->getHitPoints() == 130);
        }

        try {
            enemy->counterAttack(den);
            REQUIRE_THROWS_AS(enemy->counterAttack(den), const OutOfHitPointsException& ex);
        }
        catch (const OutOfHitPointsException& ex) {
            REQUIRE(ex.getUnitName() + ex.what() == enemy->getName() + " is dead. Game over!");
            REQUIRE(enemy->getHitPoints() == 0);
            REQUIRE(den->getHitPoints() == 130);
        }
    }

    SECTION("Vampire::bite test") {
        Soldier* mike = new Soldier("Mike", 150, 30);
        REQUIRE(mike->getName() == "Mike");
        REQUIRE(mike->getHitPoints() == 150);
        REQUIRE(mike->getHitPointsLimit() == 150);
        REQUIRE(mike->getDamage() == 30);

        Werewolf* bob = new Werewolf("Bob", 100, 40);
        REQUIRE(bob->getName() == "Bob");
        REQUIRE(bob->getHitPoints() == 100);
        REQUIRE(bob->getHitPointsLimit() == 100);
        REQUIRE(bob->getDamage() == 40);

        den->bite(mike);
        Ability& mike_ability = *(mike->getAbility());
        REQUIRE(typeid(mike_ability) == typeid(VampireAbility));

        dynamic_cast<VampireAbility*>(mike->getAbility())->attack(bob);
        dynamic_cast<VampireAbility*>(mike->getAbility())->attack(bob);
        REQUIRE(bob->getHitPoints() == 40);
        REQUIRE(mike->getHitPoints() == 140);

        Ability& bob_ability = *(bob->getAbility());
        try {
            den->bite(bob);
            REQUIRE_THROWS_AS(den->bite(bob), const CanNotTurnException& ex);
        }
        catch (const CanNotTurnException& ex) {
            REQUIRE(std::string(ex.what()) == "Werewolf cannot be turned into vampire!");
            REQUIRE(typeid(bob_ability) == typeid(DefaultAbility));
        }
    }
}
