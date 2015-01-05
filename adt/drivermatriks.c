/* File driver ADT Matriks */

#include "matriks.c"

int main(){
	/* Kamus lokal main */
	MATRIKS M;
	/* Algoritma */
	MakeMATRIKS(BrsMax, KolMax, &M);
	SetEl(&M, 1, 1, 'A');
	SetEl(&M, 1, 2, 'B');
	SetEl(&M, 1, 3, 'C');
	SetEl(&M, 1, 4, 'D');
	SetEl(&M, 2, 1, 'E');
	SetEl(&M, 2, 2, 'F');
	SetEl(&M, 2, 3, 'G');
	SetEl(&M, 2, 4, 'H');
	SetEl(&M, 3, 1, 'I');
	SetEl(&M, 3, 2, 'J');
	SetEl(&M, 3, 3, 'K');
	SetEl(&M, 3, 4, 'L');
	SetEl(&M, 4, 1, 'M');
	SetEl(&M, 4, 2, 'N');
	SetEl(&M, 4, 3, 'O');
	SetEl(&M, 4, 4, 'P');
	TulisMATRIKS(M);
	printf("\nRotasi 90 derajat clockwise \n");
	Rotate(&M);
	TulisMATRIKS(M);
	
	return 0;
}
