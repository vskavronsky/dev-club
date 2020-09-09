#include "unit/Vampire.h"
#include "unit/Soldier.h"
#include "spellcaster/Wizard.h"
#include "spellcaster/Priest.h"

int main() {
    try {
        Vampire* john = new Vampire("John", 300, 50);

        Soldier* bob = new Soldier("Bob", 200, 40);
        Wizard* mike = new Wizard("Mike", 150, 30, 200);

        std::cout << john << std::endl;
        std::cout << "\n";
        std::cout << bob << std::endl;
        std::cout << "\n";
        std::cout << mike << std::endl;
        std::cout << "\n";

        john->bite(bob);
        john->bite(mike);

        std::cout << john << std::endl;
        std::cout << "\n";
        std::cout << bob << std::endl;
        std::cout << "\n";
        std::cout << mike << std::endl;

        delete mike;
        delete bob;
    }
    catch (const OutOfHitPointsException ex) {
        std::cout << "UnitIsDead!" << std::endl;
    }
    catch (const OutOfManaException ex) {
        std::cout << "Not enough mana for cast!" << std::endl;
    }
    catch (const InvalidAddHitPointsException ex) {
        std::cout << "Priest cannot heal undead!" << std::endl;
    }

    return 0;
}
