#include "list.h"

void List::push(HotelTracer::HotelInfo value)
{
	node *temp = new node;
	temp->value = value;

	if (!head)
	{
		temp->next = tail;
		head = temp;
		tail = head;
	}
	else
	{
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
	}
	temp = nullptr;
	delete temp;
	size++;
}

vector <HotelTracer::HotelInfo> List::get()
{
	node* temp = head;
	HotelTracer::HotelInfo info;
	vector <HotelTracer::HotelInfo> result;
	while (temp)
	{
		info = temp->value;
		result.push_back(info);
		if (temp == temp->next) temp = nullptr;
		else temp = temp->next;
	}
	return result;
}
