#include "main.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void test_FloatInput()
{
	assert(FloatInput("!") == 0);
	assert(FloatInput("123") == 1);
	assert(FloatInput("1") == 1);
	assert(FloatInput("0") == 1);
	assert(FloatInput("abdsa") == 0);
	assert(FloatInput("10af") == 0);
	assert(FloatInput("1486168416486518416.548447") == 0);
	assert(FloatInput("0.01") == 1);
	assert(FloatInput("-0.01") == 1);
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
	assert(abs(calcRightEps(1,1,3) - 1) <= 1e-5);
	assert(abs(calcRightEps(3,2,1) + 1.5) <= 1e-5);
	assert(abs(calcRightEps(5,5,2) - 0.089631) <= 1e-5);
}


#undef main

int main()
{
	test_FloatInput();
	test_postitiveIntInput();
	test_factorial();
	test_calcRightEps();

	return 0;
}