#include "device_driver.h"

DeviceDriver::DeviceDriver()
{
    pulseCount = 0;
}

void DeviceDriver::handlePulse()
{
    pulseCount++;
}

int DeviceDriver::readPulseCount()
{
    return pulseCount;
}

void DeviceDriver::reset()
{
    pulseCount = 0;
}
