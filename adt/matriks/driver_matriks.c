#include <stdio.h>
#include "matriks.h"

#define ENDL printf("\n");
#define scanint(x) scanf("%d",&x)
#define scanchar(x) scanf(" %c",&x)

void menu() {
    printf("Masukkan menu pilihanmu (1/2/.../11/12)"); ENDL;
    printf("1. BacaMATRIKS"); ENDL;
    printf("2. TulisMATRIKS"); ENDL;
    printf("3. SetElmt"); ENDL;
    printf("4. IsIdxValid"); ENDL;
    printf("5. GetFirstIdxBrs"); ENDL;
    printf("6. GetFirstIdxKol"); ENDL;
    printf("7. GetLastIdxBrs"); ENDL;
    printf("8. GetLastIdxKol"); ENDL;
    printf("9. IsIdxEff"); ENDL;
    printf("10. GetElmtDiagonal"); ENDL;
    printf("11. CopyMATRIKS"); ENDL;
    printf("12. exit"); ENDL; ENDL;
}

int main(void) {
    MATRIKS M, Mcopy;
    int brs, kol, input;
    int i, j;
    char x;
    boolean endTEST = false;

    printf("--- Driver ADT MATRIKS ---"); ENDL;
    printf("Buat matriks terlebih dahulu"); ENDL;
    printf("Masukkan jumlah baris (<100): "); scanint(brs);
    printf("Masukkan jumlah kolom (<100): "); scanint(kol);
    MakeMATRIKS(brs,kol,&M);
    ENDL; ENDL;


    while (!endTEST) {
        menu();
        printf("$ "); scanint(input);
        switch (input) {
            case 1: // BacaMATRIKS
                printf("Masukkan elemen matriks %dx%d",brs,kol); ENDL;
                BacaMATRIKS(&M,brs,kol); break;
            case 2: // TulisMATRIKS
                TulisMATRIKS(M); break;
            case 3: // SetElmt
                printf("Masukkan index baris: "); scanint(i);
                printf("Masukkan index kolom: "); scanint(j);
                printf("Masukkan character pengganti: "); scanchar(x);
                SetElmt(i,j,x,&M);
                TulisMATRIKS(M); break;
            case 4: // IsIdxValid
                printf("Masukkan index baris: "); scanint(i);
                printf("Masukkan index kolom: "); scanint(j);
                printf("valid? ");
                printf("%s", IsIdxValid(i,j) ? "true" : "false"); break;
            case 5: // GetFirstIdxBrs
                printf("Index baris pertama: %d", GetFirstIdxBrs(M)); break;
            case 6: // GetFirstIdxKol
                printf("Index kolom pertama: %d", GetFirstIdxKol(M)); break;
            case 7: // GetLastIdxBrs
                printf("Index baris terakhir: %d", GetLastIdxBrs(M)); break;
            case 8: // GetLastIdxKol
                printf("Index kolom terakhir: %d", GetLastIdxKol(M)); break;
            case 9: // IsIdxEff
                printf("Masukkan index baris: "); scanint(i);
                printf("Masukkan index kolom: "); scanint(j);
                printf("efficient? ");
                printf("%s", IsIdxEff(M,i,j) ? "true" : "false"); break;
            case 10: // GetElmtDiagonal
                printf("Masukkan index diagonal: "); scanint(i);
                printf("Elemen di indeks (%d,%d) adalah %c",i,i,GetElmtDiagonal(M,i)); break;
            case 11: // CopyMATRIKS
                CopyMATRIKS(M,&Mcopy);
                printf("Matriks asli:"); ENDL;
                TulisMATRIKS(M); ENDL; ENDL;
                printf("Matriks hasil copy:"); ENDL;
                TulisMATRIKS(Mcopy); break;
            case 12: // Exit
                endTEST = true; break;
                printf("thank you!");
        }
        ENDL; ENDL;
    }

    return 0;
}