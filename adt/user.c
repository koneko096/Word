#include "tanggal.h"
#include "jam.h"
#include "user.h"
#include <stdbool.h>

bool IsUserSama(User U1, User U2) {
	Tanggal date1 = GetTanggal(U1);
	Tanggal date2 = GetTanggal(U2);
	Jam time1 = GetJam(U1);
	Jam time2 = GetJam(U2);
	return GetSkor(U1) == GetSkor(U2)
	&& GetDay(date1) == GetDay(date2)
	&& GetMonth(date1) == GetMonth(date2)
	&& GetYear(date1) == GetYear(date2)
	&& GetHour(time1) == GetHour(time2)
	&& GetMin(time1) == GetMin(time2)
	&& GetSec(time1) == GetSec(time2);
}