/***************************************
 * 22S – Lab2 *
 * Author: Alam, Araf A *
 * Email: araf821@my.yorku.ca *
 * eecs_username: araf821 *
 * York Student #: 218124347
 ****************************************/

#include <stdio.h>

#define SIZE 10

int isPrime(int);

int main()
{
  int i;
  int arr[SIZE];
  srand(time(0));
  for (i = 0; i < SIZE; i++)
  {
    int ran = rand() % 41; /* random number in range of [0,40] inclusive */
    arr[i] = ran;
  }

  /* display array */
  printf("array [ ");
  for (i = 0; i < SIZE; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("]\n");

  /* scan the array to find even and prime numbers, and put them in corresponding arrays */
  /* create two arrays of same size of arr, to hold even and prime numbers; you may add other variables as needed */
  int evenNumbers[SIZE];
  int primeNumbers[SIZE];

  /* output even numbers */
  int j = 0;
  for (i = 0; i < SIZE; i++)
  {
    if (arr[i] % 2 == 0)
    {
      evenNumbers[j] = arr[i];
      j++;
    }
  }
  printf("%d even numbers: ", j);
  for (i = 0; i < j; i++)
  {
    printf("%d ", evenNumbers[i]);
  }

  /* output prime numbers */
  j = 0;
  for (i = 0; i < SIZE; i++)
  {
    if (isPrime(arr[i]))
    {
      primeNumbers[j] = arr[i];
      j++;
    }
  }
  printf("\n%d prime numbers: ", j);
  for (i = 0; i < j; i++)
    printf("%d ", primeNumbers[i]);
  printf("\n");
}

int isPrime(int n)
{
  int i;
  if (n <= 1)
  {
    return 0;
  }
  else if (n % 2 == 0)
  {
    return 0;
  }
  else if (n == 2)
  {
    return 1;
  }

  for (i = 3; i <= (n/2); i +=2 ) {
    if (n % i == 0) {
      return 0;
    }
  }

  return 1;
}
