#include <stdio.h>
#include <time.h>

clock_t start, end;
double cpu_time_used;
#include <conio.h>
#include <stdlib.h>

int max = 10; /* determines the maximum capacity of Hash Table array */
int size = 0; /* determines the number of elements present in Hash Table */

/* node for storing an item in a Binary Tree */
struct node
{
	int key;
	int value;
	struct node *left;
	struct node *right;
};

/* for storing a Binary Tree at each index of Hash Table array */
struct bst
{
	struct node *head;
	/* head pointing to the root of Binary Tree */
};

struct bst *array;

void insert_element(struct node *tree, struct node *item);
struct node *find(struct node *tree, int key);
struct node *remove_element(struct node *tree, int key);
void display_tree(struct node *tree);

/* this function creates an index corresponding to the every given key */
int hashcode(int key)
{
	return (key % max);
}

void add(int key, int value)
{
	int index = hashcode(key);

	/* extracting Binary Tree at the given index */
	struct node *tree = (struct node *)array[index].head;

	/* creating an item to insert in the hashtable */
	struct node *new_item = (struct node *)malloc(sizeof(struct node));
	new_item->key = key;
	new_item->value = value;
	new_item->left = NULL;
	new_item->right = NULL;

	if (tree == NULL)
	{
		/* absence of Binary Tree at a given index of Hash Table array */

		printf("Inserting %d(key) and %d(value)\n", key, value);
		array[index].head = new_item;
		size++;
	}
	else
	{
		/* a Binary Tree is present at given index of Hash Table */

		struct node *temp = find(tree, key);
		if (temp == NULL)
		{
			/*
			 * Key not found in existing Binary Tree
			 * Adding the key in existing Binary Tree
			 */

			printf("Inserting %d(key) and %d(value) \n", key, value);
			insert_element(tree, new_item);
			size++;
		}
		else
		{
			/*
			 * Key already present in existing Binary Tree
			 * Updating the value of already existing key
			 */

			temp->value = value;
		}
	}
}

/*
 * this function finds the given key in the Binary Tree
 * returns the node containing the key
 * returns NULL in case key is not present
 */
struct node *find(struct node *tree, int key)
{
	if (tree == NULL)
	{
		return NULL;
	}
	if (tree->key == key)
	{
		return tree;
	}
	else if (key < tree->key)
	{
		return find(tree->left, key);
	}
	else
	{
		return find(tree->right, key);
	}
}

/* this function inserts the newly created node in the existing Binary Tree */
void insert_element(struct node *tree, struct node *item)
{
	if (item->key < tree->key)
	{
		if (tree->left == NULL)
		{
			tree->left = item;
			return;
		}
		else
		{
			insert_element(tree->left, item);
			return;
		}
	}
	else if (item->key > tree->key)
	{
		if (tree->right == NULL)
		{
			tree->right = item;
			return;
		}
		else
		{
			insert_element(tree->right, item);
			return;
		}
	}
}

/* displays the content of hash table */
void display()
{
	int i = 0;
	for (i = 0; i < max; i++)
	{
		struct node *tree = array[i].head;
		if (tree == NULL)
		{
			printf("\n array[%d] has no elements \n", i);
		}
		else
		{
			printf("\n array[%d] has elements \t", i);
			display_tree(tree);
		}
	}
}

/* displays content of binary tree of particular index */
void display_tree(struct node *tree)
{
	if (tree == NULL)
	{
		return;
	}
	printf("%d and %d \t", tree->key, tree->value);

	if (tree->left != NULL)
	{
		display_tree(tree->left);
	}
	if (tree->right != NULL)
	{
		display_tree(tree->right);
	}
}

/* for initializing the hash table */
void init()
{
	int i = 0;
	for (i = 0; i < max; i++)
	{
		array[i].head = NULL;
	}
}

/* returns the size of hash table */
int size_of_hashtable()
{
	return size;
}

/* to delete a key from hash table */
void delete(int key)
{
	int index = hashcode(key);
	struct node *tree = (struct node *)array[index].head;
	if (tree == NULL)
	{
		printf("\n %d Key not present \n", key);
	}
	else
	{
		struct node *temp = find(tree, key);
		if (temp == NULL)
		{
			printf("%d Key not present.", key);
		}
		else
		{
			tree = remove_element(tree, key);
			printf("%d has been removed form the hash table\n", key);
		}
	}
}

struct node *remove_element(struct node *tree, int key)
{
	if (tree == NULL)
	{
		return NULL;
	}
	if (key < tree->key)
	{
		tree->left = remove_element(tree->left, key);
		return tree;
	}
	else if (key > tree->key)
	{
		tree->right = remove_element(tree->right, key);
		return tree;
	}
	else
	{
		/* reached the node */
		if (tree->left == NULL && tree->right == NULL)
		{
			size--;
			return tree->left;
		}
		else if (tree->left != NULL && tree->right == NULL)
		{
			size--;
			return tree->left;
		}
		else if (tree->left == NULL && tree->right != NULL)
		{
			size--;
			return tree->right;
		}
		else
		{
			struct node *left_one = tree->left;

			while (left_one->right != NULL)
			{
				left_one = left_one->right;
			}

			tree->key = left_one->key;
			tree->value = left_one->value;
			tree->left = remove_element(tree->left, tree->key);
			return tree;
		}
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

void main()
{
	int choice, key, value, n, c;

	array = (struct bst *)malloc(max * sizeof(struct bst *));
	init();
    int nums = MAX;
    int arr[MAX];
    for (int i = 0; i < MAX; i++)
        arr[i] = i;
    random_shuffle(arr);
	for (int i = 0; i < 100; i++) add(i, arr[i]);
			start = clock();
			for (int i = 0; i < 100; i++) delete(arr[i]);
			end = clock();
			cpu_time_used = ((double)(end - start));
			printf("Time taken: %f\n", cpu_time_used);
}