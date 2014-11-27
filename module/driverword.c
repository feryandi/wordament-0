#include "global.h"
#include "word.c"
//#include "load.c"
#include "save.c"
#include "timer.c"
#include "../UI/Interface.c"

TabKamus K;
Stack S;
MATRIKS M;
SetStr E;
Queue G;
char kata[18];
infotype temp;
infoqueue temp1;
boolean endK, endGame, playing;
int dictordinat;
int sumscore;	
int selectedBoard;

void initGame() {
	// Ke Play Game
	// Title
	clrscr();
	BuatSubJudul();
	// Pembuatan Stack
	CreateEmpty(&S);
	// Pembuatan matriks
	MakeMATRIKS(&M);
	// Pembuatan Set
	MakeEmpty(&E);
	// Mengambil Suggestion
	getSuggestion(&G, selectedBoard, username);
	// Pembuatan UI board
	BuatBoard();
	// Pengambilan template board
	getBoard(selectedBoard, &M);
	// Pengisian UI board dengan template
	IsiBoard(&M);
	// Inisialisasi UI board - matriks
	initBoard();
	//ShowCursor();
	// Cursor board aktif + dict
	endGame = false;

}

/* skeleton program for play */
void Play(double seconds) {
	initTermios(); // initailize new terminal setting to make kbhit() and getch() work
	char cc;
	double i;
	boolean firstTime = true;
	const double TIME_LIMIT = seconds * CLOCKS_PER_SEC / 10;
	//ver. baru TIME_LIMIT = seconds * CLOCKS_PER_SEC;
	clock_t startTime = clock();
	
	initGame();
	dictordinat = 8;
	sumscore = 0;
	//ver. baru ((clock() - startTime) <= TIME_LIMIT * 0.26)
	while ((clock() - startTime) <= TIME_LIMIT) {
		i = (TIME_LIMIT - (clock() - startTime)) / CLOCKS_PER_SEC;
		
		if ( kbhit() ) {
			/* Board program here*/	
			
			if (!firstTime) {
    			PointerBoard(&M, &S, kata, &endK);
			}
			firstTime = false;

			resetTermios();
			
			if ( endK == true )
				{
					if ( isOnKamus(kata) )
					{
            			if(!isFound(E,kata))
            			{
		        			gotoxy(61,12);
		        			printf("                ");
		        			gotoxy(61,12);
		        			printf("%s",kata);
		        			gotoxy(61,14);
		        			printf("                ");
		        			gotoxy(61,14);
		        			printf("is in dictionary");
		        			gotoxy(17,20);
		        			printf("%d", (sumscore += Score(kata)));
		        			
		            		
		            		addFoundWord (&E, kata); 
	   						saveWord(kata, selectedBoard, username);
	   						
	   						if(dictordinat >= 19)
	   						{
	   							dictordinat = 8;
	   							for(repeat = 0; repeat < 11; repeat++)
	   							{
	   								gotoxy(3,dictordinat);
		            				printf("                  ");
		            				dictordinat += 1;
	   							}
	   							dictordinat = 8;
	   						}
	   						if(dictordinat < 19)
	   						{
		            			gotoxy(3,dictordinat);
		            			printf("%d", Score(kata));
	   							gotoxy(7,dictordinat);
	   							printf("%s",kata);
	   							dictordinat += 1;
	   						}
						}
						else
						{
							gotoxy(61,12);
							printf("                ");
							gotoxy(61,12);
							printf("%s", kata);
							gotoxy(61,14);
							printf("                ");
							gotoxy(61,14);
							printf("already found");
						}            		
            		}
            		else
            		{
            			gotoxy(61,12);
            			printf("                ");
            			gotoxy(61,12);
            			printf("%s",kata);
            			gotoxy(61,14);
            			printf("                ");
            			gotoxy(69,14);
            			printf("is wrong");
            		}
        		}
        	endK = false;

			if ( isFound(E, K.TI[InfoHead(G)]) ) {
				DelQ(&G, &temp1);
			}

			if (!IsEmptyQ(G)) {
			gotoxy(61,20);
            printf("                ");
            gotoxy(61,20);
			printf("%s", K.TI[InfoHead(G)]); }

			//printf("%d", InfoHead(G));

			initTermios();

		}

		gotoxy(absis,ordinat);
		
		
		gotoxy(73,8);
		printf("%d ", (int)(TIME_LIMIT/100000 - ((clock() - startTime)/100000)));
		// ver baru printf("%d ", (int)((TIME_LIMIT - ( (clock() - startTime) / 0.26 )) / CLOCKS_PER_SEC));

	}
	
	gotoxy(30,22);
	printf("                                  ");
	gotoxy(30,23);
	printf("                                  ");
	gotoxy(36,22);
	printf("Time Up !\n");
	saveScore(sumscore, selectedBoard, username);
	getch();
	gotoxy(26,23);
	printf("Press enter to see the result\n");
	char enter = 0;
	while (enter != '\r' && enter != '\n')
	{
		enter = getch();
	}
	ResultBoard();
	
	resetTermios(); // restore default terminal setting
}

int main ()
{

	// Pengaktifan dict
	getDictionary(&K);

	//Welcome();

	while (!quitGame) {

		while ( (!logged) && (!quitGame) ) {
			MainMenu();	
		}

		while ( (logged) && (!playing) ) {
			UserMenu();
			selectedBoard = numboard;
		}

		if ( (logged) && (playing) ) {

			HideCursor();
			Play(1);
			ShowCursor();

			playing = false;
		}

	}

    srand(time(NULL));

    getch();
    gotoxy(0,20);
    printf("                                                      \r");
    ShowCursor();
    return 0;
}
