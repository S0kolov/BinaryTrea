#include "TableMechClock.h"


bool TableMechClock::WithSecondsHand()
{
	return _secondsHand;
}

bool TableMechClock::WithAllarm()
{
	return _allarm;
}

void TableMechClock::SetSecondsHand(int is)
{
	_secondsHand = is;
	//_secondsHand = Validators::BoolValidation(is);
}

void TableMechClock::SetAllarm(int is)
{
	_allarm = is;
	//_allarm = Validators::BoolValidation(is);
}

void TableMechClock::Head()
{
	((MechClock*)this)->Head();
	cout << setw(8) << "Allarm" << setw(8) << "Second";
}

TableMechClock::TableMechClock(time_t time, bool secondsHand, bool allarm, int charge):MechClock(time,charge)
{
	//cout << "TableMechClck constructor" << endl;
	SetAllarm(allarm);
	SetSecondsHand(secondsHand);
}

TableMechClock::~TableMechClock()
{
	//cout << "TableMechClock destructor" << endl;
}
