#ifndef __JAM__H
#define __JAM__H

#include <time.h>
#include <stdio.h>


typedef struct 
{
	int hour;
	int min;
	int sec;
} Jam;

#define GetHour(T) (T).hour
#define GetMin(T) (T).min
#define GetSec(T) (T).sec

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

#endif