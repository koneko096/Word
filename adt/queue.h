/* File header ADT Queue */

#ifndef QUEUE_H
#define QUEUE_H
#include "boolean.h"
#include <stdlib.h>
#include "lqstring.h"

/* Konstanta */
#define NilQueue 0
#define limit 20

/* Definisi elemen dan address */
typedef int addressQ;
typedef char word[limit];
typedef word infotypeQ;

/* Definisi Type Queue */
typedef struct {
	infotypeQ *T;  // tabel penyimpanan elemen, didefinisikan secara dinamik
	addressQ HEAD; // alamat penghapusan
	addressQ TAIL; // alamat penambahan 
	int MaxEl; // maksimum banyaknya elemen queue
} Queue;
/* Definisi Queue kosong : HEAD == NilQueue; TAIL == NilQueue */
/* Catatan mplementasi : T[0] tidak pernah dipakai */
/* Definisi akses dengan Selektor */
#define HeadQ(Q) 	(Q).HEAD
#define TailQ(Q) 	(Q).TAIL
#define InfoHeadQ(Q) (Q).T[(Q).HEAD]
#define InfoTailQ(Q) (Q).T[(Q).TAIL]
#define MaxElQ(Q)	(Q).MaxEl


/* Predikat Pemeriksaan Kondisi Queue */
boolean IsEmptyQ(Queue Q);
/* Mengirimkan true jika queue kosong */
boolean IsFullQ(Queue Q);
/* Mengirimkan true jika queue penuh */
int NBElmtQ(Queue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */

/* Konstruktor */
void CreateEmptyQ(Queue *Q, int Max);
/* I.S. 	: sembarang */
/* F.S. 	: sebuah Q kosong terbentuk dengan salah satu kondisi berikut : */
/* 			  Jika alokasi berhasil, Tabel memori dialokasikan berukuran Max */
/* 			  Jika alokasi gagal, Q kosong dengan MaxEl = 0 */
/* Proses 	: Melakukan alokasi, membuat sebuah Q kosong */

/* Destruktor */
void DeAlokasiQ(Queue *Q);
/* I.S.		: Q pernah dialokasi */
/* F.S. 	: Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
/* Proses 	: Mengembalikan/melepas memori yang pernah dialokasikan untuk Q */

/* Operator - Operator Dasar Queue */
void AddQ(Queue *Q, infotypeQ X);
/* I.S. 	: Q mungkin kosong, tabel penampung Q tidak penuh */
/* F.S. 	: X menjadi TAIL yang baru, TAIL "maju" */
/* Proses 	: Menambahkan X pada Q dengan aturan FIFO */
void DelQ(Queue *Q, infotypeQ *X);
/* I.S. 	: Q tidak kosong */
/* F.S. 	: X = nilai elemen HEAD pada I.S. */
/* 			  Jika Queue masih isi : HEAD diset tetap = 1 */
/*			  Elemen - elemen setelah HEAD yang laman digeser ke "kiri", */
/*			  TAIL -= 1. */
/* 			  Jika Queue menjadi kosong, maka HEAD = TAIL = NilQueue */

#endif
