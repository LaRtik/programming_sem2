#include "main.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_check8Number()
{
	assert(check8Number("132") == 1);
	assert(check8Number("888") == 0);
	assert(check8Number("abacaba") == 0);
	assert(check8Number("8a") == 0);
	assert(check8Number("8") == 0);
	assert(check8Number("127") == 1);
}

void test_charSwap()
{
	char a = 'A';
	char b = 'B';
	charSwap(&a, &b);
	assert(a == 'B' && b == 'A');
}

void test_strSize()
{
	assert(strSize("ab") == 2);
	assert(strSize("aba") == 3);
	assert(strSize("123") == 3);
	assert(strSize("z") == 1);
}

void test_intToStr()
{
	int number = 228;
	char* str = 0;
	intToStr(number, str);
	assert(strcmp(str, "228") == 0);
}

void test_str8ToStr10()
{
	char input[] = "12345";
	char result[128];
	str8ToStr10(input, result);
	assert(strcmp(result, "5349") == 0);
}

void test_strReverse()
{
	char string[] = "12896";
	strReverse(string);
	assert(strcmp(string, "69821") == 0);
}

#undef main

int main()
{
	test_charSwap();
	test_check8Number();
	test_intToStr();
	test_str8ToStr10();
	test_strReverse();
	test_strSize();
	return 0;
}