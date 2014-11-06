#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "array.h"

// ****** KONSTRUKTOR ******
// Konstruktor : create tabel kosong
void MakeEmpty ( TabStr *T ) {
    // I.S. sembarang
    // F.S. terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1
    (*T).NbElmt = 0;
}

// ****** SELEKTOR ******
// *** Banyaknya elemen ***
int NbElmt ( TabStr T ) {
    // Mengirimkan banyaknya elemen efektif tabel
    // Mengirimkan nol jika tabel kosong
    return (T).NbElmt;
}

// *** Menghasilkan sebuah elemen
ElType GetElmtA ( TabStr T, IdxType i ) {
    // Prekondisi: Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T)
    // Mengirimkan elemen tabel yang ke-i
    return (T).TI[i].TabKata;
}


void SetElA ( TabStr *T, IdxType i, ElType v) {
    // I.S. T terdefinisi, sembarang }
    // F.S. Elemen T yang ke-i bernilai v
    // Mengeset nilai elemen tabel yang ke-i sehingga bernilai v
    (*T).TI[i].TabKata = v;
}

void SetNeff ( TabStr *T, IdxType N ) {
    // I.S. T terdefinisi, sembarang
    // F.S. Nilai indeks efektif T bernilai N
    // Mengeset nilai indeks elemen efektif sehingga bernilai N
    (*T).NbElmt = N;
}

// ****** Test Indeks yang valid ******
boolean IsIdxValid ( TabStr T, IdxType i ) {
    // Prekondisi : i sembarang
    // Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel
    // yaitu antara indeks yang terdefinisi utk container
    if ( (i >= 0) && (i <= MaxNbEl(T)) ) {
        return true;
    } else {
        return false;
    }
}

boolean IsIdxEff ( TabStr T, IdxType i ) {
    // Prekondisi : i sembarang
    // Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel
    // yaitu antara FirstIdx(T)..LastIdx(T)
    if ( (i >= GetFirstIdx(T)) && (i <= GetLastIdx(T)) ) {
        return true;
    } else {
        return false;
    }
}

// ****** TEST KOSONG/PENUH ******
// *** Test tabel kosong ***
boolean IsEmpty ( TabStr T ) {
    // Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak
    if ( T.Neff == 0 ) {
        return true;
    } else {
        return false;
    }
}
// *** Test tabel penuh ***
boolean IsFull ( TabStr T ) {
    // Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak
    if ( T.Neff == MaxNbEl(T) ) {
        return true;
    } else {
        return false;
    }
}

void TulisIsiTab ( TabStr T ) {
    // Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung
	// siku; antara dua elemen dipisahkan dengan separator "koma"
    // I.S. T boleh kosong
    // F.S. Jika T tidak kosong: [e1, e2, ... ,en]
    // Contoh : jika ada tiga elemen bernilai 1, 20, 30 : [1, 20, 30]
    // Jika tabel kosong : menulis []
    int i;
    if (IsEmpty(T)) {
        printf("[]");
    } else {
        printf("[");
        for ( i=GetFirstIdx(T); i<=GetLastIdx(T); i++) {
            if ( i != GetFirstIdx(T) ) {
                printf(", ");
            }
            printf("%d",T.TI[i]);
        }
        printf("]");
    }
}
