#include <catch.hpp>
#include "../spellcaster/Wizard.h"
#include "../unit/Soldier.h"

TEST_CASE("Test Wizard class", "[wizard]") {
    Wizard* wizard = new Wizard("Wizard", -100, -20, -500);
    REQUIRE(wizard->getName() == "Wizard");
    REQUIRE(wizard->getHitPointsLimit() == 0);
    REQUIRE(wizard->getHitPoints() == 0);
    REQUIRE(wizard->getManaLimit() == 0);
    REQUIRE(wizard->getMana() == 0);
    REQUIRE(wizard->getDamage() == 0);
    REQUIRE(wizard->isBattleMagician() == true);

    Wizard* rowena = new Wizard();
    REQUIRE(rowena->getName() == "Rowena");
    REQUIRE(rowena->getHitPointsLimit() == 150);
    REQUIRE(rowena->getHitPoints() == 150);
    REQUIRE(rowena->getManaLimit() == 500);
    REQUIRE(rowena->getMana() == 500);
    REQUIRE(rowena->getDamage() == 25);
    REQUIRE(rowena->isBattleMagician() == true);

    Wizard* den = new Wizard("Den", 150, 30, 500);
    REQUIRE(den->getName() == "Den");
    REQUIRE(den->getHitPointsLimit() == 150);
    REQUIRE(den->getHitPoints() == 150);
    REQUIRE(den->getManaLimit() == 500);
    REQUIRE(den->getMana() == 500);
    REQUIRE(den->getDamage() == 30);
    REQUIRE(den->isBattleMagician() == true);

    SECTION( "Wizard::takeDamage test" ) {
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

    SECTION("Wizard::takeMagicDamage test") {
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

    SECTION("Wizard::addHitPoints test") {
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

    SECTION("Wizard::attack test") {
        Wizard* enemy = new Wizard("Enemy", 100, 20, 400);
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

    SECTION("Wizard::counterAttack test") {
        Wizard* enemy = new Wizard("Enemy", 100, 20, 400);
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

    SECTION("Wizard::addMana test") {
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

    SECTION("Wizard::spendMana test") {
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

    SECTION("Wizard::cast test") {
        Soldier* enemy = new Soldier("Enemy", 200, 30);
        REQUIRE(enemy->getName() == "Enemy");
        REQUIRE(enemy->getHitPointsLimit() == 200);
        REQUIRE(enemy->getHitPoints() == 200);
        REQUIRE(enemy->getDamage() == 30);

        den->cast(enemy);
        REQUIRE(enemy->getHitPoints() == 170);
        REQUIRE(den->getHitPoints() == 150);
        REQUIRE(den->getMana() == 470);

        den->cast(enemy);
        den->cast(enemy);
        den->cast(enemy);
        REQUIRE(enemy->getHitPoints() == 80);
        REQUIRE(den->getHitPoints() == 150);
        REQUIRE(den->getMana() == 380);

        den->changeSpell(HEAL);
        den->cast(enemy);
        REQUIRE(enemy->getHitPoints() == 105);
        REQUIRE(den->getHitPoints() == 150);
        REQUIRE(den->getMana() == 330);

        den->cast(enemy);
        den->cast(enemy);
        REQUIRE(enemy->getHitPoints() == 155);
        REQUIRE(den->getHitPoints() == 150);
        REQUIRE(den->getMana() == 230);

        enemy->takeMagicDamage(100);
        REQUIRE(enemy->getHitPoints() == 55);

        den->changeSpell(LIGHTNING);
        den->cast(enemy);
        REQUIRE(enemy->getHitPoints() == 0);
        REQUIRE(den->getHitPoints() == 150);
        REQUIRE(den->getMana() == 160);

        try {
            den->cast(enemy);
            REQUIRE_THROWS_AS(den->cast(enemy), const OutOfHitPointsException& ex);
        }
        catch (const OutOfHitPointsException& ex) {
            REQUIRE(ex.getUnitName() + ex.what() == enemy->getName() + " is dead. Game over!");
            REQUIRE(enemy->getHitPoints() == 0);
            REQUIRE(den->getHitPoints() == 150);
            REQUIRE(den->getMana() == 160);
        }
    }
}
