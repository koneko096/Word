#ifndef TREE_H
#define TREE_H

#include <stdbool.h>
#include <stdlib.h>

/**** DEFINISI TIPE TREE ****/
typedef struct Node_t* Tree;
typedef struct Node_t {
	int NChildren;
	bool status;
	Tree children[26];
} Node;


/**** SELEKTOR ****/
#define TreeEmpty 			NULL
#define TreeStatus(T)		(T)->status
#define TreeChildren(T)		(T)->children
#define TreeChild(T,c)		(T)->children[c - 'A']


/**** KONSTRUKTOR ****/
void CreateTree(Tree* T);
/* Membentuk tree yang sudah teralokasi menjadi terdefinisi */


/**** TREE KOSONG ****/
bool isTreeEmpty(Tree T);
/* Mengecek apakah tree merupakan tree kosong */


/**** MANAJEMEN MEMORI ****/
Tree TreeAllocate();
/* Mengalokasikan memori untuk node baru tree */
/* I.S tree T tidak teralokasi */
/* F.S tree T teralokasi */

void TreeDeallocate(Tree* T);
/* Mendealokasikan memori dari node */
/* I.S tree T teralokasi */
/* F.S tree T tidak teralokasi */


/**** PRIMITIF PEMROSESAN TREE KATA *****/
void TreeAdd(Tree* T, char* S);
/* Menambahkan string S ke tree T */

bool TreeSearch(Tree T, char* S);
/* Mencari keberadaan string S dalam tree T */
/* Prekondisi : tree T terdefinisi */

#endif