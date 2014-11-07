#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "global.h"
#include "dict.c"

/* Kamus Global */
extern boolean endGame;
int absis,ordinat,simpanabsis,simpanordinat, count;
boolean aktif, discovered[5][5];

COORD coord= {0,0}; // this is global variable
//center of axis is set to the top left corner of the screen

void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void BuatJudul()
{
    // Kamus Lokal
    int a;

    // Algoritma
    a = 0;
    ordinat = 3;

    gotoxy(35,20);
    printf("ALPHA 0.1");

    while(a < 13)
    {
        gotoxy(30,ordinat);
        printf("|     |     |     |");
        a += 1;
        ordinat += 1;
    }
    a = 0;
    ordinat = 3;
    while (a < 4)
    {
        gotoxy(30,ordinat);
        printf("-------------------");
        a +=1;
        ordinat += 4;
    }

    /*--*/
    gotoxy(33,5); printf("W");
    gotoxy(39,5); printf("O");
    gotoxy(45,5); printf("R");
    gotoxy(33,9); printf("N");
    gotoxy(39,9); printf("T");
    gotoxy(45,9); printf("D");
    gotoxy(33,13); printf("E");
    gotoxy(39,13); printf("M");
    gotoxy(45,13); printf("A");
}

void BuatBoard()
{
    // Kamus Lokal
    int a;

    // Algoritma
    a = 0;
    ordinat = 4;

    /*--*/
    while(a < 16)
    {
        gotoxy(27,ordinat);
        printf("|     |     |     |     |");
        a += 1;
        ordinat += 1;
    }
    a = 0;
    ordinat = 4;
    while (a < 5)
    {
        gotoxy(27,ordinat);
        printf("-------------------------");
        a +=1;
        ordinat += 4;
    }
}

void IsiBoard(MATRIKS *M)
{
    // Kamus Lokal
    int a,x,y,i,j;

    // Algoritma
    a = 0;
    x = 30;
    y = 6;
    i = 1;
    j = 1;
    while(a < 4)
    {
        while(x <= 48)
        {
            gotoxy(x,y);
            printf("%c",GetElmt(*M,i,j));
            x += 6;
            j += 1;
        }
        x = 30;
        j = 1;
        y += 4;
        i += 1;
        a += 1;
    }
}

void initBoard () {
    int i, j;

    count = 0;
    absis = 36;
    ordinat = 10;
    for (i=1;i<=4;i++)
        for (j=1;j<=4;j++)
            discovered[i][j] = false;

}

void PointerBoard(MATRIKS M, Stack *S, char *kata, boolean *endK)
{
    // Kamus Lokal
    int i, j;
    // Algoritma
    gotoxy(absis,ordinat);


        switch(getch())
        {
        case 'q':
            {
                if ((absis >= 36)&&(ordinat >= 10))
                {
                    absis -= 6;
                    ordinat -= 4;
                    gotoxy(absis,ordinat);
                    if (aktif == true)
                        SimbolAktif(M, S);
                }
                break;
            }
        case 'w':
            {
                if (ordinat >= 10)
                {
                    ordinat -= 4;
                    gotoxy(absis,ordinat);
                    if (aktif == true)
                        SimbolAktif(M, S);
                }
                break;
            }
        case 'e':
            {
                if ((absis <= 42)&&(ordinat >= 10))
                {
                    absis += 6;
                    ordinat -= 4;
                    gotoxy(absis,ordinat);
                    if (aktif == true)
                        SimbolAktif(M, S);
                }
                break;
            }
        case 'a':
            {
                if (absis >= 36)
                {
                    absis -= 6;
                    gotoxy(absis,ordinat);
                    if (aktif == true)
                        SimbolAktif(M, S);
                }
                break;
            }
        case 'd':
            {
                if (absis <= 42)
                {
                    absis += 6;
                    gotoxy(absis,ordinat);
                    if (aktif == true)
                        SimbolAktif(M, S);
                }
                break;
            }
        case 'z':
            {
                if ((absis >= 36)&&(ordinat <= 14))
                {
                    absis -= 6;
                    ordinat += 4;
                    gotoxy(absis,ordinat);
                    if (aktif == true)
                        SimbolAktif(M, S);
                }
                break;
            }
        case 'x':
            {
                if (ordinat <= 14)
                {
                    ordinat += 4;
                    gotoxy(absis,ordinat);
                    if (aktif == true)
                        SimbolAktif(M, S);
                }
                break;
            }
        case 'c':
            {
                if ((absis <= 42)&&(ordinat <= 14))
                {
                    absis += 6;
                    ordinat += 4;
                    gotoxy(absis,ordinat);
                    if (aktif == true)
                        SimbolAktif(M, S);
                }
                break;
            }
        case 's':
            {
                simpanabsis = absis;
                simpanordinat = ordinat;
                if (aktif == false)
                {
                    SimbolAktif(M, S);
                    aktif = true;
                }
                else
                    EndWord(S, (kata), endK);
                break;
            }
        case 'l':
            {
                gotoxy(30,22);
                endGame = true;
                printf("GAME ENDS");

                break;
            }
        default:
                gotoxy(30,22);
            printf("doesn't recognized the input");
        }

}

void SimbolAktif(MATRIKS M, Stack *S)
{
    // Kamus Lokal
    infotype K;

    // Algoritma
    if (discovered[(ordinat-2)/4][(absis-24)/6])
    {

        while ((PosX(Infotop(*S)) != absis) || (PosY(Infotop(*S)) != ordinat))
        {
            HapusSimbol(PosX(Infotop(*S)), PosY(Infotop(*S)));
            discovered[(PosY(Infotop(*S))-2)/4][(PosX(Infotop(*S))-24)/6] = false;
            Pop(S, &K);
        }
        absis = PosX(Infotop(*S));
        ordinat = PosY(Infotop(*S));
        gotoxy(absis, ordinat);
    }
    else
    {
        gotoxy(absis-1,ordinat);
        printf("[");
        gotoxy(absis+1,ordinat);
        printf("]");
        gotoxy(absis,ordinat);
        PosX(K) = absis;
        PosY(K) = ordinat;
        Info(K) = GetElmt(M, (ordinat-2)/4, (absis-24)/6);
        Push(S, K);
        //gotoxy(30, 24 + count);
        //printf("%d %d %c", PosX(Infotop(*S)), PosY(Infotop(*S)), Info(Infotop(*S)));
        gotoxy(absis,ordinat);
        discovered[(ordinat-2)/4][(absis-24)/6] = true;
        count++;
    }
}

void HapusSimbol(int x, int y)
{
    // Kamus Lokal

    // Algoritma
    gotoxy(x-1,y);
    printf(" ");
    gotoxy(x+1,y);
    printf(" ");
    gotoxy(x,y);
}

void EndWord(Stack *S, char kata[18], boolean *endK)
{
    // Kamus Lokal
    infotype K;
    int i, j;

    // Algoritma
    i = TOP(*S);
    aktif = false;
    while (IsEmpty(*S) == false)
    {
        Pop(S, &K);
        (kata)[TOP(*S)] = Info(K);
        HapusSimbol(PosX(K), PosY(K));
    }
    (kata)[i] = '\0';

    absis = PosX(K);
    ordinat = PosY(K);
    for (i=1;i<=4;i++) {
        for (j=1;j<=4;j++) {
            discovered[i][j] = false;
        }
    }

    gotoxy(30,22);
    printf("                           ");
    gotoxy(30,22);

    (*endK) = true;
}

