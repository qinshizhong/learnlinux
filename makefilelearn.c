#include "stdio.h"
#include "sum.h"


int main(void)
{
	int a = 123, b = 456, s = 0;

	s = sum(a, b);
	printf("sum of a and b is %d.\n", s);

	return 0;
}
