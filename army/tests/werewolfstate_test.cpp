#include <catch.hpp>
#include "../state/WerewolfState.h"
#include "../unit/Soldier.h"
#include "../unit/Vampire.h"

TEST_CASE("Test WerewolfState class", "[werewolfState]") {
    WerewolfState* state = new WerewolfState("State", -100, -20);
    REQUIRE(state->getName() == "State");
    REQUIRE(state->getHitPointsLimit() == 0);
    REQUIRE(state->getHitPoints() == 0);
    REQUIRE(state->getDamage() == 0);

    WerewolfState* sam = new WerewolfState();
    REQUIRE(sam->getName() == "Sam");
    REQUIRE(sam->getHitPointsLimit() == 200);
    REQUIRE(sam->getHitPoints() == 200);
    REQUIRE(sam->getDamage() == 30);

    WerewolfState* den_state = new WerewolfState("Dens State", 150, 30);
    REQUIRE(den_state->getName() == "Dens State");
    REQUIRE(den_state->getHitPointsLimit() == 150);
    REQUIRE(den_state->getHitPoints() == 150);
    REQUIRE(den_state->getDamage() == 30);

    SECTION( "State::takeDamage test" ) {
        int damage = 50;

        den_state->takeDamage(damage);
        REQUIRE(den_state->getHitPoints() == 100);
        REQUIRE(den_state->getHitPointsLimit() == 150);

        den_state->takeDamage(damage);
        REQUIRE(den_state->getHitPoints() == 50);
        REQUIRE(den_state->getHitPointsLimit() == 150);

        den_state->takeDamage(damage);
        REQUIRE(den_state->getHitPoints() == 0);
        REQUIRE(den_state->getHitPointsLimit() == 150);

        try {
            den_state->takeDamage(damage);
            REQUIRE_THROWS_AS(den_state->takeDamage(damage), const OutOfHitPointsException& ex);
        }
        catch (const OutOfHitPointsException& ex) {
            REQUIRE(ex.getUnitName() + ex.what() == den_state->getName() + " is dead. Game over!");
            REQUIRE(den_state->getHitPoints() == 0);
        }

        try {
            den_state->addHitPoints(damage);
            REQUIRE_THROWS_AS(den_state->addHitPoints(damage), const OutOfHitPointsException& ex);
        }
        catch (const OutOfHitPointsException& ex) {
            REQUIRE(ex.getUnitName() + ex.what() == den_state->getName() + " is dead. Game over!");
            REQUIRE(den_state->getHitPoints() == 0);
        }
    }

    SECTION("State::takeMagicDamage test") {
        int damage = 50;

        den_state->takeMagicDamage(damage);
        REQUIRE(den_state->getHitPoints() == 100);
        REQUIRE(den_state->getHitPointsLimit() == 150);

        den_state->takeMagicDamage(damage);
        REQUIRE(den_state->getHitPoints() == 50);
        REQUIRE(den_state->getHitPointsLimit() == 150);

        den_state->takeMagicDamage(damage);
        REQUIRE(den_state->getHitPoints() == 0);
        REQUIRE(den_state->getHitPointsLimit() == 150);

        try {
            den_state->takeMagicDamage(damage);
            REQUIRE_THROWS_AS(den_state->takeMagicDamage(damage), const OutOfHitPointsException& ex);
        }
        catch (const OutOfHitPointsException& ex) {
            REQUIRE(ex.getUnitName() + ex.what() == den_state->getName() + " is dead. Game over!");
            REQUIRE(den_state->getHitPoints() == 0);
        }

        try {
            den_state->addHitPoints(damage);
            REQUIRE_THROWS_AS(den_state->addHitPoints(damage), const OutOfHitPointsException& ex);
        }
        catch (const OutOfHitPointsException& ex) {
            REQUIRE(ex.getUnitName() + ex.what() == den_state->getName() + " is dead. Game over!");
            REQUIRE(den_state->getHitPoints() == 0);
        }
    }

    SECTION("State::addHitPoints test") {
        den_state->takeDamage(60);
        REQUIRE(den_state->getHitPoints() == 90);
        REQUIRE(den_state->getHitPointsLimit() == 150);

        den_state->addHitPoints(50);
        REQUIRE(den_state->getHitPoints() == 140);
        REQUIRE(den_state->getHitPointsLimit() == 150);

        den_state->addHitPoints(40);
        REQUIRE(den_state->getHitPoints() == 150);
        REQUIRE(den_state->getHitPointsLimit() == 150);

        den_state->addHitPoints(30);
        REQUIRE(den_state->getHitPoints() == 150);
        REQUIRE(den_state->getHitPointsLimit() == 150);
    }

    SECTION("State::isUndead test") {
        bool result = den_state->isUndead();
        REQUIRE(result == false);

        den_state->turnUndead();
        bool conclusion = den_state->isUndead();
        REQUIRE(conclusion == true);
    }

    SECTION("State::isTransformed test") {
        bool result = den_state->isTransformed();
        REQUIRE(result == false);

        den_state->setTransformed(true);
        bool conclusion = den_state->isTransformed();
        REQUIRE(conclusion == true);
    }

    SECTION("WerewolfState::scrabble test") {
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

        den_state->scrabble(soldier);
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
            den_state->scrabble(vampire);
            REQUIRE_THROWS_AS(den_state->scrabble(vampire), const CanNotTurnException& ex);
        }
        catch (const CanNotTurnException& ex) {
            REQUIRE(std::string(ex.what()) == "Vampire cannot be turned into werewolf!");
            REQUIRE(typeid(vampire_state) == typeid(State));
        }
    }

    SECTION("WerewolfState::transformToWolf test") {
        den_state->transformToWolf();
        REQUIRE(den_state->getHitPointsLimit() == 225);
        REQUIRE(den_state->getHitPoints() == 225);
        REQUIRE(den_state->getDamage() == 45);

        den_state->takeMagicDamage(50);
        REQUIRE(den_state->getHitPointsLimit() == 225);
        REQUIRE(den_state->getHitPoints() == 150);

        den_state->takeMagicDamage(40);
        REQUIRE(den_state->getHitPointsLimit() == 225);
        REQUIRE(den_state->getHitPoints() == 90);

        try {
            den_state->transformToWolf();
            REQUIRE_THROWS_AS(den_state->transformToWolf(), const CanNotTransformException& ex);
        }
        catch (const CanNotTransformException& ex) {
            REQUIRE(std::string(ex.what()) == "Werewolf in a wolf state now!");
            REQUIRE(den_state->getHitPointsLimit() == 225);
            REQUIRE(den_state->getHitPoints() == 90);
            REQUIRE(den_state->getDamage() == 45);
        }
    }
}
