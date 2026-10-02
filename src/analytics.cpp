#include "analytics.h"

void AnalyticsEngine::addEnergyReading(double reading)
{
    energyReadings.push_back(reading);
}

double AnalyticsEngine::calculateTotalEnergy()
{
    double total = 0.0;

    for (double reading : energyReadings)
    {
        total += reading;
    }

    return total;
}

double AnalyticsEngine::calculateAverageEnergy()
{
    if (energyReadings.empty())
    {
        return 0.0;
    }

    return calculateTotalEnergy() / energyReadings.size();
}
