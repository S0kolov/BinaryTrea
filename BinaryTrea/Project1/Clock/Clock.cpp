#include "Clock.h"

time_t Clock::GetTime()
{
	return _clockTime;
}

void Clock::SetTime(time_t newTime)
{
	if (newTime == 0)
		_clockTime = time(&newTime);
	else
		_clockTime = newTime;
}

bool Clock::IsBeauty()
{
	return _beauty;
}

void Clock::SetBeauty(int b)
{
	_beauty = b;
}

void Clock::Head()
{
	cout << setw(6) << "Time" << setw(8) << "Beauty";
}

Clock::Clock(time_t newTime)
{

	//cout << "Clock constructor" << endl;
	_clockTime = time(&newTime);
}


Clock::~Clock()
{
	//cout << "Clock destructor" << endl;
}