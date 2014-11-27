#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "list.h"

/* ***************** MODUL LIST BERKAIT ***************** */
/* List direpresentasi dengan pointer, FirstL dinyatakan secara eksplisit. */

/* PROTOTYPE */
/* ***************** TEST LIST KOSONG ***************** */
boolean IsListEmpty (List L) {
/* Mengirim true jika list kosong */
    return ( FirstL(L) == NilAdd );
}

/* ***************** PEMBUATAN LIST KOSONG ***************** */
void CreateList (List *L) {
/* I.S. sembarang */
/* F.S. Terbentuk list kosong */
    FirstL(*L) = NilAdd;
}

/* ***************** Manajemen Memori ***************** */
addressL Alokasi (infotypeL X) {
/* Mengirimkan addressL hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressL tidak NilAdd, dan misalnya menghasilkan P, maka
InfoL(P) = X, NextL(P) = NilAdd */
/* Jika alokasi gagal, mengirimkan NilAdd */
    addressL alloc;

    alloc = (addressL) malloc (sizeof(ElmtList));
    if (alloc != NilAdd) {
        InfoL(alloc) = X;
        NextL(alloc) = NilAdd;
        FirstL(ChildL(alloc)) = NilAdd;
        return alloc;
    } else {
        return NilAdd;
    }
}

void Dealokasi ( addressL P ) {
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressL P */
    free(P);
}

/* ***************** PENCARIAN SEBUAH ELEMEN LIST ***************** */
addressL Search ( List L, infotypeL X ) {
/* Mencari apakah ada elemen list denga InfoL(P) = X */
/* Jika ada, mengirimkan addressL elemen tersebut */
/* Jika tidak ada, mengirimkan NilAdd */
    addressL P;

    P = FirstL(L);
    while ( P != NilAdd ) {
        if ( InfoL(P) == X ) {
            break;
        }
        P = NextL(P);
    }

    return P;
}

boolean FSearch ( List L, addressL P ) {
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
    addressL A;

    A = FirstL(L);
    while ( A != NilAdd ) {
        if ( A == P ) {
            break;
        }
        A = NextL(A);
    }

    if ( A == NilAdd ) {
        return false;
    } else {
        return true;
    }
}

addressL SearchPrec ( List L, infotypeL X ) {
/* Mengirimkan addressL elemen sebelum elemen yang NilAddainya = X */
/* Mencari apakah ada elemen list dengan InfoL(P) = X */
/* Jika ada, mengirimkan addressL Prec, dengan NextL(Prec) = P dan InfoL(P) = X */
/* Jika tidak ada, mengirimkan NilAdd */
/* Jika P adalah elemen pertama, maka mengirimkan NilAdd */
/* Search dengan spesifikasi seperti ini menghindari traversal ulang jika setelah
Search akan dilakukan operasi lain */
    addressL Q, R;

    Q = Search(L,X);
    if ( Q == NilAdd ) {
        return NilAdd;
    } else if ( Q == FirstL(L) ) {
        return NilAdd;
    } else {
        R = FirstL(L);
        while ( R != NilAdd ) {
            if ( NextL(R) == Q ) {
                break;
            }
            R = NextL(R);
        }

        return R;
    }
}

/* ***************** PRIMITIF BERDASARKAN NilAddAI ***************** */
/* *** PENAMBAHAN ELEMEN *** */
void InsVFirstL ( List *L, infotypeL X ) {
/* I.S. L mungkin kosong */
/* F.S. X ditambahkan sebagai elemen pertama L */
/* Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen pertama dengan
NilAddai X jika alokasi berhasil.
Jika alokasi gagal: I.S.= F.S. */
    addressL Q;
    Q = Alokasi(X);

    NextL(Q) = FirstL(*L);
    FirstL(*L) = Q;
}

void InsVLast ( List *L, infotypeL X ) {
/* I.S. L mungkin kosong */
/* F.S. X ditambahkan sebagai elemen terakhir L */
/* Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen list di akhir :
elemen terakhir yang baru berNilAddai X jika alokasi berhasil.
Jika alokasi gagal: I.S.= F.S. */
    addressL Q, R;
    R = Alokasi(X);

    Q = FirstL(*L);
    if ( Q != NilAdd ) {
        while ( NextL(Q) != NilAdd ) {
            Q = NextL(Q);
        }
        NextL(Q) = R;
    } else {
        FirstL(*L) = R;
    }
}

/* *** PENGHAPUSAN ELEMEN *** */
void DelVFirstL ( List *L, infotypeL *X ) {
/* I.S. List L tidak kosong */
/* F.S. Elemen pertama list dihapus : NilAddai InfoL disimpan pada X */
/* dan alamat elemen pertama di-dealokasi */
    addressL Q;

    Q = FirstL(*L);
    (*X) = InfoL(Q);

    Q = NextL(Q);

    Dealokasi(FirstL(*L));
    FirstL(*L) = Q;
}

void DelVLast ( List *L, infotypeL *X ) {
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus : NilAddai InfoL disimpan pada X */
/* dan alamat elemen terakhir di-dealokasi */
    addressL Q, R;

    Q = FirstL(*L);
    R = NilAdd;

    while ( Q != NilAdd ) {
        if ( NextL(Q) == NilAdd ) { break; }
        R = Q;
        Q = NextL(Q);
    }
    (*X) = InfoL(Q);
    Dealokasi(Q);

    if ( R != NilAdd ) { NextL(R) = NilAdd; }

}

/* ***************** PRIMITIF BERDASARKAN ALAMAT ***************** */
/* *** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT *** */
void InsertFirstL ( List *L, addressL P ) {
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. Menambahkan elemen ber-addressL P sebagai elemen pertama */
    addressL Q;

    Q = FirstL(*L);
    FirstL(*L) = P;
    NextL(P) = Q;
}

void InsertAfter ( List *L, addressL P, addressL Prec ) {
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/* P sudah dialokasi */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    NextL(P) = NextL(Prec);
    NextL(Prec) = P;
}

void InsertLast ( List *L, addressL P ) {
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    addressL Q;

    Q = FirstL(*L);
    while ( Q != NilAdd ) {
        if ( NextL(Q) == NilAdd ) {
            NextL(P) = NilAdd;
            NextL(Q) = P;
            break;
        }
        Q = NextL(Q);
    }

}


/* *** PENGHAPUSAN SEBUAH ELEMEN *** */

void DeleteFirstL ( List *L, addressL *P ) {
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* FirstL element yang baru adalah suksesor elemen pertama yang lama */
    (*P) = FirstL(*L);

    FirstL(*L) = NextL(FirstL(*L));
    Dealokasi(*P);
}

void DeleteP ( List *L, infotypeL X ) {
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddressL P, dengan InfoL(P) = X */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan InfoL(P) = X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
    addressL Q, R;
    R = Search(*L, X);

    if ( R != NilAdd ) {
        Q = FirstL(*L);
        while ( Q != NilAdd ) {
            if ( NextL(Q) == R ) { break; }
            Q = NextL(Q);
        }

        NextL(Q) = NextL(R);
        Dealokasi(R);
    }
}

void DeleteLast ( List *L, addressL *P ) {
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yang lama, jika ada */
    addressL Q;

    Q = FirstL(*L);

    if ( NextL(Q) != NilAdd ) {
        while ( NextL(NextL(Q)) != NilAdd ) {
            Q = NextL(Q);
        }
        (*P) = Q;
        NextL(Q) = NilAdd;
    } else {
        (*P) = FirstL(*L);
        FirstL(*L) = NilAdd;
    }

    Dealokasi(*P);

}

void DeleteAfter ( List *L, addressL *Pdel, addressL Prec ) {
/* I.S. List tidak kosong. Prec adalah anggota list L. */
/* F.S. Menghapus NextL(Prec) : Pdel adalah alamat elemen list yang dihapus */
    (*Pdel) = NextL(Prec);
    NextL(Prec) = NextL(NextL(Prec));
    Dealokasi(*Pdel);
}


/* ***************** PROSES SEMUA ELEMEN LIST ***************** */
void PrintInfoL ( List L ) {
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, */
/* Semua InfoL yg disimpan pada elemen list diprint */
/* Jika list kosong, hanya menuliskan "list kosong" */
    addressL Q;

    if ( !IsListEmpty(L) ) {
        Q = FirstL(L);

        while ( Q != NilAdd ) {
            printf("%d ", InfoL(Q));
            Q = NextL(Q);
        }

    } else {
        printf("List Kosong");
    }
}

int NbElmtL ( List L ) {
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
/* *** Prekondisi untuk Max/Min/rata-rata : List tidak kosong *** */
    addressL Q;
    int i = 1;

    if ( !IsListEmpty(L) ) {
        Q = FirstL(L);

        while ( Q != NilAdd ) {
            i++;
            Q = NextL(Q);
        }

        return i;
    } else {
        return 0;
    }
}

infotypeL Max ( List L ) {
/* Mengirimkan NilAddai InfoL(P) yang maksimum */
    addressL Q;
    //infotypeL Max = 0x80000000; //Haha
    infotypeL Max = -999;

    if ( !IsListEmpty(L) ) {
        Q = FirstL(L);

        while ( Q != NilAdd ) {
            if (InfoL(Q) > Max) { Max = InfoL(Q); }
            Q = NextL(Q);
        }

        return Max;

    } else {
        return 0; //Bener ga?
    }
}

addressL AdrMax ( List L ) {
/* Mengirimkan addressL P, dengan InfoL(P) yang berNilAddai maksimum */
    return Search(L, Max(L));
}

infotypeL Min ( List L ) {
/* Mengirimkan NilAddai InfoL(P) yang minimum */
    addressL Q;
    //infotypeL Min = 0x7FFFFFFF; //Haha
    infotypeL Min = 99999;

    if ( !IsListEmpty(L) ) {
        Q = FirstL(L);

        while ( Q != NilAdd ) {
            if (InfoL(Q) < Min) { Min = InfoL(Q); }
            Q = NextL(Q);
        }

        return Min;

    } else {
        return 0; //Bener ga?
    }
}

addressL AdrMin ( List L ) {
/* Mengirimkan addressL P, dengan InfoL(P) yang berNilAddai minimum */
    return Search(L, Min(L));
}


/* ***************** PROSES TERHADAP LIST ***************** */
void DeleteAll ( List *L ) {
/* Delete semua elemen list dan alamat elemen di-dealokasi */
/* I.S. : L terdefinisi, boleh kosong */
/* F.S. : Jika L tidak kosong, semua elemen list di-delete dan didealokasi */
    addressL Q;
    Q = NilAdd;
    while ( !IsListEmpty(*L) ) {
        DeleteFirstL(L, &Q);
    }
}

