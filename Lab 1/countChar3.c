/***************************************
 * 22SU - Lab01 *
 * Author: Alam, Araf A *
 * Email: araf821@my.yorku.ca *
 * eecs_username: araf821 *
 * York Student #: 218124347
 ****************************************/

#include <stdio.h>

main()
{
  int c;
  int count = 0;

  c = getchar();
  while (c != EOF) /* no end of file*/
  {

    if (c != '\n')
    {
      count++;
    }

    c = getchar(); /* read next */
  }
  printf("# of chars: %d\n", count);
}
