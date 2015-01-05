#ifndef _PREP_MENU__
#define _PREP_MENU__

#include <stdbool.h>
#include <stdio.h>
#include "../adt/bukan_string.h"
#include "interface.h"
#include "../global.h"
#include "../adt/array.c"
#include "../UI_board/displayboard.h"


const char *captionprep[5];

/* Mencetak Print Menu */
void PrintPrep(bool statprep[5]);

void PrintUserHighScore();

void PrintAllTimeHighScore();


void PrintPilih(bool statprep[10]);

void PilihBoard();

#endif
