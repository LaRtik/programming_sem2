#ifndef LIST_H
#define LIST_H

#include "HotelTracer.h"
#include <vector>

class List
{
	struct node
	{
		node* next = nullptr;
		node* prev = nullptr;
		HotelTracer::HotelInfo value;
	};

	node* head = nullptr;
	node* tail = nullptr;
	
public:
	 size_t size = 0;

public:
	void push(HotelTracer::HotelInfo value);
	std::vector <HotelTracer::HotelInfo> get();
};

#endif // LIST_H