/**
 * Nama file	: map.c
 * Topik			: Abstract Data Type
 * Tanggal 		: 11 November 2014
 * Deskripsi	: File Body dari ADT Map
 * Author			: Luqman Arifin
 */

#include "map.h"

/* return an item with spesific key and value */
item make_item(char i, int v) {
	item temp;
	temp.key = i;
	temp.val = v;
	return temp;
}

/* insert an item to a map */
void insert(map *m, char i, int v) {
	item temp = make_item(i, v);
	int placedAt = i % MAX_HASH_VALUE;
	while((*m).isi[placedAt]) {
		if(i == (*m).tab[placedAt].key) {
			(*m).tab[placedAt] = temp;
			(*m).isi[placedAt] = true;
			return;
		}
		placedAt++;
		placedAt %= MAX_HASH_VALUE;
	}
	(*m).tab[placedAt] = temp;
	(*m).isi[placedAt] = true;
}

/* erase an item from a map */
/* I.S. char harus pernah diinsert dalam map */
void erase(map *m, char i) { 
	int placedAt = i % MAX_HASH_VALUE;
	while((*m).tab[placedAt].key != i) {
		i++;
	}
	(*m).isi[placedAt] = false;
}

/* menghapus keseluruhan isi map */
void clear(map *m) {
	int i;
	for(i = 0; i < MAX_HASH_VALUE; i++) {
		(*m).isi[i] = false;
		(*m).tab[i].key = 0;
		(*m).tab[i].val = 0;
	}
}

/* mengembalikan value yang tersimpan dalam key i */
int at(map m, char i) {
	int placedAt = i % MAX_HASH_VALUE;
	while(m.isi[placedAt]) {
		if(i == m.tab[placedAt].key)
			return m.tab[placedAt].val;
		placedAt++;
		placedAt %= MAX_HASH_VALUE;
	}
	return null;
}

/* mengembalikan true bila char punya nilai, false jika tidak */
bool find(map m, char i) {
	int placedAt = i % MAX_HASH_VALUE;
	while(m.isi[placedAt]) {
		if(i == m.tab[placedAt].key)
			return true;
		placedAt++;
		placedAt %= MAX_HASH_VALUE;
	}
	return false;
}