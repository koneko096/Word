#include "tree.h"
#include <stdio.h>

/**** KONSTRUKTOR ****/
void CreateTree(Tree* T)
/* Mengalokasikan dan mendefinisikan tree */
/* I.S tree T belum terdefinisi */
{
	/* Kamus lokal */
	char i;

	/* Algoritma */
	*T = TreeAllocate();

	for(i = 'A'; i <= 'Z'; ++i) {
		TreeChild(*T, i) = TreeEmpty;
	}

	TreeStatus(*T) = 0;
}


/**** TREE KOSONG ****/
bool isTreeEmpty(Tree T)
/* Mengecek apakah tree merupakan tree kosong */
{
	return (T == TreeEmpty);
}


/**** MANAJEMEN MEMORI ****/
Tree TreeAllocate()
/* Mengalokasikan memori untuk node baru tree */
/* I.S tree T tidak teralokasi */
/* F.S tree T teralokasi */
{
	Tree ret = (Node*) malloc(sizeof(Node));
	while(ret == NULL) {
		ret = (Node*) malloc(sizeof(Node));
	}
	return ret;
}

void TreeDeallocate(Tree* T)
/* Mendealokasikan memori dari node */
/* I.S tree T teralokasi */
/* F.S tree T tidak teralokasi */
{
	free(*T);
}


/**** PRIMITIF PEMROSESAN TREE KATA *****/
void TreeAdd(Tree* T, char* S)
/* Menambahkan string S ke tree T */
/* Prekondisi : tree T terdefinisi */
{
	/* Kamus lokal */
	Tree P = *T;
	char *Ss = S; 
	/* Algoritma */
	while (*Ss != '\0')
	{
		if (isTreeEmpty(TreeChild(P, *Ss)))
		{
			CreateTree(&TreeChild(P, *Ss));
		}

		P = TreeChild(P, *Ss);
		Ss++;
	}

	TreeStatus(P) = true;
}

bool TreeSearch(Tree T, char* S)
/* Mencari keberadaan string S dalam tree T */
{
	/* Kamus lokal */
	char *Ss = S;
	Tree P = T;
	/* Algoritma */
	while ((!isTreeEmpty(P)) && (*Ss != '\0'))
	{
		P = TreeChild(P, *Ss);
		Ss++;
	}
	if (isTreeEmpty(P)) 
		return false;
	else
		return TreeStatus(P);
}