#define LOG_N 42
#include <stdio.h>
#include <time.h>

clock_t start, end;
double cpu_time_used;

static int delta[LOG_N];

void make_delta(int N)
{
    int power = 1;
    int i = 0;
    do
    {
        int half = power;
        power <<= 1;
        delta[i] = (N + half) / power;
    } while (delta[i++] != 0);
}

int unisearch(int *a, int key)
{
    int i = delta[0]; /* midpoint of array */
    int d = 0;

    while (1)
    {
        if (key == a[i])
        {
            return i;
        }
        else if (delta[d] == 0)
        {
            return -1;
        }
        else
        {
            if (key < a[i])
            {
                i -= delta[++d];
            }
            else
            {
                i += delta[++d];
            }
        }
    }
}

#define N 10
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
    make_delta(MAX);
    start = clock();
    for (int i = 0; i < 100; i++) nums = unisearch(arr, 50);
    // printf("%d is at index %d\n", 50, nums);
    end = clock();
    cpu_time_used = ((double)(end - start));
    printf("Time taken: %f\n", cpu_time_used);
    return 0;
}