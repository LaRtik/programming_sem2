/*
Lab 2. Programming
task 2.1 (14)
Supports next functions:
Input:
- sphere radius

Output:
- surface area of a sphere
- volume of a sphere
- edge length of a sphere-inscribed regular tetrahedron
- cross-section area defined at a distance K from the sphere center
- program version && author

Void:
- program exit

*/

#include <stdio.h>
#include <stdlib.h> /* atof(); */
#include <string.h> /* strlen(); */
#include <math.h> /* sqrt(); */
#include "main.h"

const float pi = 3.1415; 

void versionAuthor()
{
	printf("Program version 1.0\nAuthor - Ilya Lazuk (github.com/lartik).\n");
}

int positiveFloatInput(char buffer[])
{
	float result;
	int i;
	
	if (strlen(buffer) > 20) return 0;
	for (i = 0; i<strlen(buffer); i++)
	{
		if ((buffer[i]>'9' || buffer[i]<'0') && buffer[i]!='.') return 0;
	}
	result = atof(buffer); /* char* to float / double value */
	if (abs(result) <= 1e-6 || result < 0) return 0;
    return 1;
}

float sphereArea(float sphereRadius) /* S = 4 * pi * R^2 */
{
	return sphereRadius * sphereRadius * 4 * pi;
}

float sphereVolume(float sphereRadius) /* V = 4/3 * pi * R^3 */
{
	return sphereRadius * sphereRadius * sphereRadius * 4/3 * pi;
}

float edgeLength(float sphereRadius) /*  R = a(sqrt6) / 4  */
{
	return sphereRadius * 4 / sqrt(6);
}

float crossArea(float sphereRadius, float k) /* R^2 = r^2 - k^2 */
{
	float newSquareRadius = (sphereRadius * sphereRadius) - (k * k);
	return newSquareRadius * pi;  
}

int main()
{
    float sphereRadius, K;
	char buffer[128];
	int choice;

	printf("Enter sphere radius (positive real number <20 digits):\n");
    scanf("%s", buffer);
	while (positiveFloatInput(buffer) == 0)
	{
		printf("Incorrect input! Enter positive real number (<20 digits)!\n");
		scanf("%s", buffer);
	}
	sphereRadius = atof(buffer);
	choice = -1;
	while (choice != 6)
	{
		printf("Select function to perform:\n");
		printf("1. Surface area of a sphere.\n");		
		printf("2. Volume of a sphere.\n");		
		printf("3. Edge length of a sphere-inscribed regular tetrahedron.\n");		
		printf("4. Cross-section area defined at a distance K from the sphere center.\n");		
		printf("5. Program version && author.\n");		
		printf("6. Program exit.\n");
		printf("choice - ");
		scanf("%d", &choice);
		switch (choice)
		{
			case 1:
				printf("Surface area of a sphere is %f\n", sphereArea(sphereRadius));
				break;
			case 2:
				printf("Volume of a sphere is %f\n", sphereVolume(sphereRadius));
				break;
			case 3:
				printf("Edge length of a sphere-inscribed regular tetrahedron is %f\n", edgeLength(sphereRadius));
				break;
			case 4:
				printf("Enter K:\n");
				scanf("%s", buffer);
				while (positiveFloatInput(buffer) == 0)
				{
					printf("Incorrect input! Enter positive real number (<20 digits)!\n");
					scanf("%s", buffer);
				}
				K = atof(buffer);
				if (K > sphereRadius)
				{
					printf("K can not be greated than sphere radius");
					break;
				}
				printf("Cross-section area defined at a distance K from the sphere center is %f\n", crossArea(sphereRadius, K));
				break;
			case 5:
				versionAuthor();
				break;
			case 6:
				printf("Program exiting..."); 
				return 0;
				break;
			default:
				printf("Incorrect input! Program exiting...");
				return 0;
				break; 
		}
	}
    return 0;
}
