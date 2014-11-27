#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "set.h"

// ****** KONSTRUKTOR ******
// Konstruktor : create tabel kosong
void MakeEmpty ( SetStr *T ) {
    // I.S. sembarang
    // F.S. terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1
    (*T).Neff = 0;
}

// ****** SELEKTOR ******
// *** Banyaknya elemen ***
int NbElmt ( SetStr T ) {
    // Mengirimkan banyaknya elemen efektif tabel
    // Mengirimkan nol jika tabel kosong
    return (T).Neff;
}

// *** Menghasilkan sebuah elemen
ElType GetSetElmt ( SetStr T, IdxType i ) {
    // Prekondisi: Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T)
    // Mengirimkan elemen tabel yang ke-i
	int n;
	char elmt[18];
	n = 0;

	while ( (T).TI[i][n] != '\0' ) {
		(elmt)[n] = (T).TI[i][n]; //??
		n++;
	}
	(elmt)[n] = '\0';

	return *elmt;
}


void SetSetEl ( SetStr *T, IdxType i, ElType v[18]) {
    // I.S. T terdefinisi, sembarang }
    // F.S. Elemen T yang ke-i bernilai v
    // Mengeset nilai elemen tabel yang ke-i sehingga bernilai v
	int n;
	n = 0;

	while ( v[n] != '\0' ) {
		(*T).TI[i][n] = v[n];
		n++;
	}
	(*T).TI[i][n] = '\0';
	
}

void SetNeff ( SetStr *T, IdxType N ) {
    // I.S. T terdefinisi, sembarang
    // F.S. Nilai indeks efektif T bernilai N
    // Mengeset nilai indeks elemen efektif sehingga bernilai N
    (*T).Neff = N;
}

// ****** TEST KOSONG/PENUH ******
// *** Test tabel kosong ***
boolean IsSetEmpty ( SetStr T ) {
    // Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak
    if ( T.Neff == 0 ) {
        return true;
    } else {
        return false;
    }
}
// *** Test tabel penuh ***
boolean IsSetFull ( SetStr T ) {
    // Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak
    if ( T.Neff == 16 ) {
        return true;
    } else {
        return false;
    }
}

void TulisIsiTab ( SetStr T ) {
    // Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung
	// siku; antara dua elemen dipisahkan dengan separator "koma"
    // I.S. T boleh kosong
    // F.S. Jika T tidak kosong: [e1, e2, ... ,en]
    // Contoh : jika ada tiga elemen bernilai 1, 20, 30 : [1, 20, 30]
    // Jika tabel kosong : menulis []
    int i;
    if (IsSetEmpty(T)) {
        printf("[]");
    } else {
        printf("[");
        for ( i=0; i<=(NbElmt(T)-1); i++) {
            if ( i != 0 ) {
                printf(", ");
            }
            printf("%s",T.TI[i]);
        }
        printf("]");
    }
}
