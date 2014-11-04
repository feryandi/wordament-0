#include <stdio.h>
#include "boolean.h"
#include "mesinkata.h"
#include "mesinkar1.c"

/* Kamus Global */
extern char CC;

/* **** Primitif-Primitif Mesin Kata **** */
void Ignore_Blank(int type) {
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
   if ( type == 1 ){
        while ( ( CC == BLANK ) && ( CC != MARK ) ) {
            ADV();
        }
   } else {
        while ( ( ( CC == BLANK2 ) || ( CC == BLANK ) ) && ( CC != MARK ) ) {
            ADV();
        }
   }
}

void STARTKATA( char file_name[63], char modes[2], int type ) {
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = Mark;
   atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
   CC karakter pertama sesudah karakter terakhir kata */
	START(file_name, modes);
	Ignore_Blank(type);

    if (CC == MARK) {
        EndKata = true;
    } else {
        EndKata = false;
        SalinKata(type);
    }
}

void ADVKATA(int type) {
/* I.S. : EndKata = false; CC adalah karakter sesudah karakter terakhir
   dari kata yg sudah diakuisisi */
/* F.S. : Jika CC = MARK, maka EndKata = true
   atau EndKata = false, CKata adalah kata terakhir yang sudah diakuisisi;
   CC karakter pertama sesudah karakter terakhir kata */

	Ignore_Blank(type);

    if ( CC == MARK ) {
        EndKata = true;
    } else {
        EndKata = false;
        SalinKata(type);
    }
}

void SalinKata(int type) {
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi, jika karakternya melebihi
   NMax, sisa "kata" dibuang; CC = BLANK atau CC = MARK; CC adalah
   karakter sesudah karakter terakhir yang diakuisisi */
    int i;
	i = 1;

    for (;;) {
        CKata.TabKata[i] = CC;
        ADV();
        if ( type == 1 ) {
            if ((CC == MARK) || (CC == BLANK)) {
                break;
            } else {
                i++;
            }
        } else {
            if ((CC == MARK) || (CC == BLANK) || ( CC == BLANK2 )) {
                break;
            } else {
                i++;
            }
        }
    }
	CKata.Length = i;
}

/* **** Operasi Lain **** */
boolean IsKataSama (Kata K1, Kata K2) {
/* Mengembalikan true jika K1 = K2; dua kata dikatakan sama jika panjangnya sama dan
urutan karakter yang menyusun kata juga sama */
	int i;
	boolean sama;

	sama = true;

	if ( K1.Length == K2.Length ) {
		for ( i = 1; i <= K1.Length; i++ ) {
			if ( K1.TabKata[i] != K2.TabKata[i] ) {
				sama == false;
			}
		}
	} else {
		sama = false;
	}

	return sama;
}
