#include <unistd.h>
#include <stdio.h>


void quit(char *p_msg, int exit_status) {
    perror(p_msg);
    exit(exit_status);
}


int main(void) {
    int fd[2];
    char buf[200];
    int n;

    if(pipe(fd) < 0)
        quit("pipe", 1);
    switch (fork()) {
        case -1: quit("fork", 2); break;
        case 0: close(fd[1]);
                n = read(fd[0], buf, 100);
                write(STDOUT_FILENO, buf, n);
                break;
        default: close(fd[0]);
                 write(fd[1], "Writing to pipe\n", 16);
                 break;
    }

    return 0;
}
