#include "keyboard.h"
#include "io.h"
#include "screen.h"

#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64
#define MAX_INPUT_SIZE 80

void init_keyboard() {
}

static int get_key() {
    while (!(get_port_value(KEYBOARD_STATUS_PORT) & 1));
    int read_key = get_port_value(KEYBOARD_DATA_PORT);
    if (read_key & 0x80) return -1;
    return read_key;
}

char get_char() {
    static const char keyboard_map[] = {
        0, 0, '1', '2', '3', '4', '5', '6',
        '7', '8', '9', '0', '-', '=', -1, 0,
        'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
        0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`',
        0, '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0,
        '*', 0, ' '
    };

    int scancode = get_key();
    if (scancode == -1 || scancode >= (int)sizeof(keyboard_map)) {
        return 0;
    }
    return keyboard_map[scancode];
}

char* get_string() {
    static char string[MAX_INPUT_SIZE];
    char current = get_char();
    int i = 0;
    while (current != '\n' && i < MAX_INPUT_SIZE - 1) {
        if (current == -1) {
            if (clear_character()) string[i--] = ' ';
        } else if (current != 0) {
            string[i++] = current;
            print_char(current);
        }
        current = get_char();
    }
    string[i] = '\0';
    return string;
}
