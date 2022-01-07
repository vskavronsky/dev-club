#include <iostream>

const int LIMIT = 50;
const int LAST = LIMIT - 1;
const int BEGIN = 0;
const int ERROR = -1;

int population[LIMIT];

enum class STATE {
    ALABAMA,
    ALASKA,
    ARKANSAS
};

int getPopulation(STATE s);
int setPopulation(STATE s, int population);

int main() {
    STATE alabama = STATE::ALABAMA;
    STATE alaska = STATE::ALASKA;
    STATE arkansas = STATE::ARKANSAS;
    
    setPopulation(alabama, 2500);
    setPopulation(alaska, 4100);
    setPopulation(arkansas, 7300);
    
    std::cout << "Alabama: " << getPopulation(alabama) << std::endl;
    std::cout << "Alaska: " << getPopulation(alaska) << std::endl;
    std::cout << "Arkansas: " << getPopulation(arkansas) << std::endl;

    return 0;
}

int getPopulation(STATE s) {
    if ( static_cast<int>(s) < BEGIN || static_cast<int>(s) > LAST ) {
        return ERROR;
    }
    return population[static_cast<int>(s)];
}

int setPopulation(STATE s, int pop) {
    if ( static_cast<int>(s) < BEGIN || static_cast<int>(s) > LAST ) {
        return ERROR;
    }
    population[static_cast<int>(s)] = pop;
}
