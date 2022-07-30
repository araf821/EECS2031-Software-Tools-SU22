#include <stdio.h>

/*********  DO NOT CHANGE THESE CONSTANTS IN THE FINAL SUBMISSION *********/

#define MAX_SIZE 20
#define SUCCESS 0

int size; 

/******************  YOUR CODE STARTS HERE ******************/

/************************************************************/
/*
   Input: array A with 'size' elemments in it, and an integer d
   Output: d is added to the array.
   Return a non-negative number if the addition is successful.
   Return a negative number if the addition is unsuccessful.
   Error condition(s): A reaches the MAX_SIZE already.
 */

int myAdd(int A[], int d)
{

  if (size < MAX_SIZE)
  {
    int i, index = 0;
    /*
      Step 1: Detect where to insert the value d.
    */
    for (i = 0; i < size; i++)
    {
      /* Every time we come across a value that is less than d,
      we increment our 'index' by 1. The loop stops as soon as
      d is greater than the value at index i, and our 'index'
      will be the value at which we store d at. */
      if (A[i] < d)
        index++;
      else
        break;
    }

    /*
      Step 2: Move over all the values in the array that
      are greater than d.
    */
    for (i = size; i > index; i--)
    {
      A[i] = A[i - 1];
    }

    /*
      Step 3: Add d to the 'index' of the array.
      Increase the size of the array by 1.
    */
    A[index] = d;
    size++;
    return 1;
  }

  return -1;
}

/*
   Input: array A with "size" elements in it, and an integer d
   Output: If d is found in the array, return the index of the cell containing d.
   Otherwise return a negative number if d is not found.
   Error condition(s): d is not found.

   note the search should be binary search, and iterative (i.e., no recursive)
 */
int myBinarySearch_Iterative(int A[], int d)
{
  /*
    start - the first index we are considering
    end - the last index we are considering
    Middle - the index in between start and end
    currentValue - the value we will be comparing to d to check for a match
  */
  int start = 0, end = size - 1, middle, currentValue;

  while (start <= end)
  {
    /* We set the middle value equal to the midpoint of end and start */
    middle = start + (end - start) / 2;
    /* Then we set the currentValue to the value at that midpoint.
    Here, currentValue represents the value that we will be
    comparing to d. */
    currentValue = A[middle];

    /* If the currentValue is less than d, we set the start point
    equal to the middle index(+1) and then loop again. */
    if (currentValue < d)
      start = middle + 1;

    /* If the currentValue is greater than d, we set the end
    point equal to the middle index(-1) and then loop again. */
    else if (currentValue > d)
      end = middle - 1;

    /* If the above conditions aren't met, then it's proof that
    the currentValue is equal to d, and thus, we return the current
    middle index. */
    else
      return middle;
  }
  return -1;
}

/*
   Input: array A with "size" elements in it, and an integer d
   Output: Return a negative number if d is not found.
   Otherwise d is removed from the array and return 0.
   Error condition(s): d does not exist in A.
 */

int myRemove(int A[], int d)
{
  /* found - determines if d is found in the array, 0 = false, 1 = true */
  int i, found = 0;

  /* Step 1: Loop through the array to look for d */
  for (i = 0; i < size; i++)
  {
    if (A[i] == d)
    {
      found = 1;
      break;
    }
  }

  if (found) /* if d is found */
  {
    for (i; i < size - 1; i++)
    {
      /* Replace the index of d with the next value in the array
      and continue to replace every other value of this array with
      the value at its next index */
      A[i] = A[i + 1];
    }
    /* Cut the size of the array by 1, since 1 value has been removed */
    size = size - 1;
    return 0;
  }

  return -1;
}

/*******************  YOUR CODE ENDS HERE *******************/
/************************************************************/

/*********  DO NOT CHANGE ANYTHING BELOW THIS LINE IN THE FINAL SUBMISSION *********/

/*
   Input: array A with "size" elements in it,
   Output: Display the array on the standard output with one space between every two numbers.
   Print a new line after the last element.
 */
int printArray(int A[])
{
  int i;
  printf("[ ");
  for (i = 0; i < size; i++)
    printf("%d ", A[i]);
  printf("]\n");
  return 0;
}

/*
  Main() function
*/
int main()
{
  int myArray[MAX_SIZE];
  int retCode, data, size;
  char action;
  char a[20];
  do
  {
    fgets(a, 20, stdin);
    sscanf(a, "%c %d", &action, &data);

    switch (action)
    {
    case 'a': /* add */
    case 'A':
      retCode = myAdd(myArray, data);
      if (retCode >= SUCCESS)
      {
        printArray(myArray);
      }
      else
        printf("Failed to add %d.\n", data);
      break;

    case 'r': /* remove */
    case 'R':
      retCode = myRemove(myArray, data);
      if (retCode >= SUCCESS)
      {
        printArray(myArray);
      }
      else
        printf("Failed to remove %d.\n", data);
      break;

    case 's': /* search */
    case 'S':
      retCode = myBinarySearch_Iterative(myArray, data);
      if (retCode >= 0)
        printf("Found %d at index %d.\n", data, retCode);
      else
        printf("Not found %d.\n", data);
      break;

    case 'q': /* quit */
    case 'Q':
      /* To quit, enter an arbitrary integer and character (action) 'q' or 'Q'.
         This is not elegant but makes the code simpler.  */
      /* Do nothing but exit the switch statement */
      break;

    default:
      printf("Invalid operation %c\n", action);
    }
  } while (action != 'q' && action != 'Q');

  return 0;
}
