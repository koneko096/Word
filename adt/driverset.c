/**
 * Nama file	: mset.c
 * Topik			: Abstract Data Type
 * Tanggal 		: 12 November 2014
 * Deskripsi	: File Driver dari ADT Set
 * Author			: Luqman Arifin
 */

#include "set.c"

Set S;
char temp[64000];

int main() {
	int i, j, n, id = 1;
	CreateSet(&S);
	while(id != -1) {
		scanf("%d %s", &id, temp);
		if(id) {
			Insert(&S, temp);
		} else {
			Delete(&S, temp);
		}
		PrintInfoSet(S);
	}

	return 0;
}