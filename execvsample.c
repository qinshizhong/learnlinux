#include <stdio.h>

int main(int argc, char **argv) {
    char *cmdargs[] = {"egrep", "-i", "-n", "ben", "/etc/passwd", NULL};
   
    execv("/bin/grep", cmdargs);
    //execvp("/bin/grep", cmdargs);
    printf("execv error\n");
}
