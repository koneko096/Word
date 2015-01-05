/* File driver ADT Queue */

#include "queue.c"
#include <stdio.h>

int main(){
	/* Kamus lokal main */
	Queue Q;
	int i;
	infotypeQ X, temp;
	/* Algoritma */
	system("clear");
	CreateEmptyQ(&Q, 10);
	printf("Masukan 10 elemen \n");
	for(i = 1; i <= 10; i++){
		printf("Input elemen : ");
		scanf("%s", X);
		AddQ(&Q, X);
	}
	system("clear");
	printf("Suggest : %s\n", InfoHeadQ(Q));
	scanf("%s", X);
	while(!IsEmptyQ(Q)){
		if (strcmp(X, InfoHeadQ(Q))) // X != InfoHead(Q)
			scanf("%s", X);
		else {
			DelQ(&Q, &temp);
			if (!IsEmptyQ(Q)){
				system("clear");
				printf("Suggest : %s\n", InfoHeadQ(Q));
				scanf("%s", X);
			}
		}
	}
	printf("Done \n");
	return 0;
}
