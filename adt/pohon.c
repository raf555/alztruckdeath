#include "pohon.h"
#include "mesinpohon.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>


addrNode AlokNode(char X[])

{
  addrNode N = (addrNode)malloc(sizeof(Node));
  if (N != Nil)
  {
    StrConv(X,Akar(N));
    Left(N) = Nil;
    Right(N) = Nil;
    return N;
  }
  else
    return Nil;
}

void DealokNode(addrNode P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */
{
  free(P);
}

/* *** Konstruktor *** */
BinTree Tree(char Akar[], BinTree L, BinTree R)
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
{
  BinTree T = (BinTree)malloc(sizeof(BinTree));
  if (T != Nil)
  {
    StrConv(Akar,Akar(T));
    Left(T) = L;
    Right(T) = R;
    return T;
  }
  else
    return Nil;
}

void MakeTree(char Akar[], BinTree L, BinTree R, BinTree *P)
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R
   jika alokasi berhasil. P = Nil jika alokasi gagal. */
{
  (*P) = Tree(Akar, L, R);
}

boolean IsTreeEmpty (BinTree P) {
    return(P==Nil);
}


void BuildTree(BinTree *P){  // Note : Tree yang dibuild cuma pake keyword dari nama wahana, info sisanya bakal dicocokin pake fungsi lain
    wahanode W;
    if(CKataW[0] == '.') *P = Nil;
    else{
        WahReader(&W);
        MakeTree(W.nama,Nil,Nil,P);
        printf("%s\n",W.nama);
        ADVW();
        ADVKATAW();
        BuildTree(&(Left(*P)));
        ADVW();
        ADVKATAW();
        //BuildTree(&(Right(*P))); (masi error kali add right, handling end parse nya kurang bagus, bakal di fix nanti)

    }
}

void PrintPrefix (BinTree P) { // Print dalam form prefix
	if (IsTreeEmpty(P)) {
		printf("()");
	} else {
		printf("(%s", Akar(P));
			PrintPrefix(Left(P));
			PrintPrefix(Right(P));
			printf(")");
	}
}

void WahReader(wahanode *W){
    char nama[Wlen]; /* Nama Wahana */
	int prc; /* Price */
	int cap; /* Capacity */
	int mnt; /* Durasi(Menit) */
	char desc[Wlen]; /* Deskripsi*/
	int cost;/*Cost to upgrade, untuk akar didefine -1*/
	char bhn[Wlen];/* Bahan untuk upgrade, untuk akar didefine -1*/
    
    StrConv(CKataW,W->nama);
    ADVKATAW();
    W->prc = atoi(CKataW);
    ADVKATAW();
    W->cap = atoi(CKataW);
    ADVKATAW();
    W->mnt = atoi(CKataW);
    ADVKATAW();
    StrConv(CKataW,W->desc);
    ADVKATAW();
    W->cost = atoi(CKataW);
    ADVKATAW();
    StrConv(CKataW,W->bhn);
    
    // TBAdded : entah tree langsung bentuk node atau nambah fungsi bikin list of wahana disini
    //return W;


}
// Driver, temporary
int main(){
    wahanode W;
    BinTree P;
    //BuildTree(&P);
    STARTKATAW();
    BuildTree(&P);
    PrintPrefix(P);
    /*WahReader(&W);
    printf("%s\n",W.nama);
    printf("%d\n",W.prc);
    printf("%d\n",W.cap);
    printf("%d\n",W.mnt);
    printf("%s\n",W.desc);
    printf("%d\n",W.cost);
    printf("%s\n",W.bhn); 
    ADVW();
    ADVKATAW();
    WahReader(&W);
    printf("%s\n",W.nama);
    printf("%d\n",W.prc);
    printf("%d\n",W.cap);
    printf("%d\n",W.mnt);
    printf("%s\n",W.desc);
    printf("%d\n",W.cost);
    printf("%s\n",W.bhn);
    ADVW();
    ADVKATAW();
    WahReader(&W);
    printf("%s\n",W.nama);
    printf("%d\n",W.prc);
    printf("%d\n",W.cap);
    printf("%d\n",W.mnt);
    printf("%s\n",W.desc);
    printf("%d\n",W.cost);
    printf("%s\n",W.bhn);  */
    

}