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

void PointerBoard(MATRIKS M, Stack *S, char *kata, boolean *endK)
{
    // Kamus Lokal
    int i, j;
    
    // Algoritma
    gotoxy(absis,ordinat);

    switch(getch())
    {
    	case 'q':
    		{
				if((absis >= 36)&&(ordinat >= 11))
		    		{
						absis -= 8;
						ordinat -= 4;
						gotoxy(absis,ordinat);
						if (aktif == true)
						{
							SimbolAktif(M, S);
		            	}
		            }
				break;
			}
		case 'w':
			{
				if (ordinat >= 11)
				{
					ordinat -= 4;
					gotoxy(absis,ordinat);
					if (aktif == true)
					{
						SimbolAktif(M, S);
					}
				}
				break;
			}
		case 'e':
			{
				if ((absis <= 44)&&(ordinat >= 10))
				{
					absis += 8;
					ordinat -= 4;
					gotoxy(absis,ordinat);
					if (aktif == true)
					{
						SimbolAktif(M, S);
					}
				}
				break;
			}
        case 'a':
            {
                if (absis >= 36)
                {
                    absis -= 8;
                    gotoxy(absis,ordinat);
                    if (aktif == true)
                    {
                        SimbolAktif(M, S);
                	}
                }
                break;
            }
        case 'd':
            {
                if (absis <= 44)
                {
                    absis += 8;
                    gotoxy(absis,ordinat);
                    if (aktif == true)
                    {
                        SimbolAktif(M, S);
                	}
                }
                break;
            }
        case 'z':
            {
                if ((absis >= 36)&&(ordinat <= 15))
                {
                    absis -= 8;
                    ordinat += 4;
                    gotoxy(absis,ordinat);
                    if (aktif == true)
                    {
                        SimbolAktif(M, S);
                	}
                }
                break;
            }
        case 'x':
            {
                if (ordinat <= 15)
                {
                    ordinat += 4;
                    gotoxy(absis,ordinat);
                    if (aktif == true)
                    {
                        SimbolAktif(M, S);
                	}
                }
                break;
            }
        case 'c':
            {
                if ((absis <= 44)&&(ordinat <= 15))
                {
                    absis += 8;
                    ordinat += 4;
                    gotoxy(absis,ordinat);
                    if (aktif == true)
                    {
                        SimbolAktif(M, S);
                	}
                }
                break;
            }
        case 's':
            {
                simpanabsis = absis;
                simpanordinat = ordinat;
                if (aktif == false)
                {
                    SimbolAktif(M, S);
                    aktif = true;
                }
                else
                {
                    EndWord(S, (kata), endK);
				}
                break;
            }
        case 'l':
            {
                gotoxy(30,22);
                endGame = true;
                printf("\r                                        ");
                gotoxy(30,22);
                printf("GAME ENDS");
                break;
            }
        default:
        	{
                gotoxy(30,22);
                printf("\r                                                ");
                gotoxy(30,22);
            	printf("doesn't recognized the input");
            	break;
            }
	}
}

void SimbolAktif(MATRIKS M, Stack *S)
{
    // Kamus Lokal
    infotype K;

    // Algoritma
    if (discovered[((ordinat+1)/4-1)][((((absis+8)/4)-7)/2)])
    {

        while ((PosX(Infotop(*S)) != absis) || (PosY(Infotop(*S)) != ordinat))
        {
            HapusSimbol(PosX(Infotop(*S)), PosY(Infotop(*S)));
            discovered[((PosY(Infotop(*S))+1)/4-1)][((((PosX(Infotop(*S))+8)/4)-7)/2)] = false;
            Pop(S, &K);
        }
        absis = PosX(Infotop(*S));
        ordinat = PosY(Infotop(*S));
        gotoxy(absis, ordinat);
    }
    else
    {
        gotoxy(absis-1,ordinat);
        printf("[");

        gotoxy(absis+1,ordinat);
        printf("]");
        gotoxy(absis,ordinat);

        PosX(K) = absis;
        PosY(K) = ordinat;
        Info(K) = GetElmt(M, ((ordinat+1)/4-1), ((((absis+8)/4)-7)/2));

        Push(S, K);
        //gotoxy(30, 24 + count);
        //printf("%d %d %c", PosX(Infotop(*S)), PosY(Infotop(*S)), Info(Infotop(*S)));

        gotoxy(absis,ordinat);
        discovered[((ordinat+1)/4-1)][((((absis+8)/4)-7)/2)] = true;
        count++;
    }
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
    // Kamus Lokal
    infotype K;
    int i, j;

    // Algoritma
    i = TOP(*S);
    aktif = false;
    while (IsEmpty(*S) == false)
    {
        Pop(S, &K);
        (kata)[TOP(*S)] = Info(K);
        HapusSimbol(PosX(K), PosY(K));
    }
    (kata)[i] = '\0';

    absis = PosX(K);
    ordinat = PosY(K);
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

/*
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
 
void Score(Stack *S, int *score)
{
	int sum=0;
	int count=0;
	char X;
	while (!IsEmpty(*S)) {
		Pop(S,&X);
		count++;
		sum = sum+Map(X);
		}
	score = sum*count;
	if (count>=10)
		score += 100;
}*/
