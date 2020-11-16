#include <stdlib.h>
#include <stdio.h>
#include "adt/matriks.h"

int main(){
    MATRIKS M;
    MakeMATRIKS(10,10,&M);
    for(int i = 0; i < 10; i++){
        SetElmt(0,i,'*',&M);
        SetElmt(9,i,'*',&M);
    }
    for(int i = 1; i < 9; i++){
        SetElmt(i,0,'*',&M);
        SetElmt(i,9,'*',&M);
    }
    SetElmt(2,2,'P',&M);
    TulisMATRIKS(M);
    printf("\n");
    char move;
    indeks k,l;
    for(indeks i = 0; i < 10; i++){
        for(indeks j = 0; j < 10; j++){
            if(Elmt(M,i,j) == 'P'){
                k = i;
                l = j;
            }
        }
    }
    while(true){
        printf("Masukkan gerakan: ");
        scanf("%c", &move);
        printf("\n");
        if(move == 'a'){
            if(Elmt(M,k-1,l) != '*'){
                SetElmt(k-1,l,'P',&M);
                SetElmt(k,l,'-',&M);
            }
        }
        TulisMATRIKS(M);
        printf("\n");
    }
}