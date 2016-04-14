#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;

	pid = fork();
	if (pid < 0)
	{
		printf("error in fork!\n");
	}
	else if (0 == pid)
	{	
		printf("I am the child process, ID is %d.!\n", getpid());
	}
	else
	{		
		printf("I am the parent process, ID is %d.!\n", getpid());
                sleep(2);
	}

	return 0;
}
