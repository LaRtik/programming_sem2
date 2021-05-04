#include "stack.h"
#include <assert.h>

void stack_test_sort()
{
	Stack temp;
	temp.push('a');
	temp.push('a');
	temp.push('b');
	temp.push('c');
	temp.push('z');
	temp.push('e');
	assert(temp.size() == 6);
	
	temp.sort();
	assert(temp.pop() == 'a');
	assert(temp.pop() == 'a');
	assert(temp.pop() == 'b');
	assert(temp.pop() == 'c');
	assert(temp.pop() == 'e');
	assert(temp.pop() == 'z');

	assert(temp.empty() == true);
}

int main()
{
	stack_test_sort();
}