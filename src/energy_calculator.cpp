#include "energy_calculator.h"

EnergyCalculator::EnergyCalculator(double factor) {
    conversionFactor = factor;
}

double EnergyCalculator::calculateEnergy(int pulseCount) const {
    return pulseCount * conversionFactor;
}
