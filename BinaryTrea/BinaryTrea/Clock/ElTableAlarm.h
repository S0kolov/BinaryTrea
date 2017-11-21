#pragma once
#include "El_Clocks.h"

class ElectronicAlarm : public El_Clocks
{
protected:
	time_t AlarmsTime;
public:
	time_t GetAlarmsTime();
	void SetAlarmsTime(time_t newAlarmsTime = NULL);
	ElectronicAlarm(int newCharge = 1, time_t newTime = NULL, time_t newAlarmsTime = NULL);
	~ElectronicAlarm();

	friend istream& operator>>(istream& is, ElectronicAlarm& temp) {
		is >> *dynamic_cast<El_Clocks*>(&temp);
		cout << "enter alart time:" << endl;
		temp.AlarmsTime = Validation::VvodChisla(0, 100000);
		return is;
	}
	friend ostream& operator<<(ostream& os, ElectronicAlarm& temp) {
		os << (El_Clocks)temp;
		os << setw(12);
		os << temp.GetAlarmsTime();
		return os;
	}

	void Head();
};