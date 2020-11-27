#include "../boolean.h"
#include "mesinpohon.h"
#include "wahanatree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/* *** Konstruktor *** */
addrNode Tree(wahanode Akar, BinTree L, BinTree R)
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
{
  addrNode T = malloc(sizeof(Node));
  if (T != Nil)
  {
    StrConv(Akar.nama,Akar(T).nama);
    (Akar(T)).prc = Akar.prc;
    (Akar(T)).cap = Akar.cap;
    (Akar(T)).mnt = Akar.mnt;
    StrConv(Akar.desc,(Akar(T)).desc);
    (Akar(T)).cost = Akar.cost;
    StrConv(Akar.bhn,(Akar(T)).bhn);
    Left(T) = L;
    Right(T) = R;
  }
  return T;
}

addrNode Alok(wahanode Akar){
  addrNode T = malloc(sizeof(Node));
  if (T != Nil)
  {
    StrConv(Akar.nama,Akar(T).nama);
    (Akar(T)).prc = Akar.prc;
    (Akar(T)).cap = Akar.cap;
    (Akar(T)).mnt = Akar.mnt;
    StrConv(Akar.desc,(Akar(T)).desc);
    (Akar(T)).cost = Akar.cost;
    StrConv(Akar.bhn,(Akar(T)).bhn);
    Left(T) = Nil;
    Right(T) = Nil;
  }
      return T;
}
void Dealok(addrNode P){
    free(P);
}

void MakeTree(wahanode Akar, BinTree L, BinTree R, BinTree *P)
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R
   jika alokasi berhasil. P = Nil jika alokasi gagal. */
{
  (*P) = Tree(Akar, L, R);
}

boolean IsTreeEmpty (BinTree P) {
    return(P==Nil);
}



// help fix gan

void PrintWahanode(wahanode W){
    printf("%s ",W.nama);
    printf("%d ",W.prc);
    printf("%d ",W.cap);
    printf("%d ",W.mnt);
    printf("%s ",W.desc);
    printf("%d ",W.cost);
    printf("%s", W.bhn);
}

void PrintPrefix (BinTree P) { // Print dalam form prefix
	if (IsTreeEmpty(P)) {
		printf("()");
	} else {
		printf("(");
        PrintWahanode(Akar(P));
		PrintPrefix(Left(P));
		PrintPrefix(Right(P));
		printf(")");
	}
}

void PrintIndent(BinTree P,int indent){
    if(!IsTreeEmpty(P)){
        printf("%*s",indent,"");
        PrintWahanode(Akar(P));
        printf("\n");

        PrintIndent(Left(P),indent+2);
        PrintIndent(Right(P),indent+2);

    }
}

BinTree WahReader(char namafile[]){
    BinTree P[3],whn;
    int c = 0;
    P[0] = malloc(sizeof(Node));
    P[1] = malloc(sizeof(Node));
    P[2] = malloc(sizeof(Node));
    if (P[0] != Nil && P[1]!=Nil && P[2]!=Nil){
    STARTKATAW(namafile);
    while(!EOP){
        while(!EndKataW){
            StrConv(CKataW,Akar(P[c]).nama);
            ADVKATAW();
            Akar(P[c]).prc = atoi(CKataW);
            ADVKATAW();
            Akar(P[c]).cap = atoi(CKataW);
            ADVKATAW();
            Akar(P[c]).mnt = atoi(CKataW);
            ADVKATAW();
            StrConv(CKataW,Akar(P[c]).desc);
            ADVKATAW();
            Akar(P[c]).cost = atoi(CKataW);
            ADVKATAW();
            StrConv(CKataW,Akar(P[c]).bhn);
            }
        Left(P[c]) = NULL;
        Right(P[c]) = NULL;
        ADVKATAW();
        c++;
    }
    
    Left(P[0]) = P[1];
    Right(P[0]) = P[2];
    return P[0];
    }
    // TBAdded : entah tree langsung bentuk node atau nambah fungsi bikin list of wahana disini
    //return W;

    return Nil;
}
