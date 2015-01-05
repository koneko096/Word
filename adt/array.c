/**
 * NIM / Nama	: 13513078/ Gazandi Cahyadarma
 * Nama file	: array.c
 * Topik		: Abstract Data Type
 * Tanggal 		: 18 September 2014
 * Deskripsi	: ADT Tabel Berurut Array Kontigu Eksplisit Statik
 */
#include <stdio.h>
#include "array.h"

TabInt T;

/*----- Konstruktor -----*/
/* Membentuk tabel kosong dengan kapasitas IdxMaxAA - IdxMinAA + 1 */

void MakeEmptyA (TabInt* T) {
    SetNeffA(T, 0);
}

/*----- Selektor -----*/
/* Banyaknya elemen dalam tabel*/
int NbElmtA (TabInt T) {
    return T.Neff;
}
/* Daya tampung container */
int MaxANbElA (TabInt T) {
    return IdxMaxA + 1;
}
/*-- Selektor indeks --*/
/* Prekondisi : array tidak kosong */
/* Indeks elemen pertama */
IdxTypeA GetFirstIdxA(TabInt T) {
    return IdxMinA;
}
/* Indeks elemen terakhir */
IdxTypeA GetLastIdxA(TabInt T) {
    return NbElmtA(T);
}
/* Elemen pada indeks */
User GetElmtA(TabInt T, IdxTypeA i) {
    return T.TI[i];
}
/*-- Selektor Set --*/
/* Menyalin isi Tin pada Tout */
void SetTabA(TabInt Tin, TabInt* Tout) {
    SetNeffA(Tout, NbElmtA(Tin));
    IdxTypeA i;
    for(i = 1; i <= NbElmtA(Tin); ++i)
        SetElA(Tout, i, GetElmtA(Tin, i));
}
/* Mengeset nilai elemen tabel */
void SetElA(TabInt *T, IdxTypeA i, User v) {
    T->TI[i] = v;
}
/* Mengeset nilai efektif tabel */
void SetNeffA(TabInt *T, IdxTypeA N) {
    T->Neff = N;
}

/*----- Test kosong/penuh -----*/
/* Tes tabel kosong */
boolean IsEmptyA(TabInt T) {
    return (NbElmtA(T) == 0);
}
/* Tes tabel penuh */
boolean IsFullA(TabInt T) {
    return (NbElmtA(T) == MaxANbElA(T));
}
/*----- Baca dan tulis dengan input/output device -----*/
/* Mendefinisikan isi tabel dari pembacaan */
void BacaIsiA(TabInt *T) {
    int n;
    IdxTypeA i;
    User x;
    MakeEmptyA(T);
    printf("masukkan nilai efektif tabel =" );scanf("%d",&n);
    SetNeffA(T, n);
    /*
    for(i = GetFirstIdxA(*T); i <= GetLastIdxA(*T); ++i) {
         printf("masukkan nilai elemen ke-%d ",i);scanf("%d",&x);
         SetElA(T, i, x);
    } */
    MaxSortDesc(T);
}
/* Menuliskan isi tabel secara terurut ke bawah */
void TulisIsiA (TabInt T) {
    IdxTypeA i;
    MaxSortDesc(&T);
    /*
    for(i = GetFirstIdxA(T); i <= GetLastIdxA(T); ++i)
        printf("[%d] %d \n",i,GetElmtA(T, i));
    */
}

boolean IsLessA(User E1, User E2){
  if(GetSkor(E1) != GetSkor(E2))
    return GetSkor(E1) > GetSkor(E2);
  Tanggal Date1 = GetTanggal(E1);
  Tanggal Date2 = GetTanggal(E2);
  if(GetYear(Date1) != GetYear(Date2))
    return GetYear(Date1) < GetYear(Date2);
  if(GetMonth(Date1) != GetMonth(Date2))
    return GetMonth(Date1) < GetMonth(Date2);
  if(GetDay(Date1) != GetDay(Date2))
    return GetDay(Date1) < GetDay(Date2);

  Jam Time1 = GetJam(E1);
  Jam Time2 = GetJam(E2);
  if(GetHour(Time1) != GetHour(Time2))
    return GetHour(Time1) < GetHour(Time2);
  if(GetMin(Time1) != GetMin(Time2))
    return GetMin(Time1) < GetMin(Time2);
  return GetSec(Time1) < GetSec(Time2);
}
/*----- Sorting -----*/
/* Mengurutkan elemen tabel menurun dengan MaxAimum Sort */
/* Asumsi : MaxAimum sort adalah insertion sort yang dibalik */
/* sehingga array terurut menurun */
void MaxSortDesc(TabInt *T) {
    IdxTypeA i;
    for(i = GetFirstIdxA(*T); i <= GetLastIdxA(*T); ++i) {
        IdxTypeA j = GetFirstIdxA(*T);
        while (j <= GetLastIdxA(*T)) {
	if ((j-1)>0&&j <= GetLastIdxA(*T)&&IsLessA(GetElmtA(*T, j),GetElmtA(*T, j - 1))){
            User temp = GetElmtA(*T, j);
            SetElA(T, j, GetElmtA(*T, j - 1));
            SetElA(T, j - 1, temp);
	}
	    j = j+1;
        }
    }
}
/*----- Menambah elemen -----*/
/* Menambah elemen terakhir */
void AddAsLastEl(TabInt *T, User x) {
    SetNeffA(T, NbElmtA(*T) + 1);
    SetElA(T, GetLastIdxA(*T), x);
}

/* Menghapus elemen ke i */
void DelEl1(TabInt *T, IdxTypeA i) {
    IdxTypeA idx;
    SetNeffA(T, NbElmtA(*T) - 1);
    for(idx = i; idx < GetLastIdxA(*T); ++idx)
        SetElA(T, idx, GetElmtA(*T, idx + 1));

}

/*----- Tabel dengan elemen terurut membesar -----*/
/* Mencari indeks terkecil yang elemennya bernilai x */
IdxTypeA SearchUrutB (TabInt T, User x) {
	boolean found = FALSE;
    IdxTypeA i;
    i = 1;
   while(i <= GetLastIdxA(T) && !found){
        if (IsUserSama(GetElmtA(T, i), x)) 
            found = TRUE;
	else
	    i++;
        }
    if(found)
    	return i;
    else 
	return IdxUndefA;
}
/* Menambah x tanpa mengubah urutan nilai */
void Add1Urut(TabInt *T, User x) {
    if (!IsFullA(*T)) {
        AddAsLastEl(T, x);
	MaxSortDesc(T);
    }else 
	printf("T penuh");
}
/* Menghapus elemen bernilai x yang memiliki indeks terkecil */
void Del1Urut(TabInt *T, User x) {
    if (SearchUrutB(*T, x)!=IdxUndefA){
        DelEl1(T, SearchUrutB(*T, x));
	MaxSortDesc(T);
    }
}

/* I.S. : T terdefinisi, tidak kosong.
 * i merupakan indeks valid dalam T.
X terdefinisi. 
  F.S. : Nilai elemen T pada indeks ke-i berubah menjadi X.
T tetap terurut membesar, sehingga ada kemungkinan dilakukan
proses pengurutan kembali. } */
void UpdateElmtA(TabInt *T, IdxTypeA i,User x){
	SetElA(T,i,x);
	MaxSortDesc(T);
}
/* I.S. : T terdefinisi, boleh kosong. X terdefinisi
 F.S. : Semua elemen T yang bernilai X dihapus dari tabel penampung, jika
X ada di T. Jika X tidak ada, T tetap. */
void DelAllXA(TabInt *T,User x){
	IdxTypeA i;
	for(i = GetFirstIdxA(*T); i <= GetLastIdxA(*T); ++i)
		Del1Urut(T,x);
}

