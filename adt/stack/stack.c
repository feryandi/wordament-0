#include "stack.h"
#include <stdio.h>

/* ********* Prototype ********* */
/* *** Konstruktor/Kreator *** */
void CreateEmpty (Stack *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1..MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
{
    TOP(*S) = Nil;
}
/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty (Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return (TOP(S) == Nil);
}
boolean IsFull (Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    return (TOP(S) == MaxEl);
}
/* ********** Operator Dasar Stack ********* */
void Push (Stack *S, infotype X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru, TOP bertambah 1 */
{
    TOP(*S)++;
    PosX(Infotop(*S)) = PosX(X);
    PosY(Infotop(*S)) = PosY(X);
    Info(Infotop(*S)) = Info(X);
}
void Pop (Stack *S, infotype *X)
/* Menghapus X dari Stack S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    PosX(*X) = PosX(Infotop(*S));
    PosY(*X) = PosY(Infotop(*S));
    Info(*X) = Info(Infotop(*S));
    TOP(*S)--;
}
