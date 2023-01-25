#include<stdio.h>
#include <time.h>

clock_t start, end;
double cpu_time_used;
#include <stdlib.h>
 
int main(void)
{
    int length;
    char str[] = "0123456789ABCDEF";
    /* Seed number for rand() */
    srand((unsigned int) time(0) + getpid());
    length = 100;

    start = clock();
    while(length--) {
        putchar(str[rand() % 16]);
        srand(rand());
    }
    printf("\n");
    
    end = clock();
    cpu_time_used = ((double) (end - start));
    printf("Time taken: %f\n", cpu_time_used);
    return EXIT_SUCCESS;
}