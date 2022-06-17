#include <stdio.h>

int main()
{ 

    char c;

    while (c != EOF)
    {
        if (c >= 97 && c <= 122)
        {
            c = c - 32;
        }
        else if (c >= 48 && c < 53)
        {
            c = '-';
        }
        else if (c > 53 && c <= 57)
        {
            c = '+';
        }
        printf("%c", c);
        c = getchar();
    }
    
    printf("\n");

}
