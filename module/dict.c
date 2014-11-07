#include "global.h"

#define prime 109013


int getHash ( int multi, char word[18] ) {
    int n, h, a;

    n = 0;
    for ( h = 1; h <= strlen(word); h++ ) {
        //HASH FUNCTION HERE

        if ( h == strlen(word) ) {
            n *= word[0] + (h * (word[h-1] - 64));
        } else {
            n += h * (word[h-1] - 64);
        }

    }

    n *= strlen(word);
    a = ( n + ( multi * multi ) )%prime ;

    if ( a > prime ) {
        a = a - prime;
    }

    return a;

}

boolean isOnKamus (char word[18]) {
    int i, j, k;
    boolean found;

    i = 0;
    found = false;

    while ( (i <= 12966) && (!found) ) {
        j = getHash(i,word);

        found = true;
        k = 0;
        while ( (found) && ( k <= strlen(word) )) {
            if ( word[k] != K.TI[j][k] ) {
                found = false;
            }

            k++;
        }

        i++;
    }

    return found;
}

int realHash (char word[18]) {
    int i, j, k;
    boolean found;

    i = 0;
    found = false;

    while ( (i <= 12966) && (!found) ) {
        j = getHash(i,word);

        found = true;
        k = 0;
        while ( (found) && ( k <= strlen(word) )) {
            if ( word[k] != K.TI[j][k] ) {
                found = false;
            }

            k++;
        }

        i++;
    }

    if (found) { return j; } else { return 0; }
}


void getDictionary(TabKamus (*T)) {
	/* Kamus Lokal */
    FILE *file_save;

    (*T).NbElmt = 0;

    char file_dir[90];
    int i, n, h, a, s;
    boolean granted;

	/* Algoritma */
    file_dir[0] = '\0';

	strcat(file_dir, "../res/Dictionary.txt");

    STARTKATA(file_dir,"r",1);
    i = 0;
    n = 0;


    while ( (!EndKata) ) {

        // HASH FUNCTION

            n = 0;
            for ( h = 1; h <= CKata.Length; h++ ) {

                if ( h == CKata.Length ) {
                    n *= CKata.TabKata[1] + (h * (CKata.TabKata[h] - 64));
                } else {
                    n += h * (CKata.TabKata[h] - 64);
                }

            }

            n *= CKata.Length;
            a = (n%prime);

            // COLISION
            s = n;
            h = 1;

            while ( (*T).TI[a][0] != '\0' ) {
                a = ( s + ( h * h ) )%prime ;

                if ( a > prime ) {
                    a = a - prime;
                }
                h++;
            }


        // HASH FUNCTION

        for ( i = 1; i <= CKata.Length; i++ ) {
            (*T).TI[a][i-1] = CKata.TabKata[i];
        }
        (*T).TI[a][i-1] = '\0';

        (*T).NbElmt += 1;


        ADVKATA(1);

    }

}
