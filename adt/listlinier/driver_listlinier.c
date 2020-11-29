#include <stdio.h>
#include "listlinier.h"

#define ENDL printf("\n");
#define scanint(x) scanf("%d",&x)

int menu() {
    printf("Masukkan menu pilihanmu (1/2/.../18/19)"); ENDL;
    printf("1. IsEmpty              11. DelP"); ENDL;
    printf("2. Search               12. DelLast"); ENDL;
    printf("3. InsVFirst            13. DelAfter"); ENDL;
    printf("4. InsVLast             14. PrintInfo"); ENDL;
    printf("5. DelVFirst            15. NbElmt"); ENDL;
    printf("6. DelVLast             16. Min"); ENDL;
    printf("7. InsertFirst          17. Max"); ENDL;
    printf("8. InsertAfter          18. Konkat1"); ENDL;
    printf("9. InsertLast           19. exit"); ENDL;
    printf("10. DelFirst"); ENDL; ENDL;
}

int main(void) {
    List L, L1, Lhasil;
    address P, Prec, Pdummy;
    int input, dummy;
    boolean endTEST = false;

    printf("--- Driver ADT LISTLINIER ---"); ENDL;
    // printf("Buat list terlebih dahulu"); ENDL;
    CreateEmpty(&L); CreateEmpty(&L1); CreateEmpty(&Lhasil);
    for (int i = 1; i <= 10; i++) InsVLast(&L,i);
    printf("List L dengan 10 elemen berhasil dibuat"); ENDL;
    for (int j = 1; j <= 10; j+=2) InsVLast(&L1,j);
    printf("List L1 dengan 5 elemen berhasil dibuat"); // ENDL;

    // Prec = Next(Next(Next(Next(First(L)))));
    // P = Alokasi(99);
    printf("Disediakan address P dengan Info(P) = 99 untuk testing");
    ENDL; ENDL;

    while (!endTEST) {
        Prec = Next(Next(Next(Next(First(L)))));
        P = Alokasi(99);
        menu();
        printf("$ "); scanint(input);
        switch (input) {
            case 1: // IsEmpty
                printf("empty? %s", IsEmpty(L) ? "true" : "false"); break;
            case 2: // Search 
                printf("Masukkan elemen yang ingin dicari: "); scanint(dummy);
                printf("ketemu? %s", Search(L,dummy) != Nil ? "true" : "false"); break;
            case 3: // InsVFirst
                printf("Masukkan elemen yang ingin ditambahkan: "); scanint(dummy);
                printf("List awal = "); PrintInfo(L); ENDL;
                InsVFirst(&L,dummy);
                printf("List akhir (ditambah di awal) = "); PrintInfo(L); break;
            case 4: // InsVLast
                printf("Masukkan elemen yang ingin ditambahkan: "); scanint(dummy);
                printf("List awal = "); PrintInfo(L); ENDL;
                InsVLast(&L,dummy);
                printf("List akhir (ditambah di akhir) = "); PrintInfo(L); break;
            case 5: // DelVFirst
                printf("List awal = "); PrintInfo(L); ENDL;
                DelVFirst(&L,&dummy);
                printf("List akhir (elemen awal didelete) = "); PrintInfo(L); ENDL;
                printf("Elemen yang didelete = %d", dummy); break;
            case 6: // DelVLast
                printf("List awal = "); PrintInfo(L); ENDL;
                DelVLast(&L,&dummy);
                printf("List akhir (elemen akhir didelete) = "); PrintInfo(L); ENDL;
                printf("Elemen yang didelete = %d", dummy); break;
            case 7: // InsertFirst
                printf("Disediakan address P dengan Info(P) = 99"); ENDL;
                printf("List awal = "); PrintInfo(L); ENDL;
                InsertFirst(&L,P);
                printf("List akhir (ditambah di awal) = "); PrintInfo(L); break;
            case 8: // InsertAfter
                printf("Disediakan address P dengan Info(P) = 99"); ENDL;
                printf("Disediakan address Prec yang terdapat di L"); ENDL;
                printf("List awal = "); PrintInfo(L); ENDL;
                InsertAfter(&L,P,Prec);
                printf("List akhir (ditambah di tengah) = "); PrintInfo(L); break;
            case 9: // InsertLast
                printf("Disediakan address P dengan Info(P) = 99"); ENDL;
                printf("List awal = "); PrintInfo(L); ENDL;
                InsertLast(&L,P);
                printf("List akhir (ditambah di akhir) = "); PrintInfo(L); break;
            case 10: // DelFirst
                printf("List awal = "); PrintInfo(L); ENDL;
                DelFirst(&L,&Pdummy);
                printf("List akhir (address awal didelete) = "); PrintInfo(L); break;
            case 11: // DelP
                printf("Masukkan angka yang addressnya ingin dihapus: "); scanint(dummy);
                printf("List awal = "); PrintInfo(L); ENDL;
                DelP(&L,dummy);
                printf("List akhir (address dengan info(dummy) didelete) = "); PrintInfo(L); break;
            case 12: // DelLast
                printf("List awal = "); PrintInfo(L); ENDL;
                DelLast(&L,&Pdummy);
                printf("List akhir (address akhir didelete) = "); PrintInfo(L); break;
            case 13: // DelAfter
                printf("Disediakan address P dengan Info(P) = 99"); ENDL;
                printf("Disediakan address Prec yang terdapat di L"); ENDL;
                printf("List awal = "); PrintInfo(L); ENDL;
                DelAfter(&L,&Pdummy,Prec);
                printf("List akhir (dihapus di tengah) = "); PrintInfo(L); break;
            case 14: // PrintInfo
                PrintInfo(L); break;
            case 15: // NbElmt
                printf("Banyaknya elemen List = %d", NbElmt(L)); break;
            case 16: // Min
                printf("Nilai info(P) yang minimum adalah %d", Min(L)); break;
            case 17: // Max
                printf("Nilai info(P) yang maximum adalah %d", Max(L)); break;
            case 18: // Konkat1
                printf("List sebelum digabung L = "); PrintInfo(L); ENDL;
                printf("List sebelum digabung L1 = "); PrintInfo(L1); ENDL;
                Konkat1(&L,&L1,&Lhasil);
                printf("List setelah digabung Lhasil = "); PrintInfo(Lhasil); break;  
            case 19 : // exit
                endTEST = true; 
                printf("thank you, sudah mencoba!"); break;
            default:
                printf("input invalid"); break;              
        }
        ENDL; ENDL;
    }

    return 0;
}