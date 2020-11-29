#include <stdio.h>
#include "jam.h"

#define ENDL printf("\n");
#define scanint(x) scanf("%d",&x)
#define scanlong(x) scanf("%ld",&x)

void menu() {
    printf("Masukkan menu pilihanmu (1/2/.../14/15)"); ENDL;
    printf("1. IsJAMValid"); ENDL;
    printf("2. BacaJAM"); ENDL;
    printf("3. TulisJAM"); ENDL;
    printf("4. JAMToDetik"); ENDL;
    printf("5. DetikToJAM"); ENDL;
    printf("6. JEQ"); ENDL;
    printf("7. JNEQ"); ENDL;
    printf("8. JLT"); ENDL;
    printf("9. JGT"); ENDL;
    printf("10. NextDetik"); ENDL;
    printf("11. NextNDetik"); ENDL;
    printf("12. PrevDetik"); ENDL;
    printf("13. PrevNDetik"); ENDL;
    printf("14. Durasi"); ENDL;
    printf("15. exit"); ENDL; ENDL;
}

int main(void) {
    JAM J, otherJ;
    int h, m, s, input;
    long n;
    boolean endTEST = false;

    printf("--- Driver ADT JAM ---"); ENDL;
    printf("Buat jam terlebih dahulu"); ENDL;
    printf("Masukkan jam (HH): "); scanint(h);
    printf("Masukkan menit (MM): "); scanint(m);
    printf("Masukkan detik (DD): "); scanint(s);
    J = MakeJAM(h,m,s); ENDL;
    otherJ = MakeJAM(12,0,0);
    printf("Diketahui jam lain, otherJ = "); TulisJAM(otherJ);
    ENDL; ENDL;

    while (!endTEST) {
        menu();
        printf("$ "); scanint(input);
        switch (input) {
            case 1: // IsJAMValid
                printf("valid? %s", IsJAMValid(h,m,s) ? "true" : "false"); break;
            case 2: // BacaJAM
                printf("Masukkan jam, menit, dan detik baru <h m d>"); ENDL;
                BacaJAM(&J); break;
            case 3: // TulisJAM
                TulisJAM(J); break;
            case 4: // JAMToDetik
                printf("Bentuk jam = "); TulisJAM(J); ENDL;
                printf("Dalam detik = %ld detik", JAMToDetik(J)); break;
            case 5: // DetikToJAM
                printf("Masukkan detik yang akan diubah dalam bentuk jam: "); scanlong(n); ENDL;
                printf("Bentuk jam = "); TulisJAM(DetikToJAM(n)); break;
            case 6: // JEQ
                printf("otherJ = "); TulisJAM(otherJ); ENDL;
                printf("equal? %s", JEQ(J,otherJ) ? "true" : "false"); break;
            case 7: // JNEQ
                printf("otherJ = "); TulisJAM(otherJ); ENDL;
                printf("not equal? %s", JNEQ(J,otherJ) ? "true" : "false"); break;
            case 8: // JLT
                printf("otherJ = "); TulisJAM(otherJ); ENDL;
                printf("J < otherJ? %s", JLT(J,otherJ) ? "true" : "false"); break;
            case 9: // JGT
                printf("otherJ = "); TulisJAM(otherJ); ENDL;
                printf("J > otherJ? %s", JGT(J,otherJ) ? "true" : "false"); break;
            case 10: // NextDetik
                printf("Jam awal = "); TulisJAM(J); ENDL;
                printf("Jam akhir (detik + 1) = "); TulisJAM(NextDetik(J)); break;
            case 11: // NextNDetik
                printf("Masukkan detik (n): "); scanint(s);
                printf("Jam awal = "); TulisJAM(J); ENDL;
                printf("Jam akhir (detik + n) = "); TulisJAM(NextNDetik(J,s)); break;
            case 12: // PrevDetik
                printf("Jam awal = "); TulisJAM(J); ENDL;
                printf("Jam akhir (detik - 1) = "); TulisJAM(PrevDetik(J)); break;
            case 13: // PrevNDetik
                printf("Masukkan detik (n): "); scanint(s);
                printf("Jam awal = "); TulisJAM(J); ENDL;
                printf("Jam akhir (detik - n) = "); TulisJAM(PrevNDetik(J,s)); break;
            case 14: // Durasi
                printf("otherJ = "); TulisJAM(otherJ); ENDL;
                printf("Durasi dari J ("); TulisJAM(J);
                printf(") ke otherJ ("); TulisJAM(otherJ);
                printf(") adalah %ld detik", Durasi(J,otherJ)); break;
            case 15: // exit
                endTEST = true;
                printf("thank you, sudah mencoba!"); break;
            default:
                printf("input invalid"); break;
        }
        ENDL; ENDL;
    }

    return 0;
}