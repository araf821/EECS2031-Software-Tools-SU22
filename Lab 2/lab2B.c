/***************************************
 * 22S – Lab2 *
 * Author: Alam, Araf A *
 * Email: araf821@my.yorku.ca *
 * eecs_username: araf821 *
 * York Student #: 218124347
 ****************************************/

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
