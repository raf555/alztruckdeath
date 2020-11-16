#include <stdio.h>
#include "matriks.h"
#include "boolean.h"

void MakeMATRIKS (int NB, int NK, MATRIKS * M){
    M->NBrsEff = NB;
    M->NKolEff = NK;
    
    int i,j;
    for (i = 0; i < NB; i++){
        for (j = 0; j < NK; j++){
            M->Mem[i][j] = '-';
        }
    }
}

void SetElmt(int i, int j, ElType x, MATRIKS * M){
    M->Mem[i][j] = x;
}

boolean IsIdxValid (int i, int j){
    return (i >= BrsMin && i <= BrsMax && j >= KolMin && j <= KolMax);
}

indeks GetFirstIdxBrs (MATRIKS M){
    return BrsMin;
}

indeks GetFirstIdxKol (MATRIKS M){
    return KolMin;
}

indeks GetLastIdxBrs (MATRIKS M){
    return M.NBrsEff-1;
}

indeks GetLastIdxKol (MATRIKS M){
    return M.NKolEff-1;
}

boolean IsIdxEff (MATRIKS M, indeks i, indeks j){
    return (i >= GetFirstIdxBrs(M) && i <= GetLastIdxBrs(M) && j >= GetFirstIdxKol(M) && j <= GetLastIdxKol(M));
}

ElType GetElmtDiagonal (MATRIKS M, indeks i){
    return M.Mem[i][i];
}

void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl){
    MakeMATRIKS(MIn.NBrsEff, MIn.NKolEff, MHsl);

    int i,j;
    for (i = GetFirstIdxBrs(*MHsl); i <= GetLastIdxBrs(*MHsl); i++){
        for (j = GetFirstIdxKol(*MHsl); j <= GetLastIdxKol(*MHsl); j++){
            MHsl->Mem[i][j] = MIn.Mem[i][j];
        }
    }
}

void BacaMATRIKS (MATRIKS * M, int NB, int NK){
    MakeMATRIKS(NB, NK, M);

    int i,j;
    for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++){
        for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++){
            scanf("%c", &(M->Mem[i][j]));
        }
    }
}

void TulisMATRIKS (MATRIKS M){
    int i,j;
    for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
        for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
            printf((
                (j != GetLastIdxKol(M)) ? "%c " : 
                ((i != GetLastIdxBrs(M)) ? "%c\n" : "%c")
                ), M.Mem[i][j]);
        }
    }
}