#include <stdint.h>
#include "io.h"

uint8_t gpvh(uint16_t port) {
    uint8_t result;
    // Read from port in AT&T syntax assembly
    __asm__ volatile ("inb %1, %0" : "=a" (result) : "Nd" (port));
    return result;
}

uint16_t gpvw(uint16_t port) {
    uint16_t result;
    // Read from port in AT&T syntax assembly
    __asm__ volatile ("inw %1, %0" : "=a" (result) : "Nd" (port));
    return result;
}

uint32_t gpvl(uint16_t port) {
    uint32_t result;
    // Read from port in AT&T syntax assembly
    __asm__ volatile ("inl %1, %0" : "=a" (result) : "Nd" (port));
    return result;
}

void spvh(uint16_t port, uint8_t value) {
    // Write in a port in AT&T syntax assembly
    __asm__ volatile ("outb %1, %0": :"Nd" (port), "a" (value));
}

void spvw(uint16_t port, uint16_t value) {
    // Write in a port in AT&T syntax assembly
    __asm__ volatile ("outw %1, %0": :"Nd" (port), "a" (value));
}

void spvl(uint16_t port, uint32_t value) {
    // Write in a port in AT&T syntax assembly
    __asm__ volatile ("outl %1, %0": :"Nd" (port), "a" (value));
}
