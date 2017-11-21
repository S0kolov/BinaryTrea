#pragma once
#include <ctime>
#include <iostream>
#include <iomanip>
#include "Validation.h"

using namespace std;

class Clock
{
protected:
	time_t _clockTime;
	bool _beauty;

public:
	time_t GetTime();
	void SetTime(time_t newTime);

	bool IsBeauty();
	void SetBeauty(int b);

	friend istream& operator>>(istream& is, Clock& temp) {
		cout << "Is it beauty?(1/0):\n";
		rewind(stdin);
		is.clear();
		temp.SetTime(NULL);
		temp._beauty = Validation::VvodChisla(0,1);
		return is;
	}
	friend ostream& operator<<(ostream& os, Clock& temp)
	{
		os << setw(6) << temp.GetTime() % 10000;
		if (temp.IsBeauty())
			os << setw(8) << "true";
		else
			os << setw(8) << "false";
		return os;
	}
	void Head();
	Clock(time_t newTime = NULL);
	~Clock();
};