#pragma once
#include "Clock.h"
#include <iomanip>

class MechClock :
	public Clock
{
protected:
	int _charge;
public:
	int GetCharge();
	void SetCharge(int charge);

	void WindWatch();
	friend istream& operator>>(istream& is, MechClock& temp) {
		MechClock* obj = &temp;
		is>>*dynamic_cast<Clock*>(obj);
		cout << "enter charge value(0-100):\n";
		rewind(stdin);
		temp._charge = Validation::VvodChisla(0, 100);
		return is;
	}

	friend ostream& operator<<(ostream& os, MechClock& temp) {
		os << (Clock)temp;
		os << setw(10) << temp.GetCharge();
		return os;
	}

	void Head();

	MechClock(time_t newTime = NULL,int charge=100);
	~MechClock();
};
