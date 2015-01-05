#include <stdio.h>
#include "mesinkar.h"
#include <unistd.h>

#ifndef MARK
#define MARK '.'
#endif // MARK

/* definisi states */
char CC;

/* definisi pita */
#define Pita_karakter "database/Dictionary.txt"
static int _handle;

void START() {
/*
    I.S Sembarang
    F.S CC adalah karakter pertama pita
        jika CC = MARK, EOP menyala
        jika CC != MARK, EOP mati
*/
    _handle = open(Pita_karakter,O_RDONLY);
    assert(_handle != -1);
    assert( read(_handle, &CC, 1) != -1);
}

void ADV() {
/*
    I.S CC != MARK
    F.S CC adalah karakter berikutnya dari CC pada I.S
        jika CC = MARK, EOP menyala
*/
    assert(!EOP());
    assert( read(_handle, &CC, 1) != -1);
    if (CC == MARK) assert( close(_handle) != -1);
}

bool EOP() {
/* true jika CC = MARK */
    return (CC == MARK);
}
