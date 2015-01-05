/**
 * Nama file	: mmap.c
 * Topik			: Abstract Data Type
 * Tanggal 		: 11 November 2014
 * Deskripsi	: File Driver dari ADT Map
 * Author			: Luqman Arifin
 */

#include "map.c"
#include <stdio.h>

map m;

int main() {
	char c;
	for(c = 'a'; c <= 'z'; c++) {
		insert(&m, c, c - 'a');
		printf("%c %d\n", c, at(m, c));
	}
	insert(&m, 'a', 1000);
	printf("%c %d\n", 'a', at(m, 'a'));
	clear(&m);
	for(c = 'a'; c <= 'z'; c++) {
		printf("%c %d\n", c, at(m, c));
	}
	clear(&m);
	int i, j;
	for(i = 10242; i < 11232; i += 50, j++) {
		insert(&m, i, j);
		printf("%d %d\n", i, at(m, i));
	}
	return 0;
}