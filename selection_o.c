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
int main()
{
    int array[10], i, size;
    printf("How many numbers you want to sort:  ");
    scanf("%d", &size);
    printf("\nEnter %d numbers\t", size);
    printf("\n");
    for (i = 0; i < size; i++)
        scanf("%d", &array[i]);
    start = clock();
    selectionSort(array, size);
    end = clock();
    cpu_time_used = ((double)(end - start));
    printf("Time taken: %f\n", cpu_time_used);

    printf("\nSorted array is ");
    for (i = 0; i < size; i++)
        printf(" %d ", array[i]);
    return 0;
}