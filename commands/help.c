#include "help.h"
#include <screen.h>
#include <commands.h>

int help_command() {
    print_string("\nHELP command. Available commands:\n");
    print_string("help - Print all available commands\n");
    print_string("clear (num) - Clear the screen.\n");
    print_string("exit - Stops the kernel\n");
    print_string("----ARITMETIC OPERATIONS----\n");
    print_string("sum (num1) (num2) - Sums two numbers.\n");
    print_string("operation (num1) (operator) ... - Operate numbers. It does follow\nthe firts order operation, not the math one.");
    return 0;
}

__attribute__((section("commands")))
struct command help_cmd = {"help", help_command};

