#ifndef CASH_C_BUILTINS_H
#define CASH_C_BUILTINS_H

int cd(char **args);
int help(char **args);
int terminate(char **args);

extern int (*builtin_func[]) (char **);
extern char *builtin_str[];
extern int num_builtins;

#endif //CASH_C_BUILTINS_H
