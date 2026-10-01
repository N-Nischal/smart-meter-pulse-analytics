#include <iostream>
#include "data_logger.h"

int main() {
    DataLogger logger("data/test_meter_readings.csv");

    if (logger.logReading(10, 10.0)) {
        std::cout << "DataLogger test passed" << std::endl;
        return 0;
    }

    std::cout << "DataLogger test failed" << std::endl;
    return 1;
}
