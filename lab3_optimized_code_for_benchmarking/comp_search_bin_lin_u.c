#include<stdio.h>
#include <time.h>

clock_t start, end;
double cpu_time_used;
#define MAX 100
int linearsearch(int numbers[], int key)
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        if (key == numbers[i])
            return i;
    }
    return -1;
}
int binarysearch(int numbers[], int key)
{
    int l = 0, u = MAX - 1;
    int c, mid;
     while (l <= u){
         mid = (l + u) >> 1;
         if (key == numbers[mid]){
             return mid;
         }
         else if (key < numbers[mid]){
             u = mid - 1;
         }
         else
             l = mid + 1;
    }
    return -1;
}

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
    int index;
    for (int i = 0; i < MAX; i++)
        arr[i] = i;
    // random_shuffle(arr);
    start = clock();
    for (int i = 0; i < 100; i++) index = linearsearch(arr, 70);
    end = clock();
    cpu_time_used = ((double) (end - start));
    printf("Time taken: %f\n", cpu_time_used);
    if ( index >= 0)
        printf("\n%d found at index %d using linear search.\n", 70, index);
    else
        printf("\nNot found!!");
    start = clock();
    for (int i = 0; i < 100; i++) index = binarysearch(arr, 70);
    end = clock();
    cpu_time_used = ((double) (end - start));
    printf("Time taken: %f\n", cpu_time_used);
    if (index >= 0 )
        printf("Found at index %d using binary search", index);
    else
        printf("\nNot found!!!");
 
    return 0;
    }