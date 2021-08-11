/**
 * Nama file	: menu.h
 * Topik			: Display
 * Tanggal 		: 13 November 2014
 * Deskripsi	: File Header Display Menu Utama
 * Author			: Luqman Arifin
 */

#ifndef _MAIN_MENU__
#define _MAIN_MENU__

#include <stdbool.h>
#include <stdio.h>
#include "../adt/lqstring.h"
#include "../adt/multilist.h"
#include "../adt/user.h"
#include "interface.h"

const char *caption[5];

#define DUMMY_ID -1

/* Mencetak Print Menu */
void PrintMain(bool stat[5]);

bool isAlphaNum(char c);

bool valid(char temp[50]);


void TemplateRegis();

void TemplateAgain(bool again);

void PrintRegisAgain(int salah, char** registeredUser, int nRegisteredUser);

void PrintRegister(char** registeredUser, int nRegisteredUser);


void TemplateLogin(bool again);

void PrintLoginAgain(char** registeredUser, int nRegisteredUser);

int PrintLogin(char** registeredUser, int nRegisteredUser);


void PrintAzam();

void PrintRahman();

void PrintAfrizal();

void PrintLuqman();

void PrintGazandi();


void PrintHowTo();

void PrintAbout(bool st[5]);

void About();


const char *captionprep[5];

/* Mencetak Print Menu */
void PrintPrep(bool statprep[5], char* onlineUser, int PilihanBoard);
void PrintUserHighScore(MultiList Highscore, char* onlineUser);
void PrintAllTimeHighScore(MultiList Highscore, char* onlineUser);
void PrintPilih(bool statprep[10]);
void PilihBoard(int PilihanBoard);

#endif