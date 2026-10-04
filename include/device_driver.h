#ifndef DEVICE_DRIVER_H
#define DEVICE_DRIVER_H

class DeviceDriver
{
private:
    int pulseCount;

public:
    DeviceDriver();

    void handlePulse();
    int readPulseCount();
    void reset();
};

#endif
