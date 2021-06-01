#include "files.h"


void loadFile(List* _list)
{
	ifstream in("hotels.txt");
	string temp;
	while (getline(in, temp))
	{
		string temp2;
		HotelTracer::HotelInfo info;
		int i = 0;
		while (temp[i] != ';')
		{
			temp2 += temp[i];
			i++;
		}
		info.city = temp2;
		i++;
		temp2.clear();


		while (temp[i] != ';')
		{
			temp2 += temp[i];
			i++;
		}
		info.hotelName = temp2;
		i++;
		temp2.clear();


		while (temp[i] != ';')
		{
			temp2 += temp[i];
			i++;
		}
		info.hotelAdress = temp2;
		i++;
		temp2.clear();


		while (temp[i] != ';')
		{
			temp2 += temp[i];
			i++;
		}
		info.roomClass = temp2;
		i++;
		temp2.clear();


		while (temp[i] != ';')
		{
			temp2 += temp[i];
			i++;
		}
		info.placesRoom = stoi(temp2);
		i++;
		temp2.clear();


		while (temp[i] != ';')
		{
			temp2 += temp[i];
			i++;
		}
		info.cost = stod(temp2);
		i++;
		temp2.clear();


		while (temp[i] != ';')
		{
			temp2 += temp[i];
			i++;
		}
		info.reserved = stoi(temp2);
		i++;
		temp2.clear();

		_list->push(info);
	}
	in.close();	
}

void outFile(List* _list)
{
	ofstream out("hotels.txt");
	vector <HotelTracer::HotelInfo> temp = _list->get();
	for (int i = 0; i < (int)temp.size(); i++)
	{
		out << temp[i].toString();
		out << "\n";
	}
	out.close();
}


int countCommas(string s)
{
	int ans = 0;
	for (auto i : s) if (i == ',') ans++;
	return ans;
}