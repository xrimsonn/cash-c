#ifndef CASH_C_CASH_H
#define CASH_C_CASH_H

void cash_init(void);
char *read_line(void);
char **tokenize(char *line);
int exec(char **args);

#endif //CASH_C_CASH_H
