#include <stdio.h>
#include <time.h>

clock_t start, end;
double cpu_time_used;
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void shakersort(int a[], int n)
{
    int p, i;
    for (p = 1; p <= n / 2; p++)
    {
        for (i = p - 1; i < n - p; i++)
            if (a[i] > a[i + 1])
                swap(&a[i], &a[i + 1]);
        for (i = n - p - 1; i >= p; i--)
            if (a[i] < a[i - 1])
                swap(&a[i], &a[i - 1]);
    }
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
    int i;
    start = clock();
    for (int i = 0; i < 1000; i++) shakersort(arr, MAX);
    end = clock();
    cpu_time_used = ((double)(end - start));
    printf("Time taken: %f\n", cpu_time_used);

    // for (i = 0; i < MAX; i++)
    //     printf("%d ", arr[i]);
    return 0;
}