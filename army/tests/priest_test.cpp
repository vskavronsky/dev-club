#include <catch.hpp>
#include "../spellcaster/Priest.h"
#include "../spellcaster/Necromancer.h"
#include "../unit/Soldier.h"

TEST_CASE("Test Priest class", "[priest]") {
    Priest* priest = new Priest("Priest", -100, -20, -500);
    REQUIRE(priest->getName() == "Priest");
    REQUIRE(priest->getHitPointsLimit() == 0);
    REQUIRE(priest->getHitPoints() == 0);
    REQUIRE(priest->getManaLimit() == 0);
    REQUIRE(priest->getMana() == 0);
    REQUIRE(priest->getDamage() == 0);
    REQUIRE(priest->isBattleMagician() == false);

    Priest* jack = new Priest();
    REQUIRE(jack->getName() == "Jack");
    REQUIRE(jack->getHitPointsLimit() == 150);
    REQUIRE(jack->getHitPoints() == 150);
    REQUIRE(jack->getManaLimit() == 500);
    REQUIRE(jack->getMana() == 500);
    REQUIRE(jack->getDamage() == 25);
    REQUIRE(jack->isBattleMagician() == false);

    Priest* den = new Priest("Den", 150, 30, 500);
    REQUIRE(den->getName() == "Den");
    REQUIRE(den->getHitPointsLimit() == 150);
    REQUIRE(den->getHitPoints() == 150);
    REQUIRE(den->getManaLimit() == 500);
    REQUIRE(den->getMana() == 500);
    REQUIRE(den->getDamage() == 30);
    REQUIRE(den->isBattleMagician() == false);

    SECTION( "Priest::takeDamage test" ) {
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

    SECTION("Priest::takeMagicDamage test") {
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

    SECTION("Priest::addHitPoints test") {
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

    SECTION("Priest::attack test") {
        Priest* enemy = new Priest("Enemy", 100, 20, 400);
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

    SECTION("Priest::counterAttack test") {
        Priest* enemy = new Priest("Enemy", 100, 20, 400);
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

    SECTION("Priest::addMana test") {
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

    SECTION("Priest::spendMana test") {
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

    SECTION("Priest::cast test") {
        Soldier* enemy = new Soldier("Enemy", 400, 30);
        REQUIRE(enemy->getName() == "Enemy");
        REQUIRE(enemy->getHitPointsLimit() == 400);
        REQUIRE(enemy->getHitPoints() == 400);
        REQUIRE(enemy->getDamage() == 30);

        Necromancer* undead = new Necromancer("Enemy", 200, 20, 400);
        REQUIRE(undead->getName() == "Enemy");
        REQUIRE(undead->getHitPointsLimit() == 200);
        REQUIRE(undead->getHitPoints() == 200);
        REQUIRE(undead->getManaLimit() == 400);
        REQUIRE(undead->getMana() == 400);
        REQUIRE(undead->getDamage() == 20);

        undead->takeMagicDamage(10);
        REQUIRE(undead->getHitPoints() == 190);

        try {
            den->cast(undead);
            REQUIRE_THROWS_AS(den->cast(undead), const InvalidAddHitPointsException& ex);
        }
        catch (const InvalidAddHitPointsException& ex) {
            REQUIRE(std::string(ex.what()) == "Priest cannot heal undead!");
            REQUIRE(undead->getHitPoints() == 190);
            REQUIRE(den->getHitPoints() == 150);
        }

        den->changeSpell(FIRE_BALL);
        den->cast(undead);
        REQUIRE(undead->getHitPoints() == 130);
        REQUIRE(den->getHitPoints() == 150);
        REQUIRE(den->getMana() == 470);

        den->cast(undead);
        den->cast(undead);
        REQUIRE(undead->getHitPoints() == 10);
        REQUIRE(den->getHitPoints() == 150);
        REQUIRE(den->getMana() == 410);

        enemy->takeMagicDamage(350);
        den->changeSpell(BLESSING);
        den->cast(enemy);
        REQUIRE(enemy->getHitPoints() == 160);
        REQUIRE(den->getHitPoints() == 150);
        REQUIRE(den->getMana() == 300);

        den->cast(enemy);
        den->cast(enemy);
        REQUIRE(enemy->getHitPoints() == 380);
        REQUIRE(den->getHitPoints() == 150);
        REQUIRE(den->getMana() == 80);

        enemy->takeMagicDamage(350);
        REQUIRE(enemy->getHitPoints() == 30);

        den->changeSpell(LIGHTNING);
        den->cast(enemy);
        REQUIRE(enemy->getHitPoints() == 0);
        REQUIRE(den->getHitPoints() == 150);
        REQUIRE(den->getMana() == 10);

        try {
            den->cast(enemy);
            REQUIRE_THROWS_AS(den->cast(enemy), const OutOfHitPointsException& ex);
        }
        catch (const OutOfHitPointsException& ex) {
            REQUIRE(ex.getUnitName() + ex.what() == enemy->getName() + " is dead. Game over!");
            REQUIRE(enemy->getHitPoints() == 0);
            REQUIRE(den->getHitPoints() == 150);
            REQUIRE(den->getMana() == 10);
        }
    }
}
