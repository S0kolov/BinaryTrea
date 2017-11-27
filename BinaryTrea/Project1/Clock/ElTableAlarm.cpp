#include "ElTableAlarm.h"

time_t ElectronicAlarm::GetAlarmsTime()
{
	return AlarmsTime;
}

void ElectronicAlarm::SetAlarmsTime(time_t newAlarmsTime)
{
	AlarmsTime = time(&newAlarmsTime);
}

ElectronicAlarm::ElectronicAlarm(int newCharge, time_t newTime, time_t newAlarmsTime) : El_Clocks(newCharge, newTime)
{
	SetAlarmsTime(newAlarmsTime);
	//cout << "In ElectronicTableAlarm ctor" << endl;
}

ElectronicAlarm::~ElectronicAlarm()
{
	//cout << "In ElectronicTableAlarm destr" << endl;
}

void ElectronicAlarm::Head()
{
	((El_Clocks*)this)->Head();
	cout << setw(12) << "AlarmsTime";
}
