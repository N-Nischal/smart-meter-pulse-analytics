#ifndef DATA_LOGGER_H
#define DATA_LOGGER_H

#include <string>

class DataLogger {
private:
    std::string filename;

public:
    DataLogger(const std::string& file);

    bool logReading(int pulseCount, double energy);
};

#endif
