#include <stdio.h>
#include "boolean.h"

typedef struct {
	int HH;
	int MM;
	int SS;
} JAM;

boolean IsJAMValid ( int H, int M, int S );
JAM MakeJAM ( int HH, int MM, int SS );
int GetHour ( JAM J );
int GetMinute ( JAM J );
int GetSecond ( JAM J );
void SetHH ( JAM J, int newHH );
void SetMM ( JAM J, int newMM );
void SetSS ( JAM J, int newSS );
void BacaJam (JAM *J);
void TulisJam (JAM J);
int JamToDetik (JAM J);
JAM DetikToJam (int N);
boolean JEQ (JAM J1, JAM J2);
boolean JNEQ (JAM J1, JAM J2);
boolean JLT (JAM J1, JAM J2);
boolean JGT (JAM J1, JAM J2);

boolean IsJAMValid ( int H, int M, int S ) {
	if ( H >= 0  &&  H < 24 ) {
		if ( M >= 0  &&  M < 60 ) {
			if ( S >= 0  &&  S < 60 ) {
				return true;
			} else {
				return false;
			}
		} else {
			return false;
		}
	} else {
		return false;
	}
}

JAM MakeJAM ( int HH, int MM, int SS ) {
	if ( IsJAMValid ( HH, MM, SS ) ) {
		JAM cache;
		cache.HH = HH;
		cache.MM = MM;
		cache.SS = SS;
		return cache;
	}
}

int GetHour ( JAM J ) {
	return J.HH;
}

int GetMinute ( JAM J ) {
	return J.MM;
}

int GetSecond ( JAM J ) {
	return J.SS;
}

void SetHH ( JAM J, int newHH ) {
	J.HH = newHH;
}

void SetMM ( JAM J, int newMM ) {
	J.MM = newMM;
}

void SetSS( JAM J, int newSS ) {
	J.SS = newSS;
}

void TulisJam (JAM J) {
	printf("%d %d %d",GetHour(J),GetMinute(J),GetSecond(J));
}

int JamToDetik (JAM J) {
	return ((3600 * GetHour(J)) + (60 * GetMinute(J)) + (GetSecond(J)));
}

JAM DetikToJam (int N) {
	JAM cache;

	if ( N >= 86400 ) {
		N = N % 86400;
	}

	SetHH(cache,(N/3600));
	SetMM(cache,((N%3600)/60));
	SetSS(cache,(((N%3600)%60)/60));

	return cache;
}


boolean JEQ (JAM J1, JAM J2) {
	return ( ( GetHour(J1) == GetHour(J2) ) && ( GetMinute(J1) == GetMinute(J2) ) && ( GetSecond(J1) == GetSecond(J2) ) );
}

boolean JNEQ (JAM J1, JAM J2) {
	return !JEQ(J1,J2);
}

boolean JLT (JAM J1, JAM J2) {
	if ( GetHour(J1) < GetHour(J2) ) {
		return true;
	} else if ( GetHour(J1) > GetHour(J2) ) {
		return false;
	} else {

		if ( GetMinute(J1) < GetMinute(J2) ) {
			return true;
		} else if ( GetMinute(J1) > GetMinute(J2) ) {
			return false;
		} else {

			if ( GetSecond(J1) < GetSecond(J2) ) {
				return true;
			} else {
				return false;
			}

		}

	}
}

boolean JGT (JAM J1, JAM J2) {
	return !JGT(J1,J2);
}
