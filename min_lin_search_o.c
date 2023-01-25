/* C program to find the minimum element in an array using Linear Search */
#include <stdio.h>
#include <time.h>

clock_t start, end;
double cpu_time_used;
int min_linearsearch(int numbers[], int n)
{
    int min = numbers[0];
    int i;
    for (i = 1; i <= n; i++)
    {
        if (min > numbers[i])
            min = numbers[i];
    }
    return min;
}
int main()
{
    int n;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    int numbers[n];
    int i;
    int min;
    printf("Enter %d numbers : ", n);
    printf("\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i]);
    }

    start = clock();
    min = min_linearsearch(numbers, n);
    end = clock();
    cpu_time_used = ((double)(end - start));
    printf("Time taken: %f\n", cpu_time_used);
    printf("\nMinimum number in the array is : %d\n", min);
    return 0;
}