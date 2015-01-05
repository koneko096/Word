#include "array.c" 
#include <stdio.h>
#define pf printf
#define sf scanf

int main()
{
	TabInt T;
	IdxType l;
	ElType x;
	MakeEmpty(&T); 
	pf ("*** Inisialisasi tabel ***\n");
	BacaIsi(&T);
	TulisIsi(T);
	pf ("*** Penjumlahan seluruh elemen tabel *** \n");
	pf("Hasil penjumlahan seluruh elemen tabel = %d \n",SumTab(&T));
	pf("*** Update elemen tabel *** ");
	pf("Masukkan sebuah nilai baru = ");sf("%d",&x);
	l =0;
	pf("Masukkan indeks untuk update (antara 1 s.d. 6)");
	sf("%d",&l);
	UpdateElmt(&T,l,x);
	TulisIsi(T); 
	pf("*** Penambahan sebuah nilai elemen tabel ***\n");
	pf("Masukkan nilai yang akan ditambah = ");
	sf("%d",&x);
	Add1Urut(&T,x);
	TulisIsi(T);
	pf("*** Penghapusan semua elemen bernilai tertentu  ***\n");
	pf("Masukkan nilai yang akan dihapus = "); 
	sf("%d",&x);
	DelAllX(&T,x);
	TulisIsi(T);
	return(0);
}

