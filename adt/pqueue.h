#ifndef PQUEUE_H
#define PQUEUE_H

#include <stdbool.h>
#include <stdlib.h>

/**** DEFINISI TIPE PQ (PRIORITY QUEUE) ****/
typedef struct PQElmt_t* PQueue;
typedef struct PQElmt_t {
    char Info[20];
    int Priority;
    PQueue Next;
} PQElmt;


/**** SELEKTOR ****/
#define PQEmpty 		NULL
#define PQFirst(L) 		(L)
#define PQInfo(L) 		(L)->Info
#define PQPriority(L) 	(L)->Priority
#define PQNext(L) 	    (L)->Next


/**** KONSTRUKTOR ****/
void CreatePQ(PQueue* T);
/* Membentuk tree yang sudah teralokasi menjadi terdefinisi */


/**** TREE KOSONG ****/
bool isPQEmpty(PQueue T);
/* Mengecek apakah PQ merupakan PQ kosong */


/**** MANAJEMEN MEMORI ****/
PQueue PQAllocate(char X[20]);
/* Mengalokasikan memori PQ */
/* I.S PQ T tidak teralokasi */
/* F.S PQ T teralokasi */

void PQDeallocate(PQueue* T);
/* Mendealokasikan memori PQ */
/* I.S PQ T teralokasi */
/* F.S PQ T tidak teralokasi */


/**** PENYISIPAN DAN PENGHAPUSAN ELEMEN *****/
void PQPush(PQueue* T, char X[20], int priority);
/* Menambahkan elemen X ke PQ T */

void PQPop(PQueue* T, char* X);
/* Mengambil elemen dengan prioritas terbesar dalam PQ T */
/* I.S PQ T tidak kosong */

/**** PENULISAN ELEMEN ****/
void PrintInfoPQ(PQueue P, int x);
/* Menampilkan semua isi PQ secara terurut 
mengecil berdasar prioritas */
/* I.S sembarang */

#endif