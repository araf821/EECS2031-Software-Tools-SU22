/***************************************
 * 22S - Lab06 *
 * Author: Alam, Araf *
 * Email: araf821@my.yorku.ca *
 * eecs_username: araf821 *
 * York Student #: 218124347
 ************************************** **/

#include <stdio.h>
#include <stdlib.h>

void insertBegining(int);
int len();
int get(int);

struct node
{
   int data;
   struct node *next;
};

struct node *head;

int main()
{
   head = NULL;

   insertBegining(100);
   insertBegining(200);
   insertBegining(300);
   insertBegining(400);
   insertBegining(500);

   int i;
   struct node *cur;
   for (cur = head; cur != NULL; cur = cur->next)
      printf("%d ", cur->data);
   printf("\n");

   printf("len: %d\n", len());
   printf("get(0): %d\n", get(0));
   printf("get(1): %d\n", get(1));
   printf("get(3): %d\n", get(3));
}

/* insert at the begining of the list*/
void insertBegining(int data)
{
   /* Similar to what we did in setArr2.c, we have to allocate memory space. */
   struct node *newNode = malloc(sizeof(struct node));
   newNode->data = data;

   newNode->next = head;

   head = newNode;
}

/* 'length' info of the list */
int len()
{
   int length = 0;
   struct node *cur;
   /* Keep incrementing length until the current node is null. */
   for (cur = head; cur != NULL; cur = cur->next)
      length++;

   return length;
}

/* get value at index 'index' */
int get(int index)
{
   /* Variable currentIndex checks to see if it matches the index we're searching for, */
   int currentIndex = 0;
   struct node *cur;
   for (cur = head; cur != NULL; cur = cur->next)
   {
      if (currentIndex == index)
         return cur->data; /* Return data of the current index. */
      
      /* Increment current index to check if it matches with the next */
      currentIndex++;
   }
}
