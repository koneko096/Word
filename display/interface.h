/**
 * Nama file	: interface.h
 * Topik		: Display
 * Tanggal 		: 13 November 2014
 * Deskripsi	: File Header Display Menu Utama
 * Author		: Luqman Arifin
 */

#ifndef _INTERFACE__
#define _INTERFACE__

#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <termios.h>
#include <time.h>

/* restore new terminal i/o settings */
void resetTermios();

/* initialize new terminal i/o settings */
void initTermios();

/* detect keyboard press */
int kbhit();

/* read 1 character */
char getch();

void gotoxy(int x, int y);

void HideCursor();

void ShowCursor();

#endif