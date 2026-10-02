#include <iostream>
#include "pulse_counter.h"
#include "energy_calculator.h"
#include "analytics.h"
#include "data_logger.h"

int main()
{
    PulseCounter counter;

    int pulses;

    std::cout << "Enter number of pulses: ";
    std::cin >> pulses;

    for (int i = 0; i < pulses; i++)
    {
        counter.addPulse();
    }

    int pulseCount = counter.getPulseCount();

    EnergyCalculator calculator(0.001);
    double energy = calculator.calculateEnergy(pulseCount);

    AnalyticsEngine analytics;
    analytics.addEnergyReading(energy);

    DataLogger logger("energy_log.txt");
    logger.logReading(pulseCount, energy);

    std::cout << "\nPulse Count: " << pulseCount << std::endl;
    std::cout << "Energy Consumed: " << energy << " kWh" << std::endl;
    std::cout << "Total Energy: "
              << analytics.calculateTotalEnergy()
              << " kWh" << std::endl;
    std::cout << "Average Energy: "
              << analytics.calculateAverageEnergy()
              << " kWh" << std::endl;

    return 0;
}
