#include <iostream>
#include "pulse_counter.h"

int main() {
    PulseCounter counter;

    counter.addPulse();
    counter.addPulse();
    counter.addPulse();

    if (counter.getPulseCount() == 3) {
        std::cout << "PulseCounter test passed" << std::endl;
        return 0;
    }

    std::cout << "PulseCounter test failed" << std::endl;
    return 1;
}
