#include "global.h"

char username[30];
boolean logged;

boolean searchUser (TabStr X, char word[30]) {
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
				//printf("%c", word[n]);
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

void makeFileUser(char word[30]) {

    FILE *file_save;
    char file_dir[90];
    char file_fdir[40];
    int i;
    char *board;

	/* Algoritma */
    file_dir[0] = '\0';

	i = 0;

    for ( i = 0; i <= 9; i++ ) {
        file_dir[0] = '\0';

        strcat(file_dir, "../saves/board");

		switch (i) {
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
		default: board = "0";
		}

        strcat(file_dir, board);
        strcat(file_dir, "/highscore/");
        strcat(file_dir, word);
        strcat(file_dir, ".txt");

        file_save = fopen(file_dir, "w+");
            fprintf(file_save, ".");
        fclose(file_save);

    }

    for ( i = 0; i <= 9; i++ ) {
        file_dir[0] = '\0';

        strcat(file_dir, "../saves/board");

		switch (i) {
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
		default: board = "0";
		}

        strcat(file_dir, board);
        strcat(file_dir, "/words/");
        strcat(file_dir, word);
        strcat(file_dir, ".txt");

        file_save = fopen(file_dir, "w+");
            fprintf(file_save, ".");
        fclose(file_save);

    }
}

boolean registerUser(char word[30]) {
	/* Kamus Lokal */
    FILE *file_save;

    TabStr X;
    X.NbElmt = 0;

    char file_dir[90];
    int i, n;
    boolean granted;

	/* Algoritma */
    file_dir[0] = '\0';

	strcat(file_dir, "../saves/userlist.txt");

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

    // Check if the username is available
    if ( !searchUser(X, word) ) {
        granted = true;
    } else {
        granted = false;
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

        fprintf(file_save, ".");
        fclose(file_save);

        makeFileUser(word);
        return true;

    } else {

        return false;

    }
}

boolean loginUser(char word[30]) {
    /* Kamus Lokal */
    TabStr X;
    X.NbElmt = 0;

    char file_dir[90];
    int i, n;
    boolean granted;

	/* Algoritma */
    file_dir[0] = '\0';

	strcat(file_dir, "../saves/userlist.txt");

    STARTKATA(file_dir,"r",1);
    i = 0;
    n = 0;

    while (!EndKata) {
        for ( i = 1; i <= CKata.Length; i++ ) {
            X.TI[n].TabKata[i-1] = CKata.TabKata[i];
        }
        X.TI[n].Length = CKata.Length;

        X.NbElmt += 1;

		//printf("%s", X.TI[n].TabKata);

        n++;
        ADVKATA(1);
	}

    // Check if the username is available
    if ( searchUser(X, word) ) {
        granted = true;
    } else {
        granted = false;
    }


    if ( granted ) {
		
		username[0] = '\0';
		strcat(username, word);
		logged = true;
        return true;

    } else {

        return false;

    }
}


