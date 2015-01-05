/**
 * Nama file	: multilist.c
 * Topik			: Abstract Data Type
 * Tanggal 		: 12 November 2014
 * Deskripsi	: File Body dari ADT Multi List
 * Author			: Luqman Arifin
 */

#include "multilist.h"

bool IsUserSama(User U1, User U2) {
	Tanggal date1 = GetTanggal(U1);
	Tanggal date2 = GetTanggal(U2);
	Jam time1 = GetJam(U1);
	Jam time2 = GetJam(U2);
	return GetSkor(U1) == GetSkor(U2)
	&& GetDay(date1) == GetDay(date2)
	&& GetMonth(date1) == GetMonth(date2)
	&& GetYear(date1) == GetYear(date2)
	&& GetHour(time1) == GetHour(time2)
	&& GetMin(time1) == GetMin(time2)
	&& GetSec(time1) == GetSec(time2);
}

/* AlokasiMulti memori untuk User U, return alamat p
 * MultiInfo(p) = U
 * NextMulti(p) = Nil */
addressMulti AlokasiMulti(User U) {
	addressMulti p = (addressMulti) malloc(sizeof(ElementMultiList));
	while(p == NULL) {
		p = (addressMulti) malloc(sizeof(ElementMultiList));
	}
	MultiInfo(p) = U;
	NextMulti(p) = Nil;
	return p;
}

/* Membebaskan memori */
void DealokasiMulti(addressMulti p) {
	free(p);
}

/* Mengecek apakah sebuah List kosong */
bool IsMultiListEmpty(MultiList L) {
	return FirstMulti(L) == Nil;
}

/* Membuat MultiList baru  */
void CreateMultiList(MultiList *L) {
	addressMulti now = FirstMulti(*L);
	while(now != Nil) {
		addressMulti cont = ContMulti(now);
		addressMulti p = now;
		while(p != Nil) {
			addressMulti next = NextMulti(p);
			DealokasiMulti(p);
			p = next;
		}
		now = cont;
	}
	FirstMulti(*L) = Nil;
}

/* Mencari apa user sudah masuk di multilist
 * return true kalo sudah di include
 * return false otherwise */
bool SearchName(MultiList L, User U) {
	addressMulti now = FirstMulti(L);
	while(now != Nil) {
		User info = MultiInfo(now);
		if(Equal(GetNama(info), GetNama(U))) {
			return true;
		}
		now = ContMulti(now);
	}
	return false;
}

/* Memasukkan sebuah user ke dalam multilist */
void InsertUser(MultiList *L, User U) {
	if(SearchName(*L, U)) {
		InsertOldUser(L, U);
	} else {
		InsertNewUser(L, U);
	}
}

/* Memasukkan user baru yang belum pernah dimasukkan ke dalam multilist */
void InsertNewUser(MultiList *L, User U) {
	addressMulti now = FirstMulti(*L);
	addressMulti prev = Nil;
	while(now != Nil) {
		prev = now;
		now = ContMulti(now);
	}
	addressMulti loc = AlokasiMulti(U);
	if(prev) {
		ContMulti(prev) = loc;
	} else {
		FirstMulti(*L) = loc;
	}
}

/* Memasukkan record user yang usernya pernah dimasukkan ke dalam multilist */
void InsertOldUser(MultiList *L, User U) {
	addressMulti now = FirstMulti(*L);
	addressMulti prev = Nil;
	while(now != Nil) {
		prev = now;
		if(Equal(GetNama(MultiInfo(now)), GetNama(U))) {
			now = NextMulti(now);
		} else {
			now = ContMulti(now);
		}
	}
	addressMulti loc = AlokasiMulti(U);
	NextMulti(prev) = loc;
}

/* Output List untuk debugging */
void PrintList(MultiList L) {
	addressMulti now = FirstMulti(L);
	while(now != Nil) {
		addressMulti p = now;
		while(p != Nil) {
			/*
			printf("%d ", MultiInfo(p));
			*/
			p = NextMulti(p);
		}
		printf("\n");
		now = ContMulti(now);
	}
	if(IsMultiListEmpty(L))
		printf("MultiList kosong.\n");
	printf("\n");
}