#include "global.h"

void getBoard (int target, MATRIKS *M) {
    /* Kamus Lokal */
    int i, n;
    char file_dir[90];
    char *board;

    /* Algoritma */
    file_dir[0] = '\0';

	strcat(file_dir, "../res/boards/");

    switch (target) {
    case 0: board = "0"; break;
    case 1: board = "1"; break;
    case 2: board = "2"; break;
    case 3: board = "3"; break;
    case 4: board = "4"; break;
    case 5: board = "5"; break;
    case 6: board = "6"; break;
    case 7: board = "7"; break;
    case 8: board = "8"; break;
    case 9: board = "9"; break;
    default: board = "3";
    }

    strcat(file_dir, board);
    strcat(file_dir, ".txt");

    STARTKATA(file_dir,"r", 2);
    i = 0;
    n = 1;

    while (!EndKata) {

        i++;
        if ( i > 4 ) {
            n++;
            i = 1;
        }

        SetEl(M,n,i,CKata.TabKata[1]);

        ADVKATA(2);
    }

}

Queue getSuggestion ( int target, char user[62] ) {
    /* Kamus Lokal */
    int i;
    char file_dir[90];
    char *board;
    char word[18];
    Queue Q;

    CreateEmptyQ(&Q, 1000);

    /* Algoritma */
    file_dir[0] = '\0';

	strcat(file_dir, "../saves/");

    switch (target) {
    case 0: board = "0"; break;
    case 1: board = "1"; break;
    case 2: board = "2"; break;
    case 3: board = "3"; break;
    case 4: board = "4"; break;
    case 5: board = "5"; break;
    case 6: board = "6"; break;
    case 7: board = "7"; break;
    case 8: board = "8"; break;
    case 9: board = "9"; break;
    default: board = "3";
    }

	if ( target == 99 ) {
        strcat(file_dir, "template");
    } else {
        strcat(file_dir, "board");
        strcat(file_dir, board);
	}

    strcat(file_dir, "/words/");
	strcat(file_dir, user);
    strcat(file_dir, ".txt");

    STARTKATA(file_dir,"r", 1);
    i = 0;

    while (!EndKata) {

        for (i = 1; i <= CKata.Length; i++ ){
            word[i-1] = CKata.TabKata[i];
        }
        word[i-1] = '\0';

        AddQ(&Q, realHash(word));
        printf("s: %d\n", realHash(word));

        ADVKATA(1);
    }

    return Q;

}

void GetSuggestion (char word[18], int target, char user[62]) {
    /* Kamus Lokal */
    int i;
    char file_dir[90];
    char *board;
    char suggest[18];
    boolean partof;

    /* Algoritma */
    file_dir[0] = '\0';

	strcat(file_dir, "../saves/");

    switch (target) {
    case 0: board = "0"; break;
    case 1: board = "1"; break;
    case 2: board = "2"; break;
    case 3: board = "3"; break;
    case 4: board = "4"; break;
    case 5: board = "5"; break;
    case 6: board = "6"; break;
    case 7: board = "7"; break;
    case 8: board = "8"; break;
    case 9: board = "9"; break;
    default: board = "3";
    }

	if ( target == 99 ) {
        strcat(file_dir, "template");
    } else {
        strcat(file_dir, "board");
        strcat(file_dir, board);
	}

    strcat(file_dir, "/words/");
	strcat(file_dir, user);
    strcat(file_dir, ".txt");

    STARTKATA(file_dir,"r", 1);
    i = 0;

    while (!EndKata) {
        partof = true;

        for ( i = 1; i <= strlen(word); i++ ) {
            if ( word[i-1] != CKata.TabKata[i] ) {
                partof = false;
            }
        }

        if ( partof ) {
            for ( i = 1; i <= CKata.Length; i++ ) {
                suggest[i-1] = CKata.TabKata[i];
            }
            suggest[i-1] = '\0';

            EndKata = true;
        } else {
            ADVKATA(1);
        }
    }

    if ( partof ) {
        printf("%s", suggest);
    } else {
        printf("No Suggestion");
    }
}

TimeArray SortByHS ( TimeArray T ) {
    /* Kamus Lokal */
    HScore temp;
    int i, n, x;
    int max;

    /* Algoritma */
    for ( i = 0; i < T.NbElmt; i++ ) {
        max = 0;
        x = -1;

        for ( n = i; n < T.NbElmt; n++ ) {

            if ( T.get[n].s > max ) {
                max = T.get[n].s;
                x = n;
            } else if ( T.get[n].s == max ) {

                if ( T.get[n].w.Y > T.get[x].w.Y ) {
                    max = T.get[n].s;
                    x = n;
                } else {

                    if ( T.get[n].w.M > T.get[x].w.M ) {
                        max = T.get[n].s;
                        x = n;
                    } else {

                        if ( T.get[n].w.D > T.get[x].w.D ) {
                            max = T.get[n].s;
                            x = n;
                        } else {

                            if (JamToDetik(T.get[n].t) < JamToDetik(T.get[x].t)) {
                                max = T.get[n].s;
                                x = n;
                            }

                        }

                    }

                }

            }

        }

        temp = T.get[x];
        T.get[x] = T.get[i];
        T.get[i] = temp;

    }

    return T;
}

TimeArray ListUserHS (int target, char user[62]) {
    /* Kamus Lokal */
    TimeArray temp;
    char file_dir[90];
    int counter;
    int i;
    int buff;
    char *board;

    /* Algoritma */
    file_dir[0] = '\0';

	strcat(file_dir, "../saves/");

    switch (target) {
    case 0: board = "0"; break;
    case 1: board = "1"; break;
    case 2: board = "2"; break;
    case 3: board = "3"; break;
    case 4: board = "4"; break;
    case 5: board = "5"; break;
    case 6: board = "6"; break;
    case 7: board = "7"; break;
    case 8: board = "8"; break;
    case 9: board = "9"; break;
    default: board = "3";
    }

	if ( target == 99 ) {
        strcat(file_dir, "template");
    } else {
        strcat(file_dir, "board");
        strcat(file_dir, board);
	}

    strcat(file_dir, "/highscore/");
	strcat(file_dir, user);
    strcat(file_dir, ".txt");

    STARTKATA(file_dir,"r", 2);
    i = 0;
    counter = 0;

    while (!EndKata) {
        if ( counter == 6 ) {
            counter = 0;
        }

        counter++;
        buff = 0;

        for ( i = 1; i <= CKata.Length; i++ ) {
            buff = (buff * 10) + CKata.TabKata[i] - 48;
        }

        switch (counter) {
        case 1:
            temp.get[temp.NbElmt].s = buff;
            break;
        case 2:
            temp.get[temp.NbElmt].w.D = buff;
            break;
        case 3:
            temp.get[temp.NbElmt].w.M = buff;
            break;
        case 4:
            temp.get[temp.NbElmt].w.Y = buff;
            break;
        case 5:
            temp.get[temp.NbElmt].t.HH = buff;
            break;
        case 6:
            temp.get[temp.NbElmt].t.MM = buff;
            temp.get[temp.NbElmt].t.SS = 00;
            temp.NbElmt += 1;
            break;
        default:
            temp.get[temp.NbElmt].t.SS = 00;
        }

        ADVKATA(2);
    }

    temp = SortByHS(temp);

    return temp;
}
