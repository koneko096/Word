#ifndef BOARD_H
#define BOARD_H

#include "../adt/matriks.c"
#include "../adt/point.h"
#include <stdbool.h>
#include "displayboard.c"
#include "../global.h"

/** DEFINISI TIPE BOARD **/
typedef MATRIKS Board;

/* Papan permainan yang sedang digunakan */
int rotateCounter = 0;
char letterBoard[5][5];
char* captionKeterangan[4];
int idCaption;

bool activeSelect = false;
bool visited[5][5];
bool mask;

Set used;
PQueue words;
User usernow;
point posNow;
Board posBoard;
Stack path;

const point dpos[] = {
	{-1,0},
	{-1,-1},
	{0,-1},
	{1,-1},
	{1,0},
	{1,1},
	{0,1},
	{-1,1}
};

/** KONSTRUKTOR **/
void CreateBoard();
/* Membuat board siap main dari file yang dberikan */


/** ROTASI PAPAN PERMAINAN **/
void RotateBoard();
/* Merotasi board 90 derajat clockwise */

void PrintSuggest();

void PrintKataPernah();

/** CETAK PAPAN PERMAINAN **/
void PrintBoard(int x_in, int y_in);
/* Mencetak isi papan permainan sekarang */


/** PINDAH KURSOR **/
void moveCursor(char cc);
/* Memindah posisi kursor */

void PrintMiniHighScore();

/** GAMEPLAY **/
void gamePlay();
/* Menjalankan permainan */

#endif
