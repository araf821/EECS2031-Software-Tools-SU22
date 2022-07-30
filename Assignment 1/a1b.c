/*
Problem:  Get an input from the user of text containing integer literals.
          
          Our program should detect each integer manually and form float
          values from the input, all while separating each value from the
          other every time there is a space, a new line, or any unaccpeted
          character.

          The program should store each value within an array and then display
          each value of the array with up to 4 decimal points in each line 
          along with what the (value * 2) should be.

          For example, if the input is:
          1.23 56.9 9.999
          2.654987321
          1 -5 -6.369

          The output should be:

          1.2300    2.4600
          56.9000   113.8000
          2.6550    5.3100
          1.0000    2.0000
          -5.0000   -10.0000
          -6.3690   -12.7380 
*/

#include <stdio.h>
#define SIZE 40 /* Assume that the input has no more than 40 characters. */

int acceptedLiteral(float);

int main()
{

  /* 
    Change the int values to float for the new program to work.
  */
  float c;
  float value = 0;
  float resu[SIZE];
  
  /*
    The count variable keeps count of how many values are being
    stored in the array.
    
    The neg variable keeps track of whether or not the current
    integer has a negative sign before it.

    The dec variable keeps track of whether or not we have come
    across a decimal during our current sequence of integers. 
  */
  int count = 0, i = 1, neg = 0, dec = 0;

  c = getchar();
  while (c != EOF)
  {

    while (c == '-' || c == '.' || (c >= '0' && c <= '9'))
    {
      /* 
        Check to see if there is a decimal, we then set some conditions to
        deal with literals after the decimal.
      */
      if (c == '.')
      {
        dec = 1;
        c = getchar();
        i = 10;
      }

      /*
        Check to see if c is a negative sign, we then set some conditions to
        deal with the negative value.
      */
      if (c == '-')
      {
        neg = 1;
        c = getchar();
      }

      if (dec) /* If the char is after a decimal point */
      {
        value = value + (c - 48) / i;
        i *= 10;
      }
      else /* Otherwise, same process as program a1A.c */
      {
        value = (value * i) + (c - 48);
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
      }
      else
      {
        resu[count] = value;
        count++;
      }
    }

    
    i = 1, dec = 0, neg = 0, value = 0; /* Reset these values to the default values */
    c = getchar();
  }

  printf("-----------------------------------\n");

  for (i = 0; i < count; i++)
  {
    printf("%.4f\t%.4f\n", resu[i], resu[i] * 2);
  }

  return 0;
}

/*
  This function exists to make the above program more readable.
*/
int acceptedLiteral(float c)
{
  if (c == '-' || c == '.' || (c >= '0' && c <= '9'))
  {
    return 1;
  }
  return 0;
}
