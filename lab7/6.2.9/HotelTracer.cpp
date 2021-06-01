#include "HotelTracer.h"

void HotelTracer::reserve(HotelTracer::HotelInfo _a)
{
	_a.reserved = true;
}

void HotelTracer::removeReserve(HotelTracer::HotelInfo _a)
{
	_a.reserved = false;
}