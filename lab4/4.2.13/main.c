/*
Lab4, task 4.2.13 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int check8Number(char buffer[])
{
	int i = 0;
	for (; buffer[i] != '\0' && buffer[i] != '\n'; i++)
	{
		if (buffer[i] > '7' || buffer[i] < '0')
			return 0;
	}
	return 1;
}

void charSwap(char *first, char *second)
{
	char third = *first;
	*first = *second;
	*second = third;
}

int strSize(char string[])
{
	int i = 0;
	for (; string[i] != '\0'; i++) {}
	return i;
}

void intToStr(int number, char result[])
{
	char toAdd[1];
	while (number != 0)
	{
		sprintf(toAdd, "%d", number%10);
		number /= 10;
		strcat(result, toAdd);
	}
}

void str8ToStr10(char buffer[], char result[])
{
	int intResult = 0;
	int mn = 1;
	int i;
	for (i = strSize(buffer) - 1; i >= 0; i--)
	{
		if (buffer[i] == '\n') continue;
		intResult += (buffer[i] - '0') * mn;
		mn *= 8;
	}
	intToStr(intResult, result);
}

void strReverse(char string[])
{
	int n = strSize(string);
	int left = 0, right = n - 1;
	while (left < right)
	{
		charSwap(&string[left], &string[right]);
		left++;
		right--;
	}
}



int main()
{
	/*Init variables begin */
	int i;
	char buffer[128];
	char numbers[128][128];
	char result[128];
	int numbersIndex = 0;
	FILE *fp;
	/* Init variables end */

	fp = fopen("number.txt", "r");
	if (!fp)
	{
		printf("File can not be opened or not found.\n");
		return 1;
	}

	while (fgets(buffer, 128, fp) != NULL)
	{
		if (!check8Number(buffer))
		{
			printf("Incorrect number found (%s). Skipping..\n", buffer);
			continue;
		}
		memset(result, 0, strlen(result));
		str8ToStr10(buffer, result);
		strcpy(numbers[numbersIndex++], result);
	}

	fclose(fp);
	fp = fopen("number.txt", "w");
	if (!fp)
	{
		printf("File can not be opened / created.");
		return 1;
	}
	for (i = 0; i < numbersIndex; i++)
	{
		strReverse(numbers[i]);
		fputs(numbers[i], fp);
		fputs("\n", fp);
		printf("%s\n", numbers[i]);
	}
	fclose(fp);
	return 0;
}