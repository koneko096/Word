//NIM/Nama 	: 13513012/Muhammad Azam Iszuhri
//Nama file : P061351301201.c
//Topik 	: Stack
//Tanggal 	: 9 Oktober 2014
//Deskripsi : Driver Stack

#include "stack.h"

void CreateStackEmpty(Stack *S)
	{
		TOP(*S) = Nil;
	}
	
boolean IsStackEmpty(Stack S)
	{
		return(TOP(S)==Nil);
	}
	
boolean IsStackFull(Stack S)
	{
		return(TOP(S) == MaxElStack);
	}
	
void PushStack(Stack *S, point X)
	{
		TOP(*S) = TOP(*S) + 1;
		InfoTop(*S) = X;
	}
	
void PopStack(Stack *S,point *X)
{
	*X=InfoTop(*S);
	
	TOP(*S) = TOP(*S) - 1;
}

void Revstack(Stack *S)
{
	/* Kamus lokal */
	Stack T, U;
	point p;

	/* Algoritma */
	CreateStackEmpty(&T);
	while (!IsStackEmpty(*S)) {
		PopStack(S, &p);
		PushStack(&T, p);
	}

	while (!IsStackEmpty(T)) {
		PopStack(&T, &p);
		PushStack(&U, p);
	}

	while (!IsStackEmpty(U)) {
		PopStack(&U, &p);
		PushStack(S, p);
	} 
}
