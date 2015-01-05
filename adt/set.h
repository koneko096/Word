/**
 * Nama file	: set.h
 * Topik			: Abstract Data Type
 * Tanggal 		: 12 November 2014
 * Deskripsi	: File Header dari ADT Set
 * Author			: Luqman Arifin
 */

#ifndef SET_ADT
#define SET_ADT

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bukan_string.h"
#include "../global.h"

/* ADT Set dengan representasi List double pointer: prev dan next
 * Dengan 2 penunjuk list: first dan last
 * Representasi addressSet dengan pointer
 * infotype adalah integer */

#define Nil NULL

typedef struct tElementSet* addressSet;
typedef struct tElementSet {
	addressSet prev;
	addressSet next;
	char info[20];
} ElementSet;

/* Definisi list :
 * List kosong : First(L) = Nil, Last(L) = Nil
 * Setiap elemen dengan addressSet P dapat diacu Info(P), PrevSet(P), NextSet(P) */
 
#define SetInfo(P) (P)->info
#define PrevSet(P) (P)->prev
#define NextSet(P) (P)->next

typedef struct {
	addressSet first;
	addressSet last;
} Set;

#define First(S) (S).first
#define Last(S) (S).last

/* ***************** PRIMITIF-PRIMITIF LIST ***************** */

/* *** TEST LIST KOSONG *** */
bool IsSetEmpty(Set S);

/* *** PEMBUATAN LIST KOSONG *** */
void CreateSet(Set *S);

/* *** Manajemen Memori *** */
addressSet AlokasiSet(char x[20]);
void DealokasiSet(addressSet *p);

/* *** PENCARIAN SEBUAH ELEMEN LIST *** */
addressSet Search(Set S, char x[20]);

/* ***************** PRIMITIF BERDASARKAN NILAI ***************** */

/* *** PENAMBAHAN ELEMEN *** */
void Insert(Set *S, char x[20]);

/* *** PENGHAPUSAN ELEMEN *** */
void DeleteAt(Set *S, addressSet p);
void Delete(Set *S, char x[20]);

void PrintInfoSet(Set S);

#endif