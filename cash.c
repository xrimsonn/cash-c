#include <stdio.h>
#include <stdlib.h>
#include "cash.h"
#include "constants.h"

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
    char * line= NULL;
    size_t bufsz = 0;
    if (getline(&line, &bufsz, stdin)) {
        if (feof(stdin)) {
            exit(SUCCESS);
        } else {
            perror("Failed to read line");
            exit(ERROR);
        }
    }
    return line;
}

char **tokenize(char *line) {
    // TODO
}

int exec(char **args) {
    // TODO
}