/*
 * GDB supports three functions mainly. 
 * 1: start a program.
 * 2: stop a program at a specified point.
 * 3: check status of program when it stop.

 * command list(l), break(b), info break(b), run(r), delete(d), next(n), step(s),
 * continue(c), print(p), finish, watch, quit(q)
 */


#include "stdio.h"

int main(void)
{
	int i;
	long result = 0;
	
	for (i = 1; i <= 10; ++i)
	{
		result += i;
	}
	printf("result = %ld.\n", result);

	return 0;
}
