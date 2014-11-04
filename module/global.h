#ifndef global_H
#define global_H

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "boolean.h"
#include "../adt/mesin_kar/mesinkata.c"
#include "../adt/jam/jam.c"
#include "../adt/matriks/matriks.c"
#include "../adt/stack/stack.c"

typedef struct {
    int NbElmt;
    Kata TI[10000]; //??
} TabStr;

typedef struct {
	int D;
	int M;
	int Y;
} TANGGAL;

typedef struct {
    TANGGAL w;
    JAM t;
    int s;
} HScore;

typedef struct {
    int NbElmt;
    HScore get[100];
} TimeArray;

/* save.c */
boolean searchWord (TabStr X, char word[18]);
void save(char word[18], int target, char user[62], int t);
void saveWord(char word[18], int target, char user[62]);
void saveScore(int score, int target, char user[62]);

void BuatJudul();
void BuatBoard();
/* Board ukuran 4x4 blok besar */
/* Tiap blok besar ukuran 5x3 (x y) */

void IsiBoard(MATRIKS *M);
void PointerBoard(MATRIKS M, Stack *S, char *kata);
void PointerIsi();
void SimbolAktif(MATRIKS M, Stack *S);
void HapusSimbol(int x, int y);
void EndWord();

#endif
