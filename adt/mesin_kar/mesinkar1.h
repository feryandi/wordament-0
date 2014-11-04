#ifndef MESINKAR1_H
#define MESINKAR1_H
#include "boolean.h"
#ifndef MARK
#define MARK '.'
#endif

void START( char file_name[63], char modes[2] );
/* I.S sembarang
   F.S CC adalah karakter pertama pita
	   Jika CC == MARK, EOP menyala (true)
	   Jika CC != MARK, EOP padam (false) */

void ADV();
/* I.S CC != MARK
   F.S CC adalah karakter berikutnya dari CC pada I.S.
	   Jika CC == MARK, EOP menyala (true) */

boolean EOP();
/* true jika CC == MARK */

#endif
