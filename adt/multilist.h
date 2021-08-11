/**
 * Nama file	: multilist.h
 * Topik			: Abstract Data Type
 * Tanggal 		: 12 November 2014
 * Deskripsi	: File Header dari ADT Multi List
 * Author			: Luqman Arifin
 */

#ifndef MULTI_LIST
#define MULTI_LIST

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "lqstring.h"
#include "user.h"
#include "jam.h"
#include "tanggal.h"

#define Nil NULL

typedef struct tElementMultiList* addressMulti;
typedef struct tElementMultiList {
	User info;
	addressMulti next;
	addressMulti cont;
} ElementMultiList;

typedef struct {
	addressMulti first;
} MultiList;

#define MultiInfo(P) (P)->info
#define NextMulti(P) (P)->next
#define ContMulti(P) (P)->cont
#define FirstMulti(L) (L).first

/** PRIMITIF PRIMITIF LIST **/
addressMulti AlokasiMulti(User U);
void DealokasiMulti(addressMulti p);

bool IsMultiListEmpty(MultiList L);
void CreateMultiList(MultiList *L);

bool SearchName(MultiList L, User U);
void InsertUser(MultiList *L, User U);
void InsertNewUser(MultiList *L, User U);
void InsertOldUser(MultiList *L, User U);

void PrintList(MultiList L);


#endif