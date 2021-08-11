#include "mesinkar.h"
#include "mesinkata.h"

/* ***** Definisi State Mesin Kata ***** */
bool EndKata; /* penanda akhir akuisisi kata */
Kata CKata; /* kata yang sudah diakuisisi dan akan diproses */

/* ***** Primitif-Primitif Mesin Kata ***** */
void Ignore_Blank() {
    /* Mengabaikan satu atau beberapa BLANK */
    /* I.S. : CC sembarang */
    /* F.S. : CC != BLANK atau CC = MARK */
    while (CC == BLANK)
        ADV();
}
void STARTKATA() {
    /* I.S. : CC sembarang */
    /* F.S. : EndKata = true, dan CC = Mark; */
    /* atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
    CC karakter pertama sesudah karakter terakhir kata */
    START();
    Ignore_Blank();
    if (CC == MARK) {
        EndKata = true;
    } else {
        EndKata = false;
        SalinKata();
    }
}
void ADVKATA() {
    /* I.S. : EndKata = false; CC adalah karakter sesudah karakter terakhir
    dari kata yg sudah diakuisisi */
    /* F.S. : Jika CC = MARK, maka EndKata = true
    atau EndKata = false, CKata adalah kata terakhir yang sudah diakuisisi;
    CC karakter pertama sesudah karakter terakhir kata */
    Ignore_Blank();
    if (CC == MARK) {
        EndKata = true;
    } else {
        SalinKata();
    }
}
void SalinKata() {
    /* Mengakuisisi kata, menyimpan dalam CKata */
    /* I.S. : CC adalah karakter pertama dari kata */
    /* F.S. : CKata berisi kata yang sudah diakuisisi, jika karakternya melebihi
    NMax, sisa "kata" dibuang; CC = BLANK atau CC = MARK; CC adalah
    karakter sesudah karakter terakhir yang diakuisisi */
    /* Kamus lokal */
    int i;
    bool ulang;
    /* Algoritma */
    i = 1;
    ulang = true;
    do {
        CKata.TabKata[i] = CC;
        ADV();
        if (CC == MARK || CC == BLANK)
            ulang = false;
        else
            i++;
    } while (ulang);
    CKata.Length = i;
}

/* ***** Operasi Lain ***** */
bool IsKataSama (Kata K1, Kata K2) {
    /* Mengembalikan true jika K1 = K2; dua kata dikatakan sama jika panjangnya sama dan
    urutan karakter yang menyusun kata juga sama */
    /* Kamus Lokal */
    int i;
    /* Algoritma */
    if (K1.Length != K2.Length)
        return false;
    else {
        i = 1;
        while (i < K1.Length && K1.TabKata[i] == K2.TabKata[i])
            i++;
        return (K1.TabKata[i] == K2.TabKata[i]);
    }
}
