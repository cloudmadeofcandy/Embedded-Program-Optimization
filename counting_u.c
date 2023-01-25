/*
 * C Program for counting sort
 */
#include<stdio.h>
#include <time.h>
#define MAX 100
clock_t start, end;
double cpu_time_used;
 
/*  Counting sort function  */
void counting_sort(int A[], int k, int n)
{
    int i, j;
    int B[MAX+10], C[MAX+10];
    for (i = 0; i <= k; i++)
        C[i] = 0;
    for (j = 1; j <= n; j++)
        C[A[j]] = C[A[j]] + 1;
    for (i = 1; i <= k; i++)
        C[i] = C[i] + C[i-1];
    for (j = n; j >= 1; j--)
    {
        B[C[A[j]]] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }
    // printf("The Sorted array is : ");
    // for (i = 0; i < n; i++)
    //     printf("%d ", B[i]);
}
/*  End of counting_sort()  */

#include <stdlib.h>

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
    int A[MAX+10];
    for (int i = 0; i < MAX; i++)
        A[i] = i;

    random_shuffle(A);
    int k = 0, i;

    for (i = 0; i < MAX; i++)
    {
        if (A[i] > k) {
            k = A[i];
        }
    }
    start = clock();
    for (int i = 0; i < 1000; i++) counting_sort(A, k, MAX);
    end = clock();
    cpu_time_used = ((double) (end - start));
    printf("Time taken: %f\n", cpu_time_used);
    
    printf("\n");
    return 0;
}