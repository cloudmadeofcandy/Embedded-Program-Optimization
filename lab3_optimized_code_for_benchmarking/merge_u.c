#include <stdio.h>
#include <time.h>

clock_t start, end;
double cpu_time_used;
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *sortedmerge(struct node *a, struct node *b);
void frontbacksplit(struct node *source, struct node **frontRef, struct node **backRef);

void mergesort(struct node **headRef)
{
    struct node *head = *headRef;
    struct node *a;
    struct node *b;
    if ((head == NULL) || (head->next == NULL))
    {
        return;
    }
    frontbacksplit(head, &a, &b);
    mergesort(&a);
    mergesort(&b);
    *headRef = sortedmerge(a, b);
}

struct node *sortedmerge(struct node *a, struct node *b)
{
    struct node *result = NULL;

    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    if (a->data <= b->data)
    {
        result = a;
        result->next = sortedmerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = sortedmerge(a, b->next);
    }
    return (result);
}

void frontbacksplit(struct node *source, struct node **frontRef, struct node **backRef)
{
    struct node *fast;
    struct node *slow;
    if (source == NULL || source->next == NULL)
    {
        *frontRef = source;
        *backRef = NULL;
    }
    else
    {
        slow = source;
        fast = source->next;
        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }

        *frontRef = source;
        *backRef = slow->next;
        slow->next = NULL;
    }
}

void printlist(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

void push(struct node **head_ref, int new_data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
int main()
{
    struct node *a = NULL;
    for (int i = 0; i < 1000; i++) {
        push(&a, rand());
    }
    start = clock();
    for (int i = 0; i < 1000; i++) mergesort(&a);
    end = clock();
    cpu_time_used = ((double)(end - start));
    printf("Time taken: %f\n", cpu_time_used);

    // printf("\n Sorted Linked List is: \n");
    // printlist(a);
    return 0;
}