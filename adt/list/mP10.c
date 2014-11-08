#include <stdio.h>
#include "list.c"

List daftar1, daftar2, daftar3;
infotype a, b;
address P, Q;
/* bahassa indonesia dari list adalah senarai */

int main () {
    CreateList(&daftar1);
    InsVFirst(&daftar1, 8);
    InsVFirst(&daftar1, 7);
    InsVFirst(&daftar1, 9);
    InsVFirst(&daftar1, 1);

    CreateList(&daftar2);
    InsVLast(&daftar2, 1);
    InsVLast(&daftar2, 5);
    InsVLast(&daftar2, 9);
    InsVLast(&daftar2, 9);
    InsVLast(&daftar2, 19);

    InsVLast(&Child(First(daftar1)), 2);

    PrintInfo(daftar1);
    printf("\n");
    PrintInfo(daftar2);
    printf("\n");

    PrintInfo(Child(First(daftar1)));

    /*
    DelVFirst(&daftar2, &a);
    printf("\n");
    PrintInfo(daftar2);

    DelVLast(&daftar2, &a);
    printf("\n");
    PrintInfo(daftar2);

    printf("\n===");

    P = Alokasi(16);
    InsertFirst(&daftar1, P);
    //InsertLast(&daftar1, P);
    printf("\n");
    PrintInfo(daftar1);

    Q = Alokasi(21);
    InsertAfter(&daftar1, Q, P);

    DeleteAfter(&daftar1, &P, Q);
    printf("\n");
    PrintInfo(daftar1);

    printf("\n===");
    DeleteFirst(&daftar1, &P);
    printf("\n");
    PrintInfo(daftar1);

    DeleteP(&daftar1, 7);
    printf("\n");
    PrintInfo(daftar1);

    DeleteLast(&daftar1, &Q);
    printf("\n");
    PrintInfo(daftar1);

    printf("\n===");

    DeleteAll(&daftar1);
    printf("\n");
    PrintInfo(daftar1);

    InversList(&daftar2);

    printf("\n");
    PrintInfo(daftar2);

    CpAlokList(daftar2, &daftar1);
    printf("\n 1: ");
    PrintInfo(daftar1);
    printf("\n 2: ");
    PrintInfo(daftar2);*/

    return 0;
}

