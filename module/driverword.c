#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "global.h"
#include "word.c"
#include "load.c"

TabKamus Dict;
char kata[18];
boolean endK, endGame;

int main ()
{
    // Kamus
    MATRIKS M;
    Stack S;
    int randomint, i, j;
    // Algoritma
    system("Color 30");
    BuatJudul();

    getDictionary(&Dict);

    getch();
    system("cls");
    BuatBoard();
    srand(time(NULL));
    /**Matriks**/
    MakeMATRIKS(&M);
    CreateEmpty(&S);
    getBoard(3, &M);
    /**       **/
    IsiBoard(&M);

    initBoard();

    while ( ( !endK ) && ( !endGame ) ) {
        PointerBoard(M, &S, kata, &endK);

        if ( endK == true ) {
            if ( isOnKamus(kata, Dict) ) {
                printf("%s is in dictionary", kata);
            } else {
                printf("%s is wrong", kata);
            }
        }

        endK = false;
    }



    printf("\n");
    //gotoxy(30,22);
    //TulisMATRIKS(M);
    getch();
    return 0;
}
