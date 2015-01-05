/**
 * Nama file	: map.h
 * Topik			: Abstract Data Type
 * Tanggal 		: 11 November 2014
 * Deskripsi	: File Header dari ADT Map
 * Author			: Luqman Arifin
 */

#ifndef MAP_ADT
#define MAP_ADT

/* ADT Map diimplementasi menggunakan Hash  */

#include <stdbool.h>
#include <stdlib.h>


// usually a prime number
#define MAX_HASH_VALUE 31

#define null 0

typedef struct {
	char key;
	int val;
} item;

typedef struct {
	item tab[MAX_HASH_VALUE];
	bool isi[MAX_HASH_VALUE];
} map;

item make_item(char i, int v);
void insert(map *m, char i, int v);
void erase(map *m, char i);
void clear(map *m);
int at(map m, char i);
bool find(map m, char i);

#endif