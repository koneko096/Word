#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"

static FILE* fileExtern;
static char filename[] = "UI_board/boards/0.txt";

typedef point el_type;

/** KONSTRUKTOR **/
void CreateBoard()
/* Membuat board siap main dari file yang dberikan */
{
	/* Kamus lokal */
	int lotre, i, j, retval, x, y;
	char c;

	/* Algoritma */
	MakeMATRIKS(4, 4, &posBoard);
	for (i = FirstIdxBrs(posBoard); i <= LastIdxBrs(posBoard); i++) 
		for (j = FirstIdxKol(posBoard); j<= LastIdxKol(posBoard); j++)
			visited[i][j] = false;

	filename[16] = '0' + PilihanBoard;

	fileExtern = fopen(filename, "r");
	for (i = FirstIdxBrs(posBoard); i <= LastIdxBrs(posBoard); i++) 
	{
		for (j = FirstIdxKol(posBoard); j<= LastIdxKol(posBoard); j++) 
		{
			retval = fscanf(fileExtern, "%c ", &c);
			letterBoard[i][j] = c;
			visited[i][j] = false;
		}
	}
	fclose(fileExtern);
}


/** ROTASI PAPAN PERMAINAN **/
void RotateBoard()
/* Merotasi board 90 derajat clockwise */
{
	/* Kamus lokal */
	int i;

	/* Algoritma */
	/* Memutar papan koordinat 90 derajat counter clockwise */
	Rotate(&posBoard);
	rotateCounter++;
}

void PrintSuggest() {
	gotoxy(10, 5);
	printf("Word Suggest");
	gotoxy(11, 5);
	int i;
	for(i = 0; i < 13; i++) {
		printf("%s", HL);
	}
	while(!IsEmptyQ(Suggestion[idOnlineUser][PilihanBoard])
	&& Search(used, InfoHeadQ(Suggestion[idOnlineUser][PilihanBoard]))) {
		char temp[20];
		DelQ(&Suggestion[idOnlineUser][PilihanBoard], &temp);
	}
	if(!IsEmptyQ(Suggestion[idOnlineUser][PilihanBoard])) {
		gotoxy(12, 8);
		printf("%s", InfoHeadQ(Suggestion[idOnlineUser][PilihanBoard]));
	}
}

void PrintKataPernah() {
	gotoxy(3, 63);
	printf("Found Words");
	gotoxy(4, 63);
	int i;
	for(i = 0; i < 16; i++)
		printf("%s", HL);

	PrintInfoPQ(words, 5);
}

/** CETAK PAPAN PERMAINAN **/
void PrintBoard(int x_in, int y_in)
/* Mencetak isi papan permainan sekarang */
{
	/* Kamus lokal */
	int i, j, x;
	point p;
	bool current_cursor, visited_status;

	/* Algoritma */
	PrintSuggest();
	PrintKataPernah();
	gotoxy(22, 5);
	printf("%s", captionKeterangan[idCaption]);

	gotoxy(21, 63);
	for(i = 0; i < 16; i++) {
		printf("%s", HL);
	}

	gotoxy(22, 63);
	printf("SCORE NOW : %d", Totalscore);
	x = 2;
	board_sceleton(x_in, y_in);
	for (i = FirstIdxBrs(posBoard); i <= LastIdxBrs(posBoard); i++) 
	{
		gotoxy(x_in + x, y_in);
		pVL;
		for (j = FirstIdxKol(posBoard); j<= LastIdxKol(posBoard); j++) 
		{
			p = GetElmt(posBoard, i, j);
			visited_status = visited[getabsis(p)][getordinat(p)];

			if (eq(p, posNow))
				current_cursor = true;
			else
				current_cursor = false;
			print_char(letterBoard[getabsis(p)][getordinat(p)], current_cursor, visited_status, mask);
			pVL;
		}

		x += 4;
	}
}

/** PINDAH KURSOR **/
void moveCursor(char cc)
/* Memindah posisi kursor */
{
	/* Kamus lokal */
	char in[] = "wqazxcde";
	point newPos;
	int i = 0;

	/* Algoritma */
	while (i < 8 && cc != in[i]) i++;
	if (i < 8)
	{
		newPos = geser(posNow, dpos[(i + rotateCounter * 2) % 8]);
		if (IsIdxValid(posBoard, getabsis(newPos), getordinat(newPos)))
		{
			posNow = newPos;
		}
	}
}


void PrintMiniHighScore() {
	TabInt All;
	MakeEmptyA(&All);
	addressMulti now = FirstMulti(Highscore);
	while(now != NULL) {
		addressMulti p = now;
		while(p != NULL) {
			Add1Urut(&All, MultiInfo(p));
			p = NextMulti(p);
		}
		now = ContMulti(now);
	}

	gotoxy(2, 30);
	printf("No");
	gotoxy(2, 34);
	printf("Score");
	gotoxy(2, 50);
	printf("Who");

	int i, x = 4;
	int until = 1e9;
	if(NbElmtA(All) < until) until = NbElmtA(All);
	if(10 < until) until = 10;
	for(i = 1; i <= until; i++) {
		User currentUser = GetElmtA(All, i);
		bool hebat = Equal(GetNama(currentUser), onlineUser);
		bool punyaDia = IsUserSama(currentUser, usernow);
	
		gotoxy(x, 30);
		if(punyaDia) {
			printf("%s%d.", CYAN, i);
		} else
			printf("%d.", i);

		gotoxy(x, 34);
		printf("%d", GetSkor(currentUser));

		gotoxy(x, 45);
		if(hebat)
			printf("You");
		else
			printf("%s", GetNama(currentUser));

		printf("%s", NORMAL);
		norm;
		x += 2;
	}
}

void PrintKataSekarang() {
	/* Kamus */
	Stack tmp;
	point p, real;

	/* Algoritma */
	/* goto posisi benerno */
	while (!IsStackEmpty(path)) {
		PopStack(&path, &p);
		PushStack(&tmp, p);
	}
	while (!IsStackEmpty(tmp)) {
		PopStack(&tmp, &p);
		real = GetElmt(posBoard, getabsis(p), getordinat(p));
		printf("%c", letterBoard[getabsis(real)][getordinat(real)]);
		PushStack(&path, p);
	}
}

/** GAMEPLAY **/
void gamePlay()
/* Menjalankan permainan */
{
	/* Kamus lokal */
	double prev, now, sec;
	int i, j;
	char cc, *wordPointer;
	clock_t startTime;
	point tmp;
	bool cursorOn;
	rotateCounter = 0;

	/* Algoritma */
	CreateStackEmpty(&path);
	CreateSet(&used);
	CreatePQ(&words);
	sec = 5.0; // waktu permainan 2 menit
	Totalscore = 0;
	cursorOn = false;
	idCaption = 0;

	activeSelect = false;
	mask = false;
	CreateBoard();
	system("clear");
	initTermios();
	captionKeterangan[0] = "";
	captionKeterangan[1] = "Kata pernah dibentuk sebelumnya";
	captionKeterangan[2] = "Kata tidak ada dalam kamus";
	captionKeterangan[3] = "Kata berhasil dibentuk";

	posNow = makepoint(1,1);
	printf("%s", NORMAL); // inisialisasi warna 
	startTime = clock();
	prev = -1;

	HideCursor();
	while(1)
	{
		now = (int) (clock() - startTime)/ CLOCKS_PER_SEC;
		if (kbhit())
		{
			cc = getch();
			if (cc == 's')
			{
				if (!cursorOn){
					mask = true;
					cursorOn = true;
				}else{
					mask = false;
					cursorOn = false;
				}
				if (activeSelect)
				{
					for (i = FirstIdxBrs(posBoard); i <= LastIdxBrs(posBoard); i++) 
						for (j = FirstIdxKol(posBoard); j<= LastIdxKol(posBoard); j++)
							visited[i][j] = false;

					Revstack(&path);
					wordPointer = Word;

					while(!IsStackEmpty(path)) {
						PopStack(&path, &tmp);
						*wordPointer = letterBoard[getabsis(tmp)][getordinat(tmp)];
						wordPointer++;
					}					
					*wordPointer = '\0';

					if (TreeSearch(Dictionary, Word)) {
						if (!Search(used, Word)) {
							Insert(&used, Word);
							PQPush(&words, Word);
							Totalscore += getSkor(Word);
							idCaption = 3;
						} else {
							idCaption = 1;
						}
					} else {
						idCaption = 2;
					}
				} else
					idCaption = 0;
				activeSelect = !activeSelect;				
			}
			else if (cc == 'r')
			{
				RotateBoard();
			}
			moveCursor(cc);
			resetTermios();
			if (activeSelect)
			{
				if (!visited[getabsis(posNow)][getordinat(posNow)])
				{
					PushStack(&path, posNow);
					visited[getabsis(posNow)][getordinat(posNow)] = true;
				}
				else
				{
					while (!IsStackEmpty(path) && neq(posNow, InfoTop(path)))
					{
						PopStack(&path, &tmp);
						visited[getabsis(tmp)][getordinat(tmp)] = false;
					}
				}
			}
			initTermios();
			system("clear");
			PrintBoard(4,20);
			gotoxy(2, 5);
			printf("%.0lf seconds remaining\n", sec - now);
		}
		if (prev != now)
		{
			if (prev == sec) break;
			resetTermios(); // reset terminal setting to enable buffer i/o and echo (printf)
			system("clear");
			PrintBoard(4,20);
			PrintKataSekarang();
			gotoxy(2, 5);
			printf("%.0lf seconds remaining\n", sec - now);
			initTermios(); // use new terminal setting again to make kbhit() and getch() work
			prev = now;
		}
	}
	system("clear");
	gotoxy(2, 10);
	printf("Time Up\n"); /* <-- pasang ditengah */

	strcpy(GetNama(usernow), onlineUser);
	GetTanggal(usernow) = GetCurrentDate();
	GetJam(usernow) = GetCurrentTime();
	GetSkor(usernow) = Totalscore;
	InsertUser(&Highscore, usernow);

	gotoxy(4, 4);
	printf("Totalscore : %d\n", Totalscore);
	gotoxy(6, 4);
	printf("Found Word");
	bool ada = 0;
	int x = 7;
	while(!isPQEmpty(words)) {
		char temp[20];
		PQPop(&words, temp);
		gotoxy(x, 4);
		printf("+%d", getSkor(temp));
		gotoxy(x, 8);
		printf("%s\n", temp);
		AddQ(&Suggestion[idOnlineUser][PilihanBoard], temp);
		ada = 1;
		x++;
	}
	if(!ada) {
		gotoxy(7, 4);
		printf("Tidak ada");
	}
	PrintMiniHighScore();
	while(1) {
		HideCursor();
		if(kbhit()) {
			cc = getch();
			if(cc == 's' || cc == '\n') {
				break;
			}
		}
	}
	resetTermios();
}