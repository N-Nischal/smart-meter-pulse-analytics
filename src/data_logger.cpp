#include "data_logger.h"
#include <fstream>

DataLogger::DataLogger(const std::string& file) {
    filename = file;
}

bool DataLogger::logReading(int pulseCount, double energy) {
    std::ofstream file(filename, std::ios::app);

    if (!file.is_open()) {
        return false;
    }

    file << pulseCount << "," << energy << std::endl;

    file.close();
    return true;
}
