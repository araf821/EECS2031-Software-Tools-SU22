#include <stdio.h> 

int isLetter(char);
int isDigit(char);
int isOperator(char);

int main()
{

    int number;
    char character;

    while (1)
    {
        printf("Enter an integer and a character separated by blank: ");
        scanf("%d %c", &number, &character);

        if (number == -10000)
        {
            break;
        }

        if (isDigit(character))
        {
            printf("Character '%d' represents a digit. Sum of %d and %d is %d\n\n", (character - 48), number, (character - 48), (number + character - 48));
        }
        else if (isLetter(character))
        {
            printf("Character '%c' represents a letter.\n\n", character);
        }
        else if (isOperator(character))
        {
            printf("Character '%c' represents an operator.\n\n", character);
        }
        else
        {
            printf("Character '%c' represents others.\n\n", character);
        }
    }
}

int isDigit(char c)
{
    if (c >= 48 && c <= 57)
    {
        return 1;
    }
    return 0;
}

int isLetter(char c)
{
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
    {
        return 1;
    }
    return 0;
}

int isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
    {
        return 1;
    }
    return 0;
}
