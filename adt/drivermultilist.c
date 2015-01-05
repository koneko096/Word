/**
 * Nama file	: drivermultilist.c
 * Topik			: Abstract Data Type
 * Tanggal 		: 12 November 2014
 * Deskripsi	: File Body dari ADT Multi List
 * Author			: Luqman Arifin
 */

#include "multilist.c"
#include <stdio.h>

MultiList L;
User temp;

int main() {
	int i, j, n, id = 1;
	CreateMultiList(&L);
	while(id != -1) {
		scanf("%d", &temp);
		InsertUser(&L, temp);
		PrintList(L);
	}
	CreateMultiList(&L);
	return 0;
}