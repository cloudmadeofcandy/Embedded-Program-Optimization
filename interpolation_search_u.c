/*
 * C Program for Interpolation search algorithm
 */
#include <stdio.h>
#include <time.h>

clock_t start, end;
double cpu_time_used;

/* Interpolation search function */
int interpolation_search(int a[], int bottom, int top, int item)
{
    int mid;
    while (bottom <= top)
    {
        mid = bottom + (top - bottom) * ((item - a[bottom]) / (a[top] - a[bottom]));
        if (item == a[mid])
            return mid + 1;
        if (item < a[mid])
            top = mid - 1;
        else
            bottom = mid + 1;
    }
    return -1;
}
/* End of interpolation_search() */
/* The main() begins */
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
    int pos;
    int arr[MAX];
    for (int i = 0; i < MAX; i++)
        arr[i] = i;
    start = clock();
    for (int i = 0; i < 100; i++) pos = interpolation_search(&arr[0], 0, MAX - 1, 50);
    end = clock();
    cpu_time_used = ((double)(end - start));
    printf("Time taken: %f\n", cpu_time_used);

    if (pos == -1)
        printf("\nElement %d not found\n", 50);
    else
        printf("\nElement %d found at position %d\n", 50, pos);
    return 0;
}