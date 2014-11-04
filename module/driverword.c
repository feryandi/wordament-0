#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "global.h"
#include "word.c"

int main ()
{
    // Kamus
    MATRIKS M;
    Stack S;
    char kata[16];
    int randomint, i, j;
    // Algoritma
    system("Color 30");
    BuatJudul();
    getch();
    system("cls");
    BuatBoard();
    srand(time(NULL));
    /**Matriks**/
    MakeMATRIKS(&M);
    CreateEmpty(&S);
    for(i=1;i<=4;i++)
    {
        for(j=1;j<=4;j++)
        {
            randomint = rand()%26+1;
            SetEl(&M, i, j, randomint+64);
        }
    }
    /**       **/
    IsiBoard(&M);
    PointerBoard(M, &S, &kata);
    printf("\n");
    //gotoxy(30,22);
    //TulisMATRIKS(M);
    getch();
    return 0;
}
