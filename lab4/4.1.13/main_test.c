#include "main.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

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

void test_sortArrAscendingOrder()
{
	int arr[5] = {4,3,1,2,8};
	int resArr[5] = {1,2,3,4,8};
	int i;
	sortArrAscendingOrder(arr, 5);
	for (i = 0; i < 5; i++) assert(arr[i] == resArr[i]);
}

#undef main

int main()
{
	test_postitiveIntInput();
	test_sortArrAscendingOrder();
	return 0;
}