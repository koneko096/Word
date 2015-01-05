/* File body ADT Queue */

 #include "queue.h"
 
/* Predikat Pemeriksaan Kondisi Queue */
boolean IsEmptyQ(Queue Q){
	/* Kamus lokal */
	/* Algoritma */
	return (HeadQ(Q) == NilQueue) && (TailQ(Q) == NilQueue);
}
boolean IsFullQ(Queue Q){
	/* Kamus lokal */
	addressQ i;
	/* Algoritma */
	return (HeadQ(Q) == 1) && (TailQ(Q) == MaxElQ(Q));
}
int NBElmtQ(Queue Q){
	/* Kamus lokal */
	/* Algoritma */
	return TailQ(Q) - HeadQ(Q) + 1;
}

/* Konstruktor */
void CreateEmptyQ(Queue *Q, int Max)
/* I.S. 	: sembarang */
{
	/* Kamus lokal */
	/* Algoritma */
	(*Q).T = (infotypeQ *) malloc ((Max + 1) * sizeof(infotypeQ));
	while((*Q).T == NULL) {
		(*Q).T = (infotypeQ *) malloc ((Max + 1) * sizeof(infotypeQ));
	}
	MaxElQ(*Q) = Max;
	HeadQ(*Q)  = NilQueue;
	TailQ(*Q)  = NilQueue;
}

/* Destruktor */
void DeAlokasiQ(Queue *Q)
/* I.S.		: Q pernah dialokasi */
{
	/* Kamus lokal */
	/* Algoritma */
	MaxElQ(*Q) = NilQueue;
	free((*Q).T);
	
}

/* Operator - Operator Dasar Queue */
void AddQ(Queue *Q, infotypeQ X)
/* I.S. 	: Q mungkin kosong, tabel penampung Q tidak penuh */
{
	/* Kamus lokal */
	addressQ i, j;
	/* Algoritma */
	if (IsEmptyQ(*Q))
		HeadQ(*Q) = 1;
	else {
		if (TailQ(*Q) == MaxElQ(*Q)){
			i = HeadQ(*Q);
			j = 1;
			do {
				strcpy(*((*Q).T+j), (*(*Q).T+i));
				i++;
				j++;
			} while (i <= TailQ(*Q));
		}
	}
	TailQ(*Q)++;
	strcpy(InfoTailQ(*Q), X);
}
void DelQ(Queue *Q, infotypeQ *X)
/* I.S. 	: Q tidak kosong */
{
	/* Kamus lokal */
	/* Algoritma */
	strcpy(*X, InfoHeadQ(*Q));
	if (HeadQ(*Q) == TailQ(*Q)){
		HeadQ(*Q) = NilQueue;
		TailQ(*Q) = NilQueue;
	}
	else{
		HeadQ(*Q)++;
	}
}
