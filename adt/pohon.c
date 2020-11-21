#include "pohon.h"
#include "mesinpohon.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>


/*addrNode AlokNode(wahanode X)

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
} */

//void DealokNode(addrNode P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */
//{
//  free(P);
//}


/* *** Konstruktor *** */
BinTree Tree(wahanode Akar, BinTree L, BinTree R)
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
{
  BinTree T = (BinTree)malloc(sizeof(BinTree));
  if (T != Nil)
  {
    StrConv(Akar.nama,Akar(T).nama);
    Akar(T).prc = Akar.prc;
    Akar(T).cap = Akar.cap;
    Akar(T).mnt = Akar.mnt;
    StrConv(Akar.desc,Akar(T).desc);
    Akar(T).cost = Akar.cost;
    StrConv(Akar.bhn,Akar(T).bhn);
    Left(T) = L;
    Right(T) = R;
    return T;
  }
  else
    return Nil;
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


void BuildTree(BinTree *P){  // Note : Tree yang dibuild cuma pake keyword dari nama wahana, info sisanya bakal dicocokin pake fungsi lain
    wahanode W;
    if(CKataW[0] == '.') *P = Nil;
    else{
        WahReader(&W);
        MakeTree(W,Nil,Nil,P);
        printf("%s\n",W.nama); // Coba delete line ini dan pas di run tb2 segmentation error
        ADVW();
        ADVKATAW();
        BuildTree(&(Left(*P)));
        ADVKATAW(); // Coba delete ini, node right gabakal ke build dan node left value capacity sama menit jadi ga error
        //ADVKATAW();
        BuildTree(&(Right(*P))); //(masi error kali add right, handling end parse nya kurang bagus, bakal di fix nanti)

    }
}

// help fix gan

void PrintWahanode(wahanode W){
    printf("%s ",W.nama);
    printf("%d ",W.prc);
    printf("%d ",W.cap);
    printf("%d ",W.mnt);
    printf("%s ",W.desc);
    printf("%d ",W.cost);
    printf("%s",W.bhn);
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
    BinTree P,P2;
    //BuildTree(&P);
    STARTKATAW();
    BuildTree(&P);
    P2 = P;
    PrintIndent(P,0);
    printf("\n");
    //PrintPrefix(P);
    //printf("\n");
    return 0;
    //PrintIndent(P2,0);
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