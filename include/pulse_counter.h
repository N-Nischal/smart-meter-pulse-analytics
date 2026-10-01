#ifndef PULSE_COUNTER_H
#define PULSE_COUNTER_H

class PulseCounter {
private:
    int pulseCount;

public:
    PulseCounter();

    void addPulse();

    int getPulseCount() const;
};

#endif
