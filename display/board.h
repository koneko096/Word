#ifndef BOARD_H
#define BOARD_H

#include "../adt/matriks.c"
#include "../adt/point.h"
#include "../adt/set.h"
#include "../adt/pqueue.h"
#include "../adt/stack.h"
#include "../adt/multilist.h"
#include "../adt/queue.h"
#include "../adt/user.h"
#include <stdbool.h>
#include "displayboard.h"

/** DEFINISI TIPE BOARD **/
typedef MATRIKS Board;

#define MAX_EXPECTED_SUGGEST 100
#define MAX_EXPECTED_USER 1000
#define N_BOARD 10

/* Papan permainan yang sedang digunakan */
int rotateCounter = 0;
char letterBoard[5][5];
char* captionKeterangan[4];
int idCaption;
int PilihanBoard;
Queue Suggestion[MAX_EXPECTED_USER][N_BOARD];

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
void CreateBoard(int PilihanBoard);
/* Membuat board siap main dari file yang dberikan */


/** ROTASI PAPAN PERMAINAN **/
void RotateBoard();
/* Merotasi board 90 derajat clockwise */

void PrintKataPernah();

/** CETAK PAPAN PERMAINAN **/
void PrintBoard(int x_in, int y_in, long Totalscore, int idOnlineUser);
/* Mencetak isi papan permainan sekarang */


/** PINDAH KURSOR **/
void moveCursor(char cc);
/* Memindah posisi kursor */

void PrintMiniHighScore(MultiList Highscore, char* onlineUser);

#endif
