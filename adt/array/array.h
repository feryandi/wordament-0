#ifndef array_H
#define array_H
#include "../mesin_kar/mesinkata.h"

// Kamus Umum
const int IdxMax = 100;
const int IdxMin = 1;
const int IdxUndef = -999;

// Definisi elemen dan koleksi objek
typedef int IdxType;
typedef char *ElType;
typedef struct {
    int Neff; // banyaknya elemen efektif
    ElType TI[109013]; // memori tempat penyimpan elemen (container)
} TabInt;

typedef struct {
    int NbElmt;
    Kata TI[109013]; //??
} TabStr;

// Indeks yang digunakan [IdxMin..IdxMax]
// Jika T adalah TabInt, cara deklarasi dan akses:
// Deklarasi : T : TabInt
// Maka cara akses:
// T.Neff untuk mengetahui banyaknya elemen
// T.TI untuk mengakses seluruh nilai elemen tabel
// T.TI[i] untuk mengakses elemen ke-i }
// Definisi :
// Tabel kosong: T.Neff = 0
// Definisi elemen pertama : T.TI[i] dengan i=1
// Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff }

typedef struct {
    ElType A;
    ElType B;
} TwoElType;

void MakeEmpty ( TabStr *T );
int NbElmt ( TabStr T );
int MaxNbEl ( TabStr T );
IdxType GetFirstIdx ( TabStr T );
IdxType GetLastIdx ( TabStr T );
ElType GetElmtA ( TabStr T, IdxType i );
void SetTab ( TabStr Tin, TabStr *Tout );
void SetElA ( TabStr *T, IdxType i, ElType v);
void SetNeff ( TabStr *T, IdxType N );
boolean IsIdxValid ( TabStr T, IdxType i );
boolean IsIdxEff ( TabStr T, IdxType i );
boolean IsEmpty ( TabStr T );
boolean IsFull ( TabStr T );
void TulisIsiTab ( TabStr T );
#endif
