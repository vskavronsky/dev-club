#include <catch.hpp>
#include "../state/State.h"

TEST_CASE("Test State class", "[state]") {
    State* state = new State("State", -100, -20);
    REQUIRE(state->getName() == "State");
    REQUIRE(state->getHitPointsLimit() == 0);
    REQUIRE(state->getHitPoints() == 0);
    REQUIRE(state->getDamage() == 0);

    State* den_state = new State("Dens State", 150, 30);
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
}
