#include <stdio.h>
#include <termios.h>


int main(int argc, char **argv)
{
    printf("tty = %s\n", ctermid(NULL));

    return 0;
}
