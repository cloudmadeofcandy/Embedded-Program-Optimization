/* C program to find the minimum element in an array using Linear Search */
#include <stdio.h>
#include <time.h>

clock_t start, end;
double cpu_time_used;
int min_linearsearch(int numbers[], int n)
{
    int min = numbers[0];
    int i;
    for (i = 0; i < n; i++)
    {
        if (min > numbers[i])
            min = numbers[i];
    }
    return min;
}
#define MAX 100
#include<stdlib.h>
void random_shuffle(int arr[])
{
    srand(time(NULL));
    int i, j, temp;
    for (i = MAX - 1; i > 0; i--)
    {
        j = rand() % (i + 1);
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main()
{
    int nums = MAX;
    int arr[MAX];
    for (int i = 0; i < MAX; i++)
        arr[i] = i;
    random_shuffle(arr);
    int min = 0; 
    start = clock();
    for (int i = 0; i < 100; i++) min = min_linearsearch(arr, MAX);
    end = clock();
    cpu_time_used = ((double)(end - start));
    printf("Time taken: %f\n", cpu_time_used);
    printf("\nMinimum number in the array is : %d\n", min);
    return 0;
}