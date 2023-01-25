/*
 * C Program to Perform Stooge Sort
 */
#include <stdio.h>
#include <time.h>

clock_t start, end;
double cpu_time_used;
void stoogesort(int[], int, int);

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

void main()
{
    int nums = MAX;
    int arr[MAX];
    for (int i = 0; i < MAX; i++)
        arr[i] = i;
    random_shuffle(arr);

    start = clock();
    for (int i = 0; i < 100; i++) stoogesort(arr, 0, MAX - 1);
    end = clock();
    cpu_time_used = ((double)(end - start));
    printf("Time taken: %f\n", cpu_time_used);

    // printf("Sorted array : \n");
    // for (i = 0; i < MAX; i++)
    // {
    //     printf("%d ", arr[i]);
    // }
    printf("\n");
}

void stoogesort(int arr[], int i, int j)
{
    int temp, k;
    if (arr[i] > arr[j])
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    if ((i + 1) >= j)
        return;
    k = (int)((j - i + 1) / 3);
    stoogesort(arr, i, j - k);
    stoogesort(arr, i + k, j);
    stoogesort(arr, i, j - k);
}