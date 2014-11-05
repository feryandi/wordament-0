#include "global.h"

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

        return true;

    } else {

        return false;

    }
}


