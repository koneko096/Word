#include "global.h"
#include "display/drivermenu.c"
#include "display/driverprep.c"
#include "UI_board/board.c"

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