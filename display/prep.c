#include "prep.h"

const char *captionboard[10];
const char *captionfoot[5];

void PrintPrep(bool statprep[5])  {
	captionfoot[0] = "Click 's' or Enter to play the game";
	captionfoot[1] = "Select your board to play";
	captionfoot[2] = "View your hilarious Achievement";
	captionfoot[3] = "View other's best game record";
	captionfoot[4] = "Don't be far from me :(";
	
	system("clear");
	
	gotoxy(3, 3);
	printf("Welcome back, %s!", onlineUser);
	gotoxy(5, 3);
	printf("You will play on board : %d", PilihanBoard);

	int i, x = 5;
	for(i = 0; i < 5; i++) 
	{
		gotoxy(x, 45);
		if(statprep[i]) {
			printf("-> ");
		}
		printf("%s\n", captionprep[i]);
		if(statprep[i]) {
			gotoxy(20, 3);
			printf("%s", captionfoot[i]);
		}
		x += 2;
	}
}

void PrintUserHighScore() {
	TabInt Him;
	MakeEmptyA(&Him);
	addressMulti now = FirstMulti(Highscore);
	while(now != Nil) {
		addressMulti p = now;
		while(p != Nil) {
			if(Equal(GetNama(MultiInfo(p)), onlineUser))
				Add1Urut(&Him, MultiInfo(p));
			p = NextMulti(p);
		}
		now = ContMulti(now);
	}

	system("clear");
	if(IsEmptyA(Him)) {
		gotoxy(10, 28);
		printf("Highscore belum ditemukan");
	} else {
		gotoxy(2, 5);
		printf("No");
		gotoxy(2, 9);
		printf("Score");
		gotoxy(2, 22);
		printf("Who");
		gotoxy(2, 42);
		printf("Date");
		gotoxy(2, 61);
		printf("When");

		int i, x = 4;
		int until = 1e9;
		if(NbElmtA(Him) < until) until = NbElmtA(Him);
		if(10 < until) until = 10;
		for(i = 1; i <= until; i++) {
			gotoxy(x, 5);
			printf("%d.", i);

			User currentUser = GetElmtA(Him, i);
			Tanggal currentTanggal = GetTanggal(currentUser);
			Jam currentJam = GetJam(currentUser);
			int dd = GetDay(currentTanggal);
			int mm = GetMonth(currentTanggal);
			int yy = GetYear(currentTanggal);
			int jam = GetHour(currentJam);
			int men = GetMin(currentJam);
			int det = GetSec(currentJam);

			gotoxy(x, 9);
			printf("%d", GetSkor(currentUser));

			gotoxy(x, 15);
			printf("%s", GetNama(currentUser));

			gotoxy(x, 38);
			printf("%d", dd);
			gotoxy(x, 41);
			printf("- %d", mm);
			gotoxy(x, 46);
			printf("- %d", yy);

			gotoxy(x, 58);
			printf("%d", jam);
			gotoxy(x, 61);
			printf(": %d", men);
			gotoxy(x, 66);
			printf(": %d", det);
			x += 2;
		}
	}
	gotoxy(28, 30);
	printf("[ Kembali ke laptop ]");
	while(1) {
		HideCursor();
		if(kbhit()) {
			char cc = getch();
			if(cc == 's' || cc == '\n') {
				break;
			}
		}
	}
}

void PrintAllTimeHighScore() {
	TabInt All;
	MakeEmptyA(&All);
	addressMulti now = FirstMulti(Highscore);
	while(now != Nil) {
		addressMulti p = now;
		while(p != Nil) {
			Add1Urut(&All, MultiInfo(p));
			p = NextMulti(p);
		}
		now = ContMulti(now);
	}

	system("clear");
	if(IsEmptyA(All)) {
		gotoxy(10, 28);
		printf("Highscore belum ditemukan");
	} else {
		gotoxy(2, 5);
		printf("No");
		gotoxy(2, 9);
		printf("Score");
		gotoxy(2, 22);
		printf("Who");
		gotoxy(2, 42);
		printf("Date");
		gotoxy(2, 61);
		printf("When");

		int i, x = 4;
		int until = 1e9;
		if(NbElmtA(All) < until) until = NbElmtA(All);
		if(10 < until) until = 10;
		for(i = 1; i <= until; i++) {

			User currentUser = GetElmtA(All, i);
			Tanggal currentTanggal = GetTanggal(currentUser);
			Jam currentJam = GetJam(currentUser);
			bool hebat = Equal(GetNama(currentUser), onlineUser);

			int dd = GetDay(currentTanggal);
			int mm = GetMonth(currentTanggal);
			int yy = GetYear(currentTanggal);
			int jam = GetHour(currentJam);
			int men = GetMin(currentJam);
			int det = GetSec(currentJam);

			gotoxy(x, 5);
			if(hebat) {
				printf("%s%d.", CYAN, i);
			} else
				printf("%d.", i);

			gotoxy(x, 9);
			printf("%d", GetSkor(currentUser));

			gotoxy(x, 15);
			if(hebat)
				printf("You");
			else
				printf("%s", GetNama(currentUser));

			gotoxy(x, 38);
			printf("%d", dd);
			gotoxy(x, 41);
			printf("- %d", mm);
			gotoxy(x, 46);
			printf("- %d", yy);

			gotoxy(x, 58);
			printf("%d", jam);
			gotoxy(x, 61);
			printf(": %d", men);
			gotoxy(x, 66);
			printf(": %d", det);

			printf("%s", NORMAL);
			norm;
			x += 2;
		}
	}
	gotoxy(28, 30);
	printf("[ Kembali ke laptop ]");
	while(1) {
		HideCursor();
		if(kbhit()) {
			char cc = getch();
			if(cc == 's' || cc == '\n') {
				break;
			}
		}
	}
}

void PrintPilih(bool statprep[10]) 
{
	captionboard[0] = "Board 0";
	captionboard[1] = "Board 1";
	captionboard[2] = "Board 2";
	captionboard[3] = "Board 3";
	captionboard[4] = "Board 4";
	captionboard[5] = "Board 5";
	captionboard[6] = "Board 6";
	captionboard[7] = "Board 7";
	captionboard[8] = "Board 8";
	captionboard[9] = "Board 9";
	system("clear");
	gotoxy(2, 34);
	printf("Pilih Board");
	int i, x = 4;
	for(i = 0; i < 10; i++) 
	{
		if(statprep[i]){
			gotoxy(x, 33);
			printf("[");
			gotoxy(x, 43);
			printf("]");
		}
		gotoxy(x, 35);
		
		printf("%s\n", captionboard[i]);
		x += 2;
	}
}


void PilihBoard () {
	bool pb[10];
	bool keluar = 0;
	int i;
	for(i = 0; i < 10; i++) {
		pb[i] = 0;
	}
	pb[PilihanBoard] = 1;
		
	int pbnow = PilihanBoard;

	PrintPilih(pb);
	while(!keluar) {
		HideCursor();
		if(kbhit()) {
			char cc = getch();
			if(cc == 'w') {
				if(pbnow) {
					
					pb[pbnow] = 0;
					pbnow--;
					pb[pbnow] = 1;
					PrintPilih(pb);
				}
			}
				else if(cc == 'x') {
				if(pbnow < 9) {
					pb[pbnow] = 0;
					pbnow++;
					pb[pbnow] = 1;
					PrintPilih(pb);
				}
			}
				else if(cc == 's' || cc == '\n') {
				if(pb[0]) {
					PilihanBoard = 0;
					keluar = 1;
				} else if(pb[1]) {
					PilihanBoard = 1;
					keluar = 1;
				} else if(pb[2]) {
					PilihanBoard = 2;
					keluar = 1;
				} else if(pb[3]) {
					PilihanBoard = 3;
					keluar = 1;
				} else if(pb[4]) {
					PilihanBoard = 4;
					keluar = 1;
				} else if(pb[5]) {
					PilihanBoard = 5;
					keluar = 1;
				} else if(pb[6]) {
					PilihanBoard = 6;
					keluar = 1;
				} else if(pb[7]) {
					PilihanBoard = 7;
					keluar = 1;
				} else if(pb[8]) {
					PilihanBoard = 8;
					keluar = 1;
				} else if(pb[9]) {
					PilihanBoard = 9;
					keluar = 1;
				} 
			}
		}
	}
}
