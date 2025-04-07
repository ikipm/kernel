#ifndef COMMANDS_H
#define COMMANDS_H

struct command {
    const char *name;
    int (*func)(char **args, int i);
};

void execute_command(char *command);

#endif //COMMANDS_H
