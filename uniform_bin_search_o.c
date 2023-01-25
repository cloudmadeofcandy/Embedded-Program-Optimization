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
    int i = delta[0] - 1; /* midpoint of array */
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
int main(void)
{
    int num, a[N] = {1, 3, 5, 6, 7, 9, 14, 15, 17, 19};
    make_delta(N);
    printf("\nEnter an element to search: ");
    scanf("%d", &num);
    start = clock();
    printf("%d is at index %d\n", num, unisearch(a, num));
    end = clock();
    cpu_time_used = ((double)(end - start));
    printf("Time taken: %f\n", cpu_time_used);
    return 0;
}