#ifndef LIST_H
#define LIST_H

#include "stack.h"

class List
{
	struct node
	{
		node* next = nullptr;
		node* prev = nullptr;
		Stack value;
	};

	node* head = nullptr;
	node* tail = nullptr;
	size_t size = 0;

public:
	void push(Stack value);
	void display();
};

#endif // LIST_H