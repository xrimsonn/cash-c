#include <stdio.h>
#include <stdlib.h>
#include "cash.h"

void cash_init(void) {
    char *line;
    char **args;
    int status;

    do {
        printf("& ");
        line = read_line();
        args = tokenize(line);
        status = exec(args);

        free(line);
        free(args);
    } while (status);
}

char *read_line(void) {
    // TODO
}

char **tokenize(char *line) {
    // TODO
}

int exec(char **args) {
    // TODO
}