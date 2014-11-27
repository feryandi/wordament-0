#include <stdio.h>
#include "set.c"

SetStr T;

int main() {
	MakeEmpty(&T);
	SetSetEl(&T, NbElmt(T), "PUISI");
	SetNeff(&T, (NbElmt(T) + 1));

	SetSetEl(&T, NbElmt(T), "CINTA");
	SetNeff(&T, (NbElmt(T) + 1));

	SetSetEl(&T, NbElmt(T), "RANGGA");
	SetNeff(&T, (NbElmt(T) + 1));
	TulisIsiTab(T);

	return 0;
}
