#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int nEps; /* | sin (X) - right | < EPSILON, when N = nEps */

int factorial(int n)
{
    if(n < 0) return 0;
    if (n == 0) return 1;
    else return n * factorial(n-1);
}

float calcRightEps(float x, int n, float eps)
{
	int i;
	float result = 0, right = 0;
	for (i = 1; i <= n || abs(sin(x) - right) <= eps; i++)
    {
		if (2 * i - 1 > 42) return result;
        right += pow(-1, (i-1)) * (pow(x, (2*i-1)) / factorial(2*i-1));
		if (i == n) result = right;
		if (abs(sin(x) - right) <= eps && nEps == 0) nEps = i;
	}
	return result;
}

int positiveIntInput(char buffer[])
{
    int i = 0, result;
    for (; buffer[i] != '\0'; i++)
    {
        if (i > 8) return 0;
        if (buffer[i] > '9' || buffer[i] < '0') return 0;
    }
	result = atoi(buffer);
	if (result == 0) return 0;
    return 1;
}

int FloatInput(char buffer[])
{
	int i;
		
	if (strlen(buffer) > 20) return 0;
	for (i = 0; i<strlen(buffer); i++)
	{
		if ((buffer[i] > '9' || buffer[i] < '0') && buffer[i] != '.' && buffer[i] != '-') return 0;
	}
    return 1;
}


int main()
{
    float x, eps;
    int n;
	char buffer[128];

    printf("Enter N (positive integer):\n");
	scanf("%s", buffer);
    while (positiveIntInput(buffer) == 0)
    {
		printf("Incorrect input! Enter positive integer number (<9 digits)!\n");
		scanf("%s", buffer);
	}
	n = atoi(buffer);

    printf("Enter X (real):\n");
	scanf("%s", buffer);
    while (FloatInput(buffer) == 0)
    {
		printf("Incorrect input! Enter real number (<9 digits)!\n");
		scanf("%s", buffer);
	}
	x = atof(buffer);


	printf("Enter EPSILON (real):\n");
	scanf("%s", buffer);
    while (FloatInput(buffer) == 0)
    {
		printf("Incorrect input! Enter real number (<9 digits)!\n");
		scanf("%s", buffer);
	}
	eps = atof(buffer);
	eps = abs(eps);

    printf("left = %f, right = %f\n", sin(x), calcRightEps(x,n, eps));

	printf("| sin (X) - right | < EPSILON, when N = %d\n", nEps);

    return 0;
}