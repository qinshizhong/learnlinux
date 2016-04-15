#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#define BUFSIZE 100

void alrm_handler(int signo);

void quit(char *p_msg, int exit_status) {
    perror(p_msg);
    exit(exit_status);
}


char buf[BUFSIZE] = "foo\0";

int main(void) {
    int n;
    if (signal(SIGALRM, alrm_handler) == SIG_ERR)
        quit("sigalrm", 1);

    fprintf(stderr, "Enter filename: ");
    alarm(5);
    n = read(STDIN_FILENO, buf, BUFSIZE);
    if (n > 1)
        printf("Filename: %s\n", buf);
    exit(0);
}


void alrm_handler(int signo) {
    signal(SIGALRM, alrm_handler);
    fprintf(stderr, "\nSignal %d received, default filename: %s\n", signo, buf);
    exit(1);
}
