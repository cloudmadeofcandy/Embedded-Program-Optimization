/*
 * C Program to Implement Selection Sort
 */
#include <stdio.h>
#include <time.h>

clock_t start, end;
double cpu_time_used;
void selectionSort(int arr[], int size);
void swap(int *a, int *b);
/*
 * Selection sort function
 */
void selectionSort(int arr[], int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = i; j < size; j++)
        {
            if (arr[i] > arr[j])
                swap(&arr[i], &arr[j]);
        }
    }
}

/* Function to swap two variables */
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/*
 * Main Function
 */
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
    for (int i = 0; i <100; i++) selectionSort(arr, MAX);
    end = clock();
    cpu_time_used = ((double)(end - start));
    printf("Time taken: %f\n", cpu_time_used);

    // printf("\nSorted array is ");
    // for (int i = 0; i < MAX; i++)
    //     printf(" %d ", arr[i]);
    // return 0;
}