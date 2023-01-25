#include<stdio.h>
#include <time.h>

clock_t start, end;
double cpu_time_used;
#define MAX 10
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
int main() {
    int numbers[MAX];
    int i;
    int index, key;
    printf("Enter %d numbers : ", MAX);
    for (i = 0; i < MAX; i++)
    {
        scanf("%d", &numbers[i]);
    }
    printf("\nEnter a key to find using linear search: ");
    scanf("%d", &key);
    start = clock();
    index = linearsearch(numbers, key);
    end = clock();
    cpu_time_used = ((double) (end - start));
    printf("Time taken: %f\n", cpu_time_used);
    if ( index >= 0)
        printf("\n%d found at index %d using linear search.", key, index);
    else
        printf("\nNot found!!");
    printf("\nEnter %d numbers in increasing order: ", MAX);
    for (i = 0 ; i < MAX; i++)
        scanf("%d", &numbers[i]);
    printf("\nEnter a key to find using binary search: ");
    scanf("%d", &key);
    start = clock();
    index = binarysearch(numbers, key);
    end = clock();
    cpu_time_used = ((double) (end - start));
    printf("Time taken: %f\n", cpu_time_used);
    if (index >= 0 )
        printf("Found at index %d", index);
    else
        printf("\nNot found!!!");
 
    return 0;
    }