#include "wahanatree.h"
#include "wahanatree.c"
#include "mesinpohon.c"
#include <stdio.h>
#include <stdlib.h>

int main(){
    BinTree P1,P2,P3;
    P1 = WahReader("wahana.txt");
    P2 = WahReader("wahana2.txt");
    P3 = WahReader("wahana3.txt");
    PrintIndent(P1,1);
    printf("\n");
    PrintIndent(P2,1);
    printf("\n");
    PrintIndent(P3,1);
    printf("\n");
}
