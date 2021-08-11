#include "display/menu.h"
#include "display/board.h"
#include "adt/jam.h"
#include "adt/tanggal.h"
#include "adt/mesinkata.c"
#include "adt/tree.c"
#include "adt/multilist.c"
#include "adt/pqueue.c"
#include "adt/queue.c"
#include "adt/stack.c"
#include "adt/set.c"
#include "adt/map.c"
#include <stdbool.h>
// #include "adt/bukan_string.h"

/* berisi nama user yang sedang online */
char onlineUser[20];
char registeredUser[MAX_EXPECTED_USER][20];
char Word[20];
int nRegisteredUser;
int Totalscore;

Tree Dictionary;
MultiList Highscore;
map Scoring;

static FILE *data;
static int retval;

/* 1 bila ada orang yang online (nama ada di onlineUser)
 * 0 bila tidak ada orang yang sedang online */
int onlineStatus;

/* Berisi ID user dalam tabel Suggestion dan registered user */
int idOnlineUser;

int getSkor(char* S) {
	char* t = S;
	int skor = 0;
	while (*t) {
		skor += at(Scoring, *t);
		t++;
	}
	return skor;
}

/* load data from external file */
/* Data yang diinclude :
 * - Daftar registered user
 * - List Highscore
 * - Suggestion kata
 * - Dictionary */
void initialize() {
	/* Load scoring to the map */
	clear(&Scoring);
	insert(&Scoring, 'E', 1);
	insert(&Scoring, 'A', 2);
	insert(&Scoring, 'I', 2);
	insert(&Scoring, 'N', 2);
	insert(&Scoring, 'O', 2);
	insert(&Scoring, 'R', 2);
	insert(&Scoring, 'S', 2);
	insert(&Scoring, 'T', 2);

	insert(&Scoring, 'C', 3);
	insert(&Scoring, 'D', 3);
	insert(&Scoring, 'L', 3);

	insert(&Scoring, 'G', 4);
	insert(&Scoring, 'H', 4);
	insert(&Scoring, 'M', 4);
	insert(&Scoring, 'P', 4);
	insert(&Scoring, 'U', 4);

	insert(&Scoring, 'B', 5);
	insert(&Scoring, 'F', 5);
	insert(&Scoring, 'Y', 5);

	insert(&Scoring, 'K', 6);
	insert(&Scoring, 'V', 6);
	insert(&Scoring, 'W', 6);

	insert(&Scoring, 'Z', 8);
	insert(&Scoring, 'X', 9);

	insert(&Scoring, 'J', 10);
	insert(&Scoring, 'Q', 10);

	/* Load Dictionary */
	CreateTree(&Dictionary);
	STARTKATA();
	while(!EndKata) {
		CKata.TabKata[CKata.Length + 1] = '\0';
		TreeAdd(&Dictionary, CKata.TabKata + 1);
		ADVKATA();
	}

	/* Load Registered User */
	data = fopen("database/user.txt", "r");
	fscanf(data, "%d", &nRegisteredUser);
	int i, j;
	for(i = 0; i < nRegisteredUser; i++) {
		fscanf(data, "%s", registeredUser[i]);
	}
	fclose(data);

	/* Load Database Record */
	data = fopen("database/highscore.txt", "r");
	CreateMultiList(&Highscore);
	int n;
	fscanf(data, "%d", &n);
	for(i = 0; i < n; i++) {
		User U;
		int skor, tanggal, bulan, tahun, jam, menit, detik;
		char name[20];
		fscanf(data, "%d", &skor);
		fscanf(data, "%s", name);
		fscanf(data, "%d", &tanggal);
		fscanf(data, "%d", &bulan);
		fscanf(data, "%d", &tahun);
		fscanf(data, "%d", &jam);
		fscanf(data, "%d", &menit);
		fscanf(data, "%d", &detik);
		Tanggal date = MakeTanggal(tanggal, bulan, tahun);
		Jam waktu = MakeJam(jam, menit, detik);
		int lent = strlen(name);
		for(j = 0; j < lent; j++) {
			GetNama(U)[j] = name[j];
		}
		GetNama(U)[lent] = '\0';
		GetTanggal(U) = date;
		GetJam(U) = waktu;
		GetSkor(U) = skor;
		InsertUser(&Highscore, U);
	}
	fclose(data);

	/* Load Suggestion from External File */
	data = fopen ("database/suggestion.txt", "r");
	fscanf(data, "%d", &n);
	for(i = 0; i < nRegisteredUser; i++) {
		for(j = 0; j < N_BOARD; j++) {
			CreateEmptyQ(&Suggestion[i][j], MAX_EXPECTED_SUGGEST);
		}
	}
	for(i = 0; i < n; i++) {
		char name[20];
		int hisId = -1;
		int nSuggest, numBoard;

		fscanf(data, "%d", &hisId);
		fscanf(data, "%d", &numBoard);
		fscanf(data, "%d", &nSuggest);
		for(j = 0; j < nSuggest; j++) {
			char temp[20];
			fscanf(data, "%s", temp);
			AddQ(&Suggestion[hisId][numBoard], temp);
		}
	}
	fclose(data);
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

/* Menulis data penting ke dalam file eksternal untuk diproses kapan kapan */
void finishing() {
	int i, j, n;

	data = fopen("database/user.txt", "w");
	fprintf(data, "%d\n", nRegisteredUser);
	for(i = 0; i < nRegisteredUser; i++) {
		fprintf(data, "%s\n", registeredUser[i]);
	}
	fclose(data);

	data = fopen("database/highscore.txt", "w");
	addressMulti now = FirstMulti(Highscore);
	n = 0;
	while(now != NULL) {
		addressMulti p = now;
		while(p != NULL) {
			++n;
			p = NextMulti(p);
		}
		now = ContMulti(now);
	}
	fprintf(data, "%d\n", n);
	now = FirstMulti(Highscore);
	while(now != NULL) {
		addressMulti p = now;
		while(p != NULL) {
			addressMulti next = NextMulti(p);
			User currentUser = MultiInfo(p);
			DealokasiMulti(p);
			fprintf(data, "%d", GetSkor(currentUser));
			fprintf(data, " %s", GetNama(currentUser));

			Tanggal currentTanggal = GetTanggal(currentUser);
			fprintf(data, " %d", GetDay(currentTanggal));
			fprintf(data, " %d", GetMonth(currentTanggal));
			fprintf(data, " %d", GetYear(currentTanggal));

			Jam currentJam = GetJam(currentUser);
			fprintf(data, " %d", GetHour(currentJam));
			fprintf(data, " %d", GetMin(currentJam));
			fprintf(data, " %d\n", GetSec(currentJam));
			p = next;
		}
		now = ContMulti(now);
	}
	fclose(data);


	data = fopen("database/suggestion.txt", "w");
	n = 0;
	for(i = 0; i < nRegisteredUser; i++) {
		for(j = 0; j < N_BOARD; j++) {
			if(!IsEmptyQ(Suggestion[i][j])) {
				n++;
			}
		}
	}
	fprintf(data, "%d\n", n);
	for(i = 0; i < nRegisteredUser; i++) {
		for(j = 0; j < N_BOARD; j++) {
			if(!IsEmptyQ(Suggestion[i][j])) {
				fprintf(data, "%d", i);
				fprintf(data, " %d", j);
				fprintf(data, " %d\n", NBElmtQ(Suggestion[i][j]));
				while(!IsEmptyQ(Suggestion[i][j])) {
					char temp[20];
					DelQ(&Suggestion[i][j], &temp);
					fprintf(data, "%s\n", temp);
				}
			}
		}
	}
	fclose(data);
}

int PrintMainMenu() {
	bool st[5];
	bool exit = 0;
	char cc;

	int i;
	for(i = 0; i < 5; i++) {
		st[i] = 0;
	}
	st[0] = 1;
	int now = 0;

	
	initTermios();
	PrintMain(st);
	
	while(!exit) {
		HideCursor();
		if(kbhit()) {
			cc = getch();
			if(cc == 'w') {
				if(now) {
					st[now] = 0;
					now--;
					st[now] = 1;
					PrintMain(st);
				}
			}

			else if(cc == 'x') {
				if(now < 4) {
					st[now] = 0;
					now++;
					st[now] = 1;
					PrintMain(st);
				}
			}

			else if(cc == 's' || cc == '\n') {
				if(st[0]) {
					PrintRegister(registeredUser, nRegisteredUser);
					PrintMain(st);
				} else if(st[1]) {
					int id = PrintLogin(registeredUser, nRegisteredUser);
					if(id == DUMMY_ID) {
						onlineStatus = 0;
						break;
					} else {
						onlineStatus = 1;
						int lent = strlen(registeredUser[id]);
						for(i = 0; i < lent; i++) {
							onlineUser[i] = registeredUser[id][i];
						}
						onlineUser[lent] = '\0';
						PrintMain(st);
					}
				} else if(st[2]) {
					PrintHowTo();
					printf("now %d\n", now);
					PrintMain(st);
				} else if(st[3]) {
					About();
					PrintMain(st);
				} else if(st[4]) {
					exit = 1;
				}
			}
		}
	}
	ShowCursor();
	system("clear");
	resetTermios();
	
	return onlineStatus;
}

int PrintPrepMenu() {
	bool pm[5];
	bool logout = 0;

	int i;
	for(i = 0; i < 5; i++) {
		pm[i] = 0;
	}
	pm[0] = 1;
	int pmnow = 0;
	
	initTermios();
	PrintPrep(pm, onlineUser, PilihanBoard);
	
	while(!logout) {
		HideCursor();
		if(kbhit()) {
			char cc = getch();
			if(cc == 'w') {
				if(pmnow) {
					pm[pmnow] = 0;
					pmnow--;
					pm[pmnow] = 1;
					PrintPrep(pm, onlineUser, PilihanBoard);
				}
			}

			else if(cc == 'x') {
				if(pmnow < 4) {
					pm[pmnow] = 0;
					pmnow++;
					pm[pmnow] = 1;
					PrintPrep(pm, onlineUser, PilihanBoard);
				}
			}

			else if(cc == 's' || cc == '\n') {
				if(pm[0]) {
					break;
				} else if(pm[1]) {
					PilihBoard(PilihanBoard);
					PrintPrep(pm, onlineUser, PilihanBoard);
				} else if(pm[2]) {
					PrintUserHighScore(Highscore, onlineUser);
					PrintPrep(pm, onlineUser, PilihanBoard);
				} else if(pm[3]) {
					PrintAllTimeHighScore(Highscore, onlineUser);
					PrintPrep(pm, onlineUser, PilihanBoard);
				} else if(pm[4]) {
					onlineStatus = 0;
					logout = 1;
				} 
			}
		}
	}
	ShowCursor();
	system("clear");
	resetTermios();
	return onlineStatus;
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
	CreateBoard(PilihanBoard);
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
							PQPush(&words, Word, getSkor(Word));
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
			PrintBoard(4,20,Totalscore,idOnlineUser);
			gotoxy(2, 5);
			printf("%.0lf seconds remaining\n", sec - now);
		}
		if (prev != now)
		{
			if (prev == sec) break;
			resetTermios(); // reset terminal setting to enable buffer i/o and echo (printf)
			system("clear");
			PrintBoard(4,20,Totalscore,idOnlineUser);
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
	PrintMiniHighScore(Highscore, onlineUser);
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

int main(){
	initialize();
	while(PrintMainMenu()) {
		while(PrintPrepMenu()) {
			gamePlay();
		}
	}
	finishing();
	return 0;
}