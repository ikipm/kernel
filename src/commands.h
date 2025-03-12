#ifndef COMMANDS_H
#define COMMANDS_H

struct command {
    const char *name;
    int (*func)(char **, int);
};

void execute_command(char *command);

#endif //COMMANDS_H
