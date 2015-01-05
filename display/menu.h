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
#include "../adt/bukan_string.h"
#include "interface.h"
#include "../global.h"
#include "prep.h"

const char *caption[5];

/* Mencetak Print Menu */
void PrintMain(bool stat[5]);

bool isAlphaNum(char c);

bool valid(char temp[50]);


void TemplateRegis();

void TemplateAgain(bool again);

void PrintRegisAgain(int salah);

void PrintRegister();


void TemplateLogin(bool again);

void PrintLoginAgain();

void PrintLogin();


void PrintAzam();

void PrintRahman();

void PrintAfrizal();

void PrintLuqman();

void PrintGazandi();


void PrintHowTo();

void PrintAbout(bool st[5]);

void About();


#endif