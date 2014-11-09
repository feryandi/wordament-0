#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include "boolean.h"
#include "sistem.c"
#include "../module/auth.c"

// Color
#define KNRM "\x1B[0m"	// normal
#define KRED "\x1B[31m"	// red
#define KGRN "\x1B[32m"	// green
#define KYEL "\x1B[33m"	// yellow
#define KBLU "\x1B[34m"	// blue
#define KMAG "\x1B[35m"	// magenta
#define KCYN "\x1B[36m"	// cyan
#define KWHT "\x1B[37m"	// white

/* Usage
printf("%sred\n", KRED);
printf("%sgreen\n", KGRN);
printf("%syellow\n", KYEL);
printf("%sblue\n", KBLU);
printf("%smagenta\n", KMAG);
printf("%scyan\n", KCYN);
printf("%swhite\n", KWHT);
printf("%snormal\n", KNRM);
*/

// Kamus Global

// List Prosedur-Fungsi
/* Menu */
void BuatJudul();
void BuatMenu();
void BuatSubJudul();
void LoginScreen();
void RegisterScreen();

/* Board */
void BuatBoard();

#endif // MENU_H_INCLUDED
