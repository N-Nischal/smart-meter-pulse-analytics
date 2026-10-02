#ifndef ANALYTICS_H
#define ANALYTICS_H

#include <vector>

class AnalyticsEngine {
private:
    std::vector<double> energyReadings;

public:
    void addEnergyReading(double reading);
    double calculateTotalEnergy();
    double calculateAverageEnergy();
};

#endif
