/* Lab3, task 3.2.13 
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "main.h"

int positiveIntInput(char buffer[], int maxValue)
{
	int i = 0, result;
	for (; buffer[i] != '\0'; i++)
	{
		if (i > 8)
			return 0;
		if (buffer[i] > '9' || buffer[i] < '0')
			return 0;
	}
	result = atoi(buffer);
	if (result == 0 || result > maxValue)
		return 0;
	return 1;
}


void precalc(char (*nmb)[7][128])
{
	int i, j;
	/* 1 */
	strcpy(nmb[1][1], "один");
	strcpy(nmb[1][2], "одного");
	strcpy(nmb[1][3], "одному");
	strcpy(nmb[1][4], "один");
	strcpy(nmb[1][5], "одним");
	strcpy(nmb[1][6], "одним");

	/* 2 */
	strcpy(nmb[2][1], "два");
	strcpy(nmb[2][2], "двух");
	strcpy(nmb[2][3], "двум");
	strcpy(nmb[2][4], "два");
	strcpy(nmb[2][5], "двумя");
	strcpy(nmb[2][6], "двух");

	/* 3 */
	strcpy(nmb[3][1], "три");
	strcpy(nmb[3][2], "трёх");
	strcpy(nmb[3][3], "трём");
	strcpy(nmb[3][4], "три");
	strcpy(nmb[3][5], "тремя");
	strcpy(nmb[3][6], "трёх");

	/* 4 */
	strcpy(nmb[4][1], "четыре");
	strcpy(nmb[4][2], "четырёх");
	strcpy(nmb[4][3], "четырём");
	strcpy(nmb[4][4], "четыре");
	strcpy(nmb[4][5], "четырьмя");
	strcpy(nmb[4][6], "четырёх");

	/* 5 - 20, 30 */
	strcpy(nmb[5][1], "пят");
	strcpy(nmb[6][1], "шест");
	strcpy(nmb[7][1], "сем");
	strcpy(nmb[8][1], "восем");
	strcpy(nmb[9][1], "девят");
	strcpy(nmb[10][1], "десят");
	strcpy(nmb[11][1], "одиннадцат");
	strcpy(nmb[12][1], "двенадцат");
	strcpy(nmb[13][1], "тринадцат");
	strcpy(nmb[14][1], "четырнадцат");
	strcpy(nmb[15][1], "пятнацдат");
	strcpy(nmb[16][1], "шестнадцат");
	strcpy(nmb[17][1], "семнадцат");
	strcpy(nmb[18][1], "восемнадцат");
	strcpy(nmb[19][1], "девятнадцат");
	strcpy(nmb[20][1], "двадцат");
	strcpy(nmb[30][1], "тридцат");

	for (i = 5; i <= 30; i++)
	{
		if (i > 20 && i < 30)
			continue;
		for (j = 2; j <= 6; j++)
		{
			strcpy(nmb[i][j], nmb[i][1]);
		}
	}
	for (i = 5; i <= 30; i++)
	{
		if (i > 20 && i < 30)
			continue;
		strcat(nmb[i][1], "ь");
		strcat(nmb[i][2], "и");
		strcat(nmb[i][3], "и");
		strcat(nmb[i][4], "ь");
		strcat(nmb[i][5], "ью");
		strcat(nmb[i][6], "и");
	}

	/* 40, 90, 100 */
	strcpy(nmb[40][1], "сорок");
	strcpy(nmb[40][2], "сорока");
	strcpy(nmb[40][3], "сорока");
	strcpy(nmb[40][4], "сорок");
	strcpy(nmb[40][5], "сорока");
	strcpy(nmb[40][6], "сорока");

	strcpy(nmb[90][1], "девяносто");
	strcpy(nmb[90][2], "девяноста");
	strcpy(nmb[90][3], "девяносто");
	strcpy(nmb[90][4], "девяносто");
	strcpy(nmb[90][5], "девяноста");
	strcpy(nmb[90][6], "девяноста");

	strcpy(nmb[100][1], "сто");
	strcpy(nmb[100][2], "ста");
	strcpy(nmb[100][3], "ста");
	strcpy(nmb[100][4], "сто");
	strcpy(nmb[100][5], "ста");
	strcpy(nmb[100][6], "ста");

	/* 200 - 900 */
	strcpy(nmb[200][1], "двести");
	strcpy(nmb[200][2], "двухсот");
	strcpy(nmb[200][3], "двумстам");
	strcpy(nmb[200][4], "двести");
	strcpy(nmb[200][5], "двумястами");
	strcpy(nmb[200][6], "двухстах");

	strcpy(nmb[300][1], "триста");
	strcpy(nmb[300][2], "трёхсот");
	strcpy(nmb[300][3], "трёмстам");
	strcpy(nmb[300][4], "триста");
	strcpy(nmb[300][5], "тремястами");
	strcpy(nmb[300][6], "трёхстах");

	strcpy(nmb[400][1], "четыреста");
	strcpy(nmb[400][2], "четырёхсот");
	strcpy(nmb[400][3], "четырёмстам");
	strcpy(nmb[400][4], "четыреста");
	strcpy(nmb[400][5], "четырьмястами");
	strcpy(nmb[400][6], "четырёхстах");

	strcpy(nmb[500][1], "пятьсот");
	strcpy(nmb[500][2], "пятисот");
	strcpy(nmb[500][3], "пятисот");
	strcpy(nmb[500][4], "пятьсот");
	strcpy(nmb[500][5], "пятьюстами");
	strcpy(nmb[500][6], "пятистах");

	strcpy(nmb[600][1], "шестьсот");
	strcpy(nmb[600][2], "шестисот");
	strcpy(nmb[600][3], "шестисот");
	strcpy(nmb[600][4], "шестьсот");
	strcpy(nmb[600][5], "шестьюстами");
	strcpy(nmb[600][6], "шестистах");

	strcpy(nmb[700][1], "семьсот");
	strcpy(nmb[700][2], "семисот");
	strcpy(nmb[700][3], "семисот");
	strcpy(nmb[700][4], "семьсот");
	strcpy(nmb[700][5], "семьюстами");
	strcpy(nmb[700][6], "семистах");

	strcpy(nmb[800][1], "восемьсот");
	strcpy(nmb[800][2], "восьмисот");
	strcpy(nmb[800][3], "восьмисот");
	strcpy(nmb[800][4], "восемьсот");
	strcpy(nmb[800][5], "восемьюстами");
	strcpy(nmb[800][6], "восьмистах");

	strcpy(nmb[900][1], "девятьсот");
	strcpy(nmb[900][2], "девятисот");
	strcpy(nmb[900][3], "девятисот");
	strcpy(nmb[900][4], "девятьсот");
	strcpy(nmb[900][5], "девятьюстами");
	strcpy(nmb[900][6], "девятистах");

	/* 50 - 80 */
	strcpy(nmb[50][1], "пятьдесят");
	strcpy(nmb[50][2], "пятидесяти");
	strcpy(nmb[50][3], "пятидесяти");
	strcpy(nmb[50][4], "пятьдесят");
	strcpy(nmb[50][5], "пятьюдесятью");
	strcpy(nmb[50][6], "пятидесяти");

	strcpy(nmb[60][1], "шестьдесят");
	strcpy(nmb[60][2], "шестидесяти");
	strcpy(nmb[60][3], "шестидесяти");
	strcpy(nmb[60][4], "шестьдесят");
	strcpy(nmb[60][5], "шестьюдесятью");
	strcpy(nmb[60][6], "шестидесяти");

	strcpy(nmb[70][1], "семьдесят");
	strcpy(nmb[70][2], "семидесяти");
	strcpy(nmb[70][3], "семидесяти");
	strcpy(nmb[70][4], "семьдесят");
	strcpy(nmb[70][5], "семьдесятью");
	strcpy(nmb[70][6], "семидесяти");

	strcpy(nmb[80][1], "восемьдесят");
	strcpy(nmb[80][2], "восьмидесяти");
	strcpy(nmb[80][3], "восьмидесяти");
	strcpy(nmb[80][4], "восемьдесят");
	strcpy(nmb[80][5], "восемьюдесятью");
	strcpy(nmb[80][6], "восьмидесяти");

	/* 1000 */
	strcpy(nmb[1000][1], "тысяча");
	strcpy(nmb[1000][2], "тысячи");
	strcpy(nmb[1000][3], "тысячи");
	strcpy(nmb[1000][4], "тысяча");
	strcpy(nmb[1000][5], "тысячью");
	strcpy(nmb[1000][6], "тысячах");
}

char* calc(int n, int cs, char (*nmb)[7][128])
{
	char* result;
	int first, second, third;
	first = n%10;
	second = n/10%10;
	third = n/100;
	if (third == 10) return nmb[n][cs];
	if (n <= 20)
	{
		return (nmb[n][cs]);
	}

	if (n < 100)
	{
		if (first == 0) return nmb[n][cs];
		result = nmb[second * 10][cs];
		strcat(result, " ");
		strcat(result, nmb[first][cs]);
		return result;
	}

	else
	{
		if (first == 0 && second == 0) return nmb[n][cs];
		if (first == 0)
		{
			result = nmb[third * 100][cs];
			strcat(result, " ");
			strcat(result, nmb[second * 10][cs]);
			return result;
		}
		if (second == 0)
		{
			result = nmb[third * 100][cs];
			strcat(result, " ");
			strcat(result, nmb[first][cs]);
			return result;
		}
		else
		{
			result = nmb[third * 100][cs];
			strcat(result, " ");
			strcat(result, nmb[second * 10][cs]);
			strcat(result, " ");
			strcat(result, nmb[first][cs]);
			return result;
		}
	}
}

int main()
{
	/*Init variables begin */
	int n;
	char buffer[128];
	char rusNumbers[1001][7][128];
	int cs;
	/* Init variables end */

	setlocale(LC_ALL, "Rus");
	printf("Введите целое положительное N (<=1000):\n");
	scanf("%s", buffer);
	while (positiveIntInput(buffer, 1000) == 0)
	{
		printf("Неверный ввод! Введите целое положительное число (N <= 1000)!\n");
		return 0;
		scanf("%s", buffer);
	}
	n = atoi(buffer);

	printf("Выберите падеж: \n1 - Именительный\n2 - Родительный\n3 - Дательный\n4 - Винительный\n5 - Творительный\n6 - Предложный\n");
	scanf("%s", buffer);
	while (positiveIntInput(buffer, 6) == 0)
	{
		printf("Неверный ввод! Введите целое положительное число (<=6)!\n");
		scanf("%s", buffer);
	}
	cs = atoi(buffer);
	precalc(rusNumbers);
	printf("%s\n", calc(n, cs, rusNumbers));
	return 0;
}