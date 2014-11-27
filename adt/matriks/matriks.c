#include "matriks.h"

void MakeMATRIKS(MATRIKS *M)
{
    // Kamus Lokal
    indeks i,j;
    int n = 48;

    // Algoritma
	for (i=1;i<=4;i++)
    {
		for (j=1;j<=4;j++)
		{
			SetEl(M,i,j,n);
			n++;
		}
	}
}

void SetEl (MATRIKS *M,int i,int j,eltype X)
{
	// Kamus Lokal

	// Algoritma
	(*M).Mem[i-1][j-1] = X;
}

void TulisMATRIKS (MATRIKS M)
{
	// Kamus Lokal
	indeks i,j;

	// Algoritma
	for (i=1;i<=4;i++)
    {
		printf("[");
		for (j=1;j<=4;j++)
		{
			if (j==4)
			{
				printf("%c]\n",GetElmt(M,i,j));
			}
            else
            {
				printf("%c ",GetElmt(M,i,j));
			}
		}
	}
}

eltype GetElmt (MATRIKS M,indeks i,indeks j)
{
	// Kamus Lokal

	// Algoritma
	return M.Mem[i-1][j-1];
}

void Transpose (MATRIKS *M)
{
	// Kamus Lokal
	indeks i,j;
	char temp;
	
	// Algoritma
	for (i=1;i<=4;i++)
        {
		for (j=i;j<=4;j++)
		{
			temp = GetElmt(*M,i,j);
			SetEl(M,i,j,GetElmt(*M,j,i));
			SetEl(M,j,i,temp);
		}
	}
}

void FlipVertical (MATRIKS *M)
{
	// Kamus Lokal
	indeks i,j;
	char temp;
	
	// Algoritma
	for (i=1;i<=4;i++)
	{
		for (j=1;j<=2;j++)
		{
			temp = GetElmt(*M,i,j);
			if (j == 1)
			{
				SetEl(M,i,j,GetElmt(*M,i,4));
				SetEl(M,i,4,temp);
			}
			else
			if (j == 2)
			{
				SetEl(M,i,j,GetElmt(*M,i,3));
				SetEl(M,i,3,temp);
			}
			
		}
	}
}
