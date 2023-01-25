#include <stdio.h>
#include <time.h>

clock_t start, end;
double cpu_time_used;
#include <stdlib.h>
struct node
{
    int info;
    struct node *left;
    struct node *right;
};
typedef struct node BST;
BST *LOC, *PAR;
void search(BST *root, int item)
{
    BST *save, *ptr;
    if (root == NULL)
    {
        LOC = NULL;
        PAR = NULL;
    }
    if (item == root->info)
    {
        LOC = root;
        PAR = NULL;
        return;
    }
    if (item < root->info)
    {
        save = root;
        ptr = root->left;
    }
    else
    {
        save = root;
        ptr = root->right;
    }
    while (ptr != NULL)
    {
        if (ptr->info == item)
        {
            LOC = ptr;
            PAR = save;
            return;
        }
        if (item < ptr->info)
        {
            save = ptr;
            ptr = ptr->left;
        }
        else
        {
            save = ptr;
            ptr = ptr->right;
        }
    }
    LOC = NULL;
    PAR = save;
    return;
}

struct node *findmin(struct node *r)
{
    if (r == NULL)
        return NULL;
    else if (r->left != NULL)
        return findmin(r->left);
    else if (r->left == NULL)
        return r;
}
struct node *insert(struct node *r, int x)
{
    if (r == NULL)
    {
        r = (struct node *)malloc(sizeof(struct node));
        r->info = x;
        r->left = r->right = NULL;
        return r;
    }
    else if (x < r->info)
        r->left = insert(r->left, x);
    else if (x > r->info)
        r->right = insert(r->right, x);
    return r;
}

struct node *del(struct node *r, int x)
{
    struct node *t;
    if (r == NULL)
        printf("\nElement not found");
    else if (x < r->info)
        r->left = del(r->left, x);
    else if (x > r->info)
        r->right = del(r->right, x);
    else if ((r->left != NULL) && (r->right != NULL))
    {
        t = findmin(r->right);
        r->info = t->info;
        r->right = del(r->right, r->info);
    }
    else
    {
        t = r;
        if (r->left == NULL)
            r = r->right;
        else if (r->right == NULL)
            r = r->left;
        free(t);
    }
    return r;
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
    
    struct node *root = NULL;
    int x, c = 1, z;
    int element;
    char ch;
    for (int i = 0; i < MAX; i++)
        root = insert(root, arr[i]);
        
            element = 50;
            start = clock();
            search(root, element);
            end = clock();
            cpu_time_used = ((double)(end - start));
            printf("Time taken: %f\n", cpu_time_used);
    return 0;
}