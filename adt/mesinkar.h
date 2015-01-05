#ifndef MESINKAR_H
#define MESINKAR_H

#include <assert.h>
#include <fcntl.h>
#include <stdbool.h>

#ifndef MARK
#define MARK '.'
#endif // MARK

void START();
/*
    I.S Sembarang
    F.S CC adalah karakter pertama pita
        jika CC = MARK, EOP menyala
        jika CC != MARK, EOP mati
*/

void ADV();
/*
    I.S CC != MARK
    F.S CC adalah karakter berikutnya dari CC pada I.S
        jika CC = MARK, EOP menyala
*/

bool EOP();
/* true jika CC = MARK */

#endif // MESINKAR_H
