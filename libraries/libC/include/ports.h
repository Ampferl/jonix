#ifndef _PORTS_H
#define _PORTS_H

#include <stdint.h>

static inline uint16_t inw(uint16_t _port)
{
    uint16_t result;
    __asm__ volatile("inw %1, %0"
                     : "=a"(result)
                     : "Nd"(_port));
    return result;
}

static inline uint8_t inb(uint16_t _port)
{
    uint8_t result;
    __asm__ volatile("inb %1, %0"
                     : "=a"(result)
                     : "Nd"(_port));
    return result;
}

static inline uint32_t inl(uint16_t _port)
{
    uint32_t result;
    __asm__ volatile("inl %1, %0"
                     : "=a"(result)
                     : "Nd"(_port));
    return result;
}

static inline void outw(uint16_t _port, uint16_t _data)
{
    __asm__ volatile("outw %0, %1"
                     :
                     : "a"(_data), "Nd"(_port));
}

static inline void outb(uint16_t _port, uint8_t _data)
{
    __asm__ volatile("outb %0, %1"
                     :
                     : "a"(_data), "Nd"(_port));
}

static inline void outl(uint16_t _port, uint32_t _data)
{
    __asm__ volatile("outl %0, %1"
                     :
                     : "a"(_data), "Nd"(_port));
}

static inline void outb_wait(uint16_t _port, uint8_t _data)
{
    __asm__ volatile("outb %0, %1\njmp 1f\n1: jmp 1f\n1:"
                     :
                     : "a"(_data), "Nd"(_port));
}

#endif