#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERS_SIZE 55
#define MAX_LEN 34

struct twoInts
{
    int intA;
    int intB;
};

struct node
{
    char data;
    struct node *next;
    struct node *prev;
};

void init();
void display();
int len();
int search(char);
void insert(char);
void insertAfter(char, int);
void delete (char);

struct node *head; /* global variable, the head of the linkedlist */

int main()
{
    int i, index;
    char key;

    struct twoInts *arr[MAX_LEN];

    char buffer[BUFFERS_SIZE];
    int value1, value2;
    int count = 0;

    FILE *file;
    file = fopen("data.txt", "r");

    while (fgets(buffer, BUFFERS_SIZE, file) != NULL)
    {
        sscanf(buffer, "%d %d", &value1, &value2);

        /* call function malloc() to allocate memory for arr[count] */
        arr[count] = malloc(sizeof(arr));

        /* set the two fields of the structure pointed by arr[count] with value1 and value2 */
        arr[count]->intA = value1;
        arr[count]->intB = value2;
        count++;
    }

    fclose(file);

    /* print the two fields of stuctures pointed by the pointer array */
    for (i = 0; i < count; i++)
    {
        printf("arr[%d]: %d %d\n", i, arr[i]->intA, arr[i]->intB);
    }

    /* now build up the list by reading from the array of structure pointers */
    printf("\n");
    init();

    i = 0;
    for (; i < count; i++)
    {
        /* read two ints from each structure pointed in the array,
        sum them up and add into the list */
        char value = (char)arr[i]->intA + arr[i]->intB;
        insert(value);

        /* no more coding in main below */

        printf("insert %c: (%d)", value, len());
        display();
    }

    char removeList[] = {'S', 'A', '-', 'O', 'R', 'K', 'Y', 'U', 'L', '\0'};
    i = 0;
    while ((key = removeList[i]) != '\0')
    {
        delete (key);
        printf("remove %c: (%d)", key, len());
        display();
        i++;
    }

    /* insert again */
    char addList[] = "YORKU-LAS";
    i = 0;
    while ((key = addList[i]) != '\0')
    {
        insert(key);
        printf("insert %c: (%d)", key, len());
        display();
        i++;
    }

    key = 'x';
    index = 2;
    insertAfter(key, index);
    printf("\ninsert %c after index %d: (%d)\n", key, index, len());
    display();
    key = 'y';
    index = 0;
    insertAfter(key, index);
    printf("insert %c after index %d: (%d)\n", key, index, len());
    display();
    key = 'z';
    index = 6;
    insertAfter(key, index);
    printf("insert %c after index %d: (%d)\n", key, index, len());
    display();

    /* search */
    printf("\n");
    char searchList[] = "-orkUxyZAy@";
    int len = strlen(searchList);
    i = 0;
    while (i < len)
    {
        char key = *(searchList + i);
        printf("search %c ....  ", key);

        if (search(key))
            printf("found\n");
        else
            printf("not found\n");
        i++;
    }
}

/* Initialize the list. */
void init()
{
    head = NULL;
}

/* Print the content of the list. */
void display()
{
    if (head == NULL)
    {
        printf("\n");
        /* Exit the function if the list is empty. */
        return;
    }

    struct node *current = head;

    /* Printing the list as is. */
    while (current->next != NULL)
    {
        printf("%3c", current->data);
        current = current->next;
    }

    printf("%3c", current->data);
    printf("    <-->  ");

    /* Printing the list reversed. */
    while (current != NULL)
    {
        printf("%3c", current->data);
        current = current->prev;
    }

    printf("\n");
}

/* return the # of nodes in the linked list */
int len()
{
    /* If the linked list is empty. */
    if (head == NULL)
        return 0;

    /* ELSE */

    struct node *currentNode = head;
    int i = 0;

    while (currentNode != NULL)
    {
        /* Data exists at current node so increment
        i and move onto the next node. */
        i++;
        currentNode = currentNode->next;
    }
    return i;
}

/* search the list for the key, return whether or not it is found */
int search(char key)
{
    /* IF the linked list is empty. */
    if (head == NULL)
        return 0;

    /* ELSE */

    struct node *currentNode = head;
    int i = 0;
    while (currentNode != NULL)
    {
        if (currentNode->data == key)
            return 1;                    /* Return true if key matches the data in the current node. */
        currentNode = currentNode->next; /* Move on to the next node in the list. */
    }
    /* Coming to this point means that we couldn't find the key. */
    return 0;
}

/* Insert a new data element with key c into the end of the list. */
/* Hint: You may want to consider the special case that the list is empty,
   and the general case that the list is not empty */

void insert(char c) //  at the end
{
    /* Prepare the new data. */
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = c;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL; /* Because it's the first data in the list. */
        head = newNode;       /* Set head to NULL, so the list is no longer empty. */
    }
    else /* If there is already a list, we just add on to it. */
    {
        struct node *currentNode = head; /* The current list we have */
        /* This while loop will stop on the last available data on the list. */
        while (currentNode->next != NULL)
        {
            currentNode = currentNode->next;
        }
        /* We assign the newNode to the next of our currentNode */
        currentNode->next = newNode;
        /* We assign the currentNode to the prev of our newNode */
        newNode->prev = currentNode;
    }
}

/* insert in the middle.
  insert new node with data c, after the node of index 'index'
  assume the list is not empty, and index is in [0, len()-1] (within bounds)
 */
void insertAfter(char c, int index)
{
    /* Prepare the new data. */
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = c;
    /* This time we don't set NULL to prev or next just yet because
    we don't know exactly where in the list the index is yet. */

    /* Assume list is not empty, therefore, no need to check if head is NULL. */

    struct node *currentNode = head;
    int i = 0;
    /* This loop stop as soon as we arrive at the index. */
    while (i != index)
    {
        currentNode = currentNode->next;
        i++;
    }

    /* The next node is a pointer to the node AFTER the index,
    whereas the currentNode is a pointer to the node BEFORE.
    We need to add our newNode in between the two nodes.*/
    struct node *nextNode = currentNode->next;

    /* Prev and Next from the newNode */
    newNode->prev = currentNode;
    newNode->next = nextNode;

    /* The pointers from the two nodes before and after our new node. */
    currentNode->next = newNode;
    nextNode->prev = newNode;

    /* ----------------------- DONE :) -----------------------------*/
}

/* the lab version */
/* Remove the node with value c from the list */
/* assume the list is not empty */
/* assume no duplicated keys in the list */
/* assume the node to be deleted is in the list */
/* You do not have to free the space (welcome to do so)  */
void delete (char c)
{
    /* the special case: to be removed is the first, need to change head  */
    if (head->data == c)
    {
        /* We could set head to be the next node, but what if the next node is NULL? */
        if (head->next == NULL)
            init(); /* Or we could do head = NULL. But functions are cleaner. */
        else
        {
            head = head->next; /* Make the next node the new head node. */
            head->prev = NULL; /* Because head is the first node. */
        }
    }
    else /* If head is not the one to be removed. */
    {
        struct node *currentNode = head;

        while (currentNode->data != c)
        {
            currentNode = currentNode->next; /* Move on to the next node. */
        }

        /* After the loop, currentNode is pointing to the data be removed. */

        if (currentNode->next == NULL) /* In case current node is the last. */
            /* Setting the next node of the previous node to NULL. */
            currentNode->prev->next = NULL;
        else
        {
            /* Setting the next node of the prev node to the next node of the current node. */
            currentNode->prev->next = currentNode->next;
            /* Setting the prev node of the next node to the prev node of the current node. */
            currentNode->next->prev = currentNode->prev;
        }
    }
}
