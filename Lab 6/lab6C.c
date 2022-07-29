#include <stdio.h>
#include <string.h>
#define SIZE 11

void exchangeParr(char *[], int);
void printParr(char *[], int);
void printParr2(char **, int);

int main()
{

  char *inputs[SIZE] = {"giraffes are high 0", "mosquitos are annoying 1",
                        "monkeys are smart 2", "kangaroos are funny 3"};

  char arr1[] = "dogs are friendly 4";
  char arr2[] = "hippos are huge 5";
  char arr3[] = "cobras are fearsome 6";
  char arr4[] = "foxes 7";
  char arr5[] = "elephants 8";
  char arr6[] = "hens 9";
  char arr7[] = "bisons 10";

  inputs[4] = arr1;
  inputs[5] = arr2;
  inputs[6] = arr3;
  inputs[7] = arr4;
  inputs[8] = arr5;
  inputs[9] = arr6;
  inputs[10] = arr7;

  printf("sizeof char*: %ld, sizeof pointer array: %ld\n\n", sizeof(char *), sizeof inputs);

  /* display the array by calling function printParr() */
  printParr(inputs, SIZE);

  /* swap pointees of first and second element pointers here */
  char *tempPointer; /* create a temporary pointer */
  /* Make the temp pointer point to whatever inputs[0] was pointing to */
  tempPointer = inputs[0];
  /* Make pointer of inputs[0] point to the pointee of inputs[1] */
  inputs[0] = inputs[1];
  /* Make pointer of inputs[1] point to the pointee of the temp pointer */
  inputs[1] = tempPointer;

  /* call function exchangeParr() to swap some other pointees */
  exchangeParr(inputs, SIZE);

  printf("\n== after swapping ==\n");
  printf("===========================\n");

  /* now display the exchanged array by calling function printParr() */
  printParr(inputs, SIZE);

  printf("\n");

  /* display the exchanged array again by calling another function printParr2() */ 
  printParr2(inputs, SIZE);
}

/* exchange some pointees of the pointer array */
void exchangeParr(char *pArr[], int n)
{
  int i;
  char *tempPointer;
  for (i = 2; i < n - 1; i += 2)
  {
    tempPointer = pArr[i];
    pArr[i] = pArr[i + 1];
    pArr[i + 1] = tempPointer;
  }
}

/* print the first n pointees of the pointer array */
void printParr(char *pArr[], int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    printf("[%d]: -*-> %s\n", i, pArr[i]);
  }
}

/* print the first n pointees of the pointer array, 'decay' */
void printParr2(char **pArr, int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    printf("[%d]: -*-> %s\n", i, *(pArr + i));
  }
}
