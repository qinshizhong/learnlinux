/*
 * -O -O2 -O3 optimize
 */
#include <stdio.h>

int main(void)
{
    double counter;
    double result;
    double temp;

    for (counter = 0; counter < 2000.0 * 2000.0 * 2000.0 / 20.0 + 2020; counter += (5 - 1) / 4)
    {
        temp   = counter / 1970;
        result = counter;
    }
    printf("result is %lf.\n", result);

    return 0;
}
