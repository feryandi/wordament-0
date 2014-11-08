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
#include "../adt/queue/queue.c"
//#include "../adt/list/list.c"
//#include "../adt/array/array.c" HARUS PAKE ARRAY STRING, BANYAK BANGET YG HARUS DIGANTI

typedef struct {
    int NbElmt;
    Kata TI[10000]; //??
} TabStr;

typedef struct {
    int NbElmt;
    char TI[109013][18]; //??
} TabKamus;

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

extern TabKamus K;

/* save.c */
boolean searchWord (TabStr X, char word[18]);
void save(char word[18], int target, char user[62], int t);
void saveWord(char word[18], int target, char user[62]);
void saveScore(int score, int target, char user[62]);

/* load.c */
void getBoard (int target, MATRIKS *M);
void GetSuggestion (char word[18], int target, char user[62]);
TimeArray SortByHS ( TimeArray T );
TimeArray ListUserHS (int target, char user[62]);

/* auth.c */
boolean searchUser (TabStr X, char word[30]);
boolean registerUser(char word[30]);
boolean loginUser(char word[30]);

/* word.c */
void BuatJudul();
void BuatBoard();
/* Board ukuran 4x4 blok besar */
/* Tiap blok besar ukuran 5x3 (x y) */

void IsiBoard(MATRIKS *M);
void PointerBoard(MATRIKS M, Stack *S, char *kata, boolean *endK);
void PointerIsi();
void SimbolAktif(MATRIKS M, Stack *S);
void HapusSimbol(int x, int y);
void EndWord(Stack *S, char kata[18], boolean *endK);

/*Pake ADT map */
int Map (char key);
void Score(Stack *S, int *score);

#endif
