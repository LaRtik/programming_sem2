#include <iostream>
#include <fstream>
#include <locale>
#include <vector>
#include "list.h"


using namespace std;


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
	
}

int countCommas(string s)
{
	int ans = 0;
	for (auto i : s) if (i == ',') ans++;
	return ans;
}

vector <HotelTracer::HotelInfo> queryResult(string city, string nPersons, string roomClass, string price, List* hotels)
{
	vector <HotelTracer::HotelInfo> result;
	vector <HotelTracer::HotelInfo> info = hotels->get();

	for (auto i : info)
	{
		if (i.reserved) continue;
		if (i.city == city)
		{
			int pers = stoi(nPersons);
			if (i.placesRoom < pers)
			{
				if (i.roomClass == roomClass)
				{
					if (price == "min" || price == "max")
					{
						result.push_back(i);
						continue;
					} 

					int pr = stoi(price);
					if (pr >= i.cost) result.push_back(i);
				}
			}
		}
	}
	return result;
}

string query(string s, List* hotels)
{
	if (countCommas(s) != 3) return "Incorrect query. Please check the example";

	int i = 0;
	string city;
	while (i < (int)s.size() && s[i] != ',')
	{
		city += s[i];
		i++;
	}

	i++;
	string nPersons;
	while (i < (int)s.size() && s[i] != ',')
	{
		nPersons += s[i];
		i++;
	}

	i++;
	string roomClass;
	while (i < (int)s.size() && s[i] != ',')
	{
		roomClass += s[i];
		i++;
	}

	i++;
	string price;
	while (i < (int)s.size() && s[i] != ',')
	{
		city += s[i];
		i++;
	}

	auto res = queryResult(city, nPersons, roomClass, price, hotels);
	if ((int)res.size() == 0) return "No results found for your query.";
	else
	{
		string ans;
		ans += to_string((int)res.size()) + "result(s) found: ";
		for (auto i : res)
		{
			ans += i.toMaxString();
			ans += '\n';
		}
		return ans;
	}
}

void outFile(List* _list)
{
	ofstream out("hotels.txt");
	// check open status
	vector <HotelTracer::HotelInfo> temp = _list->get();
	for (int i = 0; i < (int)temp.size(); i++)
	{
		out << temp[i].toString();
	}
	out.close();
}

int main()
{
	//setlocale(LC_ALL, "rus");

	cout << "Welcome to Hotel Tracer! (ver. 0.1.0)" << endl;

	HotelTracer::HotelInfo temp;
	/*temp.city = "Mogilev";
	temp.cost = 228.1337;
	temp.hotelAdress = "Lenina st. 28";
	temp.hotelName = "Regina";
	temp.placesRoom = 2;
	temp.reserved = false;
	temp.roomClass = "budget";*/
	List *hotels = new List;
	loadFile(hotels);
	outFile(hotels);
	while (true)
	{
		cout << "Enter your query:" << endl;
		cout << "(format of query: City, number of persons, class of room (budget, standart, luxe), price (min / max or value)" << endl;
		cout << "(example of query: Paris, 2, budget, min price)" << endl;
		cout << "enter 'exit' to exit the program" << endl;
		string s;
		cin >> s;
		if (s == "exit")
		{
			cout << "Exiting...";
			return 0;
		}
		cout << query(s, hotels) << endl << endl;
	//	return 0;
	}





	return 0;
}