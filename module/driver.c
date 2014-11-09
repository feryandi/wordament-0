#include "global.h"
#include "save.c"
#include "load.c"
#include "auth.c"
#include "dict.c"

	/* Kamus Global */
    TimeArray test;
    TabKamus K;
    MATRIKS M;
    Queue Q;
    char matx[5][5];
    char word[18];
    int i, n, TotalWords, j, k;
    boolean found;

int main() {

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
    }
*/
    if (registerUser("aaa")) {
        printf("registered");
    } else {
        printf("failed");
    }

    if (loginUser("feryandi")) {
        printf("login auth");
    } else {
        printf("failed");
    }


  /*  for ( i=0; i <= 109013; i++ ) {
        K.TI[i][0] = '\0';
    }


    getDictionary(&K);

    printf("\n");
    scanf("Cari kata: %s", word);

    if ( isOnKamus(word) ) { printf("found"); } else { printf("not found"); }

    printf("%d", realHash("FOUND"));

    Q = getSuggestion(3, "rakarukri");

    TulisQueue(Q);
*/
    return 0;
}
