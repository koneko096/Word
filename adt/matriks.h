/* File Header ADT Matriks */
/* Digunakan untuk merepresentasikan board permainan */

/****** 	Definisi TYPE MATRIKS dengan indeks integer 	*****/

#ifndef MATRIKS_H
#define MATRIKS_H	
#include <stdio.h>
#include "point.c"
#include "boolean.h"
/* Ukuran minimum dan maksimum baris dan kolom */

#define BrsMin 1
#define BrsMax 4
#define KolMin 1
#define KolMax 4

typedef int indeks; //indeks baris,kolom
typedef point el_type;
typedef struct {
	el_type Mem[BrsMax+1][KolMax+1];
	int NBrsEff;
	int NKolEff;
} MATRIKS;
//NBrsEff>=1 dan NKolEff >=1
//Memori matriks yang dipakai selalu di "ujung kiri atas"

/** 	DEFINISI PROTOTIPE PRIMITIF 		**/
/* 	Kontruktor membentuk MATRIKS 	*/
void MakeMATRIKS(int NB, int NK, MATRIKS *M);
/* Membentuk sebuah MATRIKS "kosong" berurukan NBxNK di "ujung kiri" memori */
/* I.S : NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S : Matriks M sesuai dengan definisi di atas terbentuk */

/* 	Untuk sebuah matriks M yang terdefinisi : */
indeks FirstIdxBrs(MATRIKS M);
/* Mengirimkan indeks baris terkecil M */
indeks FirstIdxKol(MATRIKS M);
/* Mengirimkan indeks kolom terkecil M */
indeks LastIdxBrs(MATRIKS M);
/* Mengirimkan indeks baris terbesar M */
indeks LastIdxKol(MATRIKS M);
/* Mengirimkan indeks kolom terbesar M */
/* Mengirimkan true jika i,j adalah indeks efektif bagi M */
el_type GetElmt(MATRIKS M, indeks i, indeks j);
/* Mengirimkan elemen M dengan nomor baris i dan nomor kolom j */

/*	 Operasi mengubah nilai elemen matriks : Set/Assign */
void SetBrsEff(MATRIKS *M, int NB);
/* I.S : M sudah terdefinisi */
/* F.S : Nilai M.BrsEff diisi dengan NB */
void SetKolEff(MATRIKS *M, int NK);
/* I.S : M sudah terdefinisi */
/* F.S : Nilai M.KolEff diisi dengan NK */
void SetEl(MATRIKS *M, int i, int j, el_type x);
/* I.S : M sudah terdefinisi */
/* F.S : M[i,j] bernilai x */
/* Proses : Mengisi M[i,j] dengan x */
boolean IsIdxValid (MATRIKS M, int i, int j);
/* Mengirimkan true jika i, j adalah indeks yang valid */

/* 	Assigment MATRIKS 	*/
void CopyMATRIKS(MATRIKS MIn,MATRIKS *MHsl);
/* Melakukan assignment MHsl <- Min */
/* I.S : MIn terdefinisi */
/* F.S : MHsl terdefinsi dengan elemen MIn */

/* Primitif Lain */
void Rotate(MATRIKS *M);
/* I.S : M terdefinisi */
/* F.S : Elemen pada M dirotasi 90 derajat secara clockwise */

#endif
