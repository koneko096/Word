#include "displayboard.h"

/* Primitif */

void top_line(){
	int i;
	printf("%s", LT);
	for(i = 1; i <= len; i++){
		printf("%s", HL);
		if(((i % (len / 4)) == 0) && (i != len))
			printf("%s", TC);	
	}
	printf("%s", RT);
	nl;
}
void mid_line(){
	int i;
	printf("%s", LC);
	for(i = 1; i <= len; i++){
		printf("%s", HL);
		if(((i % (len / 4)) == 0) && (i != len))
			printf("%s", MC);	
	}
	printf("%s", RC);
	nl;
}
void buttom_line(){
	int i;
	printf("%s", LB);
	for(i = 1; i <= len; i++){
		printf("%s", HL);
		if(((i % (len / 4)) == 0) && (i != len))
			printf("%s", BC);	
	}
	printf("%s", RB);
	nl;
}
void vertical_line(){
	int i;
	printf("%s", VL);
	for(i = 1; i <= len; i++){
		putchar(' ');
		if(((i % (len / 4)) == 0) && (i != len))
			printf("%s", VL);	
	}
	printf("%s", VL);
	nl;
}
void print_char(char cc, bool cursor, bool visited, bool mask){
	SP; SP; 
	if (cursor && mask){
		printf("> %s%c%s ", GREEN, cc, NORMAL);
	}
	else if (cursor) {
		printf("> %c ", cc);
	}
	else if (visited){
		printf(" %s[%c]%s", GREEN, cc, NORMAL);
	}
	else{
		printf("  %c ", cc);
	}
	SP; SP;

}

void board_sceleton(int x_in, int y_in){

	gotoxy(x_in, y_in);
	top_line();
	gotoxy(x_in + 1, y_in);
	vertical_line();
	gotoxy(x_in + 3, y_in);
	vertical_line();
	gotoxy(x_in + 4, y_in);
	mid_line();
	gotoxy(x_in + 5, y_in);
	vertical_line();
	gotoxy(x_in + 7, y_in);
	vertical_line();
	gotoxy(x_in + 8, y_in);
	mid_line();
	gotoxy(x_in + 9, y_in);
	vertical_line();
	gotoxy(x_in + 11, y_in);
	vertical_line();
	gotoxy(x_in + 12, y_in);
	mid_line();
	gotoxy(x_in + 13, y_in);
	vertical_line();
	gotoxy(x_in + 15, y_in);
	vertical_line();
	gotoxy(x_in + 16, y_in);
	buttom_line();
}