#include <stdio.h> // define EOF

int main()
{
  int c;
  int count = 0;
  int blanks = 0;
  int lines = 0;

  c = getchar();
  while (c != EOF) /* no end of file*/
  {

    if (c == '\n')
    {
      lines++;
    }
    else if (c == ' ')
    {
      blanks++;
      count++;
    }
    else
    {
      count++;
    }

    c = getchar(); /* read next */
  }
  printf("# of chars: %d (# of blanks: %d)\n", count, blanks);
  printf("# of lines: %d\n", lines);
  return 0;
}
