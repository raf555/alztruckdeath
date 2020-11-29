#include <stdio.h>
#include "point.h"

#define ENDL printf("\n");
#define scanfloat(x) scanf("%f",&x)
#define scanint(x) scanf("%d",&x)

int menu() {
    printf("Masukkan menu pilihanmu (1/2/.../19/20)"); ENDL;
    printf("1. BacaPOINT        11. PlusDelta"); ENDL;
    printf("2. TulisPOINT       12. MirrorOf"); ENDL;
    printf("3. EQ               13. Jarak0"); ENDL;
    printf("4. NEQ              14. Panjang"); ENDL;
    printf("5. IsOrigin         15. Geser"); ENDL;
    printf("6. IsOnSbX          16. GeserKeSbX"); ENDL;
    printf("7. IsOnSbY          17. GeserKeSbY"); ENDL;
    printf("8. Kuadran          18. Mirror"); ENDL;
    printf("9. NextX            19. Putar"); ENDL;
    printf("10. NextY           20. exit"); ENDL; ENDL;
}

int main(void) {
    POINT P, otherP;
    int input;
    float x, y;
    boolean endTEST = false;

    printf("--- Driver ADT POINT ---"); ENDL;
    printf("Buat point terlebih dahulu"); ENDL;
    printf("Masukkan absis (x): "); scanfloat(x);
    printf("Masukkan ordinat (y): "); scanfloat(y);
    P = MakePOINT(x,y); ENDL;
    otherP = MakePOINT(4,5);
    printf("Diketahui titik lain, otherP = "); TulisPOINT(otherP);
    ENDL; ENDL;

    while (!endTEST) {
        menu();
        printf("$ "); scanint(input);
        switch (input) {
            case 1 : // BacaPOINT
                printf("Masukkan absis dan ordinat baru <x y>"); ENDL;
                BacaPOINT(&P); break;
            case 2 : // TulisPOINT
                TulisPOINT(P); break;
            case 3 : // EQ
                printf("otherP = "); TulisPOINT(otherP); ENDL;
                printf("equal? %s", EQ(P,otherP) ? "true" : "false"); break;
            case 4 : // NEQ
                printf("otherP = "); TulisPOINT(otherP); ENDL;
                printf("not equal? %s", NEQ(P,otherP) ? "true" : "false"); break;
            case 5 : // IsOrigin
                printf("origin? %s", IsOrigin(P) ? "true" : "false"); break;
            case 6 : // IsOnSbX
                printf("on sb-X? %s", IsOnSbX(P) ? "true" : "false"); break;
            case 7 : // IsOnSbY
                printf("on sb-Y? %s", IsOnSbY(P) ? "true" : "false"); break;
            case 8 : // Kuadran
                printf("Titik P "); TulisPOINT(P);
                printf(" berada di kuadran %d", Kuadran(P)); break;
            case 9 : // NextX
                printf("P awal = "); TulisPOINT(P); ENDL;
                printf("P akhir (absis + 1) = "); TulisPOINT(NextX(P)); break;
            case 10 : // NextY
                printf("P awal = "); TulisPOINT(P); ENDL;
                printf("P akhir (ordinat + 1) = "); TulisPOINT(NextY(P)); break;
            case 11 : // PlusDelta
                printf("Masukkan delta-X: "); scanfloat(x);
                printf("Masukkan delta-Y: "); scanfloat(y); ENDL;
                printf("P awal = "); TulisPOINT(P); ENDL;
                printf("P akhir (+delta) = "); TulisPOINT(PlusDelta(P,x,y)); break;
            case 12 : // MirrorOf
                printf("Cermin sb-X/sb-Y (1/0)? "); scanint(input);
                printf("P awal = "); TulisPOINT(P); ENDL;
                printf("P akhir (mirror) %s", (input == 1) ? "sb-X = " : "sb-Y = "); TulisPOINT(MirrorOf(P,input)); break;
            case 13 : // Jarak0
                printf("jarak P dengan origin = %f", Jarak0(P)); break;
            case 14 : // Panjang
                printf("otherP = "); TulisPOINT(otherP); ENDL;
                printf("jarak P dengan otherP = %f", Panjang(P,otherP)); break;
            case 15 : // Geser
                printf("Masukkan delta-X: "); scanfloat(x);
                printf("Masukkan delta-Y: "); scanfloat(y); ENDL;
                printf("P awal = "); TulisPOINT(P); ENDL;
                Geser(&P,x,y);
                printf("P akhir (+delta) = "); TulisPOINT(P); break;
            case 16 : // GeserKeSbX
                printf("P awal = "); TulisPOINT(P); ENDL;
                GeserKeSbX(&P);
                printf("P akhir (ke sb-X) = "); TulisPOINT(P); break;
            case 17 : // GeserKeSbY
                printf("P awal = "); TulisPOINT(P); ENDL;
                GeserKeSbY(&P);
                printf("P akhir (ke sb-Y) = "); TulisPOINT(P); break;
            case 18 : // Mirror
                printf("Cermin sb-X/sb-Y (1/0)? "); scanint(input);
                printf("P awal = "); TulisPOINT(P); ENDL;
                Mirror(&P,input);
                printf("P akhir (mirror) %s", (input == 1) ? "sb-X = " : "sb-Y = "); TulisPOINT(P); break;
            case 19 : // Putar
                printf("Masukkan sudut putar: "); scanfloat(x);
                printf("P awal = "); TulisPOINT(P); ENDL;
                Putar(&P,x);
                printf("P akhir (putar) = "); TulisPOINT(P); break;
            case 20 : // exit
                endTEST = true; 
                printf("thank you, sudah mencoba!"); break;
            default:
                printf("input invalid"); break;
        }
        ENDL; ENDL;
    }

    return 0;
}