#ifndef __TANGGAL_H
#define __TANGGAL_H

#include <time.h>
#include <stdio.h>

typedef struct 
{
	int month;
	int year;
	int day;
} Tanggal;

#define GetYear(T) (T).year
#define GetMonth(T) (T).month
#define GetDay(T) (T).day

Tanggal MakeTanggal(int dd, int mm, int yy) {
	Tanggal temp;
	temp.day = dd;
	temp.month = mm;
	temp.year = yy;
	return temp;
}

Tanggal GetCurrentDate(){
	time_t theTime = time(NULL);
	struct tm *aTime = localtime(&theTime);
	Tanggal Time;
	(Time).day = aTime->tm_mday;
	Time.month = aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
	Time.year = aTime->tm_year + 1900; // Year is # years since 1900
	return Time;
}

#endif