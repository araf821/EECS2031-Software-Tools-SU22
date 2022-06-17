#include <stdio.h>

int main()
{

    int c;
    int digits[10] = {0};
    int counter = 0;
    int others;

    while (c != EOF)
    {

        if (c == '0')
        {
            digits[0]++;
        }
        else if (c == '1')
        {
            digits[1]++;
        }
        else if (c == '2')
        {
            digits[2]++;
        }
        else if (c == '3')
        {
            digits[3]++;
        }
        else if (c == '4')
        {
            digits[4]++;
        }
        else if (c == '5')
        {
            digits[5]++;
        }
        else if (c == '6')
        {
            digits[6]++;
        }
        else if (c == '7')
        {
            digits[7]++;
        }
        else if (c == '8')
        {
            digits[8]++;
        }
        else if (c == '9')
        {
            digits[9]++;
        } else {
            others++;
        }
        c = getchar();
    }
    printf("\n");
    while (counter < 10)
    {
        printf("%d: %d\n", counter, digits[counter]);
        counter++;
    }
    printf("X: %d\n", others);
}
