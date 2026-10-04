#include "pulse_generator.h"
#include "device_driver.h"

void PulseGenerator::generatePulses(int count, DeviceDriver& driver)
{
    for (int i = 0; i < count; i++)
    {
        driver.handlePulse();
    }
}
