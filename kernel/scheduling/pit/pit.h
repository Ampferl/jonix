#pragma once
#include <stdint.h>

namespace PIT{
    extern double TimeSinceBoot;
    const uint64_t BaseFrequency = 1193182;

    void sleepd(double seconds);
    void sleep(double milliSeconds);

    void setDivisor(uint16_t divisor);
    uint64_t getFrequency();
    void setFrequency(uint64_t frequency);
    void tick();
}