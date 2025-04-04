#include "commands.h"
#include "screen.h"

#define MAX_ARGS 10

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

static void initialize_commands(char *args[]) {
    for (int i = 0; i < MAX_ARGS; i++) {
        *args[i] = -1;
    }
}

static void parse_command(char *command, char *args[]) {
    int i = 0;
    while (*command != '\0' && i < MAX_ARGS) {
        while (*command == ' ') command++;
        args[i] = command;
        i++;

        while (*command != '\0' && *command != ' ') command++;
        if (*command == ' ') {
            *command = '\0';
            command++;
        }
    }
}

void execute_command(char *command) {
    char *args[MAX_ARGS] = {};
    initialize_commands(args); // Define default value to all elements of the array
    parse_command(command, args); // Split the params
    for (struct command *cmd = __start_commands; cmd < __stop_commands; cmd++) {
        if (check_command(args[0], cmd->name)){
            if (cmd->func(args, MAX_ARGS) != 0) {
                print_string("Command can't be executed.\n");
            }
            return;
        }
    }

    print_string("\nERROR: Unknown command ");
    print_string(command);
}
