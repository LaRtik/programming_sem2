#include "main.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void test_postitiveIntInput()
{
	assert(positiveIntInput("!", 1000) == 0);
	assert(positiveIntInput("123", 1000) == 1);
	assert(positiveIntInput("1", 1) == 1);
	assert(positiveIntInput("0", 0) == 0);
	assert(positiveIntInput("abdsa", 1000) == 0);
	assert(positiveIntInput("10af", 1000) == 0);
	assert(positiveIntInput("1486168416486518416.548447", 1000) == 0);
	assert(positiveIntInput("0.01", 100) == 0);
	assert(positiveIntInput("-0.01", 1) == 0);
	assert(positiveIntInput("128", 127) == 0);
}
#undef main

int main()
{
	test_postitiveIntInput();
	return 0;
}