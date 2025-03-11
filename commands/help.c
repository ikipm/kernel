#include "help.h"
#include <screen.h>
#include <commands.h>

int help_command() {
    print_string("HELP command. Available commands:\n");
    print_string("help - Print all available commands\n");
    print_string("exit - Stops the kernel\n");
    print_string("echo (Future)");
    return 0;
}

__attribute__((section("commands")))
struct command help_cmd = {"help", help_command};

