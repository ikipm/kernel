#include "commands.h"
#include "screen.h"

extern struct command __start_commands[];
extern struct command __stop_commands[];

static int check_command(const char *command, const char *struct_command) {
    while (*command != '\0' && *struct_command != '\0') {
        if (*command != *struct_command) return 0;
        command++;
        struct_command++;
    }
    return (*command == '\0' && *struct_command == '\0');
}

void execute_command(const char *command) {
    for (struct command *cmd = __start_commands; cmd < __stop_commands; cmd++) {
        if (check_command(command, cmd->name)) {
            print_char('\n');
            cmd->func();
            return;
        }
    }

    print_string("\nERROR: Unknown command ");
    print_string(command);
}
