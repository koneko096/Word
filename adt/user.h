#ifndef USER
#define USER

#include "tanggal.h"
#include "jam.h"
#include <stdbool.h>

typedef struct {
	char name[20];
	Tanggal date;
	Jam time;
	int skor;
} User;

/* Selektor */

#define GetNama(U) (U).name
#define GetTanggal(U) (U).date
#define GetJam(U) (U).time
#define GetSkor(U) (U).skor

bool IsUserSama(User U1, User U2);

#endif