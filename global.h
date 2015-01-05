/**
 * Nama file	: global.h
 * Topik			: Abstract Data Type
 * Tanggal 		: 12 November 2014
 * Deskripsi	: File Header dari ADT Global yang akan digunakan
 * Author			: Luqman Arifin
 */

#ifndef GLOBAL_ADT__
#define GLOBAL_ADT__

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
#include "adt/bukan_string.h"

#define MAX_EXPECTED_USER 1000
#define MAX_EXPECTED_SUGGEST 100
#define N_BOARD 10

/* berisi nama user yang sedang online */
char onlineUser[20];
char registeredUser[MAX_EXPECTED_USER][20];
char Word[20];
int nRegisteredUser;
int PilihanBoard;
int Totalscore;


Tree Dictionary;
MultiList Highscore;
Queue Suggestion[MAX_EXPECTED_USER][N_BOARD];
map Scoring;

static FILE *data;
static int retval;

/* 1 bila ada orang yang online (nama ada di onlineUser)
 * 0 bila tidak ada orang yang sedang online */
int onlineStatus;

/* Berisi ID user dalam tabel Suggestion dan registered user */
int idOnlineUser;

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


int getSkor(char* S) {
	char* t = S;
	int skor = 0;
	while (*t) {
		skor += at(Scoring, *t);
		t++;
	}
	return skor;
}

#endif