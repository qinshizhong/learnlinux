#include <stdio.h>
#include <sys/types.h>
#define PATH_LENGTH 300


int main(void) {
    pid_t pid;
    int x = 100;
    char newdir[PATH_LENGTH + 1];

    getcwd(newdir, PATH_LENGTH);
    printf("BEFORE FORK -- Current directory: %s\n", newdir);

    pid = fork();
    switch (pid) {
        case -1:
            perror("fork");
            exit(1);
        case 0:
            printf("CHILD -- inherite value of x: %d\n", x);
            x = 200;
            printf("CHILD -- changed value of x: %d\n", x);
            printf("CHILD -- inherite value of PATH: %s\n", getenv("PATH"));
            //setenv("PATH", ".", 1);
            putenv("PATH=.");
            printf("CHILD -- new value of PATH: %s\n", getenv("PATH"));
            if (chdir("/etc") != -1) {
                getcwd(newdir, PATH_LENGTH);
                printf("CHILD -- Current directory changed to: %s\n", newdir);
            }
            break;
            exit(0);
        default:
            sleep(2);
            getcwd(newdir, PATH_LENGTH);
            printf("PARENT -- value of x after change by child: %d\n", x);
            printf("PARENT -- current directory is still: %s\n", newdir);
            printf("PARENT -- valude of PATH is unchanged: %s\n", getenv("PATH"));
            exit(0);
    }
}
