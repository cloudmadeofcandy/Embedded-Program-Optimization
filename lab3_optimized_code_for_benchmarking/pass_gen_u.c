#include <time.h>
#include <stdio.h>
#include <time.h>

clock_t start, end;
double cpu_time_used;
#include <stdlib.h>

int main(void)
{
    /* Length of the password */
    int length=10;
    int num=10;
    int temp;
    /* Seed number for rand() */
    srand((unsigned int)time(0) + getpid());

    start = clock();
    while (num--)
    {
        temp = length;
        printf("\n");
        while (temp--)
        {
            putchar(rand() % 56 + 65);
            srand(rand());
        }

        temp = length;
    }
    end = clock();
    cpu_time_used = ((double)(end - start));
    printf("\nTime taken: %f\n", cpu_time_used);
    printf("\n");

    return EXIT_SUCCESS;
}