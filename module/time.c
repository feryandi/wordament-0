#include "global.h"
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>

static struct termios old_termios, new_termios;

/* restore new terminal i/o setting */
void resetTermios() {
	tcsetattr(0,TCSANOW,&old_termios);
}

/* initialize new terminal i/o settings */
void initTermios() {
	tcgetattr(0,&old_termios); //store old terminal
	new_termios = old_termios; // assign to new setting
	new_termios.c_lflag &= ~ICANON; // disable buffer i/o
	new_termios.c_lflag &= ~ECHO; // disable echo mode
	tcsetattr(0,TCSANOW,&new_termios); // use new terminal setting
}

/* detect keyboard press */
int kbhit() {
	struct timeval tv = {0L,0L};
	fd_set fds;
	FD_ZERO(&fds);
	FD_SET(0,&fds);
	return select(1,&fds,NULL,NULL,&tv);
}

/* read 1 character */
/* already defined in UI/sistem.c */

int ngetch()
{
	int x;	
	system("stty cbreak -echo");
	x = getchar();
	system("stty cooked echo");
	return x;
}

char getch()
{
	char x;	
	//system("stty cbreak -echo");
	x = getchar();
	//system("stty cooked echo");
	return x;
}

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


void dummyProd () {
	printf("tock");

	switch (getch()) {
		case 'a': 
			printf("tack");
			gotoxy(20,20);
			break;
		default : 
			printf("tick");
	}
}

/* skeleton program for play */
void Play(double seconds) {
	initTermios(); // initailize new terminal setting to make kbhit() and getch() work
	char cc;
	double i;
	const double TIME_LIMIT = seconds * CLOCKS_PER_SEC;
	clock_t startTime = clock();

	//cc = 1;

	while ((clock() - startTime) <= TIME_LIMIT) {
		i = (TIME_LIMIT - (clock() - startTime)) / CLOCKS_PER_SEC;
		if ( kbhit() ) {
			/* Board program here*/		
		
			//cc = ngetch();
			/*switch (ngetch()) {
				case 'a': printf("tack"); gotoxy(); break;
				default : printf("tick");
			}*/
			dummyProd();

			resetTermios();
			//dummyProd();
			
			printf("tick %f\n", i);
		
			initTermios();
		}
	}
	
	printf("\nTime Up!\n");
	resetTermios(); // restore default terminal setting
}

int main () {
	Play(5);
	return 0;
}

