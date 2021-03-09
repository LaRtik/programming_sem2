#include "main.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void test_positiveFloatInput()
{
	assert(positiveFloatInput("!") == 0);
	assert(positiveFloatInput("123") == 1);
	assert(positiveFloatInput("1") == 1);
	assert(positiveFloatInput("0") == 0);
	assert(positiveFloatInput("abdsa") == 0);
	assert(positiveFloatInput("10af") == 0);
	assert(positiveFloatInput("1486168416486518416.548447") == 0);
}

void test_sphereArea()
{
	assert(abs(sphereArea(15) - 2827.35) <= 1e-5);
	assert(abs(sphereArea(16) - 3216.896) <= 1e-5);
	assert(abs(sphereArea(1) - 12.566) <= 1e-5);
	assert(abs(sphereArea(1.97) - 48.7673894) <= 1e-5);
	assert(abs(sphereArea(1.57) - 30.9739334) <= 1e-5);
	assert(abs(sphereArea(3.1415) - 124.0141335935) <= 1e-5);
}

void test_sphereVolume()
{
	assert(abs(sphereVolume(15) - 14136.75) <= 1e-5);
	assert(abs(sphereVolume(16) - 17156.7787) <= 1e-5);
	assert(abs(sphereVolume(1) - 4.18866667) <= 1e-5);
	assert(abs(sphereVolume(1.97) - 32.023919) <= 1e-5);
	assert(abs(sphereVolume(1.57) - 16.2096918) <= 1e-5);
	assert(abs(sphereVolume(3.1415) - 129.863467) <= 1e-5);
}

void test_edgeLength()
{
	assert(abs(edgeLength(15) - 24.4948974) <= 1e-5);
	assert(abs(edgeLength(1) - 1.63299316) <= 1e-5);
	assert(abs(edgeLength(1.57) - 2.56379926) <= 1e-5);
	assert(abs(edgeLength(3.1415) - 5.13004802) <= 1e-5);
}

void test_crossArea()
{
	assert(abs(crossArea(15,14) - 91.1035) <= 1e-5);
	assert(abs(crossArea(1, 0.57) - 2.12082665) <= 1e-5);
	assert(abs(crossArea(1.57, 1.56) - 0.09832895) <= 1e-5);
	assert(abs(crossArea(3.1415, 2) - 18.437533398375) <= 1e-5);

}
#undef main

int main()
{
	test_positiveFloatInput();
	test_sphereArea();
	test_sphereVolume();
	test_crossArea();
	test_crossArea();

	return 0;
}