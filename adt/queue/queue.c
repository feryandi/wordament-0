#include <stdlib.h>
#include "boolean.h"
#include "queue.h"

/* ********* Prototype ********* */
boolean IsEmptyQ (Queue Q) {
/* Mengirim true jika Q kosong: lihat definisi diatas */
    return ((Head(Q)==NilQ) && (Tail(Q)==NilQ));
}

boolean IsFullQ (Queue Q) {
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxElQ */
    if ( Head(Q) == 1 ) {
        return ( Tail(Q) == MaxElQ(Q) );
    } else {
        return ( Tail(Q) == ( Head(Q) - 1 ) );
    }
}

int NBElmtQ (Queue Q) {
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong*/
    int temp;

    if ( IsFullQ(Q) ) {
        return MaxElQ(Q);
    } else if ( IsEmptyQ(Q) ) {
        return 0;
    } else {
        temp = ( Tail(Q) - Head(Q) + 1 );
        if ( temp <= 0 ) {
            return ( MaxElQ(Q) + temp ); //bisa juga full!
        } else {
            return temp;
        }
    }
}

/* ********* Kreator ********* */
void CreateEmptyQ (Queue *Q, int Max) {
/* I.S. sembarang */
/* F.S. sebuah Q kosong terbentuk dan salah satu kondisi sbb:*/
/* Jika alokasi berhasil, tabel memori dialokasi berukuran Max*/
/* atau: jika alokasi gagal, Q kosong dengan MaxElQ = 0*/
/* Proses : Melakukan alokasi, membuat sebuah Q kosong*/
    (*Q).T = (infoqueue *) malloc ((Max+1) * sizeof(infoqueue));
    if ((*Q).T != NULL) {
        MaxElQ(*Q) = Max;
        Head(*Q) = NilQ;
        Tail(*Q) = NilQ;
    } else { /*alokasi gagal*/
        MaxElQ(*Q) = NilQ;
    }
}

/* ********* Destruktor ********* */
void DeAlokasiQ (Queue *Q) {
/* Proses: Mengmbalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxElQ(Q) diset 0 */
    MaxElQ(*Q) = NilQ;
    free((*Q).T);
}

/* ********* Primitif Add/Delete ********* */
void AddQ (Queue *Q, infoqueue X) {
/* Proses : Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju". */
/* Jika TAIL baru = MaxElQ + 1, maka TAIL diset = 1.*/
    if ( IsEmptyQ(*Q) ) {
        Head(*Q) = 1;
        Tail(*Q) = 1;
        InfoHead(*Q) = X;
        InfoTail(*Q) = X;
    } else if ( !IsFullQ(*Q)) { /*ngga kosong dan ngga penuh*/
        if ( Tail(*Q) == MaxElQ(*Q) ) { /*kalo tailnya udah di max*/
            Tail(*Q) = 1;
            InfoTail(*Q) = X;
        } else { /*kalo tailnya ngga di max (ujung)*/
            Tail(*Q) += 1;
            InfoTail(*Q) = X;
        }
    } else {
        printf(":: Tabel Penuh ::");
    }
}

void DelQ (Queue *Q, infoqueue *X) {
/* Proses : Menghapus elemen pertama pada Q dengan aturan FIFO */
/* I.S. Q tidak kosong */
/* F.S. X = NilQai elemen HEAD pada I.S.,
            Jika Queue masih isi : HEAD "maju".
            Jika HEAD baru menjadi MaxElQ + 1, maka HEAD diset = 1;
            Jika Queue menjadi kosong, HEAD = TAIL = NilQ. */
    if ( !IsEmptyQ(*Q) ) {
        (*X) = InfoHead(*Q);
        if ( Head(*Q) == MaxElQ(*Q) ) { /*kepalanya ada di ujung*/
            Head(*Q) = 1;
        } else {
            Head(*Q) += 1;
        }
    } else {
        printf(":: Tabel Kosong ::");
    }
}

void WriteQueue (Queue Q) {
    int i;
    for ( i = Head(Q); i != Tail(Q); i++ ) {
        if ( i > MaxElQ(Q) ) { i = 1; }
        printf("%d ", Q.T[i]);
    }
    if ( Head(Q) != Tail(Q) ) {
        printf("%d", InfoTail(Q));
    }
}

void TulisQueue (Queue Q) {
    infoqueue Y;
    int i, initHead, initTail;

    initHead = Head(Q);
    initTail = Tail(Q);

    for ( i = initHead; i != initTail; i++ ) {
        if ( i > MaxElQ(Q) ) { i = 1; }
        printf("%d", InfoHead(Q));
        DelQ(&Q, &Y);
        AddQ(&Q, Y);
    }
    if ( initHead != initTail ) {
        printf("%d", InfoHead(Q));
        DelQ(&Q, &Y);
        AddQ(&Q, Y);
    }
}
