/* File Body ADT Matriks */

#include "matriks.h"
/** 	DEFINISI PROTOTIPE PRIMITIF 		**/
/* 	Kontruktor membentuk MATRIKS 	*/
void MakeMATRIKS(int NB, int NK, MATRIKS *M)
/* I.S : NB dan NK adalah valid untuk memori matriks yang dibuat */
{
	/* Kamus lokal */
	indeks i,j;
	/* Algoritma */
	SetBrsEff(M, NB);
	SetKolEff(M, NK);
	for (i = FirstIdxBrs(*M); i <= LastIdxBrs(*M); i++)
		for (j = FirstIdxKol(*M); j<= LastIdxBrs(*M); j++)
			SetEl(M, i, j, makepoint(i,j));
}

/* 	Untuk sebuah matriks M yang terdefinisi : */
indeks FirstIdxBrs(MATRIKS M){
	/* Kamus lokal */
	/* Algoritma */
	return BrsMin;
}
indeks FirstIdxKol(MATRIKS M){
	/* Kamus lokal */
	/* Algoritma */
	return KolMin;
}
indeks LastIdxBrs(MATRIKS M){
	/* Kamus lokal */
	/* Algoritma */
	return M.NBrsEff;
}
indeks LastIdxKol(MATRIKS M){
	/* Kamus lokal */
	/* Algoritma */
	return M.NKolEff;
}
el_type GetElmt(MATRIKS M, indeks i, indeks j){
	/* Kamus lokal */
	/* Algoritma */
	return M.Mem[i][j];
}

/*	 Operasi mengubah nilai elemen matriks : Set/Assign */
void SetBrsEff(MATRIKS *M, int NB)
/* I.S : M sudah terdefinisi */
{
	/* Kamus lokal */
	/* Algortima */
	(*M).NBrsEff = NB;
}
void SetKolEff(MATRIKS *M, int NK)
/* I.S : M sudah terdefinisi */
{
	/* Kamus lokal */
	/* Algoritma */
	(*M).NKolEff = NK;
}

void SetEl(MATRIKS *M, int i, int j, el_type x)
/* I.S : M sudah terdefinisi */
{
	(*M).Mem[i][j] = x;
}

/* 	Assigment MATRIKS 	*/
void CopyMATRIKS(MATRIKS MIn,MATRIKS *MHsl)
/* I.S : MIn terdefinisi */
{
	/* Kamus lokal */
	/* Algoritma */
	*MHsl = MIn;
}

/* Primitif Lain */
void Rotate(MATRIKS *M){
	/* Kamus lokal */
	MATRIKS Mtemp;
	indeks i, j, k, l;
	/* Algoritma */
	MakeMATRIKS(BrsMax, KolMax, &Mtemp);
	CopyMATRIKS(*M, &Mtemp);
	k = 1;
	l = 1;
	for(j = FirstIdxKol(Mtemp); j <= LastIdxKol(Mtemp); j++){
		for(i = LastIdxBrs(Mtemp); i>= FirstIdxBrs(Mtemp); i--){
			SetEl(M, k, l, GetElmt(Mtemp, i, j));
			l += 1;
		}
		k += 1;
		l = 1;
	}
}
