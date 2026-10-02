#include <iostream>
#include "analytics.h"

int main()
{
    AnalyticsEngine analytics;

    analytics.addEnergyReading(10.5);
    analytics.addEnergyReading(20.0);
    analytics.addEnergyReading(15.5);

    std::cout << "Total Energy: "
              << analytics.calculateTotalEnergy()
              << std::endl;

    std::cout << "Average Energy: "
              << analytics.calculateAverageEnergy()
              << std::endl;

    return 0;
}
