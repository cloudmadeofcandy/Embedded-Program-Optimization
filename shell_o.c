#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 100
clock_t start, end;
double cpu_time_used;
void swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
    return;
}

// Function definition of sort array using shell sort
void shellsort(int arr[], int nums)
{
    // i -> gap/interval
    for (int i = nums / 2; i > 0; i = i / 2)
    {
        // Traverse j till we reach the end of the sublist.
        for (int j = i; j < nums; j++)
        {
            for (int k = j - i; k >= 0; k = k - i)
            {
                if (arr[k + i] >= arr[k])
                {
                    break;
                }
                else
                {
                    swap(&arr[k], &arr[k + i]);
                }
            }
        }
    }
    return;
}

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
    int arr[MAX];
    for (int i = 0; i < MAX; i++)
        arr[i] = i;
    random_shuffle(arr);
    // Call the function of shell sort, bypassing the array base pointer to the first element.

    start = clock();
    for (int i = 0; i < 1000; i++)
    {
        for (int i = nums / 2; i > 0; i = i / 2)
        {
            // Traverse j till we reach the end of the sublist.
            for (int j = i; j < nums; j++)
            {
                for (int k = j - i; k >= 0; k = k - i)
                {
                    if (arr[k + i] >= arr[k])
                    {
                        break;
                    }
                    else
                    {
                        swap(&arr[k], &arr[k + i]);
                    }
                }
            }
        }
        end = clock();
        cpu_time_used = ((double)(end - start));
        printf("Time taken: %f\n", cpu_time_used);
        // After the sorting the array is
        // printf("Sorted array is:  \n");
        // for (int k = 0; k < nums; k++)
        // {
        //     printf("%d ", arr[k]);
        // }
        return 0;
    }
}