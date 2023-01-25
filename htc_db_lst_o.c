#include <stdio.h>
#include <time.h>

clock_t start, end;
double cpu_time_used;
#include <stdlib.h>

/* Node for storing an item in a Doubly Linked List */
struct node
{
	int key;
	int value;
	struct node *next;
	struct node *prev;
};

/* For storing a Linked List at each index of Hash table */
struct arrayitem
{

	struct node *head;
	/* head pointing the first element of Linked List at an index of Hash table */

	struct node *tail;
	/* tail pointing the last element of Linked List at an index of Hash table */
};

struct arrayitem *array;
int size = 0; /* Determines the no. of elements present in Hash table */
int max = 10; /* Determines the maximum capacity of Hash table array */

/* This function creates an index corresponding to the every given key */
int hashcode(int key)
{
	return (key % max);
}

struct node *get_element(struct node *list, int find_index);
void remove_element(int key);
void rehash();
void init_array();

void insert(int key, int value)
{
	float n = 0.0;
	/*  n => Load Factor, keeps check on whether rehashing is required or not */

	int index = hashcode(key);

	/* Extracting Linked List at a given index */
	struct node *list = (struct node *)array[index].head;

	/* Creating an item to insert in the hash table */
	struct node *item = (struct node *)malloc(sizeof(struct node));
	item->key = key;
	item->value = value;
	item->next = NULL;
	item->prev = NULL;

	if (list == NULL)
	{
		/* Absence of Linked List at a given index of Hash table */

		printf("\n  %d (key) and %d (value) has been inserted  \n", key, value);
		array[index].head = item;
		array[index].tail = item;
		size++;
	}
	else
	{
		/* A Linked List is present at given index of Hash table */

		int find_index = find(list, key);
		if (find_index == -1)
		{
			/*
			 *Key not found in existing Linked List
			 *Adding the key at the end of the Linked List
			 */
			item->prev = array[index].tail;
			array[index].tail->next = item;
			array[index].tail = item;
			size++;
			printf("\n %d (key) and %d (value) has been inserted \n", key, value);
		}
		else
		{
			/*
			 *Key already present in Linked List
			 *Updating the value of already existing key
			 */

			struct node *element = get_element(list, find_index);
			element->value = value;
		}
	}

	/* Calculating Load factor */
	n = (1.0 * size) / max;
	if (n >= 0.75)
	{
		/* rehashing */

		printf("going to rehash\n");
		rehash();
	}
}

void rehash()
{
	struct arrayitem *temp = array;
	/* temp pointing to the current Hash table array */

	int i = 0, n = max;
	size = 0;
	max = 2 * max;

	/*
	 *array variable is assigned with newly created Hash table
	 *with double of previous array size
	 */
	array = (struct arrayitem *)malloc(size * sizeof(struct node));
	init_array();

	for (i = 0; i < n; i++)
	{

		//* Extracting the Linked List at position i of Hash table array
		struct node *list = (struct node *)temp[i].head;

		if (list == NULL)
		{

			/* if there is no Linked List, then continue */
			continue;
		}
		else
		{
			/*
			 *Presence of Linked List at i
			 *Keep moving and accessing the Linked List item until the end.
			 *Get one key and value at a time and add it to new Hash table array.
			 */

			while (list != NULL)
			{
				insert(list->key, list->value);
				list = list->next;
			}
		}
	}
	temp = NULL;
}

/*
 *This function finds the given key in the Linked List
 *Returns it's index
 *Returns -1 in case key is not present
 */
int find(struct node *list, int key)
{
	int retval = 0;
	struct node *temp = list;
	while (temp != NULL)
	{
		if (temp->key == key)
		{
			return retval;
		}
		temp = temp->next;
		retval++;
	}
	return -1;
}

/* Returns the node (Linked list item) located at given find_index */
struct node *get_element(struct node *list, int find_index)
{
	int i = 0;
	struct node *temp = list;
	while (i != find_index)
	{
		temp = temp->next;
		i++;
	}
	return temp;
}

/* To remove an element from Hash table */
void remove_element(int key)
{
	int index = hashcode(key);
	struct node *list = (struct node *)array[index].head;

	if (list == NULL)
	{
		printf("\n This key does not exists \n");
	}
	else
	{
		int find_index = find(list, key);

		if (find_index == -1)
		{
			printf("\n This key does not exists \n");
		}
		else
		{
			struct node *temp = list;
			if (temp->key == key)
			{

				array[index].head = temp->next;
				array[index].head->prev = NULL;
				size--;
				printf("\n This key has been removed \n");
				return;
			}

			while (temp->key != key)
			{
				temp = temp->next;
			}

			if (array[index].tail == temp)
			{
				temp->prev->next = NULL;
				array[index].tail = temp->prev;
				size--;
			}
			else
			{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				size--;
			}

			printf("This key has been removed\n");
		}
	}
}

/* To display the contents of Hash table */
void display()
{
	int i = 0;
	for (i = 0; i < max; i++)
	{
		struct node *temp = array[i].head;
		if (temp == NULL)
		{
			printf("array[%d] has no elements \n", i);
		}
		else
		{
			printf("array[%d] has elements-: ", i);
			while (temp != NULL)
			{
				printf("key= %d  value= %d\t", temp->key, temp->value);
				temp = temp->next;
			}
			printf("\n");
		}
	}
}

/* For initializing the Hash table */
void init_array()
{
	int i;
	for (i = 0; i < max; i++)
	{
		array[i].head = NULL;
		array[i].tail = NULL;
	}
}

/* Returns size of Hash table */
int size_of_array()
{
	return size;
}

void main()
{
	int choice, key, value, n, c;
	clrscr();

	array = (struct arrayitem *)malloc(max * sizeof(struct arrayitem *));
	init_array();

	do
	{
		printf("Implementation of Hash Table in C chaining with Doubly Linked List \n\n");
		printf("MENU-: \n1.Inserting item in the Hash Table"
			   "\n2.Removing item from the Hash Table"
			   "\n3.Check the size of Hash Table"
			   "\n4.Display a Hash Table"
			   "\n\n Please enter your choice-:");

		scanf("%d", &choice);

		switch (choice)
		{

		case 1:
			printf("Inserting element in Hash Table\n");
			printf("Enter key and value");
			scanf("%d %d", &key, &value);

			start = clock();
			insert(key, value);
			end = clock();
			cpu_time_used = ((double)(end - start));
			printf("Time taken: %f\n", cpu_time_used);
			break;

		case 2:

			printf("Deleting in Hash Table \n Enter the key to delete-:");
			scanf("%d", &key);

			start = clock();
			remove_element(key);
			end = clock();
			cpu_time_used = ((double)(end - start));
			printf("Time taken: %f\n", cpu_time_used);
			break;

		case 3:

			n = size_of_array();
			printf("Size of Hash Table is-: %d\n", n);

			break;

		case 4:

			display();

			break;

		default:

			printf("Wrong Input\n");
		}

		printf("\n Do you want to continue-:(press 1 for yes)\t");
		scanf("%d", &c);

	} while (c == 1);

	getch();
}