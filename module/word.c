#include "global.h"
#include "dict.c"

/* Kamus Global */
extern boolean endGame;
int absis,ordinat,simpanabsis,simpanordinat, count,absisboard,ordinatboard;
boolean aktif, discovered[5][5];

void initBoard ()
{
    // Kamus Lokal
    int i, j;

	// Algoritma
    count = 0;
    absis = 28;
    ordinat = 7;
    for (i=1;i<=4;i++)
    {
        for (j=1;j<=4;j++)
    	{
            discovered[i][j] = false;
		}
	}
}

void PointerBoard(MATRIKS *M, Stack *S, char *kata, boolean *endK)
{
    // Kamus Lokal
    int i, j, score;
    char cc;

    // Algoritma
    gotoxy(absis,ordinat);


    switch(getch())
    {
    	case 'q':
    		{
				if((absis >= 36)&&(ordinat >= 11))
		    		{
						if(!aktif)
						{
							HapusSimbol(absis,ordinat);
						}
						absis -= 8;
						ordinat -= 4;
						gotoxy(absis,ordinat);
						if(!aktif)
                    {
                    	PointerAktif();
                    }
						if (aktif == true)
						{
							SimbolAktif((*M), S);
		            	}
		            }
				break;
			}
		case 'w':
			{
				if (ordinat >= 11)
				{
					if(!aktif)
						{
							HapusSimbol(absis,ordinat);
						}
					ordinat -= 4;
					gotoxy(absis,ordinat);
					if(!aktif)
                    {
                    	PointerAktif();
                    }
					if (aktif == true)
					{
						SimbolAktif((*M), S);
					}
				}
				break;
			}
		case 'e':
			{
				if ((absis <= 44)&&(ordinat >= 10))
				{
					if(!aktif)
						{
							HapusSimbol(absis,ordinat);
						}
					absis += 8;
					ordinat -= 4;
					gotoxy(absis,ordinat);
					if(!aktif)
                    {
                    	PointerAktif();
                    }
					if (aktif == true)
					{
						SimbolAktif((*M), S);
					}
				}
				break;
			}
        case 'a':
            {
                if (absis >= 36)
                {
                    if(!aktif)
						{
							HapusSimbol(absis,ordinat);
						}
                    absis -= 8;
                    gotoxy(absis,ordinat);
                    if(!aktif)
                    {
                    	PointerAktif();
                    }
                    if (aktif == true)
                    {
                        SimbolAktif((*M), S);
                	}
                }
                break;
            }
        case 'd':
            {
                if (absis <= 44)
                {
                    if(!aktif)
						{
							HapusSimbol(absis,ordinat);
						}
                    absis += 8;
                    gotoxy(absis,ordinat);
                    if(!aktif)
                    {
                    	PointerAktif();
                    }
                    if (aktif == true)
                    {
                        SimbolAktif((*M), S);
                	}
                }
                break;
            }
        case 'z':
            {
                if ((absis >= 36)&&(ordinat <= 15))
                {
                    if(!aktif)
						{
							HapusSimbol(absis,ordinat);
						}
                    absis -= 8;
                    ordinat += 4;
                    gotoxy(absis,ordinat);
                    if(!aktif)
                    {
                    	PointerAktif();
                    }
                    if (aktif == true)
                    {
                        SimbolAktif((*M), S);
                	}
                }
                break;
            }
        case 'x':
            {
                if (ordinat <= 15)
                {
                    if(!aktif)
						{
							HapusSimbol(absis,ordinat);
						}
                    ordinat += 4;
                    gotoxy(absis,ordinat);
                    if(!aktif)
                    {
                    	PointerAktif();
                    }
                    if (aktif == true)
                    {
                        SimbolAktif((*M), S);
                	}
                }
                break;
            }
        case 'c':
            {
                if ((absis <= 44)&&(ordinat <= 15))
                {
                    if(!aktif)
						{
							HapusSimbol(absis,ordinat);
						}
                    absis += 8;
                    ordinat += 4;
                    gotoxy(absis,ordinat);
                    if(!aktif)
                    {
                    	PointerAktif();
                    }
                    if (aktif == true)
                    {
                        SimbolAktif((*M), S);
                	}
                }
                break;
            }
		case 'r':
            {
            	if (aktif == false)
            	{
		        	Rotate(M);
		        	gotoxy(61,12);
		        	printf("                ");
		        	gotoxy(61,12);
		        	printf("%s",kata);
		        	gotoxy(61,14);
		        	printf("                ");
		        	BuatBoard();
		        	IsiBoard(M);
					initBoard();
            	}
            	break;
            }            
        case 's':
            {
                simpanabsis = absis;
                simpanordinat = ordinat;
                if (aktif == false)
                {
                    SimbolAktif((*M), S);
                    aktif = true;
                }
                else
                {
                    EndWord(S, (kata), endK);
					//Score(S, &score, &kata);
					//printf("score: %d", score);
					PointerAktif();
				}
                break;
            }
        default:
        	{
                /*gotoxy(30,22);
                printf("\r                                                ");
                gotoxy(30,22);
            	printf("doesn't recognized the input");*/
            	break;
            }
	}
}

void SimbolAktif(MATRIKS M, Stack *S)
{
    // Kamus Lokal
    infotype A;

    // Algoritma
    if (discovered[((ordinat+1)/4-1)][((((absis+8)/4)-7)/2)])
    {

        while ((GetAbsis(Pos(Infotop(*S))) != absis) || (GetOrdinat(Pos(Infotop(*S))) != ordinat))
        {
            HapusSimbol(GetAbsis(Pos(Infotop(*S))), GetOrdinat(Pos(Infotop(*S))));
            discovered[((GetOrdinat(Pos(Infotop(*S)))+1)/4-1)][((((GetAbsis(Pos(Infotop(*S)))+8)/4)-7)/2)] = false;
            Pop(S, &A);
        }
        absis = GetAbsis(Pos(Infotop(*S)));
        ordinat = GetOrdinat(Pos(Infotop(*S)));
        gotoxy(absis, ordinat);
    }
    else
    {
        gotoxy(absis-1,ordinat);
        Bold();
        printf("%s[", KRED);

        gotoxy(absis+1,ordinat);
        printf("]%s", KNRM);
        UnBold();
        gotoxy(absis,ordinat);

        SetAbsis(&Pos(A), absis);
        SetOrdinat(&Pos(A), ordinat);
        Info(A) = GetElmt(M, ((ordinat+1)/4-1), ((((absis+8)/4)-7)/2));

        Push(S, A);
        //gotoxy(30, 24 + count);
        //printf("%d %d %c", PosX(Infotop(*S)), PosY(Infotop(*S)), Info(Infotop(*S)));

        gotoxy(absis,ordinat);
        discovered[((ordinat+1)/4-1)][((((absis+8)/4)-7)/2)] = true;
        count++;
    }
}

void PointerAktif()
{
	gotoxy(absis-1,ordinat);
    printf("[");

    gotoxy(absis+1,ordinat);
    printf("]");
    gotoxy(absis,ordinat);
}

void HapusSimbol(int x, int y)
{
    // Kamus Lokal

    // Algoritma
    gotoxy(x-1,y);
    printf(" ");
    gotoxy(x+1,y);
    printf(" ");
    gotoxy(x,y);
}

void EndWord(Stack *S, char kata[18], boolean *endK)
{
    // Aamus Lokal
    infotype A;
    int i, j;

    // Algoritma
    i = TOP(*S);
    aktif = false;
    while (IsEmpty(*S) == false)
    {
        Pop(S, &A);
        (kata)[TOP(*S)] = Info(A);
        HapusSimbol(GetAbsis(Pos(A)), GetOrdinat(Pos(A)));
    }
    (kata)[i] = '\0';

    absis = GetAbsis(Pos(A));
    ordinat = GetOrdinat(Pos(A));
    for (i=1;i<=4;i++) {
        for (j=1;j<=4;j++) {
            discovered[i][j] = false;
        }
    }

    gotoxy(30,22);
    printf("                           ");
    gotoxy(30,22);

    (*endK) = true;
}

/* ADT Set */
void addFoundWord ( SetStr *E, char word[18] ) {
	SetSetEl(E, NbElmt(*E), word);
	SetNeff(E, (NbElmt(*E) + 1));
	//TulisIsiTab(E);
}

boolean isFound ( SetStr E, char word[18] ) {
	int i, n;
	ElType *kata;
	boolean found;
	
	if ( NbElmt(E) != 0 ) {
		for ( i=0; i<NbElmt(E); i++ ) {

			n = 0;
			found = true;
			while ( ( (E.TI[i][n] != '\0' ) || (word[n] != '\0') ) && ( found ) ) {
				if (E.TI[i][n] != word[n]) {
					found = false;
				}
				n++;
			}

			if ( found == true ) {
				break;
			}
		} 
	} else {
		found = false;
	}

	return found;
}


/* End of ADT Set */

int Map (char key)
{
	StrMap *sm;
	char buf[255];
	int result;
	int val;

	sm = sm_new(30);
	if (sm != NULL) {
	sm_put(sm, "E", "1");
	sm_put(sm, "A", "11");
	sm_put(sm, "I", "11");
	sm_put(sm, "N", "11");
	sm_put(sm, "O", "11");
	sm_put(sm, "R", "11");
	sm_put(sm, "S", "11");
	sm_put(sm, "T", "11");
	sm_put(sm, "C", "111");
	sm_put(sm, "D", "111");
	sm_put(sm, "L", "111");
	sm_put(sm, "G", "1111");
	sm_put(sm, "H", "1111");
	sm_put(sm, "M", "1111");
	sm_put(sm, "P", "1111");
	sm_put(sm, "U", "1111");
	sm_put(sm, "B", "11111");
	sm_put(sm, "F", "11111");
	sm_put(sm, "Y", "11111");
	sm_put(sm, "K", "111111");
	sm_put(sm, "V", "111111");
	sm_put(sm, "W", "111111");
	sm_put(sm, "Z", "11111111");
	sm_put(sm, "X", "111111111");
	sm_put(sm, "Q", "1111111111");
	sm_put(sm, "J", "1111111111");

	result = sm_get(sm, &key, buf, sizeof(buf));
	if (result != 0) {
	val = strlen(buf);
	return val;
	}
	}
}
 
int Score(char kata[18])
{
	int sum=0;
	int count=0;
	int score=0;
	//boolean endK;
	//EndWord(S,(*kata),&endK);
	do {
		sum += Map((kata)[count]);
		count++;
	} while (kata[count] != '\0');
	(score) = sum*(count);
	if (count>=10) {
		score += 100;
	}

	return score; 
}

void Rotate (MATRIKS *M)
{
	// Kamus Lokal
	
	// Algoritma
	Transpose (M);
	FlipVertical(M);
}
