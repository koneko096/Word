#include "tree.c"
#include <stdio.h>

char S[50];
int n;

int main () {
	Tree T;
	CreateTree(&T);
	scanf("%d", &n);
	while (n--) {
		scanf("%s", S);
		TreeAdd(&T, S);
	}
	scanf("%d", &n);
	while (n--) {
		scanf("%s", S);
		printf("'%s' %s\n", S, TreeSearch(T, S) ? "Ada" : "Hilang");
	}
	return 0;
}