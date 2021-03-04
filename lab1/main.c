/*
Lab 1. Programming
Prints the numbers from [0..number], according to the condition:
the sum of the divisors of the number is equal to the number itself
*/

#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int checkInput(char buffer[])
{
    int i = 0;
    for (; buffer[i] != '\0'; i++)
    {
        if (i > 7)
        {
            printf("Too big number! Try again!\n\n");
            return 0;
        }
        if (buffer[i] <= '9' && buffer[i] >= '0') continue;
        else
        {
            printf("Incorrent input! Please, enter integer (less than 9 digits) value. \n\n");
            return 0;
        }  
    }
    return 1;
}

int getSumDivers(int number)
{
    int result = 0, i;
    for (i = 1; i < number; i++)
    {
        if (number % i == 0)
        {
            result += i;
        }
    }
    return result;
}

int main()
{
    int number, cNumber;
    char buffer[128];
    printf("Enter an integer number:\n");
    do
    {
        scanf("%s", buffer);
    } while (checkInput(buffer) == 0);
    number = atoi(buffer);
    for (cNumber = 1; cNumber <= number; cNumber++)
    {
        int sumDivers = getSumDivers(cNumber);
        if (sumDivers == cNumber)
        {
            printf("answer: %d\n", cNumber);
        }
    }
    
    return 0;
}
