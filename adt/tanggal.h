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

Tanggal MakeTanggal(int dd, int mm, int yy);

Tanggal GetCurrentDate();

#endif