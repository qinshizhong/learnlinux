#include <stdio.h>

int main(void) {
    execl("/usr/bin/wc", "wc", "-l", "-c", "/etc/passwd", NULL);
    //execlp("wc", "-l", "-c", "/etc/passwd", NULL);
    printf("execl error.\n");
}
