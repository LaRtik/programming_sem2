#ifndef STACK_H
#define STACK_H

#include <iostream>

class Stack
{
	struct node
	{
		char value;
		node *prev = nullptr;
	};
	node *top = nullptr;
	size_t siz = 0;

public:
	Stack()
	{
		top = nullptr;
	}

	void push(char value);
	void push(Stack data);
	char pop();
	bool empty();
	void display();
	void sort();
	void clear();
	size_t size();
};

#endif // STACK_H
