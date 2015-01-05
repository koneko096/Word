/**
 * Nama file	: bukan_string.h
 * Topik			: library pengganti string.h
 * Tanggal 		: 15 November 2014
 * Deskripsi	: File Header dari string.h
 * Author			: Luqman Arifin
 */

#ifndef _STRING__H_
#define _STRING__H_

#include <stdbool.h>
#include "../global.h"

/* Memeriksa apakah dua kata sama atau tidak */
/* Return true kalo ya, false kalau tidak */
bool Equal(char *x, char *y) {
	int i;
	for(i = 0; x[i] || y[i]; i++) {
		if(x[i] != y[i])
			return false;
	}
	return true;
}

int strlen(char s[50]) {
	int i;
	for(i = 0; *(s + i); i++);
	return i;
}

void strcpy(char* a, char* b) {
	int i;
	for(i = 0; *(b + i); i++) {
		*(a + i) = *(b + i);
	}
	*(a + i) = *(b + i);
}

#endif