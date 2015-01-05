/* File : point.h */
/* spesifikasi ADT point */
#ifndef point_H
#define point_H
#include "boolean.h"

typedef struct 
	{
		int x;
		int y;
	} 
	point;
	
point makepoint(int x, int y);

int getabsis(point p);

int getordinat(point p);

void setabsis(point *p, int newx);

void setordinat(point *p, int newy);

boolean eq(point p1, point p2);

boolean neq(point p1, point p2);

point geser(point p, point dp);

#endif
