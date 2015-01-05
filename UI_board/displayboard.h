#ifndef DISPLAYBOARD_H
#define DISPLAYBOARD_H

#include <stdlib.h>
#include <wchar.h> // for future trials with wide chars
#include <stdio.h>
#include <locale.h> // to set Unicode locale 
#include "interface.h"
#include <stdbool.h>

/* Definisi Pembangun kerangka board */
#define RB "\e(0\x6a\e(B" // 188 Right Bottom corner
#define RT "\e(0\x6b\e(B" // 187 Right Top corner
#define LT "\e(0\x6c\e(B" // 201 Left Top cornet
#define LB "\e(0\x6d\e(B" // 200 Left Bottom corner
#define MC "\e(0\x6e\e(B" // 206 Middle Cross
#define HL "\e(0\x71\e(B" // 205 Horizontal Line
#define LC "\e(0\x74\e(B" // 204 Left Cross
#define RC "\e(0\x75\e(B" // 185 Right Cross
#define BC "\e(0\x76\e(B" // 202 Bottom Cross
#define TC "\e(0\x77\e(B" // 203 Top Cross
#define VL "\e(0\x78\e(B" // 186 Vertical Line

/* Definisi warna */
#define NORMAL 		"\x1B[0m"
#define RED  		"\x1B[31m"
#define GREEN  		"\x1B[32m"
#define YELLOW  	"\x1B[33m"
#define BLUE  		"\x1B[34m"
#define MAGENTA  	"\x1B[35m"
#define CYAN  		"\x1B[36m"
#define WHITE  		"\x1B[37m"

/* Definsi lain */
#define nl printf("\n")
#define SP printf(" ")
#define pVL	printf("%s", VL)
#define len 32 //ukuran kerangka board yang diinginkan (horizontal)

/* Bold */
#define bold system("setterm -bold on");
#define norm system("setterm -bold off");

/* Primitif */
void top_line();
/* Menggambar garis horizontal paling atas dari kerangka board */
void mid_line();
/* Menggambar garis horizontal di tengah dari kerangka board */
void buttom_line();
/* Menggambar garis horizontal paling bawah dari kerangka board */
void vertical_line();
/* Konstruktor garis vertikal kerangka board */
void print_char(char cc, bool cursor, bool visited, bool mask);
/* Mengisi satu baris kotak board dengan karakter */
void board_sceleton(int x_in, int y_in);
/* Mencetak kerangka board */
/* Terdapat space kosong pada x_in + 2, x_in + 6, x_in + 10, x_in + 14 */
/* space tersebut dialokasikan untuk penambahan karakter huruf */
/* Cara mengisi space dengan huruf : */
/* 
	pVL;
	print_char('A', false, true);
	pVL;
	print_char('B', false, true);
	pVL;
	print_char('C', false, true);
	pVL;
	print_char('D', true, false);
	pVL; 
*/
#endif