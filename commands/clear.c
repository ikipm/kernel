#include "clear.h"
#include <commands.h>
#include <screen.h>

int clear_command() {
    clear_screen();
    return 0;
}

__attribute__((section("commands")))
struct command clear_cmd = {"clear", clear_command};
