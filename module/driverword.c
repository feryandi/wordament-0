#include "global.h"
#include "word.c"
#include "load.c"
#include "../UI/Interface.c"

//TabKamus K;
//char kata[18];
//boolean endK, endGame;

int main ()
{
    HideCursor();
    clrscr();
    BuatJudul();
    BuatMenu();	
    srand(time(NULL));

    getch();
    gotoxy(0,22);
    printf("                                                      \r");
    ShowCursor();
    return 0;
}
