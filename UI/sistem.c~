#include "Interface.h"

int gotoxy(int x, int y)
{
    char essq[100];	// String variable to hold the escape sequence
    char xstr[100];	// Strings to hold the x and y coordinates
    char ystr[100];	// Escape sequences must be built with characters
    /*
    ** Convert the screen coordinates to strings
    */
    sprintf(xstr, "%d", x);
    sprintf(ystr, "%d", y);
    /*
    ** Build the escape sequence (vertical move)
    */
    essq[0] = '\0';
    strcat(essq, "\033[");
    strcat(essq, ystr);
    /*
    ** Described in man terminfo as vpa=\E[%p1%dd
    ** Vertical position absolute
    */
    strcat(essq, "d");
    /*
    ** Horizontal move
    ** Horizontal position absolute
    */
    strcat(essq, "\033[");
    strcat(essq, xstr);
    // Described in man terminfo as hpa=\E[%p1%dG
    strcat(essq, "G");
    /*
    ** Execute the escape sequence
    ** This will move the cursor to x, y
    */
    printf("%s", essq);
    return 0;
}

int getch()
{
	int x;	
	system("stty cbreak -echo");
	x = getchar();
	system("stty cooked echo");
	return x;
}

void clrscr()
{
	// Kamus Lokal
	int a,i;
	
	// Algoritma
	gotoxy(0,24);
	for(a = 1; a < 25; a++)
	{
		for(i = 0; i < 80; i++)
		{
			printf(" ");
		}
		printf("\033[1A");
		printf("\r");
	}
	gotoxy(0,0);
}

void HideCursor()
{
	// Kamus Lokal
	
	// Algoritma
	printf("\e[?25l");
}

void ShowCursor()
{
	// Kamus Lokal
	
	// Algoritma
	printf("\e[?25h");
}
