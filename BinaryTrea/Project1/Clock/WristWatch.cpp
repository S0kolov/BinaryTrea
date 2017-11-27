#include "WristWatch.h"
#include "InvalidArgumentsException.h"
#include <iomanip>


WristWatch::Matirial WristWatch::GetMatirial()
{
	return _corpusMatirial;
}

void WristWatch::SetMatirial(Matirial corpusMatirial)
{
	//Validators::MaterialValidation(corpusMatirial);
	_corpusMatirial = corpusMatirial;
}


WristWatch::Mark WristWatch::GetMark()
{
	return _mark;
}

void WristWatch::SetMark(Mark mark)
{
	//Validators::MarkValidation(mark);
	_mark = mark;
}

WristWatch::WristWatch(time_t time, Mark mark, Matirial corpusMatirial, int charge):MechClock(time,charge)
{
	//cout << "WristWatch constructor" << endl;
	SetMark(mark);
	SetMatirial(corpusMatirial);
}

void WristWatch::Head()
{
	((MechClock*)this)->Head();
	cout << setw(6) << "Mark" << setw(10) << "Material";
}


WristWatch::~WristWatch()
{
	//cout << "WristWatch destructor" << endl;
}
