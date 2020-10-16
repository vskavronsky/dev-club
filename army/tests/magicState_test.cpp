#include <catch.hpp>
#include "../state/MagicState.h"

TEST_CASE("Test MagicState class", "[magicState]") {
    MagicState* magicState = new MagicState(-100, true);
    REQUIRE(magicState->getManaLimit() == 0);
    REQUIRE(magicState->getMana() == 0);
    REQUIRE(magicState->isBattleMagician() == true);

    MagicState* den_state = new MagicState(500, true);
    REQUIRE(den_state->getManaLimit() == 500);
    REQUIRE(den_state->getMana() == 500);
    REQUIRE(den_state->isBattleMagician() == true);

    SECTION("MagicState::addMana test") {
        den_state->spendMana(300);
        REQUIRE(den_state->getMana() == 200);
        REQUIRE(den_state->getManaLimit() == 500);

        den_state->addMana(100);
        REQUIRE(den_state->getMana() == 300);
        REQUIRE(den_state->getManaLimit() == 500);

        den_state->addMana(150);
        REQUIRE(den_state->getMana() == 450);
        REQUIRE(den_state->getManaLimit() == 500);

        den_state->addMana(100);
        REQUIRE(den_state->getMana() == 500);
        REQUIRE(den_state->getManaLimit() == 500);

        den_state->addMana(50);
        REQUIRE(den_state->getMana() == 500);
        REQUIRE(den_state->getManaLimit() == 500);
    }

    SECTION("MagicState::spendMana test") {
        den_state->spendMana(100);
        REQUIRE(den_state->getMana() == 400);
        REQUIRE(den_state->getManaLimit() == 500);

        den_state->spendMana(100);
        den_state->spendMana(250);
        REQUIRE(den_state->getMana() == 50);
        REQUIRE(den_state->getManaLimit() == 500);

        try {
            den_state->spendMana(75);
            REQUIRE_THROWS_AS(den_state->spendMana(75), const OutOfManaException& ex);
        }
        catch (const OutOfManaException& ex) {
            REQUIRE(std::string(ex.what()) == "Not enough mana for cast!");
            REQUIRE(den_state->getMana() == 50);
            REQUIRE(den_state->getManaLimit() == 500);
        }
    }
}
