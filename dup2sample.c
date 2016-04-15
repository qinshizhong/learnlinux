#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <wait.h>

#define OPENFLAGS (O_WRONLY | O_CREAT | O_TRUNC)
#define MODE600   (S_IRUSR | S_IWUSR)

void quit(char *p_msg, int exit_status) {
    perror(p_msg);
    exit(exit_status);
}


int main(int argc, char **argv) {
    int fd1, fd2, rv, exit_status;

    if (fork() == 0) {
        if ((fd1 = open(argv[1], O_RDONLY)) == -1)
            quit("Error in opening file for reading\n", 1);
        if ((fd2 = open(argv[2], OPENFLAGS, MODE600)) == -1)
            quit("Error in opening file for writing\n", 1);
        dup2(fd1, 0);
        dup2(fd2, 1);
        execvp(argv[3], &argv[3]);
        quit("exec error", 2);
    }
    else {
        wait(&rv);
        printf("Exit status:%d\n", WEXITSTATUS(rv));
    }
    
    return 0;
}
