#include "pqueue.h"
#include "lqstring.h"
#include <stdio.h>
#include <stdbool.h>

/* definisi fungsi diluar ADT */
// extern int getSkor(char* x);
// extern void gotoxy(int _x, int _y);

/**** KONSTRUKTOR ****/
void CreatePQ(PQueue* T)
/* Membentuk tree yang sudah teralokasi menjadi terdefinisi */
{
	PQFirst(T) = PQEmpty;
}


/**** TREE KOSONG ****/
bool isPQEmpty(PQueue T)
/* Mengecek apakah PQ merupakan PQ kosong */
{
	return (PQFirst(T) == PQEmpty);
}


/**** MANAJEMEN MEMORI ****/
PQueue PQAllocate(char X[20])
/* Mengalokasikan memori PQ */
/* I.S PQ T tidak teralokasi */
/* F.S PQ T teralokasi */
{
	/* Kamus lokal */
	PQueue P;

	/* Algoritma */
	P = (PQElmt*) malloc(sizeof(PQElmt));
	while(P == NULL) {
		P = (PQElmt*) malloc(sizeof(PQElmt));
	}
	PQNext(P) = PQEmpty;
	strcpy(PQInfo(P), X);
	return P;
}

void PQDeallocate(PQueue* T)
/* Mendealokasikan memori PQ */
/* I.S PQ T teralokasi */
/* F.S PQ T tidak teralokasi */
{
	free(*T);
}


/**** PENYISIPAN DAN PENGHAPUSAN ELEMEN *****/
void PQPush(PQueue* T, char X[20], int priority)
/* Menambahkan elemen X ke PQ T */
{
	/* Kamus lokal */
	PQueue P;

	/* Algoritma */
	if (isPQEmpty(*T) || PQPriority(PQFirst(*T)) < priority)
	{
		P = PQAllocate(X);
		if (!isPQEmpty(*T))
		{
			PQNext(P) = PQFirst(*T);
		}
		PQFirst(*T) = P;
	}
	else if (PQNext(*T) == PQEmpty || PQPriority(PQNext(PQFirst(*T))) < priority)
	{
		P = PQAllocate(X);
		PQNext(P) = PQNext(*T);
		PQNext(*T) = P;
	}
	else
	{
		PQPush(&PQNext(*T), X, priority);
	}
}

void PQPop(PQueue* T, char* X)
/* Mengambil elemen dengan prioritas terbesar dalam PQ T */
/* I.S PQ T tidak kosong */
{
	/* Kamus lokal */
	PQueue Tmp;

	/* Algoritma */
	Tmp = PQFirst(*T);
	PQFirst(*T) = PQNext(Tmp);
	strcpy(X, PQInfo(Tmp));
	PQDeallocate(&Tmp);
}


/**** PENULISAN ELEMEN ****/
void PrintInfoPQ(PQueue P, int x) 
/* Menampilkan semua isi PQ secara terurut 
mengecil berdasar prioritas */
/* I.S sembarang */
{
	if (isPQEmpty(P) || x == 22) {
		return;
	}
	char temp[20];
	strcpy(temp, PQInfo(PQFirst(P)));
	printf("+%d", PQPriority(PQFirst(P)));
	printf("%s", temp);
	PrintInfoPQ(PQNext(PQFirst(P)), x + 1);
}