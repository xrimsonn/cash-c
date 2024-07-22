#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
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
            fprintf(stderr, "cash: failed to read line");
            exit(ERROR);
        }
    }
    return line;
}

char **tokenize(char *line) {
    int bufsz = CASH_TOK_BUFSIZE;
    int position = 0;
    char **tokens = malloc(bufsz * sizeof(char *));
    char *token;

    if (tokens == NULL) {
        fprintf(stderr, "cash: allocation error");
        exit(ERROR);
    }

    token = strtok(line, CASH_TOK_DELIM);

    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position >= bufsz) {
            bufsz += CASH_TOK_BUFSIZE;
            tokens = realloc(tokens, bufsz * sizeof(char*));
            if (tokens == NULL) {
                fprintf(stderr, "cash: re-allocation error\n");
                exit(ERROR);
            }

        }

        token = strtok(NULL, CASH_TOK_DELIM);
    }

    tokens[position] = NULL;
    return tokens;
}

int launch(char **args) {
    pid_t pid;
    pid_t wpid;
    int status;

    pid = fork();
    // Child
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "cash: forking error\n");
        }
        exit(ERROR);
    } else if (pid < 0) {
        fprintf(stderr, "cash: forking error\n");
        exit(ERROR);
    // Parent
    } else {
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

int exec(char **args) {
    // TODO
}
