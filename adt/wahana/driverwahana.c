#include "wahanatree.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
    BinTree P1,P2,P3;
    // Membaca dari file
    WahReader("wahana3.txt",&P3);
    printf("\n");
    //Mencetak beberapa(tidak semua) komponen tree ke layar
    PrintIndent(P3,1);
    printf("\n");

}
