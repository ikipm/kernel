#include "clear.h"
#include <commands.h>
#include <screen.h>

static int strtoint(char *str) {
    int result = 0;
    while (*str){
        char c = *str;
        if ((int) c >= 48 && (int) c <= 57) result = result * 10 + (c - 48);
        str++;
    }
    return result;
}

int clear_command(char *args[], int max_args) {
    if (args[1] != " " && strtoint(args[1]) <= get_cursor_y() )slide_text(strtoint(args[1]));
    else clear_screen();
    return 0;
}

__attribute__((section("commands")))
struct command clear_cmd = {"clear", clear_command};
