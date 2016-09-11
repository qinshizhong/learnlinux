#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char **argv)
{
    pid_t pid;

    pid = fork();
    if (pid > 0)
    {
        printf("parent process.\r\n");
//	wait(NULL);
        while (1);
    }
    else if (pid == 0)
    {
        printf("child process.\r\n");
	execv("ctermid", NULL);
//	sleep(200);
    }
    else
    {
        printf("error!\r\n");
    }


    return 0;
}
