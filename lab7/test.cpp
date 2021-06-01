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
}

#undef main
int main()
{
	test_list_add();
}