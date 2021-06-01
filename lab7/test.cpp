#include "list.h"
#include "HotelTracer.h"
#include <assert.h>

void test_list_add()
{
	List temp;
	HotelTracer::HotelInfo temp2;
	temp2.city = "Grodno";
	temp.push(temp2);
	assert(temp.size == 1);
	vector <HotelTracer::HotelInfo> disp = temp.get();
	assert(disp[0].city == "Grodno");

	temp2.city = "Minsk";
	temp.push(temp2);
	disp = temp.get();
	assert(temp.size == 2);
	assert(disp[0].city == "Grodno");
	assert(disp[1].city == "Minsk");
}

#undef main
int main()
{
	test_list_add();
}