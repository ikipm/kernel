#include <stdint.h>
#include "io.h"

int get_port_value(int port) {
    uint8_t result;
    __asm__ ("inb %1, %0" : "=a"(result) : "Nd"(port));
    return result;
}
