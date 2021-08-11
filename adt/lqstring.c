#include "lqstring.h"

bool Equal(char *x, char *y) {
	int i;
	for(i = 0; x[i] || y[i]; i++) {
		if(x[i] != y[i])
			return false;
	}
	return true;
}

int strlen(char s[50]) {
	int i;
	for(i = 0; *(s + i); i++);
	return i;
}

void strcpy(char* a, char* b) {
	int i;
	for(i = 0; *(b + i); i++) {
		*(a + i) = *(b + i);
	}
	*(a + i) = *(b + i);
}