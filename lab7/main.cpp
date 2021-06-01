#include <iostream>
#include <fstream>
#include <locale>
#include <vector>
#include <assert.h>

#include "list.h"
#include "files.h"


using namespace std;

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

int main()
{
	cout << "Welcome to Hotel Tracer! (ver. 0.1.0)" << endl;
	HotelTracer::HotelInfo temp;
	List *hotels = new List;
	loadFile(hotels);
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
	}
	return 0;
}
