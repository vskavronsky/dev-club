#include <iostream>
#include "Date.hpp"
#include "Passport.hpp"

int main() {
    try {
        Date* date = new Date(28, 11, 2002);
        Date* date2 = new Date(3, 1, 2000);
        Date* date3 = new Date(14, 6, 1988);
        Date* date4 = new Date(8, 4, 2001);
        Date* date5 = new Date(19, 3, 1976);
        Date* date6 = new Date(27, 2, 1994);

        Passport* mike = new Passport("Mike", "Smith", date);
        Passport* bob = new Passport("Bob", "Alexovich", date2);
        Passport* duck = new Passport("Duck", "Huge", date3);

        Passport::getAllPassports();
        std::cout << "Total Passports: " << Passport::getTotalPassports() << std::endl;

        Passport::setNewSeries("BC", 385076);

        Passport* alex = new Passport("Alex", "BOSS", date4);
        Passport* vova = new Passport("Vova", "Lviv", date5);
        Passport* arthur = new Passport("Arthur", "Allmight", date6);

        Passport::getAllPassports();
        std::cout << "Total Passports: " << Passport::getTotalPassports() << std::endl;

        delete mike;
        mike = nullptr;

        delete bob;
        bob = nullptr;

        delete duck;
        duck = nullptr;

        delete alex;
        alex = nullptr;

        delete vova;
        vova = nullptr;

        delete arthur;
        arthur = nullptr;

    } catch (const InvalidDate& ex) {
        std::cout << ex.what() << std::endl;
    } catch (const ReachedLimit& ex) {
        std::cout << ex.what() << std::endl;
    } catch (const SeriesLengthExceeded& ex) {
        std::cout << ex.what() << std::endl;
    } catch (const InvalidUpperCase& ex) {
        std::cout << ex.what() << std::endl;
    } catch (const InvalidNewSeries& ex) {
        std::cout << ex.what() << std::endl;
    } catch (const InvalidPassportNumber& ex) {
        std::cout << ex.what() << std::endl;
    } catch (const PassportNotFound& ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}
