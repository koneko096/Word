/**
 * Nama file	: menu.h
 * Topik			: Display
 * Tanggal 		: 13 November 2014
 * Deskripsi	: File Header Display Menu Utama
 * Author			: Luqman Arifin
 */

#include "menu.h"


const char *captionN[5];

/* Mencetak Print Menu dengan status kursor sebagai parameter */
void PrintMain(bool stat[5]) {
	caption[0] = "Register";
	caption[1] = "Login";
	caption[2] = "How to play";
	caption[3] = "About";
	caption[4] = "Quit";
	system("clear");
	
	int i, x = 5;
	for(i = 0; i < 5; i++) {
		gotoxy(x, 50);
		if(stat[i]) printf("-> ");
		printf("%s", caption[i]);
		x += 2;
	}
}

/* Mengecek apakah sebuah karakter merupakan karakter alphanumerik */
bool isAlphaNum(char c) {
	return ('0' <= c && c <= '9') || ('a' <= c && c <= 'z') ||
	('A' <= c && c <= 'Z');
}

/* Mengecek apakah sebuah nama valid untuk username */
bool valid(char temp[50]) {
	int n = strlen(temp), i;
	if(n > 20 || n == 0) return false;
	for(i = 0; i < n; i++) {
		if(!isAlphaNum(temp[i]))
			return false;
	}
	return true;
}


void TemplateRegis() {
	gotoxy(7, 30);
	printf("Silakan entri nama");
	gotoxy(12, 29);
}

/* again = 1 jika kursor menunjuk pada Register Again */
/* again = 0 jika kursor menunjuk pada Back To Menu */
void TemplateAgain(bool again) {
	system("clear");
	gotoxy(20, 2);
	if(again) printf("-> ");
	printf("Register Again");
	gotoxy(22, 2);
	if(!again) printf("-> ");
	printf("Back to Menu");
}

/* salah = 1 jika input user salah */
/* salah = -1 jika input benar tapi sudah pernah diregistrasi */
void PrintRegisAgain(int salah) {
	bool again = 1;
	TemplateAgain(again);
	if(salah) {
		gotoxy(15, 16);
		if(salah == -1)
			printf("Nama user sudah pernah diregistrasi sebelumnya.");
		else
			printf("Nama harus alphanumerik dan kurang dari 20 huruf.");
	} else {
		gotoxy(18, 2);
		printf("Register berhasil");
	}

	while(1) {
		HideCursor();
		if(kbhit()) {
			char cc = getch();
			if(cc == 'w' || cc == 'x') {
				again ^= 1;
				TemplateAgain(again);

				if(salah) {
					gotoxy(15, 16);
					if(salah == -1)
						printf("Nama user sudah pernah diregistrasi sebelumnya.");
					else
						printf("Nama harus alphanumerik dan kurang dari 20 huruf.");
				} else {
					gotoxy(18, 2);
					printf("Register berhasil");
				}
			}
			if(cc == 's' || cc == '\n') {
				break;
			}
		}
	}
	if(again) PrintRegister();
}

void PrintRegister() {
	system("clear");
	ShowCursor();
	resetTermios();
	
	char temp[50];
	int i;
	for(i = 0; i < 50; i++)
		temp[i] = 0;

	gotoxy(4, 30);
	printf("Registration Page");
	gotoxy(11, 29);
	for (i = 1;i<=20;i++)
		printf("%s",HL);
	gotoxy(13, 29);
	for (i = 1;i<=20;i++)
		printf("%s",HL);
	gotoxy(12, 28);
		printf("%s",VL);
	gotoxy(12, 49);
		printf("%s",VL);
	gotoxy(11, 49);
		printf("%s",RT);
	gotoxy(13, 49);
		printf("%s",RB);
	gotoxy(11, 28);
		printf("%s",LT);
	gotoxy(13, 28);
		printf("%s",LB);

	TemplateRegis();
	gets(temp);

	bool found = false;
	bool isNameValid = valid(temp);
	if(isNameValid) {
		for(i = 0; i < nRegisteredUser; i++) {
			if(Equal(temp, registeredUser[i])) {
				found = true;
				break;
			}
		}
		if(!found) {
			int lent = strlen(temp);
			for(i = 0; i < lent; i++) {
				registeredUser[nRegisteredUser][i] = temp[i];
			}
			registeredUser[nRegisteredUser][lent] = '\0';
			nRegisteredUser++;
		}
	}
	initTermios();

	if(!isNameValid) {
		PrintRegisAgain(1);
	} else if(found) {
		PrintRegisAgain(-1);
	} else {
		PrintRegisAgain(0);
	}
}

void TemplateLogin(bool again) {
	system("clear");
	gotoxy(18, 2);
	printf("User belum terdaftar");
	gotoxy(20, 2);
	if(again) printf("-> ");
	printf("Login pake akun lain gan");
	gotoxy(22, 2);
	if(!again) printf("-> ");
	printf("Back to Menu");
}

void PrintLoginAgain() {
	bool again = 1;
	TemplateLogin(1);

	while(1) {
		HideCursor();
		if(kbhit()) {
			char cc = getch();
			if(cc == 'w' || cc == 'x') {
				again ^= 1;
				TemplateLogin(again);
			}
			if(cc == 's' || cc == '\n') {
				break;
			}
		}
	}
	if(again) {
		PrintLogin();
	}
}

void PrintLogin() {
	system("clear");
	ShowCursor();
	resetTermios();

	char temp[50];
	int i;
	for(i = 0; i < 50; i++)
		temp[i] = 0;

	gotoxy(9, 33);
	printf("Please Login");
	gotoxy(11, 35);
	printf("Username");
	gotoxy(12, 29);
	for (i = 1;i<=20;i++)
		printf("%s",HL);
	gotoxy(14, 29);
	for (i = 1;i<=20;i++)
		printf("%s",HL);
	gotoxy(13, 28);
		printf("%s",VL);
	gotoxy(13, 49);
		printf("%s",VL);
	gotoxy(12, 49);
		printf("%s",RT);
	gotoxy(14, 49);
		printf("%s",RB);
	gotoxy(12, 28);
		printf("%s",LT);
	gotoxy(14, 28);
		printf("%s",LB);
	
	gotoxy(13, 29);
	gets(temp);

	int found = 0;
	for(i = 0; i < nRegisteredUser; i++) {
		if(Equal(registeredUser[i], temp)) {
			idOnlineUser = i;
			found = 1;
			break;
		}
	}
	initTermios();
	if(found) {
		onlineStatus = 1;
		int lent = strlen(temp);
		for(i = 0; i < lent; i++) {
			onlineUser[i] = temp[i];
		}
		onlineUser[lent] = '\0';
	} else {
		onlineStatus = 0;
		PrintLoginAgain();
	}
}

void PrintHowTo() {
	char howtoplays[5][5];
	howtoplays[1][1] = 'A';
	howtoplays[1][2] = 'B';
	howtoplays[1][3] = 'C';
	howtoplays[1][4] = 'D';
	howtoplays[2][1] = 'E';
	howtoplays[2][2] = 'F';
	howtoplays[2][3] = 'G';
	howtoplays[2][4] = 'H';
	howtoplays[3][1] = 'I';
	howtoplays[3][2] = 'J';
	howtoplays[3][3] = 'K';
	howtoplays[3][4] = 'L';
	howtoplays[4][1] = 'M';
	howtoplays[4][2] = 'N';
	howtoplays[4][3] = 'O';
	howtoplays[4][4] = 'P';
	int i,j,k,l;

	system("clear");
	board_sceleton(1,25);
	k = 3;
	l = 25;
	for(j = 1; j <= 4; j++){
		for(i = 1; i <= 5; i++){
			gotoxy(k, l);
			pVL;
			l += 9;
		}
		l = 25;
		k += 4;
	}
	k = 3;
	l = 25;
	for(j = 1; j <=4 ; j++){
		for(i = 1; i <= 4; i++){
			gotoxy(k, l+4);
			if(( j == 1 ) && ( i == 1 ))
			printf(">");
			printf("%c",howtoplays[i][j]);
			l += 9;
		}
		l = 25;
		k += 4;
	}
	gotoxy(19, 15); 
	printf("Inisialisasi board dan kursor (pada petak kiri atas).");
	gotoxy(21, 28);
	printf("Tekan apa saja dari keyboard");
	gotoxy(23, 39);
	printf("-> Next");
	getch();
	system("clear");
	board_sceleton(1,25);
	k = 3;
	l = 25;
	for(j = 1; j <= 4; j++){
		for(i = 1; i <= 5; i++){
			gotoxy(k, l);
			pVL;
			l += 9;
		}
		l = 25;
		k += 4;
	}
	k = 3;
	l = 25;
	for(j = 1; j <=4 ; j++){
		for(i = 1; i <= 4; i++){
			gotoxy(k, l+4);
			if(( j == 1 ) && ( i == 2 ))
			printf(">");
			printf("%c",howtoplays[i][j]);
			l += 9;
		}
		l = 25;
		k += 4;
	}
	gotoxy(19, 12); 
	printf("Pemain menekan tombol d, maka kursor akan digerakkan ke kanan");
	gotoxy(21, 28);
	printf("Tekan apa saja dari keyboard");
	gotoxy(23, 39);
	printf("-> Next");
	getch();
	system("clear");
	board_sceleton(1,25);
	k = 3;
	l = 25;
	for(j = 1; j <= 4; j++){
		for(i = 1; i <= 5; i++){
			gotoxy(k, l);
			pVL;
			l += 9;
		}
		l = 25;
		k += 4;
	}
	k = 3;
	l = 25;
	for(j = 1; j <=4 ; j++){
		for(i = 1; i <= 4; i++){
			gotoxy(k, l+4);
			if(( j == 1 ) && ( i == 2 ))
			printf(">%s%c%s",GREEN,howtoplays[i][j],NORMAL);
			else
			printf("%c",howtoplays[i][j]);
			l += 9;
		}
		l = 25;
		k += 4;
	}
	gotoxy(19, 6); 
	printf("Pemain menekan tombol s, maka pembentukan kata pun dimulai dari petak");
	gotoxy(21, 28);
	printf("Tekan apa saja dari keyboard");
	gotoxy(23, 39);
	printf("-> Next");
	getch();
	system("clear");
	board_sceleton(1,25);
	k = 3;
	l = 25;
	for(j = 1; j <= 4; j++){
		for(i = 1; i <= 5; i++){
			gotoxy(k, l);
			pVL;
			l += 9;
		}
		l = 25;
		k += 4;
	}
	k = 3;
	l = 25;
	for(j = 1; j <=4 ; j++){
		for(i = 1; i <= 4; i++){
			gotoxy(k, l+4);
			if(( j == 1 ) && ( i == 2 ))
			printf(">%s%c%s",GREEN,howtoplays[i][j],NORMAL);
			else
			printf("%c",howtoplays[i][j]);
			l += 9;
		}
		l = 25;
		k += 4;
	}
	gotoxy(19, 35); 
	printf("kursor berada.");
	gotoxy(21, 28);
	printf("Tekan apa saja dari keyboard");
	gotoxy(23, 39);
	printf("-> Next");
	getch();
	system("clear");
	board_sceleton(1,25);
	k = 3;
	l = 25;
	for(j = 1; j <= 4; j++){
		for(i = 1; i <= 5; i++){
			gotoxy(k, l);
			pVL;
			l += 9;
		}
		l = 25;
		k += 4;
	}
	k = 3;
	l = 25;
	for(j = 1; j <=4 ; j++){
		for(i = 1; i <= 4; i++){
			if(( j == 1 ) && ( i == 2 )) {
				gotoxy(k, l+3);
				printf("%s[%c]%s",GREEN,howtoplays[i][j],NORMAL);
			}
			else if(( j == 1 ) && ( i == 3 )) {
				gotoxy(k, l+4);
				printf(">%s%c%s",GREEN,howtoplays[i][j],NORMAL);
			}
			else {
			 gotoxy(k, l+4);
			 printf("%c",howtoplays[i][j]);
			}
			l += 9;
		}
		l = 25;
		k += 4;
	}
	gotoxy(19, 6); 
	printf("Pemain menekan tombol d, maka kursor digerakkan ke kanan dan memroses");
	gotoxy(21, 28);
	printf("Tekan apa saja dari keyboard");
	gotoxy(23, 39);
	printf("-> Next");
	getch();
	system("clear");
	board_sceleton(1,25);
	k = 3;
	l = 25;
	for(j = 1; j <= 4; j++){
		for(i = 1; i <= 5; i++){
			gotoxy(k, l);
			pVL;
			l += 9;
		}
		l = 25;
		k += 4;
	}
	k = 3;
	l = 25;
	for(j = 1; j <=4 ; j++){
		for(i = 1; i <= 4; i++){
			if(( j == 1 ) && ( i == 2 )) {
				gotoxy(k, l+3);
				printf("%s[%c]%s",GREEN,howtoplays[i][j],NORMAL);
			}
			else if(( j == 1 ) && ( i == 3 )) {
				gotoxy(k, l+4);
				printf(">%s%c%s",GREEN,howtoplays[i][j],NORMAL);
			}
			else {
			 gotoxy(k, l+4);
			 printf("%c",howtoplays[i][j]);
			}
			l += 9;
		}
		l = 25;
		k += 4;
	}
	gotoxy(19, 29); 
	printf("huruf pada petak tersebut.");
	gotoxy(21, 28);
	printf("Tekan apa saja dari keyboard");
	gotoxy(23, 39);
	printf("-> Next");
	getch();
	system("clear");
	board_sceleton(1,25);
	k = 3;
	l = 25;
	for(j = 1; j <= 4; j++){
		for(i = 1; i <= 5; i++){
			gotoxy(k, l);
			pVL;
			l += 9;
		}
		l = 25;
		k += 4;
	}
	k = 3;
	l = 25;
	for(j = 1; j <=4 ; j++){
		for(i = 1; i <= 4; i++){
			if(( j == 1 ) && ( i == 2 )) {
				gotoxy(k, l+3);
				printf("%s[%c]%s",GREEN,howtoplays[i][j],NORMAL);
			}
			else if(( j == 1 ) && ( i == 3 )) {
				gotoxy(k, l+3);
				printf("%s[%c]%s",GREEN,howtoplays[i][j],NORMAL);
			}
			else if(( j == 2 ) && ( i == 3 )) {
				gotoxy(k, l+4);
				printf(">%s%c%s",GREEN,howtoplays[i][j],NORMAL);
			}
			else {
			 gotoxy(k, l+4);
			 printf("%c",howtoplays[i][j]);
			}
			l += 9;
		}
		l = 25;
		k += 4;
	}
	gotoxy(19, 6); 
	printf("Pemain menekan tombol x, maka kursor digerakkan ke bawah dan memroses");
	gotoxy(21, 28);
	printf("Tekan apa saja dari keyboard");
	gotoxy(23, 39);
	printf("-> Next");
	getch();
	system("clear");
	board_sceleton(1,25);
	k = 3;
	l = 25;
	for(j = 1; j <= 4; j++){
		for(i = 1; i <= 5; i++){
			gotoxy(k, l);
			pVL;
			l += 9;
		}
		l = 25;
		k += 4;
	}
	k = 3;
	l = 25;
	for(j = 1; j <=4 ; j++){
		for(i = 1; i <= 4; i++){
			if(( j == 1 ) && ( i == 2 )) {
				gotoxy(k, l+3);
				printf("%s[%c]%s",GREEN,howtoplays[i][j],NORMAL);
			}
			else if(( j == 1 ) && ( i == 3 )) {
				gotoxy(k, l+3);
				printf("%s[%c]%s",GREEN,howtoplays[i][j],NORMAL);
			}
			else if(( j == 2 ) && ( i == 3 )) {
				gotoxy(k, l+4);
				printf(">%s%c%s",GREEN,howtoplays[i][j],NORMAL);
			}
			else {
			 gotoxy(k, l+4);
			 printf("%c",howtoplays[i][j]);
			}
			l += 9;
		}
		l = 25;
		k += 4;
	}
	gotoxy(19, 29); 
	printf("huruf pada petak tersebut.");
	gotoxy(21, 28);
	printf("Tekan apa saja dari keyboard");
	gotoxy(23, 39);
	printf("-> Next");
	getch();
	system("clear");
	board_sceleton(1,25);
	k = 3;
	l = 25;
	for(j = 1; j <= 4; j++){
		for(i = 1; i <= 5; i++){
			gotoxy(k, l);
			pVL;
			l += 9;
		}
		l = 25;
		k += 4;
	}
	k = 3;
	l = 25;
	for(j = 1; j <=4 ; j++){
		for(i = 1; i <= 4; i++){
			gotoxy(k, l+4);
			if(( j == 1 ) && ( i == 2 ))
			printf(">%s%c%s",GREEN,howtoplays[i][j],NORMAL);
			else
			printf("%c",howtoplays[i][j]);
			l += 9;
		}
		l = 25;
		k += 4;
	}
	gotoxy(19,9);
	printf("Pemain menekan tombol q, maka kursor digerakkan ke kiri atas dan");
	gotoxy(21, 28);
	printf("Tekan apa saja dari keyboard");
	gotoxy(23, 39);
	printf("-> Next");
	getch();
	system("clear");
	board_sceleton(1,25);
	k = 3;
	l = 25;
	for(j = 1; j <= 4; j++){
		for(i = 1; i <= 5; i++){
			gotoxy(k, l);
			pVL;
			l += 9;
		}
		l = 25;
		k += 4;
	}
	k = 3;
	l = 25;
	for(j = 1; j <=4 ; j++){
		for(i = 1; i <= 4; i++){
			gotoxy(k, l+4);
			if(( j == 1 ) && ( i == 2 ))
			printf(">%s%c%s",GREEN,howtoplays[i][j],NORMAL);
			else
			printf("%c",howtoplays[i][j]);
			l += 9;
		}
		l = 25;
		k += 4;
	}
	gotoxy(19, 6); 
	printf("memroses huruf pada petak tersebut. Pemain menekan tombol q, maka kursor");
	gotoxy(21, 28);
	printf("Tekan apa saja dari keyboard");
	gotoxy(23, 39);
	printf("-> Next");
	getch();
	system("clear");
	board_sceleton(1,25);
	k = 3;
	l = 25;
	for(j = 1; j <= 4; j++){
		for(i = 1; i <= 5; i++){
			gotoxy(k, l);
			pVL;
			l += 9;
		}
		l = 25;
		k += 4;
	}
	k = 3;
	l = 25;
	for(j = 1; j <=4 ; j++){
		for(i = 1; i <= 4; i++){
			gotoxy(k, l+4);
			if(( j == 1 ) && ( i == 2 ))
			printf(">%s%c%s",GREEN,howtoplays[i][j],NORMAL);
			else
			printf("%c",howtoplays[i][j]);
			l += 9;
		}
		l = 25;
		k += 4;
	}
	gotoxy(19, 12);
	printf("digerakkan ke kiri atas. Karena petak sudah pernah dikunjungi,");
	gotoxy(21, 28);
	printf("Tekan apa saja dari keyboard");
	gotoxy(23, 39);
	printf("-> Next");
	getch();
	system("clear");
	board_sceleton(1,25);
	k = 3;
	l = 25;
	for(j = 1; j <= 4; j++){
		for(i = 1; i <= 5; i++){
			gotoxy(k, l);
			pVL;
			l += 9;
		}
		l = 25;
		k += 4;
	}
	k = 3;
	l = 25;
	for(j = 1; j <=4 ; j++){
		for(i = 1; i <= 4; i++){
			gotoxy(k, l+4);
			if(( j == 1 ) && ( i == 2 ))
			printf(">%s%c%s",GREEN,howtoplays[i][j],NORMAL);
			else
			printf("%c",howtoplays[i][j]);
			l += 9;
		}
		l = 25;
		k += 4;
	}
	gotoxy(19, 13); 
	printf("maka stack di-pop hingga top nya sama dengan posisi sekarang.");
	gotoxy(21, 28);
	printf("Tekan apa saja dari keyboard");
	gotoxy(23, 39);
	printf("-> Next");
	getch();
	system("clear");
	board_sceleton(1,25);
	k = 3;
	l = 25;
	for(j = 1; j <= 4; j++){
		for(i = 1; i <= 5; i++){
			gotoxy(k, l);
			pVL;
			l += 9;
		}
		l = 25;
		k += 4;
	}
	k = 3;
	l = 25;
	for(j = 1; j <=4 ; j++){
		for(i = 1; i <= 4; i++){
			if(( j == 1 ) && ( i == 1 )) {
				gotoxy(k, l+4);
				printf(">%s%c%s",GREEN,howtoplays[i][j],NORMAL);
			}
			else if(( j == 1 ) && ( i == 2 )) {
			 gotoxy(k, l+3);
			 printf("%s[%c]%s",GREEN,howtoplays[i][j],NORMAL);
			}
			else {
			 gotoxy(k, l+4);
			 printf("%c",howtoplays[i][j]);
			}
			l += 9;
		}
		l = 25;
		k += 4;
	}	gotoxy(19, 6); 
	printf("Pemain menekan tombol a, maka kursor digerakkan ke kiri dan memroses");
	gotoxy(21, 28);
	printf("Tekan apa saja dari keyboard");
	gotoxy(23, 39);
	printf("-> Next");
	getch();
	system("clear");
	board_sceleton(1,25);
	k = 3;
	l = 25;
	for(j = 1; j <= 4; j++){
		for(i = 1; i <= 5; i++){
			gotoxy(k, l);
			pVL;
			l += 9;
		}
		l = 25;
		k += 4;
	}
	k = 3;
	l = 25;
	for(j = 1; j <=4 ; j++){
		for(i = 1; i <= 4; i++){
			if(( j == 1 ) && ( i == 1 )) {
				gotoxy(k, l+4);
				printf(">%s%c%s",GREEN,howtoplays[i][j],NORMAL);
			}
			else if(( j == 1 ) && ( i == 2 )) {
			 gotoxy(k, l+3);
			 printf("%s[%c]%s",GREEN,howtoplays[i][j],NORMAL);
			}
			else {
			 gotoxy(k, l+4);
			 printf("%c",howtoplays[i][j]);
			}
			l += 9;
		}
		l = 25;
		k += 4;
	}
	gotoxy(19, 6); 
	printf("Pemain menekan tombol s, maka pembentukan kata pun selesai. Kata yang ");
	gotoxy(21, 28);
	printf("Tekan apa saja dari keyboard");
	gotoxy(23, 39);
	printf("-> Next");
	getch();
	system("clear");
	board_sceleton(1,25);
	k = 3;
	l = 25;
	for(j = 1; j <= 4; j++){
		for(i = 1; i <= 5; i++){
			gotoxy(k, l);
			pVL;
			l += 9;
		}
		l = 25;
		k += 4;
	}
	k = 3;
	l = 25;
	for(j = 1; j <=4 ; j++){
		for(i = 1; i <= 4; i++){
			if(( j == 1 ) && ( i == 1 )) {
				gotoxy(k, l+4);
				printf(">%s%c%s",GREEN,howtoplays[i][j],NORMAL);
			}
			else if(( j == 1 ) && ( i == 2 )) {
			 gotoxy(k, l+3);
			 printf("%s[%c]%s",GREEN,howtoplays[i][j],NORMAL);
			}
			else {
			 gotoxy(k, l+4);
			 printf("%c",howtoplays[i][j]);
			}
			l += 9;
		}
		l = 25;
		k += 4;
	}
	gotoxy(19, 33); 
	printf("dibentuk adalah EA.");
	gotoxy(21, 28);
	printf("Tekan apa saja dari keyboard");
	gotoxy(23, 39);
	printf("-> Next");
	getch();
	system("clear");
	board_sceleton(1,25);
	k = 3;
	l = 25;
	for(j = 1; j <= 4; j++){
		for(i = 1; i <= 5; i++){
			gotoxy(k, l);
			pVL;
			l += 9;
		}
		l = 25;
		k += 4;
	}
	k = 3;
	l = 25;
	for(i = 1; i <= 4 ; i++){
		for(j = 4; j >= 1; j--){
			gotoxy(k, l+4);
			if(( j == 1 ) && ( i == 1 ))
			printf(">");
			printf("%c",howtoplays[i][j]);
			l += 9;
		}
		l = 25;
		k += 4;
	}
	gotoxy(19, 6); 
	printf("Pemain menekan tombol r, maka board diputar 90 derajat CW. Kursor akan");
	gotoxy(21, 28);
	printf("Tekan apa saja dari keyboard");
	gotoxy(23, 39);
	printf("-> Next");
	getch();
	system("clear");
	board_sceleton(1,25);
	k = 3;
	l = 25;
	for(j = 1; j <= 4; j++){
		for(i = 1; i <= 5; i++){
			gotoxy(k, l);
			pVL;
			l += 9;
		}
		l = 25;
		k += 4;
	}
	k = 3;
	l = 25;
	for(i = 1; i <= 4 ; i++){
		for(j = 4; j >= 1; j--){
			gotoxy(k, l+4);
			if(( j == 1 ) && ( i == 1 ))
			printf(">");
			printf("%c",howtoplays[i][j]);
			l += 9;
		}
		l = 25;
		k += 4;
	}
	gotoxy(19, 9); 
	printf("mengikuti perputaran sehingga tetap menunjuk petak yang sama.");
	gotoxy(21, 28);
	printf("Tekan apa saja dari keyboard");
	gotoxy(23, 36);
	printf("-> Back to Menu");
	getch();
	ShowCursor();
}


void PrintAbout(bool st[5]) {
	system("clear");
	captionN[0] = "Afrizal Fikri";
	captionN[1] = "Rahman Adianto";
	captionN[2] = "Azam Iszuhri";
	captionN[3] = "Luqman Arifin";
	captionN[4] = "Gazandi Cahyadarma";
	captionN[5] = "Back";
	system("clear");
	
	int i, x = 5;
	gotoxy(3, 3);
	printf("Anggota Everybody Can Too");
	for(i = 0; i < 6; i++) {
		gotoxy(x, 3);
		if(st[i]) printf("-> ");
		printf("%s", captionN[i]);
		x += 2;
	}
}

void PrintAfrizal(){
	gotoxy(5, 29);
	printf("Hobi ");
	gotoxy(5,44);
	printf("= Tidur, BAB, Makan");
	gotoxy(7, 29);
	printf("Akun facebook ");
	gotoxy(7,44);
	printf("= afrizal fikri");
	gotoxy(9, 29);
	printf("Akun twitter ");
	gotoxy(9,44);
	printf("= ical_fikr");
	gotoxy(11, 29);
	printf("Istri Idaman ");
	gotoxy(11,44);
	printf("= 198..080");
	gotoxy(19, 67);
	printf("Ical");
	gotoxy(20, 65);
	printf("--------");
	gotoxy(21, 65);
	printf("13513004");
	gotoxy(22, 65);
	printf("--------");
	gotoxy(18, 42);
	printf("\"Gerakan anti Kuli\"");
}

void PrintRahman(){
	gotoxy(5, 29);
	printf("Hobi ");
	gotoxy(5,44);
	printf("= Baca novel");
	gotoxy(7, 29);
	printf("Akun facebook ");
	gotoxy(7,44);
	printf("= Rahman Adianto");
	gotoxy(9, 29);
	printf("Akun twitter ");
	gotoxy(9,44);
	printf("= Rahman_adianto");
	gotoxy(11, 29);
	printf("Istri Idaman ");
	gotoxy(11,44);
	printf("= PD UGM");
	gotoxy(19, 66);
	printf("Rahman");
	gotoxy(20, 65);
	printf("--------");
	gotoxy(21, 65);
	printf("13513006");
	gotoxy(22, 65);
	printf("--------");
	gotoxy(18,6);
	printf("\"The Only Way to Succeed is to not worry about what anyone else is doing\"");
}

void PrintAzam(){
	gotoxy(5, 29);
	printf("Hobi ");
	gotoxy(5,44);
	printf("= Travelling");
	gotoxy(7, 29);
	printf("Akun facebook ");
	gotoxy(7,44);
	printf("= Azam Iszuhri");
	gotoxy(9, 29);
	printf("Akun twitter ");
	gotoxy(9,44);
	printf("= -");
	gotoxy(11, 29);
	printf("Istri Idaman ");
	gotoxy(11,44);
	printf("= UNPAD");
	gotoxy(19, 67);
	printf("Azam");
	gotoxy(20, 65);
	printf("--------");
	gotoxy(21, 65);
	printf("13513012");
	gotoxy(22, 65);
	printf("--------");
	gotoxy(18, 26);
	printf("\"Kadang yang \"besar-besar\" itu belum tentu baik\"");
}

void PrintLuqman(){
	gotoxy(5, 29);
	printf("Hobi ");
	gotoxy(5,44);
	printf("= Tenis Meja");
	gotoxy(7, 29);
	printf("Akun facebook ");
	gotoxy(7,44);
	printf("= Luqman Arifin");
	gotoxy(9, 29);
	printf("Akun twitter ");
	gotoxy(9,44);
	printf("= luqmanarifiin");
	gotoxy(11, 29);
	printf("Istri Idaman ");
	gotoxy(11,44);
	printf("= Inisial C");
	gotoxy(19, 66);
	printf("Luqman");
	gotoxy(20, 65);
	printf("--------");
	gotoxy(21, 65);
	printf("13513024");
	gotoxy(22, 65);
	printf("--------");
	gotoxy(18, 26);
	printf("\"JANCOK (Jangan Anggap Neraka Cuma Omong Kosong)\"");
}

void PrintGazandi(){
	gotoxy(5, 29);
	printf("Hobi ");
	gotoxy(5,44);
	printf("= \"Main\"");
	gotoxy(7, 29);
	printf("Akun facebook ");
	gotoxy(7,44);
	printf("= Gazandi Cahyadarma");
	gotoxy(9, 29);
	printf("Akun twitter ");
	gotoxy(9,44);
	printf("= gazandic");
	gotoxy(11, 29);
	printf("Istri Idaman ");
	gotoxy(11,44);
	printf("= KMF");
	gotoxy(19, 66);
	printf("Gazandi");
	gotoxy(20, 65);
	printf("--------");
	gotoxy(21, 65);
	printf("13513078");
	gotoxy(22, 65);
	printf("--------");
	gotoxy(18, 17);
	printf("\"Sesungguhnya setiap perbuatan yang bermanfaat adalah ibadah\"");
}

void About() {
	bool st[6];
	loginSalah = 0;
	bool exit = 0;
	char cc;
	
	int i;
	for(i = 0; i < 6; i++) {
		st[i] = 0;
	}
	st[0] = 1;
	int now = 0;
	PrintAbout(st);
	PrintAfrizal();
	while(!exit) {
		HideCursor();
		if(kbhit()) {
			cc = getch();
			if(cc == 'w') {
				if(now) {
					st[now] = 0;
					now--;
					st[now] = 1;
					PrintAbout(st);
				}
			}

			else if(cc == 'x') {
				if(now < 5) {
					st[now] = 0;
					now++;
					st[now] = 1;
					PrintAbout(st);
				}
			}
			if(st[0]) {system("clear");
				PrintAbout(st);
				PrintAfrizal();
			} else if(st[1]) {
				system("clear");
				PrintAbout(st);
				PrintRahman();
			} else if(st[2]) {
				system("clear");PrintAbout(st);
				PrintAzam();
			} else if(st[3]) {
				system("clear");
				PrintAbout(st);
				PrintLuqman();
			} else if(st[4]) {
				system("clear");	
				PrintAbout(st);
				PrintGazandi();
			}else if(st[5]) 
				if(cc == 's' || cc == '\n')
					exit = 1;
		}
	}
	ShowCursor();
}
