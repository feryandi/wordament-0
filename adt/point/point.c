#include "point.h"

		/* --------- */
		/* PROTOTYPE */
		/* --------- */
		
/* Konstruktor */
POINT MakePOINT(int X, int Y)
{
	// Kamus Lokal
	POINT P;
	
	// Algoritma
	P.X = X;
	P.Y = Y;
	return P;
}

	/* Selektor */
int GetAbsis(POINT P)
{
	// Kamus Lokal
	
	// Algoritma
	return P.X;
}

int GetOrdinat(POINT P)
{
	// Kamus Lokal
	
	// Algoritma
	return P.Y;
}

void SetAbsis(POINT *P, int newX)
{
	// Kamus Lokal
	
	// Algoritma
	(*P).X = newX;
}

void SetOrdinat(POINT *P, int newY)
{
	// Kamus Lokal
	
	// Algoritma
	(*P).Y = newY;
}

		/* --------------- */
		/* AKHIR PROTOTYPE */
		/* --------------- */
		
		
		
		/* ------------------- */
		/* KELOMPOK BACA TULIS */
		/* ------------------- */
		
void BacaPOINT(POINT *P)
{
	// Kamus Lokal
	int absis, ordinat;
	
	// Algoritma
	printf("Masukan nilai absis = ");
	scanf("%d", &absis);
	printf("Masukan nilai ordinat = ");
	scanf("%d", &ordinat);
	*P = MakePOINT(absis, ordinat);
}

void TulisPOINT(POINT P)
{
	// Kamus Lokal
	
	// Algoritma
	printf("(%d,%d)\n", GetAbsis(P), GetOrdinat(P));
}

		/* ------------------------- */
		/* AKHIR KELOMPOK BACA TULIS */
		/* ------------------------- */
		
		
		
		/* --------------------------- */
		/* KELOMPOK OPERASI RELASIONAL */
		/* --------------------------- */
		
boolean EQ(POINT P1, POINT P2)
{
	// Kamus Lokal
	
	// Algoritma
	if ((P1.X == P2.X) && (P1.Y == P2.Y))
	{
		return true;
	}
	else
	{
		return false;
	}
}

boolean NEQ(POINT P1, POINT P2)
{
	// Kamus Lokal
	
	// Algoritma
	if ((P1.X != P2.X) || (P1.Y != P2.Y))
	{
		return true;
	}
	else
	{
		return false;
	}
}
		
		/* --------------------------------- */
		/* AKHIR KELOMPOK OPERASI RELASIONAL */
		/* --------------------------------- */
		
		
		
		/* --------------------- */
		/* KELOMPOK LOKASI POINT */
		/* --------------------- */
		
boolean IsOrigin(POINT P)
{
	// Kamus Lokal
	
	// Algoritma
	if ((P.X == 0) && (P.Y == 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

boolean IsOnSbX(POINT P)
{
	// Kamus Lokal
	
	// Algoritma
	if (P.Y == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

boolean IsOnSbY(POINT P)
{
	// Kamus Lokal
	
	// Algoritma
	if (P.X == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Kuadran(POINT P)
{
	// Kamus Lokal
	int kuadran;
	
	// Algoritma
	if ((P.X != 0) && (P.Y != 0))
	{
		if (P.X > 0)
		{
			if (P.Y > 0)
			{
				kuadran = 1;
			}
			else
			{
				kuadran = 4;
			}
		}
		else
		{
			if (P.Y > 0)
			{
				kuadran = 2;
			}
			else
			{
				kuadran = 3;
			}
		}
	}
	else
	{
		kuadran = 999;
	}
	
	return kuadran;
}
		
		/* --------------------------- */
		/* AKHIR KELOMPOK LOKASI POINT */
		/* --------------------------- */
