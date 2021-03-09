#include "main.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void test_floatInput()
{
	assert(floatInput("!") == 0);
	assert(floatInput("123") == 1);
	assert(floatInput("1") == 1);
	assert(floatInput("0") == 1);
	assert(floatInput("abdsa") == 0);
	assert(floatInput("10af") == 0);
	assert(floatInput("1486168416486518416.548447") == 0);
	assert(floatInput("0.01") == 1);
	assert(floatInput("-0.01") == 1);
}

void test_postitiveIntInput()
{
	assert(positiveIntInput("!") == 0);
	assert(positiveIntInput("123") == 1);
	assert(positiveIntInput("1") == 1);
	assert(positiveIntInput("0") == 0);
	assert(positiveIntInput("abdsa") == 0);
	assert(positiveIntInput("10af") == 0);
	assert(positiveIntInput("1486168416486518416.548447") == 0);
	assert(positiveIntInput("0.01") == 0);
	assert(positiveIntInput("-0.01") == 0);
}

void test_factorial()
{
	assert(factorial(1) == 1);
	assert(factorial(2) == 2);
	assert(factorial(3) == 6);
	assert(factorial(5) == 120);
}

void test_calcRightEps()
{
	assert(abs(calcRightEps(1,1,3,0) - 1) <= 1e-5);
	assert(abs(calcRightEps(3,2,1,0) + 1.5) <= 1e-5);
	assert(abs(calcRightEps(5,5,2,0) - 0.089631) <= 1e-5);
}


#undef main

int main()
{
	test_floatInput();
	test_postitiveIntInput();
	test_factorial();
	test_calcRightEps();

	return 0;
}