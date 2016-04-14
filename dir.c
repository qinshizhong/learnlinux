#include <stdio.h>
#define PATH_LENGTH        200

void quit(char *p_msg, int exit_status) {
    perror(p_msg);
    exit(exit_status);
}

int main(int argc, char **argv) {
    char olddir[PATH_LENGTH + 1];
    char newdir[PATH_LENGTH + 1];

    if (getcwd(olddir, PATH_LENGTH) == -1)
        quit("getcwd", 1);
    printf("pwd:%s\n", olddir);
    
    if ((chdir(argv[1])) == -1)
        quit("chdir", 2);
    printf("cd: %s\n", argv[1]);

    getcwd(newdir, PATH_LENGTH);
    printf("pwd: %s\n", newdir);
    exit(0);
}
