#include "global.h"
#include "word.c"
#include "load.c"
#include "../UI/Interface.c"

TabKamus K;
char kata[18];
boolean endK, endGame;
boolean logged;

int main ()
{
    HideCursor();
	logged = false;
    // Kamus
    MATRIKS M;
    Stack S;
    int randomint, i, j;
    // Algoritma

	while (!logged) {
  		clrscr();
		BuatJudul();
		BuatMenu();
	}

    getDictionary(&K);

    getch();
	clrscr();
	
    BuatBoard();
    //srand(time(NULL));
    /**Matriks**/
    MakeMATRIKS(&M);
    CreateEmpty(&S);
    getBoard(3, &M);
    /**       **/
    IsiBoard(&M);
    ShowCursor();

    initBoard();

    while ( ( !endK ) && ( !endGame ) ) {
        PointerBoard(M, &S, kata, &endK);

        if ( endK == true ) {
            printf("%s", kata);
    		gotoxy(4,7);
    		printf("                    ");
    		gotoxy(4,7);

            if ( isOnKamus(kata) ) {
    			printf("is on Dictionary!");
            } else {
    			printf("is not valid!");
            }
        }

        endK = false;
    }



    printf("\n");
    getch();
    gotoxy(0,22);
    return 0;
}
