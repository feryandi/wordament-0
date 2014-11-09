#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "list.h"

/* ***************** MODUL LIST BERKAIT ***************** */
/* List direpresentasi dengan pointer, First dinyatakan secara eksplisit. */

/* PROTOTYPE */
/* ***************** TEST LIST KOSONG ***************** */
boolean IsListEmpty (List L) {
/* Mengirim true jika list kosong */
    return ( First(L) == Nil );
}

/* ***************** PEMBUATAN LIST KOSONG ***************** */
void CreateList (List *L) {
/* I.S. sembarang */
/* F.S. Terbentuk list kosong */
    First(*L) = Nil;
}

/* ***************** Manajemen Memori ***************** */
address Alokasi (infotype X) {
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, maka
Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
    address alloc;

    alloc = (address) malloc (sizeof(ElmtList));
    if (alloc != Nil) {
        Info(alloc) = X;
        Next(alloc) = Nil;
        Child(alloc).First = Nil;
        return alloc;
    } else {
        return Nil;
    }
}

void Dealokasi ( address P ) {
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
    free(P);
}

/* ***************** PENCARIAN SEBUAH ELEMEN LIST ***************** */
address Search ( List L, infotype X ) {
/* Mencari apakah ada elemen list denga Info(P) = X */
/* Jika ada, mengirimkan address elemen tersebut */
/* Jika tidak ada, mengirimkan Nil */
    address P;

    P = First(L);
    while ( P != Nil ) {
        if ( Info(P) == X ) {
            break;
        }
        P = Next(P);
    }

    return P;
}

boolean FSearch ( List L, address P ) {
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
    address A;

    A = First(L);
    while ( A != Nil ) {
        if ( A == P ) {
            break;
        }
        A = Next(A);
    }

    if ( A == Nil ) {
        return false;
    } else {
        return true;
    }
}

address SearchPrec ( List L, infotype X ) {
/* Mengirimkan address elemen sebelum elemen yang nilainya = X */
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec) = P dan Info(P) = X */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka mengirimkan Nil */
/* Search dengan spesifikasi seperti ini menghindari traversal ulang jika setelah
Search akan dilakukan operasi lain */
    address Q, R;

    Q = Search(L,X);
    if ( Q == Nil ) {
        return Nil;
    } else if ( Q == First(L) ) {
        return Nil;
    } else {
        R = First(L);
        while ( R != Nil ) {
            if ( Next(R) == Q ) {
                break;
            }
            R = Next(R);
        }

        return R;
    }
}

/* ***************** PRIMITIF BERDASARKAN NILAI ***************** */
/* *** PENAMBAHAN ELEMEN *** */
void InsVFirst ( List *L, infotype X ) {
/* I.S. L mungkin kosong */
/* F.S. X ditambahkan sebagai elemen pertama L */
/* Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen pertama dengan
nilai X jika alokasi berhasil.
Jika alokasi gagal: I.S.= F.S. */
    address Q;
    Q = Alokasi(X);

    Next(Q) = First(*L);
    First(*L) = Q;
}

void InsVLast ( List *L, infotype X ) {
/* I.S. L mungkin kosong */
/* F.S. X ditambahkan sebagai elemen terakhir L */
/* Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen list di akhir :
elemen terakhir yang baru bernilai X jika alokasi berhasil.
Jika alokasi gagal: I.S.= F.S. */
    address Q, R;
    R = Alokasi(X);

    Q = First(*L);
    if ( Q != Nil ) {
        while ( Next(Q) != Nil ) {
            Q = Next(Q);
        }
        Next(Q) = R;
    } else {
        First(*L) = R;
    }
}

/* *** PENGHAPUSAN ELEMEN *** */
void DelVFirst ( List *L, infotype *X ) {
/* I.S. List L tidak kosong */
/* F.S. Elemen pertama list dihapus : nilai info disimpan pada X */
/* dan alamat elemen pertama di-dealokasi */
    address Q;

    Q = First(*L);
    (*X) = Info(Q);

    Q = Next(Q);

    Dealokasi(First(*L));
    First(*L) = Q;
}

void DelVLast ( List *L, infotype *X ) {
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus : nilai info disimpan pada X */
/* dan alamat elemen terakhir di-dealokasi */
    address Q, R;

    Q = First(*L);
    R = Nil;

    while ( Q != Nil ) {
        if ( Next(Q) == Nil ) { break; }
        R = Q;
        Q = Next(Q);
    }
    (*X) = Info(Q);
    Dealokasi(Q);

    if ( R != Nil ) { Next(R) = Nil; }

}

/* ***************** PRIMITIF BERDASARKAN ALAMAT ***************** */
/* *** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT *** */
void InsertFirst ( List *L, address P ) {
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
    address Q;

    Q = First(*L);
    First(*L) = P;
    Next(P) = Q;
}

void InsertAfter ( List *L, address P, address Prec ) {
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/* P sudah dialokasi */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast ( List *L, address P ) {
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    address Q;

    Q = First(*L);
    while ( Q != Nil ) {
        if ( Next(Q) == Nil ) {
            Next(P) = Nil;
            Next(Q) = P;
            break;
        }
        Q = Next(Q);
    }

}


/* *** PENGHAPUSAN SEBUAH ELEMEN *** */

void DeleteFirst ( List *L, address *P ) {
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yang baru adalah suksesor elemen pertama yang lama */
    (*P) = First(*L);

    First(*L) = Next(First(*L));
    Dealokasi(*P);
}

void DeleteP ( List *L, infotype X ) {
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P) = X */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P) = X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
    address Q, R;
    R = Search(*L, X);

    if ( R != Nil ) {
        Q = First(*L);
        while ( Q != Nil ) {
            if ( Next(Q) == R ) { break; }
            Q = Next(Q);
        }

        Next(Q) = Next(R);
        Dealokasi(R);
    }
}

void DeleteLast ( List *L, address *P ) {
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yang lama, jika ada */
    address Q;

    Q = First(*L);

    if ( Next(Q) != Nil ) {
        while ( Next(Next(Q)) != Nil ) {
            Q = Next(Q);
        }
        (*P) = Q;
        Next(Q) = Nil;
    } else {
        (*P) = First(*L);
        First(*L) = Nil;
    }

    Dealokasi(*P);

}

void DeleteAfter ( List *L, address *Pdel, address Prec ) {
/* I.S. List tidak kosong. Prec adalah anggota list L. */
/* F.S. Menghapus Next(Prec) : Pdel adalah alamat elemen list yang dihapus */
    (*Pdel) = Next(Prec);
    Next(Prec) = Next(Next(Prec));
    Dealokasi(*Pdel);
}


/* ***************** PROSES SEMUA ELEMEN LIST ***************** */
void PrintInfo ( List L ) {
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, */
/* Semua info yg disimpan pada elemen list diprint */
/* Jika list kosong, hanya menuliskan "list kosong" */
    address Q;

    if ( !IsListEmpty(L) ) {
        Q = First(L);

        while ( Q != Nil ) {
            printf("%d ", Info(Q));
            Q = Next(Q);
        }

    } else {
        printf("List Kosong");
    }
}

int NbElmt ( List L ) {
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
/* *** Prekondisi untuk Max/Min/rata-rata : List tidak kosong *** */
    address Q;
    int i = 1;

    if ( !IsListEmpty(L) ) {
        Q = First(L);

        while ( Q != Nil ) {
            i++;
            Q = Next(Q);
        }

        return i;
    } else {
        return 0;
    }
}

infotype Max ( List L ) {
/* Mengirimkan nilai Info(P) yang maksimum */
    address Q;
    //infotype Max = 0x80000000; //Haha
    infotype Max = -999;

    if ( !IsListEmpty(L) ) {
        Q = First(L);

        while ( Q != Nil ) {
            if (Info(Q) > Max) { Max = Info(Q); }
            Q = Next(Q);
        }

        return Max;

    } else {
        return 0; //Bener ga?
    }
}

address AdrMax ( List L ) {
/* Mengirimkan address P, dengan Info(P) yang bernilai maksimum */
    return Search(L, Max(L));
}

infotype Min ( List L ) {
/* Mengirimkan nilai Info(P) yang minimum */
    address Q;
    //infotype Min = 0x7FFFFFFF; //Haha
    infotype Min = 99999;

    if ( !IsListEmpty(L) ) {
        Q = First(L);

        while ( Q != Nil ) {
            if (Info(Q) < Min) { Min = Info(Q); }
            Q = Next(Q);
        }

        return Min;

    } else {
        return 0; //Bener ga?
    }
}

address AdrMin ( List L ) {
/* Mengirimkan address P, dengan Info(P) yang bernilai minimum */
    return Search(L, Min(L));
}

float Average ( List L ) {
/* Mengirimkan nilai rata-rata Info(P) */
    address Q;
    infotype total = 0;

    if ( !IsListEmpty(L) ) {
        Q = First(L);

        while ( Q != Nil ) {
            total += Info(Q);
            Q = Next(Q);
        }

        total = total / NbElmt(L);
        return total;

    } else {
        return 0;
    }
}


/* ***************** PROSES TERHADAP LIST ***************** */
void DeleteAll ( List *L ) {
/* Delete semua elemen list dan alamat elemen di-dealokasi */
/* I.S. : L terdefinisi, boleh kosong */
/* F.S. : Jika L tidak kosong, semua elemen list di-delete dan didealokasi */
    address Q;
    Q = Nil;
    while ( !IsListEmpty(*L) ) {
        DeleteFirst(L, &Q);
    }
}

