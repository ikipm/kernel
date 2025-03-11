#include "keyboard.h"
#include "io.h"

#define SCAN_CODE_MAX  128
const char scan_to_ascii[SCAN_CODE_MAX] = {
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',  // 0x00 - 0x0E
    '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',    // 0x0F - 0x1C
    0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`',           // 0x1D - 0x29
    0, '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0, '*',        // 0x2A - 0x37
    0, ' ', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,                          // 0x38 - 0x47
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '-', 0, 0, 0, '+', 0,                        // 0x48 - 0x57
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0                                              // 0x58 - 0x63
};

#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64
#define ENTER_KEY 0x1C
#define BACKSPACE 0x0E

void init_keyboard() {
}

int get_char() {
    while (!(get_port_value(KEYBOARD_STATUS_PORT) & 1)) {
    }
    return get_port_value(KEYBOARD_STATUS_PORT);
}

void get_string(char *str) {
    int current = get_char();
    int i = 0;
    while (current != ENTER_KEY) {
        if (current == BACKSPACE) {
            // Errase element
        }
        str[i] = scan_to_ascii[current];
        current = get_char();
        i++;
    }
}
