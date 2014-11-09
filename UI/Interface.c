// Note : Window console -> width 80, height 24
// Note : Ukuran board width = 32, height = 16. Inside : width = 7, height = 3
// 80-32=48 (start from absis = 24), 24-16=8 (start from ordinat 5)

#include "Interface.h"
#include "../module/auth.c"

// Kamus Global
int absis,ordinat,repeat,repeat2;
char lokasi;
TabKamus K;
char kata[18];
boolean endK, endGame;
MATRIKS M;
Stack S;

									/* ---------- */
									/*    MENU    */
									/* ---------- */
void MainMenu()
{
	clrscr();
	BuatJudul();
	BuatMenu();
}

void UserMenu()
{
	clrscr();
	BuatJudul();
	BuatMenu2();
}

void BuatJudul()
//Deksripsi : prosedur menulis judul "Wordament Zero" di tengah layar
{
    // Kamus Lokal

    // Algoritma
    absis = 22;
    ordinat = 10;

	// Peletakan judul (ukuran judul = width = 17, height = 3)
    gotoxy(absis,ordinat);
    printf("W O R D A M E N T");
    ordinat += 1;
    gotoxy(absis,ordinat);
    for(repeat = 0; repeat < 17; repeat++)
    {
    	printf("\e(0%c\e(B", 0x71); // Garis horizontal pembatas wordament - zero
    }
    ordinat += 1;
    gotoxy(absis,ordinat);
    printf("     Z E R O     ");
	
	// Peletakan garis vertikal pembatas judul dengan menu utama
    absis = 42;
    gotoxy(absis,ordinat);
    for(ordinat = 7; ordinat < 16; ordinat++)
    {
        gotoxy(absis,ordinat);
        printf("\e(0%c\e(B",0x78); // Garis vertikal pembatas
    }
}

void BuatMenu()
// Deskripsi : prosedur membuat menu utama
{
    // Kamus
    boolean end;

    // Algoritma
    end = false;
    absis = 45;
    ordinat = 7;
    lokasi = 'r'; // Inisiasi cursor awal ada di pilihan 'Register'
	
	// Penulisan pilihan menu
    gotoxy(45,7);
    printf("> Register");
    gotoxy(45,9);
    printf("Login");
    gotoxy(45,11);
    printf("How To Play");
    gotoxy(45,13);
    printf("About");
    gotoxy(45,15);
    printf("Quit");
	
	// Pengaturan cursor menu utama
    while(!end)
    {
        switch(getch())
        {
        case 'x': // Cursor down
            {
                if(ordinat < 15)
                {
                    if((ordinat + 2) == 9)
                    {
                        gotoxy(absis,ordinat); // Posisi sekarang (40,7)
                        printf("               ");
                        gotoxy(absis,ordinat);
                        printf("Register");
                        ordinat += 2;
                        gotoxy(absis,ordinat);
                        printf("               ");
                        gotoxy(absis,ordinat);
                        printf ("> Login");
                        lokasi = 'l';
                    }
                    else
                    if((ordinat + 2) == 11)
                    {
                        gotoxy(absis,ordinat); // Posisi sekarang (40,9)
                        printf("               ");
                        gotoxy(absis,ordinat);
                        printf("Login");
                        ordinat += 2;
                        gotoxy(absis,ordinat);
                        printf("               ");
                        gotoxy(absis,ordinat);
                        printf ("> How To Play");
                        lokasi = 'h';
                    }
                    else
                    if((ordinat + 2) == 13)
                    {
                        gotoxy(absis,ordinat); // Posisi sekarang (40,11)
                        printf("               ");
                        gotoxy(absis,ordinat);
                        printf("How To Play");
                        ordinat += 2;
                        gotoxy(absis,ordinat);
                        printf("               ");
                        gotoxy(absis,ordinat);
                        printf ("> About");
                        lokasi = 'a';
                    }
                    else
                    if((ordinat + 2) == 15)
                    {
                        gotoxy(absis,ordinat); // Posisi sekarang (40,13)
                        printf("               ");
                        gotoxy(absis,ordinat);
                        printf("About");
                        ordinat += 2;
                        gotoxy(absis,ordinat);
                        printf("               ");
                        gotoxy(absis,ordinat);
                        printf ("> Quit");
                        lokasi = 'q';
                    }
                }
                break;
            }
        case 'w': // Cursor up
            {
                if(ordinat > 7)
                {
                    if((ordinat - 2) == 13)
                    {
                        gotoxy(absis,ordinat); // Posisi sekarang (40,15)
                        printf("               ");
                        gotoxy(absis,ordinat);
                        printf("Quit");
                        ordinat -= 2;
                        gotoxy(absis,ordinat);
                        printf("               ");
                        gotoxy(absis,ordinat);
                        printf ("> About");
                        lokasi = 'a';
                    }
                    else
                    if((ordinat - 2) == 11)
                    {
                        gotoxy(absis,ordinat); // Posisi sekarang (40,13)
                        printf("               ");
                        gotoxy(absis,ordinat);
                        printf("About");
                        ordinat -= 2;
                        gotoxy(absis,ordinat);
                        printf("               ");
                        gotoxy(absis,ordinat);
                        printf ("> How To Play");
                        lokasi = 'h';
                    }
                    else
                    if((ordinat - 2) == 9)
                    {
                        gotoxy(absis,ordinat); // Posisi sekarang (40,11)
                        printf("               ");
                        gotoxy(absis,ordinat);
                        printf("How To Play");
                        ordinat -= 2;
                        gotoxy(absis,ordinat);
                        printf("               ");
                        gotoxy(absis,ordinat);
                        printf ("> Login");
                        lokasi = 'l';
                    }
                    else
                    if((ordinat - 2) == 7)
                    {
                        gotoxy(absis,ordinat); // Posisi sekarang (40,9)
                        printf("               ");
                        gotoxy(absis,ordinat);
                        printf("Login");
                        ordinat -= 2;
                        gotoxy(absis,ordinat);
                        printf("               ");
                        gotoxy(absis,ordinat);
                        printf ("> Register");
                        lokasi = 'r';
                    }
                }
                break;
            }
        case's': // Cursor pemilih (choose)
        	{
        		end = true;
        		break;
        	}
		}   
	}
	
	// Pengaturan tujuan link setelah end (choose)
	switch(lokasi)
    {
    case 'r':
       	{
      		// Ke Register
       		clrscr();
       		BuatSubJudul();
       		RegisterScreen();
       		break;
       	}
    case 'l':
       	{
     		// Ke Login
       		clrscr();
       		BuatSubJudul();
       		LoginScreen();
       		break;
       	}
    case 'h':
       	{
       		// Ke How To Play
       		clrscr();
       		BuatSubJudul();
       		break;
       	}
    case 'a':
       	{
       		// Ke About
       		clrscr();
       		BuatSubJudul();
       		break;
       	}	
    case 'q':
       	{
       		// Keluar
       		gotoxy(45,18);
    		printf("Bye Bye\n");\
        	break;
       	}
	}
}

void BuatMenu2()
// Deskripsi : prosedur membuat user menu (menu setelah login)
{
    // Kamus
    boolean end;

    // Algoritma
    end = false;
    absis = 45;
    ordinat = 7;
    lokasi = 'p';

    // Penulisan pilihan menu
    gotoxy(45,7);
    printf("> Play Game");
    gotoxy(45,9);
    printf("Select Board");
    gotoxy(45,11);
    printf("View My Highscore");
    gotoxy(45,13);
    printf("View All Highscore");
    gotoxy(45,15);
    printf("Logout");

    // Pengaturan cursor
    while(!end)
    {
        switch(getch())
        {
        case 'x': // Cursor down
            {
                if(ordinat < 15)
                {
                    if((ordinat + 2) == 9)
                    {
                        gotoxy(absis,ordinat); // Posisi sekarang (40,7)
                        printf("               ");
                        gotoxy(absis,ordinat);
                        printf("Play Game");
                        ordinat += 2;
                        gotoxy(absis,ordinat);
                        printf("               ");
                        gotoxy(absis,ordinat);
                        printf("> Select Board");
                        lokasi = 'b';
                    }
                    else
                    if((ordinat + 2) == 11)

                    {
                        gotoxy(absis,ordinat); // Posisi sekarang (40,9)
                        printf("               ");
                        gotoxy(absis,ordinat);
                        printf("Select Board");
                        ordinat += 2;
                        gotoxy(absis,ordinat);
                        printf("                       ");
                        gotoxy(absis,ordinat);
                        printf("> View My Highscore");
                        lokasi = 'm';
                    }
                    else
                    if((ordinat + 2) == 13)
                    {
                        gotoxy(absis,ordinat); // Posisi sekarang (40,11)
                        printf("                         ");
                        gotoxy(absis,ordinat);
                        printf("View My Highscore");
                        ordinat += 2;
                        gotoxy(absis,ordinat);
                        printf("                        ");
                        gotoxy(absis,ordinat);
                        printf("> View All Highscore");
                        lokasi = 'v';
                    }
                    else
                    if((ordinat + 2) == 15)
                    {
                        gotoxy(absis,ordinat); // Posisi sekarang (40,13)
                        printf("                          ");
                        gotoxy(absis,ordinat);
                        printf("View All Highscore");
                        ordinat += 2;
                        gotoxy(absis,ordinat);
                        printf("               ");
                        gotoxy(absis,ordinat);
                        printf("> Logout");
                        lokasi = 't';
                    }
                }
                break;
            }
        case 'w': // Cursor up
            {
                if(ordinat > 7)
                {
                    if((ordinat - 2) == 13)
                    {
                        gotoxy(absis,ordinat); // Posisi sekarang (40,15)
                        printf("               ");
                        gotoxy(absis,ordinat);
                        printf("Logout");
                        ordinat -= 2;
                        gotoxy(absis,ordinat);
                        printf("                            ");
                        gotoxy(absis,ordinat);
                        printf("> View All Highscore");
                        lokasi = 'v';
                    }
                    else
                    if((ordinat - 2) == 11)
                    {
                        gotoxy(absis,ordinat); // Posisi sekarang (40,13)
                        printf("                           ");
                        gotoxy(absis,ordinat);
                        printf("View All Highscore");
                        ordinat -= 2;
                        gotoxy(absis,ordinat);
                        printf("                           ");
                        gotoxy(absis,ordinat);
                        printf("> View My Highscore");
                        lokasi = 'm';
                    }
                    else
                    if((ordinat - 2) == 9)
                    {
                        gotoxy(absis,ordinat); // Posisi sekarang (40,11)
                        printf("                         ");
                        gotoxy(absis,ordinat);
                        printf("View My Highscore");
                        ordinat -= 2;
                        gotoxy(absis,ordinat);
                        printf("                 ");
                        gotoxy(absis,ordinat);
                        printf("> Select Board");
                        lokasi = 'b';
                    }
                    else
                    if((ordinat - 2) == 7)
                    {
                        gotoxy(absis,ordinat); // Posisi sekarang (40,9)
                        printf("               ");
                        gotoxy(absis,ordinat);
                        printf("Select Board");
                        ordinat -= 2;
                        gotoxy(absis,ordinat);
                        printf("               ");
                        gotoxy(absis,ordinat);
                        printf("> Play Game");
                        lokasi = 'p';
                    }
                }
                break;
            }
        case's': // Cursor pemilih (choose)
        	{
        		end = true;
        		break;
        	}
		}   
	}
	
	// Pengaturan tujuan link setelah end (choose)
	switch(lokasi)
    {
    case 'p':
       	{
      		// Ke Play Game
       		// Title
       		clrscr();
       		BuatSubJudul();
       		// Pengaktifan dict
       		getDictionary(&K);
       		// Pembuatan UI board
       		BuatBoard();
       		// Pembuatan matriks
       		MakeMATRIKS(&M);
    		CreateEmpty(&S);
    		// Pengambilan template board
    		getBoard(3, &M);
    		// Pengisian UI board dengan template
    		IsiBoard(&M);
    		// Inisialisasi UI board - matriks
    		initBoard();
    		ShowCursor();
    		// Cursor board aktif + dict
    		while ( ( !endK ) && ( !endGame ) )
    		{
        		PointerBoard(M, &S, kata, &endK);
				if ( endK == true )
				{
					if ( isOnKamus(kata) )
					{
            			printf("\r                         \r");
                		printf("%s is in dictionary", kata);
            		}
            		else
            		{
            			printf("\r                         \r");
                		printf("%s is wrong", kata);
            		}
        		}
        		endK = false;
    		}
       		break;
       	}
    case 'b':
       	{
     		// Ke Select Board 
       		clrscr();
       		BuatSubJudul();
       		LoginScreen();
       		break;
       	}
    case 'm':
       	{
       		// Ke View My Highscore
       		clrscr();
       		BuatSubJudul();
       		break;
       	}
    case 'v':
       	{
       		// Ke View All Highscore
       		clrscr();
       		BuatSubJudul();
       		break;
       	}	
    case 't':
       	{
       		// Ke Menu Utama
       		// Logout dulu
       		MainMenu();
        	break;
       	}
	}
}

void BuatSubJudul()
{
    // Kamus Lokal

    // Algoritma
    absis = 27;
    ordinat = 2;

    gotoxy(absis,ordinat);
    printf("W O R D A M E N T   Z E R O");
    ordinat += 1;
    gotoxy(absis,ordinat);
    for(repeat = 0; repeat < 27; repeat++)
    {
    	printf("\e(0%c\e(B", 0x71);
    }
    ordinat += 1;
    switch(lokasi)
    {
    case 'r':
    	{
    		gotoxy(33,ordinat);
			printf("R E G I S T E R");
			break;
    	}
    case 'l':
		{
			gotoxy(36,ordinat);
			printf("L O G I N");
			break;
		}
	case 'h':
		{
			gotoxy(31,ordinat);
			printf("H O W  T O  P L A Y");
			break;
		}
	case 'a':
		{
			gotoxy(36,ordinat);
			printf("A B O U T");
			break;
		}
	case 'u':
		{
			gotoxy(36,ordinat);
			printf("L O B B Y");
			break;
		}    
    }
}

void RegisterScreen()
{
	// Kamus Lokal
	char registername[30];
	boolean end,valid;
		
	// Algoritma
	// Bagian Form
	absis = 19;
	ordinat = 12;
	gotoxy(absis,ordinat);
	printf("Username");
	absis += 10;
	ordinat -= 1;
	gotoxy(absis,ordinat);
	printf("\e(0%c\e(B", 0x6c);
	for(repeat = 0; repeat < 32; repeat++)
	{
		printf("\e(0%c", 0x71);
	}
	printf("\e(0%c", 0x6b);
	ordinat += 1;
	gotoxy(absis,ordinat);
	printf("\e(0%c", 0x78);
	for(repeat = 0; repeat < 32; repeat++)
	{
		printf(" ");
	}
	printf("\e(0%c", 0x78);
	ordinat += 1;
	gotoxy(absis,ordinat);
	printf("\e(0%c", 0x6d);
	for(repeat = 0; repeat < 32; repeat++)
	{
		printf("\e(0%c", 0x71);
	}
	printf("\e(0%c\e(B", 0x6a);
	
	// Bagian Choice
	absis = 32;
	ordinat = 16;
	gotoxy(absis,ordinat);
	printf("Register");
	absis = 46;
	gotoxy(absis,ordinat);
	printf("Back to Menu");

	// Bagian Form
	absis = 31;
	ordinat = 12;
	gotoxy(absis,ordinat);
	scanf("%s",registername);
	//gotoxy login setelah klik enter
	// Authentication
	valid = false;

	if(!cekUser(registername))
	{
		gotoxy(31,14);
		printf("                                         ");
		gotoxy(31,14);
		printf("Username already taken");
	}
	else
	{
		gotoxy(31,14);
		printf("                                         ");
		gotoxy(31,14);
		printf("Username available");
		valid = true;
	}
	absis = 32;
	ordinat = 16;
	gotoxy(absis,ordinat);
	
	lokasi = 'r';
	end = false;
	if(valid)
	{
		printf("> Register");
		while(!end)
		{
			switch(getch())
			{
				case 'd':
				{
					if(absis < 46)
					{
						gotoxy(absis,ordinat);
						printf("                     ");
						gotoxy(absis,ordinat);
						printf("Register");
						absis = 46;
						gotoxy(absis,ordinat);
						printf("> Back to Menu");
						lokasi = 'b';
					}
					break;
				}
				case 'a':
				{
					if(absis > 32)
					{
						gotoxy(absis,ordinat);
						printf("                    ");
						gotoxy(absis,ordinat);
						printf("Back to Menu");
						absis = 32;
						gotoxy(absis,ordinat);
						printf("> Register");
						lokasi = 'r';
					}
					break;
				}
				case 's':
				{
					end = true;
					break;
				}
			}
		}
	}
	else
	{
		printf("          ");
		gotoxy(absis,ordinat);
		printf("> Retry");
		while(!end)
		{
			switch(getch())
			{
				case 'd':
				{
					if(absis < 46)
					{
						gotoxy(absis,ordinat);
						printf("                          ");
						gotoxy(absis,ordinat);
						printf("Retry");
						absis = 46;
						gotoxy(absis,ordinat);
						printf("> Back to Menu");
						lokasi = 'b';
					}
					break;
				}
				case 'a':
				{
					if(absis > 32)
					{
						gotoxy(absis,ordinat);
						printf("                           ");
						gotoxy(absis,ordinat);
						printf("Back to Menu");
						absis = 32;
						gotoxy(absis,ordinat);
						printf("> Retry");
						lokasi = 'r';
					}
					break;
				}
				case 's':
				{
					end = true;
					break;
				}
			}
		}
	}
	
	
	if(lokasi == 'b')
	{
		MainMenu();
	}
	else
	if((lokasi == 'r')&&(valid))
	{
		registerUser(registername);
		gotoxy(31,14);
		printf("                                         ");
		gotoxy(31,14);
		printf("Registration succesful, press any key to continue");
		valid = true;
		getch();
		MainMenu();
	}
	else
	if((lokasi == 'r')&&(!valid))
	{
		gotoxy(31,14);
		printf("                             ");
		RegisterScreen();
	}
}

void LoginScreen()
{
	// Kamus Lokal
	char username[30];
	boolean end,valid;
		
	// Algoritma
	// Bagian Form
	absis = 19;
	ordinat = 12;
	gotoxy(absis,ordinat);
	printf("Username");
	absis += 10;
	ordinat -= 1;
	gotoxy(absis,ordinat);
	printf("\e(0%c\e(B", 0x6c);
	for(repeat = 0; repeat < 32; repeat++)
	{
		printf("\e(0%c", 0x71);
	}
	printf("\e(0%c", 0x6b);
	ordinat += 1;
	gotoxy(absis,ordinat);
	printf("\e(0%c", 0x78);
	for(repeat = 0; repeat < 32; repeat++)
	{
		printf(" ");
	}
	printf("\e(0%c", 0x78);
	ordinat += 1;
	gotoxy(absis,ordinat);
	printf("\e(0%c", 0x6d);
	for(repeat = 0; repeat < 32; repeat++)
	{
		printf("\e(0%c", 0x71);
	}
	printf("\e(0%c\e(B", 0x6a);
	
	// Bagian Choice
	absis = 32;
	ordinat = 16;
	gotoxy(absis,ordinat);
	printf("       ");
	gotoxy(absis,ordinat);
	printf("Login");
	absis = 46;
	gotoxy(absis,ordinat);
	printf("Back to Menu");

	// Bagian Form
	absis = 31;
	ordinat = 12;
	gotoxy(absis,ordinat);
	scanf("%s",username);
	//gotoxy login setelah klik enter
	// Authentication
	valid = false;
	if(!loginUser(username))
	{
		gotoxy(31,14);
		printf("Username not registered");
	}
	else
	{
		valid = true;
		gotoxy(31,14);
		printf("                              ");
		gotoxy(31,14);
		printf("Hello, %s", username);
	}
	absis = 32;
	ordinat = 16;
	gotoxy(absis,ordinat);
	
	lokasi = 'l';
	end = false;
	if(valid)
	{
		printf("> Login");
		while(!end)
		{
			switch(getch())
			{
				case 'd':
				{
					if(absis < 46)
					{
						gotoxy(absis,ordinat);
						printf("       ");
						gotoxy(absis,ordinat);
						printf("Login");
						absis = 46;
						gotoxy(absis,ordinat);
						printf("> Back to Menu");
						lokasi = 'b';
					}
					break;
				}
				case 'a':
				{
					if(absis > 32)
					{
						gotoxy(absis,ordinat);
						printf("                 ");
						gotoxy(absis,ordinat);
						printf("Back to Menu");
						absis = 32;
						gotoxy(absis,ordinat);
						printf("> Login");
						lokasi = 'l';
					}
					break;
				}
				case 's':
				{
					end = true;
					break;
				}
			}
		}
	}
	else
	{
		gotoxy(absis,ordinat);
		printf("          ");
		gotoxy(absis,ordinat);
		printf("> Retry");
		while(!end)
		{
			switch(getch())
			{
				case 'd':
				{
					if(absis < 46)
					{
						gotoxy(absis,ordinat);
						printf("       ");
						gotoxy(absis,ordinat);
						printf("Retry");
						absis = 46;
						gotoxy(absis,ordinat);
						printf("> Back to Menu");
						lokasi = 'b';
					}
					break;
				}
				case 'a':
				{
					if(absis > 32)
					{
						gotoxy(absis,ordinat);
						printf("                 ");
						gotoxy(absis,ordinat);
						printf("Back to Menu");
						absis = 32;
						gotoxy(absis,ordinat);
						printf("> Retry");
						lokasi = 'l';
					}
					break;
				}
				case 's':
				{
					end = true;
					break;
				}
			}
		}
	}
	
	
	
	if(lokasi == 'b')
	{
		MainMenu();
	}
	else
	if((lokasi == 'l')&&(valid))
	{
		UserMenu();
	}
	else
	if((lokasi == 'l')&&(!valid))
	{
		gotoxy(31,14);
		printf("                              ");
		LoginScreen();
	}
}


/* --------------------------------------BOARD---------------------------------------- */
void BuatBoard()
{
	// Kamus Lokal
	
	// Algoritma
	/* Garis vertikal */
	absis = 24;
	ordinat = 5;
	for(repeat = 0; repeat < 16; repeat++)
	{
		gotoxy(absis,ordinat);
		for(repeat2 = 0; repeat2 < 5; repeat2++)
		{
			printf("\e(0%c       \e(B", 0x78);
		}
		ordinat += 1;
	}
	
	/* Garis Horizontal */
	absis = 24;
	ordinat = 5;
	for(repeat = 0; repeat < 5; repeat++)
	{
		gotoxy(absis,ordinat);
		for(repeat2 = 0; repeat2 < 33; repeat2++)
        {
        	printf("\e(0%c\e(B", 0x71);
        }
        ordinat += 4;
	}
	
	/* Corner */
	gotoxy(24,5);
	printf("\e(0%c\e(B", 0x6c);
	gotoxy(56,5);
	printf("\e(0%c\e(B", 0x6b);
	gotoxy(24,21);
	printf("\e(0%c\e(B", 0x6d);
	gotoxy(56,21);
	printf("\e(0%c\e(B", 0x6a);
	
	/* Border */
	/* Kanan */
	absis = 56;
	ordinat = 9; 
	for(repeat = 0; repeat < 3; repeat++)
	{
		gotoxy(absis,ordinat);
		printf("\e(0%c\e(B", 0x75);
		ordinat += 4;
	}
	/* Kiri */
	absis = 24;
	ordinat = 9; 
	for(repeat = 0; repeat < 3; repeat++)
	{
		gotoxy(absis,ordinat);
		printf("\e(0%c\e(B", 0x74);
		ordinat += 4;
	}
	/* Atas */
	absis = 32;
	ordinat = 5; 
	for(repeat = 0; repeat < 3; repeat++)
	{
		gotoxy(absis,ordinat);
		printf("\e(0%c\e(B", 0x77);
		absis += 8;
	}
	/* Bawah */
	absis = 32;
	ordinat = 21; 
	for(repeat = 0; repeat < 3; repeat++)
	{
		gotoxy(absis,ordinat);
		printf("\e(0%c\e(B", 0x76);
		absis += 8;
	}
	/* Dalam */
	absis = 32;
	ordinat = 9; 
	for(repeat = 0; repeat < 3; repeat++)
	{
		for(repeat2 = 0; repeat2 < 3; repeat2++)
		{
			gotoxy(absis,ordinat);
			printf("\e(0%c\e(B", 0x6e);
			absis += 8;
		}
		absis = 32;
		ordinat += 4;
	}
}

void IsiBoard(MATRIKS *M)
{
    // Kamus Lokal
    int i,j;

    // Algoritma
    absis = 28;
    ordinat = 7;
    i = 1;
    j = 1;
    for(repeat = 0; repeat < 4; repeat++)
    {
    	for(repeat2 = 0; repeat2 < 4; repeat2++)
    	{
    		gotoxy(absis,ordinat);
    		printf("%c",GetElmt(*M,i,j));
    		absis += 8;
    		j += 1;
    	}
    	absis = 28;
    	j = 1;
    	ordinat += 4;
    	i += 1;
    }
}
