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

Jam MakeJam(int hh, int mm, int dd);

Jam GetCurrentTime();

#endif