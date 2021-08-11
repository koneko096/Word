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

/* Memeriksa apakah dua kata sama atau tidak */
/* Return true kalo ya, false kalau tidak */
bool Equal(char *x, char *y);
int strlen(char s[50]);
void strcpy(char* a, char* b);

#endif