#include <unistd.h>
#include <pwd.h>
#include <string.h>
#include <malloc.h>
#include "utils.h"

char *get_user_name(void) {
    const struct passwd* pw = getpwuid(geteuid());
    return pw == NULL ? NULL : pw->pw_name;
}

void go_to_user_home(void) {
    char *user_name = get_user_name();
    char *home = "/home/";
    char* path = malloc(strlen(user_name) + strlen(home));

    strcpy(path, home);
    strcat(path, user_name);

    if (chdir(path) != 0) {
        fprintf(stderr, "cash: failed to change directory\n");
    }

    free(path);
}
