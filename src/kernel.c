#include "screen.h"
#include "io.h"
#include "keyboard.h"

extern void main() {
    clear_screen();
    print_string("Kernel started\n");
    change_color(0x0A, 0x00);
    print_string("Write a command. If you need help type /help\n");
    print_string("You input: ");
    char *str;
    get_string(str);
    print_string(str);

    while (1);  // Keep kernel active
}
