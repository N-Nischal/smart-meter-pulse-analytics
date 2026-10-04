#include <iostream>
#include <iomanip>
#include "pulse_counter.h"
#include "energy_calculator.h"
#include "analytics.h"
#include "data_logger.h"
#include "pulse_generator.h"
#include "device_driver.h"
#include <string>

int main()
{
    PulseCounter counter;

    int pulses;
    double measurementTime;

    std::cout << "========================================" << std::endl;
    std::cout << "          SMART ENERGY METER" << std::endl;
    std::cout << "========================================" << std::endl;

    std::cout << "\nStarting meter simulation..." << std::endl;
    std::cout << "\nEnter pulse count: ";
    std::cin >> pulses;

    if (std::cin.fail() || pulses < 0)
{
    std::cout << "Invalid pulse count." << std::endl;
    return 1;
}

    std::cout << "Enter measurement time (hours): ";
    std::cin >> measurementTime;

    if (std::cin.fail() || measurementTime <= 0)
{
    std::cout << "Invalid measurement time." << std::endl;
    return 1;
}
    DeviceDriver driver;
    PulseGenerator generator;

    generator.generatePulses(pulses, driver);

    int generatedPulses = driver.readPulseCount();

    for (int i = 0; i < generatedPulses; i++)
{
    counter.addPulse();
}

int pulseCount = counter.getPulseCount();

    EnergyCalculator calculator(0.001);
    double energy = calculator.calculateEnergy(pulseCount);

    double averagePower = (energy / measurementTime) * 1000.0;
    double electricityRate = 8.00;     
    double estimatedCost = energy * electricityRate;
   std::string usageStatus;

if (averagePower < 500)
{
    usageStatus = "NORMAL";
}
else if (averagePower <= 1000)
{
    usageStatus = "HIGH";
}
else
{
    usageStatus = "VERY HIGH";
}
    AnalyticsEngine analytics;
    analytics.addEnergyReading(energy);

    DataLogger logger("logs/meter.log");
    logger.logReading(pulseCount, energy);

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "\n        ENERGY METER ANALYTICS" << std::endl;
    std::cout << "\nPulse Count       : " << pulseCount << std::endl;
    std::cout << "Energy Used       : " << energy << " kWh" << std::endl;
    std::cout << "Time Measured     : " << measurementTime << " hour" << std::endl;
    std::cout << "Average Power     : " << averagePower << " W" << std::endl;
    std::cout << "Rate              : ₹" << electricityRate << " / kWh" << std::endl;
    std::cout << "Estimated Cost    : ₹" << estimatedCost << std::endl;
    std::cout << "Usage Status      : " << usageStatus << std::endl;
    std::cout << "\nLog File          : logs/meter.log" << std::endl;
    std::cout << "Reading Status    : SAVED" << std::endl;
    std::cout << "\nMeter Status      : RUNNING" << std::endl;
 return 0;
}
