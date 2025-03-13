#include <stdint.h>
#include "io.h"

int get_port_value(int port) {
    uint8_t result;
    // Read from port in AT&T syntax assembly
    __asm__ ("inb %%dx, %%al" : "=a" (result) : "d" (port));
    return result;
}

void set_port_value(int port, int value) {
    __asm__ ("outb %%al, %%dx": :"d" (port), "a" (value));
}
