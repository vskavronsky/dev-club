#include <catch.hpp>
#include "../spell/Lightning.h"
#include "../spell/FireBall.h"
#include "../spell/Heal.h"
#include "../unit/Soldier.h"
#include "../spellcaster/Wizard.h"

TEST_CASE("Test Spell class", "[spell]") {
    Soldier* soldier = new Soldier("Soldier", 200, 40);
    REQUIRE(soldier->getName() == "Soldier");
    REQUIRE(soldier->getHitPointsLimit() == 200);
    REQUIRE(soldier->getHitPoints() == 200);
    REQUIRE(soldier->getDamage() == 40);

    Wizard* den = new Wizard("Den", 150, 30, 500);
    REQUIRE(den->getName() == "Den");
    REQUIRE(den->getHitPointsLimit() == 150);
    REQUIRE(den->getHitPoints() == 150);
    REQUIRE(den->getManaLimit() == 500);
    REQUIRE(den->getMana() == 500);
    REQUIRE(den->getDamage() == 30);
    REQUIRE(den->isBattleMagician() == true);

    Lightning* spell = new Lightning("Lightning", -70, -70);
    REQUIRE(spell->getName() == "Lightning");
    REQUIRE(spell->getActionPoints() == 0);
    REQUIRE(spell->getCost() == 0);

    FireBall* fb = new FireBall("FireBall", 40, 40);
    REQUIRE(fb->getName() == "FireBall");
    REQUIRE(fb->getActionPoints() == 40);
    REQUIRE(fb->getCost() == 40);

    Heal* heal = new Heal("Heal", 60, 60);
    REQUIRE(heal->getName() == "Heal");
    REQUIRE(heal->getActionPoints() == 60);
    REQUIRE(heal->getCost() == 60);

    fb->action(den, soldier);
    REQUIRE(soldier->getHitPoints() == 160);
    REQUIRE(den->getHitPoints() == 150);
    REQUIRE(den->getMana() == 460);

    heal->action(den, soldier);
    REQUIRE(soldier->getHitPoints() == 190);
    REQUIRE(den->getHitPoints() == 150);
    REQUIRE(den->getMana() == 400);
}
