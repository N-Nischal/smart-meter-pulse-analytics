#include "pulse_counter.h"

PulseCounter::PulseCounter() {
    pulseCount = 0;
}

void PulseCounter::addPulse() {
    pulseCount++;
}

int PulseCounter::getPulseCount() const {
    return pulseCount;
}
