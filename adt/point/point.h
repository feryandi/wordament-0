#include <stdio.h>
#include "boolean.h"

// Kamus Global
boolean valid;

		/* -------- */
		/* DEFINISI */
		/* -------- */

	/* Pembentukan tipe bentukan POINT (TPOINT) */		
typedef struct
{
	int X; // absis
	int Y; // ordinat
} TPOINT;

	/* Pendefinisian POINT */
typedef TPOINT POINT;

		/* -------------- */
		/* AKHIR DEFINISI */
		/* -------------- */	
		


		/* --------- */
		/* PROTOTYPE */
		/* --------- */

	/* Konstruktor */
POINT MakePOINT(int X, int Y);
/* Fungsi untuk membentuk sebuah POINT */

	/* Selektor */
int GetAbsis(POINT P);
/* Fungsi yang mengembalikan nilai komponen absis(X) dari POINT */

int GetOrdinat(POINT P);
/* Fungsi yang mengembalikan nilai komponen ordinat(Y) dari POINT */

void SetAbsis(POINT *P, int newX);
/* Prosedur untuk merubah nilai komponen absis(X) dari POINT */

void SetOrdinat(POINT *P, int newY);
/* Prosedur untuk merubah nilai komponen ordinat(Y) dari POINT */

		/* --------------- */
		/* AKHIR PROTOTYPE */
		/* --------------- */
		
		
		
		/* ------------------- */
		/* KELOMPOK BACA TULIS */
		/* ------------------- */
		
void BacaPOINT(POINT *P);
/*	Prosedur untuk membaca nilai komponen POINT dari pengguna
	I.S.	= Sembarang
	F.S.	= P terdefinisi
	Proses	= Membaca masukan dari pengguna */
	
void TulisPOINT(POINT P);
/*	Prosedur untuk menuliskan komponen POINT di layar
	I.S.	= P terdefinisi
	F.S.	= P tertulis di layar dengan format (X,Y)
	Proses	= Menulis komponen POINT di layar */
		
		/* ------------------------- */
		/* AKHIR KELOMPOK BACA TULIS */
		/* ------------------------- */
		
		
		
		/* --------------------------- */
		/* KELOMPOK OPERASI RELASIONAL */
		/* --------------------------- */
		
boolean EQ(POINT P1, POINT P2);
/* Fungsi yang mengembalikan nilai true jika komponen POINT P1 dan P2 sama */

boolean NEQ(POINT P1, POINT P2);
/* Fungsi yang mengembalikan nilai true jika komponen POINT P1 dan P2 berbeda */
		
		/* --------------------------------- */
		/* AKHIR KELOMPOK OPERASI RELASIONAL */
		/* --------------------------------- */
		


		/* --------------------- */
		/* KELOMPOK LOKASI POINT */
		/* --------------------- */
		
boolean IsOrigin(POINT P);
/* Fungsi yang mengembalikan nilai true jika P berada di titik (0,0) */

boolean IsOnSbX(POINT P);
/* Fungsi yang mengembalikan nilai true jika P berada di sumbu X -> (Y = 0) */

boolean IsOnSbY(POINT P);
/* Fungsi yang mengembalikan nilai true jika P berada di sumbu Y -> (X = 0) */

int Kuadran(POINT P);
/*	Fungsi yang mengembalikan lokasi kuadran POINT
	Prekondisi	= P bukan origin dan P tidak terletak di sumbu */
		
		/* --------------------------- */
		/* AKHIR KELOMPOK LOKASI POINT */
		/* --------------------------- */
		
		
		
		/* --------------------------- */
		/* KELOMPOK OPERASI LAIN POINT */
		/* --------------------------- */
		
POINT NextX(POINT P);
/* Fungsi yang mengembalikan salinan P dengan absis ditambah satu */

POINT NextY(POINT P);
/* Fungsi yang mengembalikan salinan P dengan ordinat ditambah satu */

POINT PlusDelta(POINT P, int deltaX, int deltaY);
/* Fungsi yang mengembalikan salinan P dengan absis Absis(P) + deltaX, dan ordinat Ordinat(P) + deltaY */

POINT MirrorOf(POINT P, boolean Sbx);
/*	Fungsi yang mengembalikan salinan P yang dicerminkan terhadap salah satu sumbu
	Jika SbX true, maka dicerminkan terhadap sumbu X
	Jika SbX false, maka dicerminkan terhadap sumbu Y */
	
int Jarak0(POINT P);
/* Fungsi yang mengembalikan jarak P ke (0,0) */

int Panjang(POINT P1, POINT P2);
/* Fungsi yang mengembalikan jarak antara P1 dan P2 */

void Geser(POINT *P, int deltaX, int deltaY);
/*	Prosedur untuk menggeser titik sebesar absis = deltaX dan ordinat = deltaY
	I.S.	= P terdefinisi
	F.S.	= P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY
	Proses	= Penambahan komponen POINT yang sesuai dengan deltaX dan deltaY */
	
void GeserKeSbX(POINT *P);
/*	Prosedur untuk menggeser titik ke sumbu X (ordinat = 0)
	I.S.	= P terdefinisi
	F.S.	= P berada pada sumbu X dengan nilai absis sama seperti absis semula
	Proses	= Pengurangan atau penambahan ordinat agar bernilai 0 */
	
void GeserKeSbY(POINT *P);
/*	Prosedur untuk menggeser titik ke sumbu Y (absis = 0)
	I.S.	= P terdefinisi
	F.S.	= P berada pada sumbu Y dengan nilai ordinat sama seperti ordinat semula
	Proses	= Pengurangan atau penambahan absis agar bernilai 0 */
	
void Mirror(POINT *P, boolean SbX);
/*	Prosedur untuk mencerminkan P terhadap salah satu sumbu
	I.S.	= P terdefinisi
	F.S.	= P dicerminkan sesuai nilai SbX
	Jika SbX true, maka dicerminkan terhadap sumbu X
	Jika SbX false, maka dicerminkan terhadap sumbu Y */

		/* --------------------------------- */
		/* AKHIR KELOMPOK OPERASI LAIN POINT */
		/* --------------------------------- */
