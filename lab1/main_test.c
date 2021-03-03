#include "main.h"
#include <assert.h>
#include <stdio.h>

void test_checkInput()
{
	assert(checkInput("!") == 0);
	assert(checkInput("123") == 1);
	assert(checkInput("1") == 1);
	assert(checkInput("0") == 1);
	assert(checkInput("abdsa") == 0);
	assert(checkInput("10af") == 0);
}

void test_getSumDivers()
{
	assert(getSumDivers(1) == 0);
	assert(getSumDivers(2) == 1);
	assert(getSumDivers(0) == 0);
	assert(getSumDivers(3) == 1);
	assert(getSumDivers(7) == 1);
	assert(getSumDivers(6) == 6);
}
#undef main

int main()
{
	test_checkInput();
	test_getSumDivers();
	return 0;
}