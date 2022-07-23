#include <stdio.h>

main()
{
  int c, a;
  int count = 0;

  c = getchar();
  while (c != EOF) /* no end of file*/
  {
    count++;
    if (c == 'a')
    {
      a++;
    }

    c = getchar(); /* read next */
  }
  printf("# of chars: %d\n", count);
  printf("# of char 'a': %d\n", a);
}
