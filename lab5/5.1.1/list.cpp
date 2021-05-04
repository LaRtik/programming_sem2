#include "list.h"

void List::push(Stack value)
{
	node *temp = new node;
	temp->value = value;

	if (!head)
	{
		temp->next = temp;
		head = temp;
		tail = head;
	}
	else
	{
		temp->next = head;
		temp->prev = tail;
		tail = temp;
	}
	temp = nullptr;
	delete temp;
	size++;
}

void List::display()
{
	node* temp = head;
	size_t it = 0;
	while (temp != tail && it < size)
	{
		temp->value.display();
		temp = temp->next;
		it++;
	}
}