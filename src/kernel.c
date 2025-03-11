#include "screen.h"
#include "io.h"
#include "keyboard.h"
#include "commands.h"

extern void main() {
    clear_screen();
    print_string("Kernel started\n");
    //change_color(0x0A, 0x00);
    print_string("Write a command. If you need help type /help\n");
    while (1) {
        print_char('>');
        execute_command(get_string());
        print_string("\n");
    }
}
