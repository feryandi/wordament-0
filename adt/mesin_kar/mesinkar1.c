#ifndef MESINKAR1_C
#define MESINKAR1_C
#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include "boolean.h"
#include "mesinkar1.h"

/* definisi states */
char CC;

/* definisi pita */
//static char Pita_karakter[63] = "pitakar.txt";
static FILE * FILEKU;
static int retval;

void START( char file_name[63], char modes[2] ) {
/* I.S sembarang
   F.S CC adalah karakter pertama pita
	   Jika CC == MARK, EOP menyala (true)
	   Jika CC != MARK, EOP padam (false) */

	FILEKU = fopen(file_name,modes);
    retval = fscanf(FILEKU,"%c",&CC);
}

void ADV() {
/* I.S CC != MARK
   F.S CC adalah karakter berikutnya dari CC pada I.S.
	   Jika CC == MARK, EOP menyala (true) */
	retval = fscanf(FILEKU,"%c",&CC);
	if ( CC == MARK ) {
		fclose(FILEKU);
	}
}

boolean EOP() {
/* true jika CC == MARK */
	return ( CC == MARK );
}

#endif
