#include "wahanatree.h"
#include "mesinpohon.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
    BinTree P;
    // Membaca dari file
    // Alokasi tree terdapat dalam fungsi wahreader
    // Search terdapat dalam fungsi wahreader
    // Add daun terdapat dalam fungsi wahreader
    WahReader("../../exfile/wahana3.txt",&P);
    printf("\n");
    if(!IsTreeEmpty(P)) printf("Tree Tidak kosong\n");
    if(!IsUnerLeft(P)) printf("Tree tidak uner left\n");
    if(!IsUnerRight(P)) printf("Tree tidak uner right\n");
    if(!IsSkewLeft(P)) printf("Tree tidak skew left\n");
    if(!IsSkewRight(P)) printf("Tree tidak skew right\n");
    if(IsBiner(P)) printf("Tree biner\n");
    //Mencetak beberapa(tidak semua) komponen tree ke layar
    printf("Tree dalam bentuk Indentasi:\n");
    PrintIndent(P,1);
    printf("\n");
    // Mencetak bentuk preorder
    printf("Tree dalam bentuk ekspresi preorder:\n");
    PrintPrefix(P);
    printf("\n");
    // Keterangan jumlah sesuatu pada tree
    printf("Banyak elemen tree :\n");
    printf("%d",NbElmtTree(P));printf("\n");
    printf("Banyak daun tree :\n");
    printf("%d",NbDaun(P));printf("\n");
    printf("Tinggi tree :\n");
    printf("%d",Tinggi(P));printf("\n");
    // Dealokasi Tree
    DealokTree(&P);
    return 0;


}
