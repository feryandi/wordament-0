#include "matriks.h"

void MakeMATRIKS(MATRIKS *M)
{
    // Kamus Lokal
    indeks i,j;

    // Algoritma
	for (i=1;i<=4;i++)
    {
		for (j=1;j<=4;j++)
		{
			SetEl(M,i,j,'a');
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

