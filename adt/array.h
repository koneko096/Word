#ifndef ARRAY_H
#define ARRAY_H

/*----- ADT Array Kontigu Eksplisit Statik -----*/

#include "boolean.h"
#include "multilist.h"

/* Kamus Umumumumu */
#define IdxMaxA 500
#define IdxMinA 1
#define IdxUndefA -999

/* Definisi elemen dan koleksi obyek */
typedef int IdxTypeA;

typedef struct {
    User TI[IdxMaxA + 5];
    int Neff;
} TabInt;

typedef struct {
    User MaxAVal, MinAVal;
} Elms;
/*----- Konstruktor -----*/
/* Membentuk tabel kosong dengan kapasitas IdxMax - IdxMin + 1 */
void MakeEmptyA (TabInt* T);

/*----- Selektor -----*/
/* Banyaknya elemen dalam tabel */
int NbElmtA (TabInt T);
/* Daya tampung container */
int MaxNbElA (TabInt T);
/*-- Selektor indeks --*/
/* Prekondisi : array tidak kosong */
/* Indeks elemen pertama */
IdxTypeA GetFirstIdxA(TabInt T);
/* Indeks elemen terakhir */
IdxTypeA GetLastIdxA(TabInt T);
/* Elemen pada indeks */
User GetElmtA(TabInt T, IdxTypeA i);
/*-- Selektor Set --*/
/* Mengeset nilai elemen tabel */
void SetElA(TabInt *T, IdxTypeA i, User v);
/* Mengeset nilai efektif tabel */
void SetNeffA(TabInt *T, IdxTypeA N);
boolean IsLessA(User E1, User E2);
/*----- Test kosong/penuh -----*/
/* Tes tabel kosong */
boolean IsEmptyA(TabInt T);
/* Tes tabel penuh */
boolean IsFullA(TabInt T);

/*----- Baca dan tulis dengan input/output device -----*/
/* Mendefinisikan isi tabel dari pembacaan */
void BacaIsiA(TabInt *T);
/* Menuliskan isi tabel secara terurut ke bawah */
void TulisIsiA(TabInt T);

/*----- Sorting -----*/
/* Mengurutkan elemen tabel menurun dengan Maximum Sort */
void MaxSortDesc(TabInt *T);

/*----- Menambah elemen -----*/
/* Menambah elemen terakhir */
void AddAsLastEl(TabInt *T, User x);
/* Menambah elemen pada indeks ke i */
void AddEl1(TabInt *T, User x, IdxTypeA i);

/*----- Menghapus elemen -----*/
/* Menghapus elemen terakhir */
void DelLastEl(TabInt *T);
/* Menghapus elemen ke i */
void DelEl1(TabInt *T, IdxTypeA i);


/*----- Tabel dengan elemen terurut membesar -----*/
/* Mencari indeks terkecil yang elemennya bernilai x */
IdxTypeA SearchUrutB (TabInt T, User x);
void Add1Urut(TabInt *T, User x);
/* Menghapus elemen bernilai x yang memiliki indeks terkecil */
void Del1Urut(TabInt *T, User x);


/* I.S. : T terdefinisi, tidak kosong.
 * i merupakan indeks valid dalam T.
X terdefinisi. 
  F.S. : Nilai elemen T pada indeks ke-i berubah menjadi X.
T tetap terurut membesar, sehingga ada kemungkinan dilakukan
proses pengurutan kembali. } */
void UpdateElmtA(TabInt *T, IdxTypeA i,User x);


/* I.S. : T terdefinisi, boleh kosong. X terdefinisi
 F.S. : Semua elemen T yang bernilai X dihapus dari tabel penampung, jika
X ada di T. Jika X tidak ada, T tetap. */
void DelAllXA(TabInt *T,User x);
#endif // ARRAY_H
