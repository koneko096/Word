//NIM/Nama 	: 13513012/Muhammad Azam Iszuhri
//Nama file : P061351301201.h
//Topik 	: Stack
//Tanggal 	: 9 Oktober 2014
//Deskripsi : Header Stack

#ifndef stack_H
#define stack_H

#include "boolean.h"
#include <stdio.h>
#include "point.h"

#define Nil 0
#define MaxElStack 20

typedef struct
	{
		point T[MaxElStack+1];
		int TOP;
	}Stack;
	
#define TOP(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

void CreateStackEmpty(Stack *S);
boolean IsStackEmpty(Stack S);
boolean IsStackFull(Stack S);
void PushStack(Stack *S,point X);
void PopStack(Stack *S,point *X);
void Revstack(Stack *S);

#endif
