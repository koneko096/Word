/**
 * NIM / Nama	: 13513024 / Luqman Arifin Siswanto
 * Nama file	: mainkata1.c
 * Topik			: Abstract Data Type
 * Tanggal 		: 4 September 2014
 * Deskripsi	: File driver dari ADT Mesin Kata versi 1
 */

#include "mesinkata1.h"
#include <stdio.h>

int main() {
	STARTKATA();
	int i;
	while (!EndKata) {
		for (i = 1; i <= CKata.Length; i++) {
			printf("%c", CKata.TabKata[i]);
		}
		printf("\n");
		ADVKATA();
	}
	return 0;
}
