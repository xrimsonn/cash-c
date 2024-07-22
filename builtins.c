#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <malloc.h>
#include "builtins.h"
#include "constants.h"
#include "utils.h"

int (*builtin_func[])(char **) = {&cd, &help, &terminate};

char *builtin_str[] = {"cd", "help", "exit"};

int num_builtins = sizeof(builtin_str) / sizeof(char *);

int cd(char **args) {
    if (args[1] == NULL || strcmp(args[1], "~") == 0) {
        go_to_user_home();
    } else {
        if (chdir(args[1]) != 0) {
            fprintf(stderr, "cash: failed to change directory\n");
        }
    }
    return AWAIT_INPUT;
}

int help(char **args) {
    int i;
    printf("Carlos and Antonio's Shell (CASH)\n");
    printf("Built in commands:\n");

    for (i = 0; i < num_builtins; i++) {
        printf("  %s\n", builtin_str[i]);
    }

    printf("Have fun :)\n");
    return AWAIT_INPUT;
}

int terminate(char **args) {
    printf("Bye.\n");
    return SUCCESS;
}