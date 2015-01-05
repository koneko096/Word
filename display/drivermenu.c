/**
 * Nama file	: drivermenu.h
 * Topik			: Display
 * Tanggal 		: 13 November 2014
 * Deskripsi	: File Header Display Menu Utama
 * Author			: Luqman Arifin
 */

#include "menu.c"
 
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
					PrintRegister();
					PrintMain(st);
				} else if(st[1]) {
					PrintLogin();
					if(onlineStatus)
						break;
					else
						PrintMain(st);
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