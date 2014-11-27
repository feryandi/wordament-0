#include "global.h"
#include "word.c"
//#include "load.c"
#include "save.c"
#include "timer.c"
#include "../UI/Interface.c"

	/* Kamus Global */
    TimeArray test;
    TabKamus K;
    MATRIKS M;
    Queue Q;
	List L;
    char matx[5][5];
    char word[18];
	char user_list[90][63];
    int i, n, TotalWords, j, k;
	addressL A;
    boolean found,end;

int main() {

	clrscr();
	MakeMATRIKS(&M);
	end = false;
	while (!end)
	{
		switch (getch())
		{
			case 'r':
			{
				gotoxy(0,0);
				TulisMATRIKS(M);
				Rotate(&M);
				break;
			}
			case 'z':
			{
				end = true;
			}
		}
	}
	/* Algoritma */
	//saveScore(973,0,"tests");
/*
    saveWord("APYA", 3, "rakarukri");
	saveWord("APYAZ", 3, "rakarukri");


    test = ListUserHS(3, "feryandi");

    printf("- - - - - - - - - - - -\n");
    for ( i = 0; i < test.NbElmt; i++ ) {
        printf("Score: %d (%d/%d/%d %d:%d)\n", test.get[i].s, test.get[i].w.D, test.get[i].w.M, test.get[i].w.Y, test.get[i].t.HH, test.get[i].t.MM);
    }
    printf("- - - - - - - - - - - -\n");

    GetSuggestion("", 3, "rakarukri");


    MakeMATRIKS(&M);

    getBoard(3, &M);

    for ( i = 1; i <= 4; i++ ) {
        for ( n = 1; n <= 4; n++ ) {
            printf("%c", GetElmt(M,i,n));
        }
    }

    if (registerUser("aaa")) {
        printf("registered");
    } else {
        printf("failed");
    }

    if (loginUser("feryandi")) {
        printf("login auth");
    } else {
        printf("failed");
    }*/


  /*  for ( i=0; i <= 109013; i++ ) {
        K.TI[i][0] = '\0';
    }



    printf("\n");
    scanf("Cari kata: %s", word);

    if ( isOnKamus(word) ) { printf("found"); } else { printf("not found"); }

    getDictionary(&K);
    printf("%d", realHash("HAT"));

    getSuggestion(&Q, 1, "tests");

    TulisQueue(Q);


	printf("Score = %d", Map('Q'));
	
    CreateList(&L);
*/
	/*ListAllHS(1, user_list, &L);

	printListHS(user_list, L);

	test = ListToArraySorted(L);

    printf("- - - - - - - - - - - -\n");
    for ( i = 0; i < test.NbElmt; i++ ) {
        printf("%s : %d (%d/%d/%d %d:%d)\n", user_list[test.get[i].id], test.get[i].s, test.get[i].w.D, test.get[i].w.M, test.get[i].w.Y, test.get[i].t.HH, test.get[i].t.MM);
    }
    printf("- - - - - - - - - - - -\n");

/*
	A = NextL(FirstL(L));

	printf("%d", InfoL(A));
	printf("%s", user_list[InfoL(A)]);


	A = FirstL(ChildL(A));
	printf("%d", InfoL(A));
	*/

    return 0;
}
