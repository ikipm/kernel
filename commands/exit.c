#include "exit.h"
#include <commands.h>
#include <screen.h>

int exit_command() {
    print_string("Shutting down the kernel...\n");
    print_string("Bye :)");
    __asm__ ("hlt");
    return 0;
}

__attribute__((section("commands")))
struct command exit_cmd = {"exit", exit_command};
