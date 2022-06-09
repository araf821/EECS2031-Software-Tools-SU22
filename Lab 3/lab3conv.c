/***************************************
 * 22S - Lab03 *
 * Author: Alam, Araf *
 * Email: araf821@my.yorku.ca *
 * eecs_username: araf821 *
 * Yorku Student #: 218124347
 ************************************** **/

#include <stdio.h>

float func_IF(int, char, float);
float func_II(int, char, int);
float func_FF(float, char, float);

int main()
{

    int op1;
    float op2;
    char operator;
    float resu, resu2, resu3;

    float a = 9 / 2;
    float b = 9 * 1.0 / 2;    /* force 9 to be converted before */
    float c = 9 / 2 * 1.0;    /* force 2 to be converted before, but not working */
    float c2 = 9 / (2 * 1.0); /* force 2 to be converted before */
    float d = (float)9 / 2;   /* cast 9 before */
    float e = 9 / (float)2;   /* cast 2 before */
    float f = (float)(9 / 2); /* cast after, nope */
    printf("9/2=%f  9*1.0/2=%f  9/2*1.0=%f   9/(2*1.0)=%f\n\n", a, b, c, c2);
    printf("(float)9/2=%f  9/(float)2=%f  (float)(9/2)=%f\n\n", d, e, f);

    /* conversion in arithemetic */
    printf("3.0*9/2/4=%f  9/2*3.0/4=%f  9*3/2*3.0/4=%f\n\n", 3.0 * 9 / 2 / 4, 9 / 2 * 3.0 / 4, 9 / 2 * 3.0 / 4);

    /* conversion in assignment */
    float f2 = 3.96;
    float f3 = 3.03;
    int i = f2;
    int j = f3;
    printf("i: %d  j: %d\n\n", i, j);

    /* Start of the program */
    printf("Enter operand_1 operator operand_2 separated by blanks: ");
    scanf("%d %c %f", &op1, &operator, & op2);

    /* The program keeps on running unless the value of op1 is less than 0 */
    while (op1 >= 0)
    {
        /* Assigning each of the results to their respective variables */
        resu = func_IF(op1, operator, op2);
        resu2 = func_II(op1, operator, op2);
        resu3 = func_FF(op1, operator, op2);

        /* Declaring the results of each function followed by the input */
        printf("Your input '%d %c %f' result in\n", op1, operator, op2);
        printf("%f (func_IF)\n", resu);
        printf("%f (func_II)\n", resu2);
        printf("%f (func_FF)\n", resu3);

        /* Restart the program */
        printf("\nEnter operand_1 operator operand_2 separated by blanks: ");
        scanf("%d %c %f", &op1, &operator, & op2);
    }

    /* End of the program */
    printf("- Program Terminated -\n");

    return 0;
}

float func_IF(int op1, char operator, float op2)
{
    float result = 0;

    if (operator== 43)
    {
        result = op1 + op2;
    }
    else if (operator== 45)
    {
        result = op1 - op2;
    }
    else if (operator== 42)
    {
        result = op1 * op2;
    }
    else if (operator== 47)
    {
        result = op1 / op2;
    }

    return result;
}

float func_II(int op1, char operator, int op2)
{
    float result = 0;

    if (operator== 43)
    {
        result = op1 + op2;
    }
    else if (operator== 45)
    {
        result = op1 - op2;
    }
    else if (operator== 42)
    {
        result = op1 * op2;
    }
    else if (operator== 47)
    {
        result = op1 / op2;
    }

    return result;
}

float func_FF(float op1, char operator, float op2)
{
    float result = 0;

    if (operator== 43)
    {
        result = op1 + op2;
    }
    else if (operator== 45)
    {
        result = op1 - op2;
    }
    else if (operator== 42)
    {
        result = op1 * op2;
    }
    else if (operator== 47)
    {
        result = op1 / op2;
    }

    return result;
}

/*  your explanations

    IF and FF have the same answers, the accurate answers, because at least
    one of the variables is in float. However, for II, both values being int
    means that only the digits before the decimal point are taken into cons-
    ideration.

    For example, we see earlier that int i = 3.96 converts to just 3. This is
    because for integers, only the digit before the decimal is taken into
    consideration. It is not being rounded up nor down. The values after the
    decimal point are simply being ignored.

*/
