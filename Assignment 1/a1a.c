/*
Problem:  Get an input from the user of text containing integer literals.
          There may be spaces or new lines. There can also be negative integers
          or letters. Our program should store integers and ignore anything else,
          it should also be able to detect negative integers, in other words, it
          should be able to detect whenever the text contains a negative sign and
          make sure that the upcoming integer is represented as a negative integer.
          The program should store each integer within an array and then display
          each value of the array in each line along with what the (value * 2)
          should be.

          For example, if the input is:
          12 23 -4
          6

          The output should be:
          12    24
          23    46
          -4    -8
          6     12
*/

#include <stdio.h>
#define SIZE 40 /* Assume that the input has no more than 40 characters. */
int main()
{

  int c;
  int value = 0;
  int resu[SIZE];
  /*
    The count variable keeps count of how many values are being
    stored in the array and the neg variable keeps track of
    whether or not the current integer has a negative sign
    before it.
  */
  int count = 0, i = 1, neg = 0;

  c = getchar();
  while (c != EOF)
  {
    while ((c == 45) || (c >= 48 && c <= 57))
    {
      if (c == 45)
      {
        neg = 1;
      }
      else
      {
        value = (value * i) + (c - 48);
        /* Once an integer is added to the value, we set the value of i to 10.
        This is to ensure that if there is another integer right after the one
        that was just added, it won't be added to the current value. The current
        value will be multiplied by 10 to make space in the ones place. */
        i = 10;
      }

      c = getchar();
    }

    if (value != 0)
    {
      if (neg)
      {
        resu[count] = value * (-1);
        count++;
        value = 0;
        neg = 0;
      }
      else
      {
        resu[count] = value;
        count++;
        value = 0;
      }
    }
    i = 1;
    c = getchar();
  }

  printf("-----------------------------------\n");

  for (i = 0; i < count; i++)
  {
    printf("%d\t%d\n", resu[i], resu[i] * 2);
  }

  return 0;
}
