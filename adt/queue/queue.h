#ifndef queue_H
#define queue_H
#include "boolean.h"
#include <stdlib.h>
#define NilQ 0

/* Definisi elemen dan address */
typedef int infoqueue;
typedef int address; /* indeks tabel */

typedef struct {
    infoqueue *T; /* tabel penyimpan elemen */
    address HEAD; /* alamat penghapusan */
    address TAIL; /* alamat penambahan */
    int MaxElQ; /* max elemen queue */
} Queue;

/* Definisi Queue kosong: HEAD = Nil; TAIL = Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* AKSES (Selektor) ********* */
/* Jika Q adalah Queue, maka akses elemen: */
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxElQ(Q) (Q).MaxElQ

/* ********* Prototype ********* */
boolean IsEmptyQ (Queue Q);
/* Mengirim true jika Q kosong: lihat definisi diatas */

boolean IsFullQ (Queue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */

int NBElmtQ (Queue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong*/


/* ********* Kreator ********* */
void CreateEmptyQ (Queue *Q, int Max);
/* I.S. sembarang */
/* F.S. sebuah Q kosong terbentuk dan salah satu kondisi sbb:*/
/* Jika alokasi berhasil, tabel memori dialokasi berukuran Max*/
/* atau: jika alokasi gagal, Q kosong dengan MaxEl = 0*/
/* Proses : Melakukan alokasi, membuat sebuah Q kosong*/

/* ********* Destruktor ********* */
void DeAlokasiQ (Queue *Q);
/* Proses: Mengmbalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* ********* Primitif Add/Delete ********* */
void AddQ (Queue *Q, infoqueue X);
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" */
/* Jika Tail(Q) = MaxEl + 1 maka geser isi tabel, shg Head(Q) = 1*/

void DelQ (Queue *Q, infoqueue *X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju"; Q mungkin kosong */

void WriteQueue (Queue Q);
#endif // P09_H
