#include <catch.hpp>
#include "../unit/Rogue.h"

TEST_CASE("Test Rogue class", "[rogue]") {
    Rogue* rogue = new Rogue("Rogue", -100, -20);
    REQUIRE(rogue->getName() == "Rogue");
    REQUIRE(rogue->getHitPointsLimit() == 0);
    REQUIRE(rogue->getHitPoints() == 0);
    REQUIRE(rogue->getDamage() == 0);

    Rogue* ruby = new Rogue();
    REQUIRE(ruby->getName() == "Ruby");
    REQUIRE(ruby->getHitPointsLimit() == 250);
    REQUIRE(ruby->getHitPoints() == 250);
    REQUIRE(ruby->getDamage() == 40);

    Rogue* den = new Rogue("Den", 150, 30);
    REQUIRE(den->getName() == "Den");
    REQUIRE(den->getHitPointsLimit() == 150);
    REQUIRE(den->getHitPoints() == 150);
    REQUIRE(den->getDamage() == 30);

    SECTION( "Rogue::takeDamage test" ) {
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

    SECTION("Rogue::takeMagicDamage test") {
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

    SECTION("Rogue::addHitPoints test") {
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

    SECTION("Rogue::attack test") {
        Rogue* enemy = new Rogue("Enemy", 100, 20);
        REQUIRE(enemy->getName() == "Enemy");
        REQUIRE(enemy->getHitPointsLimit() == 100);
        REQUIRE(enemy->getHitPoints() == 100);
        REQUIRE(enemy->getDamage() == 20);

        den->attack(enemy);
        REQUIRE(enemy->getHitPoints() == 70);
        REQUIRE(den->getHitPoints() == 150);

        den->attack(enemy);
        den->attack(enemy);
        REQUIRE(enemy->getHitPoints() == 10);
        REQUIRE(den->getHitPoints() == 150);

        try {
            den->attack(enemy);
            REQUIRE_THROWS_AS(den->attack(enemy), const OutOfHitPointsException& ex);
        }
        catch (const OutOfHitPointsException& ex) {
            REQUIRE(ex.getUnitName() + ex.what() == enemy->getName() + " is dead. Game over!");
            REQUIRE(enemy->getHitPoints() == 0);
            REQUIRE(den->getHitPoints() == 150);
        }

        try {
            enemy->attack(den);
            REQUIRE_THROWS_AS(enemy->attack(den), const OutOfHitPointsException& ex);
        }
        catch (const OutOfHitPointsException& ex) {
            REQUIRE(ex.getUnitName() + ex.what() == enemy->getName() + " is dead. Game over!");
            REQUIRE(enemy->getHitPoints() == 0);
            REQUIRE(den->getHitPoints() == 150);
        }
    }

    SECTION("Rogue::counterAttack test") {
        Rogue* enemy = new Rogue("Enemy", 100, 20);
        REQUIRE(enemy->getName() == "Enemy");
        REQUIRE(enemy->getHitPointsLimit() == 100);
        REQUIRE(enemy->getHitPoints() == 100);
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
}
