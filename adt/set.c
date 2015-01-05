/**
 * Nama file	: set.c
 * Topik			: Abstract Data Type
 * Tanggal 		: 12 November 2014
 * Deskripsi	: File Body dari ADT Set
 * Author			: Luqman Arifin
 */

#include "set.h"

/* ***************** PRIMITIF-PRIMITIF LIST ***************** */


/* *** TEST LIST KOSONG *** */

/* Mengecek apakah suatu set kosong */
bool IsSetEmpty(Set S) {
	return First(S) == Nil && Last(S) == Nil;
}

/* *** PEMBUATAN LIST KOSONG *** */

/* Membuat set baru, semua elemen yang pernah dialokasi,
 * didealokasi */
void CreateSet(Set *S) {
	addressSet now = First(*S);
	while(now != Nil) {
		addressSet next = NextSet(now);
		DealokasiSet(&now);
		now = next;
	}
	First(*S) = Nil;
}

/* *** Manajemen Memori *** */

/* Mengalokasikan kata pada set
 * Mengembalikan addressSet p dengan
 * SetInfo(p) = x
 * NextSet(p) = PrevSet(p) = Nil */
addressSet AlokasiSet(char x[20]) {
	int lent, i;
	addressSet ret = (addressSet) malloc(sizeof(ElementSet));
	while(ret == NULL) {
		ret = (addressSet) malloc(sizeof(ElementSet));
	}
	lent = strlen(x);
	for(i = 0; i < lent; i++) {
		SetInfo(ret)[i] = x[i];
	}
	SetInfo(ret)[lent] = '\0';
	NextSet(ret) = Nil;
	PrevSet(ret) = Nil;
}

/* DealokasiSet elemen */
void DealokasiSet(addressSet *p) {
	free(*p);
}

/* *** PENCARIAN SEBUAH ELEMEN LIST *** */

/* Mengembalikan addressSet tempat elemen disimpan bila elemen
 * merupakan anggota set, Nil bila bukan */
addressSet Search(Set S, char x[20]) {
	addressSet now = First(S);
	while(now != Nil) {
		if(Equal(SetInfo(now), x))
			return now;
		now = NextSet(now);
	}
	return Nil;
}

/* ***************** PRIMITIF BERDASARKAN NILAI ***************** */

/* *** PENAMBAHAN ELEMEN *** */

/* Memasukkan elemen ke dalam set
 * Tidak melakukan apa-apa bila elemen sudah menjadi anggota set */
void Insert(Set *S, char x[20]) {
	if(Search(*S, x)) {
		return;
	}
	addressSet p = AlokasiSet(x);
	addressSet tail = Last(*S);
	PrevSet(p) = tail;
	if(tail) NextSet(tail) = p;
	if(IsSetEmpty(*S)) First(*S) = p;
	Last(*S) = p;
}

/* *** PENGHAPUSAN ELEMEN *** */

/* Menghapus elemen set pada alamat "at" */
void DeleteAt(Set *S, addressSet at) {
	PrevSet(First(*S)) = Nil;
	NextSet(Last(*S)) = Nil;
	addressSet aft = NextSet(at);
	addressSet bef = PrevSet(at);
	
	if(bef) NextSet(bef) = aft;	// punya elemen sebelum
	else First(*S) = aft;			// at adalah elemen pertama
	
	if(aft) PrevSet(aft) = bef;	// punya elemen sesudah
	else Last(*S) = bef;			// at adalah elemen terakhir
	DealokasiSet(&at);
}

/* Menghapus elemen "x" dari set
 * Tidak melakukan apa-apa jika set tidak mempunyai x */
void Delete(Set *S, char x[20]) {
	addressSet at = Search(*S, x);
	if(at) {
		DeleteAt(S, at);
	}
}

/* Fungsi tambahan untuk Debugging */
void PrintInfoSet(Set S) {
	addressSet now = First(S);
	bool ada = false;
	printf("Isi set : \n");
	while(now != Nil) {
		ada = true;
		printf("%s\n", SetInfo(now));
		now = NextSet(now);
	}
	if(!ada) printf("Set kosong\n");
	printf("\n");
}