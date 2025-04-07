#include "clear.h"
#include <commands.h>
#include <screen.h>
#include <functions.h>

int clear_command(char *args[], int i) {
    if (is_number(args[1])) return 1;

    if (str_to_int(args[1]) != 0 && str_to_int(args[1]) <= get_cursor_y() )slide_text(str_to_int(args[1]));
    else clear_screen();
    return 0;
}

__attribute__((section("commands")))
struct command clear_cmd = {"clear", clear_command};
