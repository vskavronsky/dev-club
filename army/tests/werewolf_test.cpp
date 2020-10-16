#include <catch.hpp>
#include "../unit/Werewolf.h"
#include "../unit/Soldier.h"
#include "../unit/Vampire.h"

TEST_CASE("Test Werewolf class", "[werewolf]") {
    Werewolf* werewolf = new Werewolf("Werewolf", -100, -20);
    REQUIRE(werewolf->getName() == "Werewolf");
    REQUIRE(werewolf->getHitPointsLimit() == 0);
    REQUIRE(werewolf->getHitPoints() == 0);
    REQUIRE(werewolf->getDamage() == 0);

    Werewolf* sam = new Werewolf();
    REQUIRE(sam->getName() == "Sam");
    REQUIRE(sam->getHitPointsLimit() == 250);
    REQUIRE(sam->getHitPoints() == 250);
    REQUIRE(sam->getDamage() == 40);

    Werewolf* den = new Werewolf("Den", 150, 30);
    REQUIRE(den->getName() == "Den");
    REQUIRE(den->getHitPointsLimit() == 150);
    REQUIRE(den->getHitPoints() == 150);
    REQUIRE(den->getDamage() == 30);

    SECTION( "Werewolf::takeDamage test" ) {
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

    SECTION("Werewolf::takeMagicDamage test") {
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

    SECTION("Werewolf::addHitPoints test") {
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

    SECTION("Werewolf::attack test") {
        Werewolf* enemy = new Werewolf("Enemy", 100, 20);
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

    SECTION("Werewolf::counterAttack test") {
        Werewolf* enemy = new Werewolf("Enemy", 100, 20);
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

    SECTION("Werewolf::scrabble test") {
        Soldier* soldier = new Soldier("Soldier", 110, 20);
        REQUIRE(soldier->getName() == "Soldier");
        REQUIRE(soldier->getHitPointsLimit() == 110);
        REQUIRE(soldier->getHitPoints() == 110);
        REQUIRE(soldier->getDamage() == 20);

        Vampire* vampire = new Vampire("Vampire", 120, 40);
        REQUIRE(vampire->getName() == "Vampire");
        REQUIRE(vampire->getHitPointsLimit() == 120);
        REQUIRE(vampire->getHitPoints() == 120);
        REQUIRE(vampire->getDamage() == 40);

        den->scrabble(soldier);
        State& soldier_state = *(soldier->getState());
        REQUIRE(typeid(soldier_state) == typeid(WerewolfState));
        REQUIRE(soldier->getName() == "Sam");
        REQUIRE(soldier->getHitPointsLimit() == 200);
        REQUIRE(soldier->getHitPoints() == 200);
        REQUIRE(soldier->getDamage() == 30);

        dynamic_cast<WerewolfState*>(soldier->getState())->transformToWolf();
        REQUIRE(soldier->getHitPointsLimit() == 300);
        REQUIRE(soldier->getHitPoints() == 300);
        REQUIRE(soldier->getDamage() == 45);

        State& vampire_state = *(vampire->getState());
        try {
            den->scrabble(vampire);
            REQUIRE_THROWS_AS(den->scrabble(vampire), const CanNotTurnException& ex);
        }
        catch (const CanNotTurnException& ex) {
            REQUIRE(std::string(ex.what()) == "Vampire cannot be turned into werewolf!");
            REQUIRE(typeid(vampire_state) == typeid(State));
        }
    }

    SECTION("Werewolf::transformToWolf test") {
        den->transformToWolf();
        REQUIRE(den->getHitPointsLimit() == 225);
        REQUIRE(den->getHitPoints() == 225);
        REQUIRE(den->getDamage() == 45);

        den->takeMagicDamage(50);
        REQUIRE(den->getHitPointsLimit() == 225);
        REQUIRE(den->getHitPoints() == 150);

        den->takeMagicDamage(40);
        REQUIRE(den->getHitPointsLimit() == 225);
        REQUIRE(den->getHitPoints() == 90);

        try {
            den->transformToWolf();
            REQUIRE_THROWS_AS(den->transformToWolf(), const CanNotTransformException& ex);
        }
        catch (const CanNotTransformException& ex) {
            REQUIRE(std::string(ex.what()) == "Werewolf in a wolf state now!");
            REQUIRE(den->getHitPointsLimit() == 225);
            REQUIRE(den->getHitPoints() == 90);
            REQUIRE(den->getDamage() == 45);
        }
    }
}
