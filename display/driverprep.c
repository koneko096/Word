#include "prep.c"

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
	PrintPrep(pm);
	
	while(!logout) {
		HideCursor();
		if(kbhit()) {
			char cc = getch();
			if(cc == 'w') {
				if(pmnow) {
					pm[pmnow] = 0;
					pmnow--;
					pm[pmnow] = 1;
					PrintPrep(pm);
				}
			}

			else if(cc == 'x') {
				if(pmnow < 4) {
					pm[pmnow] = 0;
					pmnow++;
					pm[pmnow] = 1;
					PrintPrep(pm);
				}
			}

			else if(cc == 's' || cc == '\n') {
				if(pm[0]) {
					break;
				} else if(pm[1]) {
					PilihBoard();
					PrintPrep(pm);
				} else if(pm[2]) {
					PrintUserHighScore();
					PrintPrep(pm);
				} else if(pm[3]) {
					PrintAllTimeHighScore();
					PrintPrep(pm);
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

