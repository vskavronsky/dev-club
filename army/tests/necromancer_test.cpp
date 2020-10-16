#include <catch.hpp>
#include "../spellcaster/Necromancer.h"
#include "../unit/Soldier.h"

TEST_CASE("Test Necromancer class", "[necromancer]") {
    Necromancer* necromancer = new Necromancer("Necromancer", -100, -20, -500);
    REQUIRE(necromancer->getName() == "Necromancer");
    REQUIRE(necromancer->getHitPointsLimit() == 0);
    REQUIRE(necromancer->getHitPoints() == 0);
    REQUIRE(necromancer->getManaLimit() == 0);
    REQUIRE(necromancer->getMana() == 0);
    REQUIRE(necromancer->getDamage() == 0);
    REQUIRE(necromancer->isBattleMagician() == true);

    Necromancer* billie = new Necromancer();
    REQUIRE(billie->getName() == "Billie");
    REQUIRE(billie->getHitPointsLimit() == 150);
    REQUIRE(billie->getHitPoints() == 150);
    REQUIRE(billie->getManaLimit() == 500);
    REQUIRE(billie->getMana() == 500);
    REQUIRE(billie->getDamage() == 25);
    REQUIRE(billie->isBattleMagician() == true);

    Necromancer* den = new Necromancer("Den", 150, 30, 500);
    REQUIRE(den->getName() == "Den");
    REQUIRE(den->getHitPointsLimit() == 150);
    REQUIRE(den->getHitPoints() == 150);
    REQUIRE(den->getManaLimit() == 500);
    REQUIRE(den->getMana() == 500);
    REQUIRE(den->getDamage() == 30);
    REQUIRE(den->isBattleMagician() == true);

    SECTION( "Necromancer::takeDamage test" ) {
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

    SECTION("Necromancer::takeMagicDamage test") {
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

    SECTION("Necromancer::addHitPoints test") {
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

    SECTION("Necromancer::attack test") {
        Necromancer* enemy = new Necromancer("Enemy", 100, 20, 400);
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

    SECTION("Necromancer::counterAttack test") {
        Necromancer* enemy = new Necromancer("Enemy", 100, 20, 400);
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
        den->takeDamage(50);
        REQUIRE(enemy->getHitPoints() == 5);
        REQUIRE(den->getHitPoints() == 100);

        try {
            den->counterAttack(enemy);
            REQUIRE_THROWS_AS(den->counterAttack(enemy), const OutOfHitPointsException& ex);
        }
        catch (const OutOfHitPointsException& ex) {
            REQUIRE(ex.getUnitName() + ex.what() == enemy->getName() + " is dead. Game over!");
            REQUIRE(enemy->getHitPoints() == 0);
            REQUIRE(den->getHitPoints() == 115);
        }

        try {
            enemy->counterAttack(den);
            REQUIRE_THROWS_AS(enemy->counterAttack(den), const OutOfHitPointsException& ex);
        }
        catch (const OutOfHitPointsException& ex) {
            REQUIRE(ex.getUnitName() + ex.what() == enemy->getName() + " is dead. Game over!");
            REQUIRE(enemy->getHitPoints() == 0);
            REQUIRE(den->getHitPoints() == 115);
        }
    }

    SECTION("Necromancer::addMana test") {
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

    SECTION("Necromancer::spendMana test") {
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

    SECTION("Necromancer::cast test") {
        Soldier* enemy = new Soldier("Enemy", 350, 30);
        REQUIRE(enemy->getName() == "Enemy");
        REQUIRE(enemy->getHitPointsLimit() == 350);
        REQUIRE(enemy->getHitPoints() == 350);
        REQUIRE(enemy->getDamage() == 30);

        den->cast(enemy);
        REQUIRE(enemy->getHitPoints() == 250);
        REQUIRE(den->getHitPoints() == 150);
        REQUIRE(den->getMana() == 400);

        den->cast(enemy);
        den->cast(enemy);
        REQUIRE(enemy->getHitPoints() == 50);
        REQUIRE(den->getHitPoints() == 150);
        REQUIRE(den->getMana() == 200);

        den->changeSpell(HEAL);
        den->cast(enemy);
        REQUIRE(enemy->getHitPoints() == 75);
        REQUIRE(den->getHitPoints() == 150);
        REQUIRE(den->getMana() == 150);

        den->cast(enemy);
        den->cast(enemy);
        REQUIRE(enemy->getHitPoints() == 125);
        REQUIRE(den->getHitPoints() == 150);
        REQUIRE(den->getMana() == 50);

        enemy->takeMagicDamage(100);
        REQUIRE(enemy->getHitPoints() == 25);

        den->takeMagicDamage(50);
        REQUIRE(den->getHitPoints() == 100);

        den->changeSpell(FIRE_BALL);
        den->cast(enemy);
        REQUIRE(enemy->getHitPoints() == 0);
        REQUIRE(den->getHitPoints() == 100);
        REQUIRE(den->getMana() == 20);

        try {
            den->cast(enemy);
            REQUIRE_THROWS_AS(den->cast(enemy), const OutOfHitPointsException& ex);
        }
        catch (const OutOfHitPointsException& ex) {
            REQUIRE(ex.getUnitName() + ex.what() == enemy->getName() + " is dead. Game over!");
            REQUIRE(enemy->getHitPoints() == 0);
            REQUIRE(den->getHitPoints() == 115);
            REQUIRE(den->getMana() == 20);
        }
    }
}
