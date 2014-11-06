#include "global.h"

boolean searchWord (TabStr X, char word[18]) {
    /* Kamus Lokal */
    int i, n;
    boolean found, temp;

    /* Algoritma */
    found = false;
    i = 0;
    while ( ( i<X.NbElmt ) && (!found) ) {
        temp = true;
        n = 0;

        if ( X.TI[i].Length == strlen(word) ) {
            while ( ( n < X.TI[i].Length ) && (temp) ) {
                if ( X.TI[i].TabKata[n] != word[n] ) {
                    n = X.TI[i].Length + 1;
                    temp = false;
                }
                n++;
            }
        } else {
            temp = false;
        }

        if ( temp ) {
            found = true;
        }

        i++;
    }

    return found;
}

void save(char word[18], int target, char user[62], int t) {
	/* Kamus Lokal */
    FILE *file_save;

    TabStr X;
    X.NbElmt = 0;

    char *board;
    char c[1];
    char file_dir[90];
    int i, n;
    boolean granted;

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

    if ( t == 1 ) {
        strcat(file_dir, "/words/");
    } else {
        strcat(file_dir, "/highscore/");
    }
	strcat(file_dir, user);
    strcat(file_dir, ".txt");

    STARTKATA(file_dir,"r",1);
    i = 0;
    n = 0;

    while (!EndKata) {
        for ( i = 1; i <= CKata.Length; i++ ) {
            X.TI[n].TabKata[i-1] = CKata.TabKata[i];
        }
        X.TI[n].Length = CKata.Length;

        X.NbElmt += 1;

        n++;
        ADVKATA(1);
    }

    // Make this void possible to other custom data type
    if ( t == 1 ) {
        if ( !searchWord(X, word) ) {
            granted = true;
        } else {
            granted = false;
        }
    } else {
        granted = true;
    }

    if ( granted ) {

        for ( n=0; n < strlen(word); n++ ) {
            X.TI[X.NbElmt].TabKata[n] = word[n];
        }
        X.TI[X.NbElmt].TabKata[n] = '\0';
        X.TI[X.NbElmt].Length = strlen(word);
        X.NbElmt = X.NbElmt + 1;

        file_save = fopen(file_dir, "w+");

        for ( i=0 ; i < X.NbElmt; i++ ) {
            for ( n = 0; n < X.TI[i].Length; n++ ) {
                fprintf(file_save, "%c", X.TI[i].TabKata[n]);
            }
            fprintf(file_save, "\n");
        }
        printf("procced");

        fprintf(file_save, ".");
        fclose(file_save);

    } else {

        printf("cannot procced..\n");

    }
}

void saveWord(char word[18], int target, char user[62]) {
    save(word, target, user, 1);
}

void saveScore(int score, int target, char user[62]) {
    char time_now[16];
    char buff[12];
    char word[20];

	time_now[0] = '\0';
	buff[0] = '\0';
	word[0] = '\0';

    time_t t = time(NULL);
    struct tm waktu = *localtime(&t);


    sprintf(buff, "%d", waktu.tm_mday);
    strcat(time_now, buff);

    sprintf(buff, " %d", waktu.tm_mon + 1);
    strcat(time_now, buff);

    sprintf(buff, " %d", waktu.tm_year + 1900);
    strcat(time_now, buff);

    sprintf(buff, " %d", waktu.tm_hour);
    strcat(time_now, buff);

    sprintf(buff, " %d", waktu.tm_min);
    strcat(time_now, buff);

    sprintf(buff, "%d ", score);
    strcat(word, buff);
    strcat(word, time_now);

    save(word, target, user, 2);
}

