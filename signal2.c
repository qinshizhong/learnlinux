#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#define PATH_LENGTH        200

void tstp_handler(int signo);
void int_handler(int signo);

int n, count;

void quit(char *p_msg, int exit_status) {
    perror(p_msg);
    exit(exit_status);
}

int main(void) {
    signal(SIGTSTP, tstp_handler);
    signal(SIGINT, int_handler);
    signal(SIGQUIT, SIG_IGN);

    fprintf(stderr, "Press [Ctrl-Z] first, then [Ctrl-C]\n");
    for (;;)
        pause();
}


void tstp_handler(int signo) {
    signal(SIGTSTP, tstp_handler);
    fprintf(stderr, "Can't stop this program\n");
}


void int_handler(int signo) {
    signal(SIGINT, int_handler);
    (++count == 1) ? printf("Press again\n") : quit("Quitting", 1);
}
