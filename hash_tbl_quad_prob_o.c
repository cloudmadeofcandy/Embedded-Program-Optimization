#include <stdio.h>
#include <time.h>

clock_t start, end;
double cpu_time_used;
#include <stdlib.h>

/* to store a data (consisting of key and value) in hash table array */
struct item
{
	int key;
	int value;
};

/* each hash table item has a flag (status) and data (consisting of key and value) */
struct hashtable_item
{

	int flag;
	/*
	 * flag = 0 : data does not exist
	 * flag = 1 : data exists at given array location
	 * flag = 2 : data was present at least once
	 */
	struct item *data;
};

struct hashtable_item *array;
int size = 0;
int max = 10;

/* this function returns corresponding index of the given key */
int hashcode(int key)
{
	return (key % max);
}

/* this  function initializes the hash table array */
void init_array()
{
	int i;
	for (i = 0; i < max; i++)
	{
		array[i].flag = 0;
		array[i].data = NULL;
	}
}

/* this function inserts an element in the hash table */
void insert(int key, int value)
{
	int index = hashcode(key);

	int i = index;
	int h = 1;

	struct item *new_item = (struct item *)malloc(sizeof(struct item));
	new_item->key = key;
	new_item->value = value;

	/* probing through the array until an empty space is found */
	while (array[i].flag == 1)
	{

		if (array[i].data->key == key)
		{

			/* case when already present key matches the given key */
			printf("\n This key is already present in hash table, hence updating it's value \n");
			array[i].data->value = value;
			return;
		}
		i = (i + (h * h)) % max;
		h++;
		if (i == index)
		{
			printf("\n Hash table is full, cannot add more elements \n");
			return;
		}
	}

	array[i].flag = 1;
	array[i].data = new_item;
	printf("\n Key (%d) has been inserted\n", key);
	size++;
}

/* to remove an element form the hash table array */
void remove_element(int key)
{
	int index = hashcode(key);
	int i = index;
	int h = 1;

	/* probing through the hash table until we reach at location where there had not been an element even once */
	while (array[i].flag != 0)
	{
		if (array[i].flag == 1 && array[i].data->key == key)
		{

			/* case where data exists at the location and its key matches to the given key */
			array[i].flag = 2;
			array[i].data = NULL;
			size--;
			printf("\n Key (%d) has been removed \n", key);
			return;
		}
		i = (i + (h * h)) % max;
		h++;
		if (i == index)
		{
			break;
		}
	}
	printf("\n Key does not exist \n");
}

/* to display the contents of hash table */
void display()
{

	int i;
	for (i = 0; i < max; i++)
	{
		if (array[i].flag != 1)
		{
			printf("\n Array[%d] has no elements \n", i);
		}
		else
		{
			printf("\n Array[%d] has elements \n  %d (key) and %d (value) \n", i, array[i].data->key, array[i].data->value);
		}
	}
}

int size_of_hashtable()
{
	return size;
}

void main()
{
	int choice, key, value, n, c;
	clrscr();

	array = (struct hashtable_item *)malloc(max * sizeof(struct hashtable_item *));
	init_array();

	do
	{
		printf("Implementation of Hash Table in C with Quadratic Probing.\n\n");
		printf("MENU-: \n1.Inserting item in the Hash table"
			   "\n2.Removing item from the Hash table"
			   "\n3.Check the size of Hash table"
			   "\n4.Display Hash table"
			   "\n\n Please enter your choice-:");

		scanf("%d", &choice);

		switch (choice)
		{

		case 1:

			printf("Inserting element in Hash table \n");
			printf("Enter key and value-:\t");
			scanf("%d %d", &key, &value);
			start = clock();
			insert(key, value);
			end = clock();
			cpu_time_used = ((double)(end - start));
			printf("Time taken: %f\n", cpu_time_used);

			break;

		case 2:

			printf("Deleting in Hash table \n Enter the key to delete-:");
			scanf("%d", &key);
			start = clock();
			remove_element(key);
			end = clock();
			cpu_time_used = ((double)(end - start));
			printf("Time taken: %f\n", cpu_time_used);
			break;

		case 3:

			n = size_of_hashtable();
			printf("Size of Hash table is-:%d\n", n);

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