// Note : Window console -> width 80, height 24
// Note : Ukuran board width = 32, height = 16. Inside : width = 7, height = 3
// 80-32=48 (start from absis = 24), 24-16=8 (start from ordinat 5)

#include "Interface.h"
#include "../module/global.h"
#include "../module/auth.c"
#include "../module/load.c"
#include <unistd.h>

// Kamus Global
int absis,ordinat,repeat,repeat2;
int numboard;
char lokasi;
TabKamus K;
char kata[18];
boolean endK, endGame, quitGame, playing;
MATRIKS M;
Stack S;
extern int sumscore;


									/* ---------- */
									/*    MENU    */
									/* ---------- */
									
void MainMenu()
// Deskripsi : prosedur yang merangkum pembuatan Main Menu
{
	// Kamus Lokal
	
	// Algoritma
	clrscr();
	HideCursor();
	BuatJudul();
	BuatMenu();
}

void UserMenu()
// Deskripsi : prosedur yang merangkum pembuatan User Menu (setelah login)
{
	// Kamus Lokal
	
	// Algoritma
	clrscr();
	HideCursor();
	BuatJudul2();
	BuatMenu2();
	selectedBoard = numboard;
}

void BuatJudul()
// Deksripsi : prosedur menulis judul "Wordament Zero" di tengah layar
{
    // Kamus Lokal

    // Algoritma
	// Peletakan judul (ukuran judul = width = 17, height = 3)
    absis = 22;
    ordinat = 10;
    gotoxy(absis,ordinat);
    printf("W O R D A M E N T");
    ordinat += 1;
    gotoxy(absis,ordinat);
    for(repeat = 0; repeat < 6; repeat++)
    {
    	printf("\e(0%c\e(B", 0x71); // Garis horizontal pembatas wordament - zero
    }

   	printf("alpha"); // Garis horizontal pembatas wordament - zero

    for(repeat = 0; repeat < 6; repeat++)
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

void BuatJudul2()
//Deksripsi : prosedur menulis judul "Wordament Zero" versi login di tengah layar
{
    // Kamus Lokal

    // Algoritma
	// Peletakan judul (ukuran judul = width = 17, height = 3)
    absis = 21;
    ordinat = 7;
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
	
	// Penulisan Lobby
    ordinat += 6;
    gotoxy(absis,ordinat);
    printf("\e(0%c%c%c \e(BL O B B Y\e(0 %c%c%c\e(B",0x6d,0x71,0x71,0x71,0x71,0x6a);
	
	// Peletakan garis vertikal pembatas judul dengan menu utama
    absis = 42;
    gotoxy(absis,ordinat);
    for(ordinat = 7; ordinat < 16; ordinat++)
    {
        gotoxy(absis,ordinat);
        printf("\e(0%c\e(B",0x78); // Garis vertikal pembatas
    }
    
    // Penulisan status board yang aktif
	absis = 23;
	ordinat = 11;
	gotoxy(absis,ordinat);
	printf("Active Board");
	absis += 4;
	ordinat += 1;
	gotoxy(absis,ordinat);
	printf("\e(0%c   %c\e(B",0x6c,0x6b);
	ordinat += 1;
	gotoxy(absis,ordinat);
	printf("\e(0%c   %c\e(B",0x78,0x78);
	ordinat += 1;
	gotoxy(absis,ordinat);
	printf("\e(0%c   %c\e(B",0x6d,0x6a);
	absis = 29;
	ordinat = 13;
	gotoxy(absis,ordinat);
	printf("%d", numboard);
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
    		printf("Bye Bye\n");
    		ShowCursor();
			quitGame = true;
        	break;
       	}
	}
}

void BuatMenu2()
// Deskripsi : prosedur membuat user menu (menu setelah login)
{
    // Kamus
    boolean end,played;
	selectBoard(0);

    // Algoritma
    end = false;
    played = false;
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

			playing = true;
    		//played = true;
    		//endGame = false;
       		break;
       	}
    case 'b':
       	{
     		// Ke Select Board 
       		ChooseBoard();
       		//UserMenu();
       		break;
       	}
    case 'm':
       	{
       		// Ke View My Highscore
       		clrscr();
       		BuatSubJudul();
			MyHSScreen();
       		break;
       	}
    case 'v':
       	{
       		// Ke View All Highscore
       		clrscr();
       		BuatSubJudul();
			AllHSScreen();
       		break;
       	}	
    case 't':
       	{
       		// Ke Menu Utama
       		// Logout dulu
       		logoutUser();
        	break;
       	}
	}
}

void BuatSubJudul()
// Deskripsi : Membuat sub-judul di layar bagian atas
{
    // Kamus Lokal

    // Algoritma
    // Penulisan sub-judul di tengah atas layar
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
    
    // Penulisan sub-judul tergantung lokasi tujuan yang dipilih sebelumnya
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
	case 'm':
		{
			gotoxy(29,ordinat);
			printf("M Y   H I G H S C O R E");
			break;
		}    
	case 'v':
		{
			gotoxy(23,ordinat);
			printf("A L L   U S E R   H I G H S C O R E");
			break;
		}
	}
}

void RegisterScreen()
// Deskripsi : Membuat tampilan register
{
	// Kamus Lokal
	char registername[30];
	boolean end,valid;
		
	// Algoritma
	// Bagian Form
	valid = false;
	while (!valid)
	{
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
		ShowCursor();
		
		//scanf("%30[^\n]",registername);
		int i = 0;
		char x;
		while(x!=10)
		{
			x = getch();
			if(x == 127)
			{
				if (i > 0)
				{
					printf("\b \b");
					i -= 1;
				}
			}
			else
			if((x != 127) && (i < 30))
			{
				printf("%c",x);
				registername[i] = x;
				i++;
			}
		}
		HideCursor();
		valid = false;
	
		// Otentikasi
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
		
		// Link ke tujuan
		if(lokasi == 'b')
		{
			//MainMenu();
			valid = true; //pseudo-valid
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
		}
	}
}

void LoginScreen()
{
	// Kamus Lokal
	char username[30];
	boolean end,valid,retry;
		
	// Algoritma
	// Bagian Form

	valid = false;
	while (!valid)
	{
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
		ShowCursor();
		scanf("%30[^\n]s",username);
		HideCursor();
		//gotoxy login setelah klik enter
		absis = 32;
		ordinat = 16;
		gotoxy(absis,ordinat);
	
		lokasi = 'l';
		end = false;
		retry = false;
		valid = true;
		
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
						printf("         ");
						gotoxy(absis,ordinat);
						if(valid)
						{
							printf("Login");
						}
						else
						{
							printf("Retry");
						}
						absis = 46;
						gotoxy(absis,ordinat);
						printf("> Back to Menu");
						retry = false;
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
						printf("            ");
						gotoxy(absis,ordinat);
						if(valid)
						{
							printf("> Login");
						}
						else
						{
							printf("> Retry");
							retry = true;
						}
						lokasi = 'l';
					}
					break;
				}
				case 's':
				{
					end = true;
					valid = false;
					// Authentication
					if(!cekUser(username))
					{
						valid = true;
					}
					if((lokasi == 'l')&&(!valid)&&(retry))
					{
						end = true;
						retry = false;
					}
					else
					if((lokasi == 'l')&&(!valid)&&(!retry))
					{
						gotoxy(31,14);
						printf("Username not registered\n");
						usleep(500000);
						gotoxy(31,14);
						printf("                              ");
						gotoxy(32,16);
						printf("           ");
						gotoxy(32,16);
						printf("> Retry");
						end = false;
						retry = true;
					}
					break;
				}
				default :
				{
					break;
				}
			}
		}
	
	
		if(lokasi == 'b')
		{
			//MainMenu();
			valid = true; //pseudo-valid
		}
		else
		if((lokasi == 'l')&&(valid))
		{
			loginUser(username);
			gotoxy(31,14);
			printf("                              ");
			gotoxy(31,14);
			printf("Welcome back, %s\n", username);
			usleep(300000);
		}
	}
}

void ChooseBoard()
{
	// Kamus Lokal
	boolean end;
	
	// Algoritma
	absis = 23;
	ordinat = 11;
	gotoxy(absis,ordinat);
	Bold();
	printf("%sChoose Board", KRED);
	UnBold();
	printf("%s", KNRM);
	absis += 4;
	ordinat += 1;
	gotoxy(absis,ordinat);
	printf("\e(0%c   %c\e(B",0x6c,0x6b);
	ordinat += 1;
	gotoxy(absis,ordinat);
	printf("\e(0%c   %c\e(B",0x78,0x78);
	ordinat += 1;
	gotoxy(absis,ordinat);
	printf("\e(0%c   %c\e(B",0x6d,0x6a);
	
	absis = 29;
	ordinat = 13;
	
	end = false;
	while(!end)
	{
		gotoxy(absis,ordinat);
		printf("%d", numboard);
		switch(getch())
		{
			case 'w':
			{
				if(numboard < 9)
				{
					numboard += 1;
				}
				selectedBoard = numboard;
				break;
			}
			case 'x':
			{
				if(numboard > 0)
				{
					numboard -= 1;
				}
				selectedBoard = numboard;
				break;
			}
			case 's':
			{
				selectedBoard = numboard;
				end = true;
			}
			default :
			{
				break;
			}
		}
	}
}

void MyHSScreen()

// Deskripsi : Membuat tampilan my highscore
{
	// Kamus Lokal
	boolean end, valid;
	
	TimeArray MyHS;
	int i;
		
	// Algoritma
	
		MyHS.NbElmt = 0;
		MyHS = ListUserHS(numboard, username);
		
		absis = 25;
		ordinat = 7;
		gotoxy(absis,ordinat);
	

		for ( i = 0; i < MyHS.NbElmt; i++ ) {
		    printf("%d ", MyHS.get[i].s);
			absis += 15;
			gotoxy(absis,ordinat);

			printf("%d/%d/%d %d:%d", MyHS.get[i].w.D, MyHS.get[i].w.M, MyHS.get[i].w.Y, MyHS.get[i].t.HH, MyHS.get[i].t.MM);
			ordinat += 2;
			absis = 25;
			gotoxy(absis,ordinat);

			if ( i >= 5 ) {
				break;
			}
		}

		lokasi = 'b';
		end = false;
		valid = false;
			
		gotoxy(absis,ordinat);
		printf("                          ");
		absis = 46;
		ordinat = 20;
		gotoxy(absis,ordinat);
		printf("> Back to Menu");

		while(!end)
		{
			switch(getch())
			{

				case 's':
				{

					lokasi = 'b';
					end = true;
					break;
				}
			}
		}

		// Link ke tujuan
		if(lokasi == 'b')
		{
			//MainMenu();
			valid = true; //pseudo-valid
		}
	

}


void AllHSScreen()

// Deskripsi : Membuat tampilan all highscore
{
	// Kamus Lokal
	boolean end, valid;
	
	TimeArray AllHS;
	List AHS;
	char user_list[90][63];
	int i;
		
	// Algoritma

		ListAllHS(numboard, user_list, &AHS);	

		AllHS.NbElmt = 0;
		AllHS = ListToArraySorted(AHS);
		
		absis = 16;
		ordinat = 7;
		gotoxy(absis,ordinat);
	

		for ( i = 0; i < AllHS.NbElmt; i++ ) {
		    printf("%s ", user_list[AllHS.get[i].id]);
			absis += 15;
			gotoxy(absis,ordinat);

		    printf("%d ", AllHS.get[i].s);
			absis += 15;
			gotoxy(absis,ordinat);

			printf("%d/%d/%d %d:%d", AllHS.get[i].w.D, AllHS.get[i].w.M, AllHS.get[i].w.Y, AllHS.get[i].t.HH, AllHS.get[i].t.MM);
			ordinat += 2;
			absis = 16;
			gotoxy(absis,ordinat);

			if ( i >= 5 ) {
				break;
			}
		}

		lokasi = 'b';
		end = false;
		valid = false;
		
		gotoxy(absis,ordinat);
		printf("                          ");
		absis = 46;
		ordinat = 20;
		gotoxy(absis,ordinat);
		printf("> Back to Menu");

		while(!end)
		{
			switch(getch())
			{

				case 's':
				{

					lokasi = 'b';
					end = true;
					break;
				}
			}
		}

		// Link ke tujuan
		if(lokasi == 'b')
		{
			//MainMenu();
			valid = true; //pseudo-valid
		}
	

}


// HANYA ISENG
#define MAX_LEN 128
void print_image(FILE *fptr)
{
    char read_string[MAX_LEN];
 	
 	//gotoxy(17,5);
    while(fgets(read_string,sizeof(read_string),fptr) != NULL)
        printf("%s",read_string);
}

void Welcome()
{
    clrscr();
    char *filename = "image.txt";
    FILE *fptr = NULL;
 
    if((fptr = fopen(filename,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename);
    }
 
    print_image(fptr);
 
    fclose(fptr);
    getch();
}

void Bold()
{
	//Kamus Lokal
	char ESC = 27;
	
	// Algoritma
	printf("%c[1m",ESC);
}

void UnBold()
{
	// Kamus Lokal
	char ESC = 27;
	
	// Algoritma
    printf("%c[0m",ESC);
}
									/* ----------- */
									/*    BOARD    */
									/* ----------- */
									
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
	
	// Pembuatan bar misc.
	// Bar time
	absis = 61;
	ordinat = 7;
	gotoxy(absis,ordinat);
	for(repeat = 0; repeat < 17; repeat++)
	{
		printf("\e(0%c\e(B",0x71);
	}
	printf("\e(0%c\e(B",0x6a);
	absis += 2;
	ordinat -= 1;
	gotoxy(absis,ordinat);
	printf("Remaining Time");
	
	// Bar dict & score
	absis = 3;
	ordinat = 7;
	gotoxy(absis,ordinat);
	printf("\e(0%c\e(B",0x6d);
	for(repeat = 0; repeat < 17; repeat++)
	{
		printf("\e(0%c\e(B",0x71);
	}
	absis += 2;
	ordinat -= 1;
	gotoxy(absis,ordinat);
	printf("Your Words");
	gotoxy(3,20);
	printf("Total Score = ");
	
	// Bar dict detect
	absis = 61;
	ordinat = 13;
	gotoxy(absis,ordinat);
	for(repeat = 0; repeat < 16; repeat++)
	{
		printf("\e(0%c\e(B",0x71);
	}
	gotoxy(63,12);
    printf("is your word");
    gotoxy(66,14);
    printf("valid?\n");
    
    // Bar suggestion
    absis = 61;
	ordinat = 19;
	gotoxy(absis,ordinat);
	for(repeat = 0; repeat < 17; repeat++)
	{
		printf("\e(0%c\e(B",0x71);
	}
	printf("\e(0%c\e(B",0x6a);
	gotoxy(67,18);
    printf("Suggestion");
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

void BuatSubJudulResult()
{
    // Kamus Lokal

    // Algoritma
    // Penulisan sub-judul di tengah atas layar
    absis = 4;
    ordinat = 2;

    gotoxy(absis,ordinat);
    printf("R E S U L T");
    ordinat += 1;
    gotoxy(absis-1,ordinat);
    for(repeat = 0; repeat < 76; repeat++)
    {
    	printf("\e(0%c\e(B", 0x71);
    }
    ordinat = 2;
    absis += 46;
    gotoxy(absis,ordinat);
    printf("Y O U R  S C O R E  =  %d", sumscore);
}

void BuatBoardResult()
{
	// Kamus Lokal
	
	// Algoritma
	/* Garis vertikal */
	gotoxy(14,4);
	printf("B O A R D %d", selectedBoard);
	absis = 3;
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
	absis = 3;
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
	gotoxy(3,5);
	printf("\e(0%c\e(B", 0x6c);
	gotoxy(35,5);
	printf("\e(0%c\e(B", 0x6b);
	gotoxy(3,21);
	printf("\e(0%c\e(B", 0x6d);
	gotoxy(35,21);
	printf("\e(0%c\e(B", 0x6a);
	
	/* Border */
	/* Kanan */
	absis = 35;
	ordinat = 9; 
	for(repeat = 0; repeat < 3; repeat++)
	{
		gotoxy(absis,ordinat);
		printf("\e(0%c\e(B", 0x75);
		ordinat += 4;
	}
	/* Kiri */
	absis = 3;
	ordinat = 9; 
	for(repeat = 0; repeat < 3; repeat++)
	{
		gotoxy(absis,ordinat);
		printf("\e(0%c\e(B", 0x74);
		ordinat += 4;
	}
	/* Atas */
	absis = 11;
	ordinat = 5; 
	for(repeat = 0; repeat < 3; repeat++)
	{
		gotoxy(absis,ordinat);
		printf("\e(0%c\e(B", 0x77);
		absis += 8;
	}
	/* Bawah */
	absis = 11;
	ordinat = 21; 
	for(repeat = 0; repeat < 3; repeat++)
	{
		gotoxy(absis,ordinat);
		printf("\e(0%c\e(B", 0x76);
		absis += 8;
	}
	/* Dalam */
	absis = 11;
	ordinat = 9; 
	for(repeat = 0; repeat < 3; repeat++)
	{
		for(repeat2 = 0; repeat2 < 3; repeat2++)

		{
			gotoxy(absis,ordinat);
			printf("\e(0%c\e(B", 0x6e);
			absis += 8;
		}
		absis = 11;
		ordinat += 4;
	}
}

void IsiBoardResult(MATRIKS *M)
{
    // Kamus Lokal
    int i,j;

    // Algoritma
    absis = 7;
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
    	absis = 7;
    	j = 1;
    	ordinat += 4;
    	i += 1;
    }
}

void ResultBoard()
{
	// Kamus Lokal
	
	// Algoritma
	clrscr();
	lokasi = 't';
	BuatSubJudulResult();
	BuatBoardResult();
	getBoard(selectedBoard, &M);
	IsiBoardResult(&M);
	
	gotoxy(28,23);
	printf("Press enter to back to menu\n");
	char enter = 0;
	while (enter != '\r' && enter != '\n')
	{
		enter = getch();
	}
}
