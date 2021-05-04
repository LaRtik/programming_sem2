#include <iostream>
#include "list.h"

using namespace std;


int main()
{
	List temp;
	Stack stack1;
	stack1.push('a'); stack1.push('g'); stack1.push('d');

	Stack stack2;
	stack2.push('b'); stack2.push('c'); stack2.push('k');

	Stack stack3;
	stack3.push('o'); stack3.push('a'); stack3.push('i');
	
	Stack super_stack;
	super_stack.push(stack1); super_stack.push(stack2); super_stack.push(stack3);
	super_stack.display();
	super_stack.sort();
	super_stack.display();
}