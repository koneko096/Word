/* File : point.c */
/* Body ADT point */

#include "point.h"
#include <stdio.h>
#include <math.h>
#define pi 3.1415926535897932

/* DEFINISI PROTOTIPE PRIMITIF */
/* Konstruktor Membentuk point */

point makepoint(int x, int y)
/*Membentuk sebuah point dari komponen-komponennya */
{
    point p;
    p.x=x;
    p.y=y;
    return(p);
}

int getabsis(point p)
/*Mengirimkan komponen Absis dari P */
{
    return (p.x);
}

int getordinat(point p)
/*Mengirimkan komponen Ordinat dari P */
{
    return(p.y);
}

void setabsis(point *p, int newx)
/*Mengubah nilai dari komponen Absis p */
{
    *p=makepoint(newx,getordinat(*p));
}

void setordinat(point *p, int newy)
/*Mengubah nilai dari komponen Ordinat p */
{
    *p=makepoint(getabsis(*p),newy);
}

/* KELOMPOK OPERASI RELASIONAL TERHADAP point */
boolean eq(point p1, point p2)
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
{
    return((getabsis(p1)==getabsis(p2))&&((getordinat(p1)==getordinat(p2))));
}

boolean neq(point p1, point p2)
/* Mengirimkan true jika P1 tidak sama dengan P2 */
{
    return !eq(p1,p2);
}

point geser(point p, point dp)
/* Menggeser point p sebesar dp */
{
	return makepoint(getabsis(p) + getabsis(dp), getordinat(p) + getordinat(dp));
}
