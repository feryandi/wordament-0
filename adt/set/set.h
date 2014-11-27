#ifndef array_H
#define array_H

// Kamus Umum
const int IdxMax = 100;
const int IdxMin = 1;
const int IdxUndef = -999;

// Definisi elemen dan koleksi objek
typedef int IdxType;
typedef char ElType;

typedef struct {
    int Neff; // banyaknya elemen efektif
    ElType TI[1000][18]; // memori tempat penyimpan elemen (container)
} SetStr;

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

void MakeEmpty ( SetStr *T );
int NbElmt ( SetStr T );
ElType GetSetElmt ( SetStr T, IdxType i );
void SetSetEl ( SetStr *T, IdxType i, ElType v[18]);
void SetNeff ( SetStr *T, IdxType N );
boolean IsSetEmpty ( SetStr T );
boolean IsSetFull ( SetStr T );
void TulisIsiTab ( SetStr T );
#endif
