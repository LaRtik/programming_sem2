#include "stack.h"

void Stack::push(char value)
{
	node *temp = new node;
	temp->value = value;
	temp->prev = top;
	top = temp;
	siz++;
}

void Stack::push(Stack data)
{
	node *temp = data.top;
	while (temp)
	{
		push(temp->value);
		temp = temp->prev;
	}
}

char Stack::pop()
{
	char val;
	if (!top)
	{
		std::cout << "stack underflow";
		exit(2);
	}
	val = top->value;
	top = top->prev;
	siz--;
	return val;
}

void Stack::clear()
{
	while (top)
	{
		pop();
	}
}

bool Stack::empty()
{
	return (siz == 0);
}

void Stack::display()
{
	node* temp = top;
	while (temp)
	{
		std::cout << temp->value << " ";
		temp = temp->prev;
	}
	std::cout << "\n";
}

void Stack::sort()
{
	char* temp = new char[siz];
	size_t temp_size = 0;
	node* temp_1 = top;
	while (temp_1)
	{
		temp[temp_size++] = temp_1->value;
		temp_1 = temp_1->prev;
	}

	for (size_t i = 0; i < temp_size; i++)
	{
		for (size_t j = i + 1; j < temp_size; j++)
		{
			if (temp[i] < temp[j]) std::swap(temp[i], temp[j]);
		}
	}
	clear();
	for (size_t i = 0; i < temp_size; i++) push(temp[i]);
	delete [] temp;
}

size_t Stack::size()
{
	return siz;
}