/*
 * C program to find all permutations of letters of a string
 */
#include <stdio.h>
#include <time.h>

clock_t start, end;
double cpu_time_used;
#include <string.h>

/* Function to swap values at two pointers */
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
/*  End of swap()  */

/*  Function to print permutations of string  */
void permute(char *a, int i, int n)
{
    int j;
    if (i == n)
        printf("%s\n", a);
    else
    {
        for (j = i; j <= n; j++)
        {
            swap((a + i), (a + j));
            permute(a, i + 1, n);
            swap((a + i), (a + j)); // backtrack
        }
    }
}

/*  The main() begins  */
int main()
{
    char a[20];
    int n;
    printf("Enter a string: ");
    scanf("%s", a);
    n = strlen(a);
    printf("Permutaions:\n");
    start = clock();
    permute(a, 0, n - 1);
    end = clock();
    cpu_time_used = ((double)(end - start));
    printf("Time taken: %f\n", cpu_time_used);

    getchar();
    return 0;
}