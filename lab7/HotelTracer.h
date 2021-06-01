#ifndef HOTELTRACER_H
#define HOTELTRACER_H

#include <string>

using namespace std;

namespace HotelTracer
{
	struct HotelInfo
	{
		string city;
		string hotelName;
		string hotelAdress;
		string roomClass;
		int placesRoom;
		double cost;
		bool reserved;

		string toString()
		{
			string buffer;
			buffer += city;
			buffer += ';';
			buffer += hotelName;
			buffer += ';';
			buffer += hotelAdress;
			buffer += ';';
			buffer += roomClass;
			buffer += ';';
			buffer += to_string(placesRoom).c_str();
			buffer += ';';
			buffer += to_string(cost).c_str();
			buffer += ';';
			buffer += to_string(reserved).c_str();
			buffer += ';';
			return buffer;
		}

		string toMaxString()
		{
			string buffer;
			buffer += "City:" + city + " - ";
			buffer += "Name of the Hotel: " + hotelName + " - ";
			buffer += "Adress of the hotel: " + hotelAdress +  " - ";
			buffer += "Class of the room: " + roomClass +  " - ";
			buffer += "Places in room: " + to_string(placesRoom) +  " - ";
			buffer += "Price:" + to_string(cost) +  " - ";
			buffer += '\n';
			return buffer;
		}
	};

	void reserve(HotelInfo* _a);
	void removeReserve(HotelInfo* _a);
}

#endif // HOTELTRACER_H
