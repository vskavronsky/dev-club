#include "unit/Vampire.h"
#include "unit/Soldier.h"
#include "unit/Berserker.h"
#include "unit/Werewolf.h"
#include "spellcaster/Wizard.h"
#include "spellcaster/Priest.h"
#include "spellcaster/Warlock.h"
#include "spellcaster/Necromancer.h"

int main() {
    try {
        Soldier* bob = new Soldier("Bob", 100, 100);
        Wizard* mike = new Wizard("Mike", 100, 100, 500);
        Necromancer* amara = new Necromancer("Amara", 300, 50, 500);

        std::cout << bob << std::endl;
        std::cout << "\n";
        std::cout << mike << std::endl;
        std::cout << "\n";
        std::cout << amara << std::endl;
        std::cout << "\n";

        amara->attack(bob);
        amara->attack(mike);

        std::cout << bob << std::endl;
        std::cout << "\n";
        std::cout << mike << std::endl;
        std::cout << "\n";
        std::cout << amara << std::endl;
        std::cout << "\n";

        try {
            amara->attack(bob);
        }
        catch (const OutOfHitPointsException& ex) {
            std::cout << ex.getUnitName() << ex.what() << std::endl;
        }

        try {
            amara->attack(mike);
        }
        catch (const OutOfHitPointsException& ex) {
            std::cout << ex.getUnitName() << ex.what() << std::endl;
        }

        std::cout << "\n";
        std::cout << bob << std::endl;
        std::cout << "\n";
        std::cout << mike << std::endl;
        std::cout << "\n";
        std::cout << amara << std::endl;
        std::cout << "\n";

        try {
            amara->attack(bob);
        }
        catch (const OutOfHitPointsException& ex) {
            std::cout << ex.getUnitName() << ex.what() << std::endl;
        }

        std::cout << "\n";
        std::cout << bob << std::endl;
        std::cout << "\n";
        std::cout << mike << std::endl;
        std::cout << "\n";
        std::cout << amara << std::endl;
        std::cout << "\n";

        try {
            bob->attack(amara);
        }
        catch (const OutOfHitPointsException& ex) {
            std::cout << ex.getUnitName() << ex.what() << std::endl;
        }

        std::cout << "\n";
        std::cout << bob << std::endl;
        std::cout << "\n";
        std::cout << mike << std::endl;
        std::cout << "\n";
        std::cout << amara << std::endl;
        std::cout << "\n";

        delete bob;
        delete mike;
        delete amara;
    }
    catch (const OutOfHitPointsException& ex) {
        std::cout << ex.getUnitName() << ex.what() << std::endl;
    }

    return 0;
}
