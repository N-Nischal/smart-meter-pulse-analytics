#ifndef ENERGY_CALCULATOR_H
#define ENERGY_CALCULATOR_H

class EnergyCalculator {
private:
    double conversionFactor;

public:
    EnergyCalculator(double factor);

    double calculateEnergy(int pulseCount) const;
};

#endif
