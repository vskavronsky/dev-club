#include <catch.hpp>
#include "../spellcaster/Warlock.h"
#include "../unit/Soldier.h"
#include "../unit/Demon.h"

TEST_CASE("Test Warlock class", "[warlock]") {
    Warlock* warlock = new Warlock("Warlock", -100, -20, -500);
    REQUIRE(warlock->getName() == "Warlock");
    REQUIRE(warlock->getHitPointsLimit() == 0);
    REQUIRE(warlock->getHitPoints() == 0);
    REQUIRE(warlock->getManaLimit() == 0);
    REQUIRE(warlock->getMana() == 0);
    REQUIRE(warlock->getDamage() == 0);
    REQUIRE(warlock->isBattleMagician() == true);

    Warlock* amara = new Warlock();
    REQUIRE(amara->getName() == "Amara");
    REQUIRE(amara->getHitPointsLimit() == 150);
    REQUIRE(amara->getHitPoints() == 150);
    REQUIRE(amara->getManaLimit() == 500);
    REQUIRE(amara->getMana() == 500);
    REQUIRE(amara->getDamage() == 25);
    REQUIRE(amara->isBattleMagician() == true);

    Warlock* den = new Warlock("Den", 150, 30, 500);
    REQUIRE(den->getName() == "Den");
    REQUIRE(den->getHitPointsLimit() == 150);
    REQUIRE(den->getHitPoints() == 150);
    REQUIRE(den->getManaLimit() == 500);
    REQUIRE(den->getMana() == 500);
    REQUIRE(den->getDamage() == 30);
    REQUIRE(den->isBattleMagician() == true);

    SECTION( "Warlock::takeDamage test" ) {
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

    SECTION("Warlock::takeMagicDamage test") {
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

    SECTION("Warlock::addHitPoints test") {
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

    SECTION("Warlock::attack test") {
        Warlock* enemy = new Warlock("Enemy", 100, 20, 400);
        REQUIRE(enemy->getName() == "Enemy");
        REQUIRE(enemy->getHitPointsLimit() == 100);
        REQUIRE(enemy->getHitPoints() == 100);
        REQUIRE(enemy->getManaLimit() == 400);
        REQUIRE(enemy->getMana() == 400);
        REQUIRE(enemy->getDamage() == 20);

        den->attack(enemy);
        REQUIRE(enemy->getHitPoints() == 70);
        REQUIRE(den->getHitPoints() == 140);

        den->attack(enemy);
        den->attack(enemy);
        REQUIRE(enemy->getHitPoints() == 10);
        REQUIRE(den->getHitPoints() == 120);

        try {
            den->attack(enemy);
            REQUIRE_THROWS_AS(den->attack(enemy), const OutOfHitPointsException& ex);
        }
        catch (const OutOfHitPointsException& ex) {
            REQUIRE(ex.getUnitName() + ex.what() == enemy->getName() + " is dead. Game over!");
            REQUIRE(enemy->getHitPoints() == 0);
            REQUIRE(den->getHitPoints() == 120);
        }

        try {
            enemy->attack(den);
            REQUIRE_THROWS_AS(enemy->attack(den), const OutOfHitPointsException& ex);
        }
        catch (const OutOfHitPointsException& ex) {
            REQUIRE(ex.getUnitName() + ex.what() == enemy->getName() + " is dead. Game over!");
            REQUIRE(enemy->getHitPoints() == 0);
            REQUIRE(den->getHitPoints() == 120);
        }
    }

    SECTION("Warlock::counterAttack test") {
        Warlock* enemy = new Warlock("Enemy", 100, 20, 400);
        REQUIRE(enemy->getName() == "Enemy");
        REQUIRE(enemy->getHitPointsLimit() == 100);
        REQUIRE(enemy->getHitPoints() == 100);
        REQUIRE(enemy->getManaLimit() == 400);
        REQUIRE(enemy->getMana() == 400);
        REQUIRE(enemy->getDamage() == 20);

        den->counterAttack(enemy);
        REQUIRE(enemy->getHitPoints() == 85);
        REQUIRE(den->getHitPoints() == 150);

        den->counterAttack(enemy);
        den->counterAttack(enemy);
        REQUIRE(enemy->getHitPoints() == 55);
        REQUIRE(den->getHitPoints() == 150);

        enemy->takeDamage(50);

        try {
            den->counterAttack(enemy);
            REQUIRE_THROWS_AS(den->counterAttack(enemy), const OutOfHitPointsException& ex);
        }
        catch (const OutOfHitPointsException& ex) {
            REQUIRE(ex.getUnitName() + ex.what() == enemy->getName() + " is dead. Game over!");
            REQUIRE(enemy->getHitPoints() == 0);
            REQUIRE(den->getHitPoints() == 150);
        }

        try {
            enemy->counterAttack(den);
            REQUIRE_THROWS_AS(enemy->counterAttack(den), const OutOfHitPointsException& ex);
        }
        catch (const OutOfHitPointsException& ex) {
            REQUIRE(ex.getUnitName() + ex.what() == enemy->getName() + " is dead. Game over!");
            REQUIRE(enemy->getHitPoints() == 0);
            REQUIRE(den->getHitPoints() == 150);
        }
    }

    SECTION("Warlock::addMana test") {
        den->spendMana(300);
        REQUIRE(den->getMana() == 200);
        REQUIRE(den->getManaLimit() == 500);

        den->addMana(100);
        REQUIRE(den->getMana() == 300);
        REQUIRE(den->getManaLimit() == 500);

        den->addMana(150);
        REQUIRE(den->getMana() == 450);
        REQUIRE(den->getManaLimit() == 500);

        den->addMana(100);
        REQUIRE(den->getMana() == 500);
        REQUIRE(den->getManaLimit() == 500);

        den->addMana(50);
        REQUIRE(den->getMana() == 500);
        REQUIRE(den->getManaLimit() == 500);
    }

    SECTION("Warlock::spendMana test") {
        den->spendMana(100);
        REQUIRE(den->getMana() == 400);
        REQUIRE(den->getManaLimit() == 500);

        den->spendMana(100);
        den->spendMana(250);
        REQUIRE(den->getMana() == 50);
        REQUIRE(den->getManaLimit() == 500);

        try {
            den->spendMana(75);
            REQUIRE_THROWS_AS(den->spendMana(75), const OutOfManaException& ex);
        }
        catch (const OutOfManaException& ex) {
            REQUIRE(std::string(ex.what()) == "Not enough mana for cast!");
            REQUIRE(den->getMana() == 50);
            REQUIRE(den->getManaLimit() == 500);
        }
    }

    SECTION("Warlock::summon test") {
        Soldier* enemy = new Soldier("Enemy", 300, 30);
        REQUIRE(enemy->getName() == "Enemy");
        REQUIRE(enemy->getHitPointsLimit() == 300);
        REQUIRE(enemy->getHitPoints() == 300);
        REQUIRE(enemy->getDamage() == 30);

        Demon* demon = den->summonDemon();
        REQUIRE(demon->getName() == "Crowley");
        REQUIRE(demon->getHitPointsLimit() == 250);
        REQUIRE(demon->getHitPoints() == 250);
        REQUIRE(demon->getDamage() == 40);

        try {
            demon->attack(den);
            REQUIRE_THROWS_AS(demon->attack(den), const CanNotAttackOwnerException& ex);
        }
        catch (const CanNotAttackOwnerException& ex) {
            REQUIRE(std::string(ex.what()) == "Demon cannot attack his master!");
            REQUIRE(demon->getHitPoints() == 250);
            REQUIRE(den->getHitPoints() == 150);
        }

        demon->attack(enemy);
        demon->attack(enemy);
        REQUIRE(enemy->getHitPoints() == 220);
        REQUIRE(demon->getHitPoints() == 220);
    }

    SECTION("Warlock::cast test") {
        Soldier* enemy = new Soldier("Enemy", 300, 30);
        REQUIRE(enemy->getName() == "Enemy");
        REQUIRE(enemy->getHitPointsLimit() == 300);
        REQUIRE(enemy->getHitPoints() == 300);
        REQUIRE(enemy->getDamage() == 30);

        den->cast(enemy);
        REQUIRE(enemy->getHitPoints() == 230);
        REQUIRE(den->getHitPoints() == 150);
        REQUIRE(den->getMana() == 430);

        den->cast(enemy);
        den->cast(enemy);
        REQUIRE(enemy->getHitPoints() == 90);
        REQUIRE(den->getHitPoints() == 150);
        REQUIRE(den->getMana() == 290);

        den->changeSpell(HEAL);
        den->cast(enemy);
        REQUIRE(enemy->getHitPoints() == 115);
        REQUIRE(den->getHitPoints() == 150);
        REQUIRE(den->getMana() == 240);

        den->cast(enemy);
        den->cast(enemy);
        REQUIRE(enemy->getHitPoints() == 165);
        REQUIRE(den->getHitPoints() == 150);
        REQUIRE(den->getMana() == 140);

        enemy->takeMagicDamage(150);
        REQUIRE(enemy->getHitPoints() == 15);

        den->changeSpell(HAND_OF_DEATH);
        den->cast(enemy);
        REQUIRE(enemy->getHitPoints() == 0);
        REQUIRE(den->getHitPoints() == 150);
        REQUIRE(den->getMana() == 40);

        try {
            den->cast(enemy);
            REQUIRE_THROWS_AS(den->cast(enemy), const OutOfHitPointsException& ex);
        }
        catch (const OutOfHitPointsException& ex) {
            REQUIRE(ex.getUnitName() + ex.what() == enemy->getName() + " is dead. Game over!");
            REQUIRE(enemy->getHitPoints() == 0);
            REQUIRE(den->getHitPoints() == 150);
            REQUIRE(den->getMana() == 40);
        }
    }
}
