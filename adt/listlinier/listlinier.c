/* Mohammad Sheva Almeyda Sofjan | 13519018
    Tanggal Praktikum : 5 November 2020
    Topik : List Linier
    Keterangan : file listlinier.c memuat implementasi ADT List Linier
*/

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{
    return(First(L)==Nil);
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{  
    First(*L) = Nil;
}
/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    ElmtList *P = (ElmtList *) malloc(sizeof(ElmtList));
    if(P==Nil) return Nil;
    else
    {
        Info(P) = X;
        Next(P) = Nil;
        return P;
    }
    
}
void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(*P);
}
/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    address P = First(L);
    boolean found = false;
    address ret = Nil;
    if(!(IsEmpty(L))){
        while(!found && (P!=Nil)){
            if(Info(P)==X){
                found = true;
                ret = P;
                }
            else P=Next(P);
        }
    }
    return ret;

}
/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    address P = Alokasi(X);
    if(P!=Nil){
       InsertFirst(L,P);
    }
}
void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address P = Alokasi(X);
    if(P!=Nil) InsertLast(L,P);
}
/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    address P;
    DelFirst(L,&P);
    *X = Info(P);
    Dealokasi(&P);
}
void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address P;
    DelLast(L,&P);
    *X = Info(P);
    Dealokasi(&P);
}
/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    Next(P) = First(*L);
    First(*L) = P; 
}
void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    if(!IsEmpty(*L)){
        address temp = First(*L);
        while(Next(temp) != Nil) temp = Next(temp);
        Next(P) = Next(temp);
        Next(temp) = P;
    }
    else InsertFirst(L,P);
}
/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    address temp = First(*L);
    if(Next(temp)!=Nil) First(*L) = Next(temp);
    else First(*L) = Nil;
    *P = temp;
}
void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    address P = Search(*L,X);
    if(P!=Nil){
        if(P==First(*L)) DelFirst(L,&P);
        else{
            address prec = First(*L);
            while(Next(prec)!=P) prec = Next(prec);
            DelAfter(L,&P,prec);
        }
    }
    Dealokasi(&P);
}
void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
    *P = First(*L);
    address prec = Nil;
    while(Next(*P)!=Nil){
        prec = *P;
        *P = Next(*P);
    }
    if(prec==Nil) First(*L) = Nil;
    else Next(prec) = Nil;
}
void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = Next(Prec);
    if(*Pdel != Nil) Next(Prec) = Next(*Pdel);
}
/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    printf("[");
    if(!IsEmpty(L)){
        address P = First(L);
        while(P!=Nil){
            printf("%d",Info(P));
            P=Next(P);
            if (P!=Nil) printf(",");
        }

    }
    printf("]");
}
int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    int count = 0;
    if(!IsEmpty(L)){
        address P = First(L);
        while(Next(P)!=Nil){
            count++;
            P=Next(P);
        }
        count++;
    }
    return count;
}
/*** Prekondisi untuk Min: List tidak kosong ***/
infotype Min (List L)
/* Mengirimkan nilai Info(P) yang minimum */
{
    address(P) = First(L);
    infotype min = Info(P);
    while(Next(P)!=Nil){
        P = Next(P);
        if(Info(P)<min) min=Info(P);
    }
    return min;
}
/*** Prekondisi untuk Max: List tidak kosong ***/
infotype Max (List L)
/* Mengirimkan nilai Info(P) yang maksimum */
{
    address(P) = First(L);
    infotype max = Info(P);
    while(Next(P)!=Nil){
        P = Next(P);
        if(Info(P)>max) max=Info(P);
    }
    return max;
}
/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    CreateEmpty(L3);
    if(!IsEmpty(*L1)){
        address P = First(*L1);
        First(*L3)= First(*L1);
        while(Next(P)!=Nil) P=Next(P);
        if (!IsEmpty(*L2)) Next(P)= First(*L2);
    }
    else First(*L3) = First(*L2);

    CreateEmpty(L1);CreateEmpty(L2);
}