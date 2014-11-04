#ifndef matriks_H
#define matriks_H

#define BrsMin 1
#define BrsMax 4
#define KolMin 1
#define KolMax 4

typedef int indeks;
typedef char eltype;
typedef struct
{
    eltype Mem[BrsMax][KolMax];
} MATRIKS;

void MakeMATRIKS(MATRIKS *M);
void SetEl(MATRIKS *M,int i,int j,eltype X);
void TulisMATRIKS(MATRIKS M);
eltype GetElmt(MATRIKS M,indeks i,indeks j);

#endif
