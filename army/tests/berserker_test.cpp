#include <catch.hpp>
#include "../unit/Berserker.h"

TEST_CASE("Test Berserker class", "[berserker]") {
    Berserker* berserker = new Berserker("Berserker", -100, -20);
    REQUIRE(berserker->getName() == "Berserker");
    REQUIRE(berserker->getHitPointsLimit() == 0);
    REQUIRE(berserker->getHitPoints() == 0);
    REQUIRE(berserker->getDamage() == 0);

    Berserker* bobby = new Berserker();
    REQUIRE(bobby->getName() == "Bobby");
    REQUIRE(bobby->getHitPointsLimit() == 250);
    REQUIRE(bobby->getHitPoints() == 250);
    REQUIRE(bobby->getDamage() == 40);

    Berserker* den = new Berserker("Den", 150, 30);
    REQUIRE(den->getName() == "Den");
    REQUIRE(den->getHitPointsLimit() == 150);
    REQUIRE(den->getHitPoints() == 150);
    REQUIRE(den->getDamage() == 30);

    SECTION( "Berserker::takeDamage test" ) {
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

    SECTION("Berserker::takeMagicDamage test") {
        int damage = 50;

        den->takeMagicDamage(damage);
        REQUIRE(den->getHitPoints() == 150);
        REQUIRE(den->getHitPointsLimit() == 150);

        den->takeMagicDamage(damage);
        REQUIRE(den->getHitPoints() == 150);
        REQUIRE(den->getHitPointsLimit() == 150);

    }

    SECTION("Berserker::addHitPoints test") {
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

    SECTION("Berserker::attack test") {
        Berserker* enemy = new Berserker("Enemy", 100, 20);
        REQUIRE(enemy->getName() == "Enemy");
        REQUIRE(enemy->getHitPointsLimit() == 100);
        REQUIRE(enemy->getHitPoints() == 100);
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

    SECTION("Berserker::counterAttack test") {
        Berserker* enemy = new Berserker("Enemy", 100, 20);
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
