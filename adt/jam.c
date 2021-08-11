#include "jam.h"

Jam MakeJam(int hh, int mm, int dd) {
	Jam temp;
	temp.hour = hh;
	temp.min = mm;
	temp.sec = dd;
	return temp;
}

Jam GetCurrentTime(){
	time_t theTime = time(NULL);
	struct tm *aTime = localtime(&theTime);
	Jam Time;
	(Time).hour = aTime->tm_hour;
	(Time).min= aTime->tm_min;
	(Time).sec = aTime->tm_sec;
	return Time;
}