#include "wahanatree.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
    BinTree P;
    // Membaca dari file
    // Alokasi tree terdapat dalam fungsi wahreader
    // Search terdapat dalam fungsi wahreader
    // Add daun terdapat dalam fungsi wahreader
    WahReader("wahana3.txt",&P);
    printf("\n");
    if(!IsTreeEmpty(P)) printf("Tidak kosong\n");
    if(!IsUnerLeft(P)) printf("Tree tidak uner left\n");
    if(!IsUnerLeft(P)) printf("Tree tidak uner right\n");
    if(IsBiner(P)) printf("Tree biner\n");
    //Mencetak beberapa(tidak semua) komponen tree ke layar
    PrintIndent(P,1);
    printf("\n");

}
