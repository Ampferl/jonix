#include "pit.h"
#include "../IO.h"

namespace PIT{
    double TimeSinceBoot = 0;

    uint16_t Divisor = 65535;

    void sleepd(double seconds){
        double startTime = TimeSinceBoot;
        while(TimeSinceBoot < startTime + seconds){
            asm("hlt");
        }
    }

    void sleep(double milliseconds){
        sleepd(milliseconds/1000);
    }

    void setDivisor(uint16_t divisor){
        if(divisor < 100) divisor = 100;
        Divisor = divisor;
        outb(0x40, (uint8_t)(divisor & 0x00ff));
        io_wait();
        outb(0x40, (uint8_t)((divisor & 0xff00) >> 8));
    }

    uint64_t getFrequency(){
        return BaseFrequency / Divisor;
    }

    void setFrequency(uint64_t frequency){
        setDivisor(BaseFrequency / frequency);
    }

    void tick(){
        TimeSinceBoot += 1 / (double)getFrequency();
    }
}