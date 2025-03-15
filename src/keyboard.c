#include "keyboard.h"
#include "io.h"
#include "screen.h"

#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64
#define MAX_INPUT_SIZE 80

// Uppercase
#define SHIFT_LEFT 0x2A
#define SHIFT_RIGHT 0x36
#define CAPS_LOCK 0x3A
static int shift_pressed = 0;
static int caps_pressed = 0;

static int get_key() {
    while (!(gpvh(KEYBOARD_STATUS_PORT) & 1));
    const int read_key = gpvh(KEYBOARD_DATA_PORT);
    if (read_key & 0x80) {
        // In case of shift being released, return to lowercase
        if (read_key == (SHIFT_LEFT | 0x80) || read_key == (SHIFT_RIGHT | 0x80)) {
            shift_pressed = 0;
        }
        return -1;
    }

    // Uppercase keys
    if (read_key == SHIFT_LEFT || read_key == SHIFT_RIGHT) {
        shift_pressed = 1;
        return -1;
    }
    if (read_key == CAPS_LOCK) {
        caps_pressed = !caps_pressed;
        return -1;
    }

    return read_key;
}

char get_char() {
    static const char lowercase_map[] = {
        0, 0, '1', '2', '3', '4', '5', '6',
        '7', '8', '9', '0', '-', '=', -1, 0,
        'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
        0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`',
        0, '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0,
        '*', 0, ' '
    };

    static const char uppercase_map[] = {
        0, 0, '!', '@', '#', '$', '%', '^',
        '&', '*', '(', ')', '_', '+', -1, 0,
        'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '{', '}', '\n',
        0, 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ':', '"', '~',
        0, '|', 'Z', 'X', 'C', 'V', 'B', 'N', 'M', '<', '>', '?', 0,
        '*', 0, ' '
    };

    int scancode = get_key();
    if (scancode == -1 || scancode >= (int)sizeof(lowercase_map)) {
        return 0;
    }

    // In case of uppercase, return the uppercase value. Otherwise, return the lowercase.
    int use_uppercase = (shift_pressed ^ caps_pressed);
    return use_uppercase ? uppercase_map[scancode] : lowercase_map[scancode];
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
