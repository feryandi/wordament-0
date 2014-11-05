#include "global.h"
#include "save.c"
#include "load.c"
#include "auth.c"

int main() {
	/* Kamus Lokal */
     TimeArray test;
    int i, n;
    char matx[5][5];
    MATRIKS M;

	/* Algoritma */
/*
    saveWord("APYA", 3, "rakarukri");
	saveWord("APYAZ", 3, "rakarukri");
	saveScore(973,3,"feryandi");


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
    }*/

    if (registerUser("rakarukri")) {
        printf("registered");
    } else {
        printf("failed");
    }

    if (loginUser("cliff")) {
        printf("login auth");
    } else {
        printf("failed");
    }


    return 0;
}
