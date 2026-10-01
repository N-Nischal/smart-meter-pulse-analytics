#include <iostream>
#include "energy_calculator.h"

int main() {
    EnergyCalculator calculator(1.0);

    double energy = calculator.calculateEnergy(10);

    if (energy == 10.0) {
        std::cout << "EnergyCalculator test passed" << std::endl;
        return 0;
    }

    std::cout << "EnergyCalculator test failed" << std::endl;
    return 1;
}
