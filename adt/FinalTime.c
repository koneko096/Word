#include <time.h>
#include <stdio.h>

typedef struct CurTime
{
	int hour;
	int min;
	int sec;
	int month;
	int year;
	int day;
}CurTime;

#define getHour(T) (T).hour
#define getMin(T) (T).min
#define getSec(T) (T).sec
#define getYear(T) (T).year
#define getMonth(T) (T).month
#define getDay(T) (T).day
CurTime Time;
void GetCurrentTime(){
	time_t theTime = time(NULL);
	struct tm *aTime = localtime(&theTime);
	(Time).hour = aTime->tm_hour;
	(Time).min= aTime->tm_min;
	(Time).sec = aTime->tm_sec;
	(Time).day = aTime->tm_mday;
	Time.month = aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
	Time.year = aTime->tm_year + 1900; // Year is # years since 1900
}
void TulisTime(){
	printf("Tanggal = %d/%d/%d \n",getDay(Time),getMonth(Time),getYear(Time));
	printf("Jam = %d:%d:%d \n",getHour(Time),getMin(Time),getSec(Time));
}

int main(){
	GetCurrentTime();
	TulisTime();
	return 0;
}
