/* Upgrade Tree */

#include "uptree.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

char CC;
boolean EOP;

static int retval;
static FILE *pt;
// Imported dari mesinkar yg ori

void START(char *filename) {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca. 
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka 
		  EOP akan padam (false). Jika CC = MARK maka EOP akan menyala (true) */
	pt = fopen(filename,"r");
    ADV();
}

void ADV() {
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama, CC mungkin = MARK
		  Jika  CC = MARK maka EOP akan menyala (true) */
	retval = fscanf(pt,"%c",&CC);
	EOP = (CC == MARK);
    if(EOP)
        fclose(pt);
}

addrNode AlokNode(infotype X)
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P,
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
  addrNode N = (addrNode)malloc(sizeof(Node));
  if (N != Nil)
  {
    Akar(N) = X;
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
BinTree Tree(infotype Akar, BinTree L, BinTree R)
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
{
  BinTree T = (BinTree)malloc(sizeof(BinTree));
  if (T != Nil)
  {
    Akar(T) = Akar;
    Left(T) = L;
    Right(T) = R;
    return T;
  }
  else
    return Nil;
}

void MakeTree(infotype Akar, BinTree L, BinTree R, BinTree *P)
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R
   jika alokasi berhasil. P = Nil jika alokasi gagal. */
{
  (*P) = Tree(Akar, L, R);
}

void BuildTree (BinTree *P) { //Bikin tree dari ekspresi prefix
    ADV();
    if(CC==')')
        *P = Nil;
    else{
        MakeTree(CC,Nil,Nil,P);
        ADV();
        BuildTree(&(Left(*P)));
        BuildTree(&(Right(*P)));
    }
    ADV();
}

boolean IsTreeEmpty (BinTree P) {
    return(P==Nil);
}

void PrintPrefix (BinTree P) { // Print dalam form prefix
	if (IsTreeEmpty(P)) {
		printf("()");
	} else {
		printf("(%c", Akar(P));
			PrintPrefix(Left(P));
			PrintPrefix(Right(P));
			printf(")");
	}
}

// DRIVER

/*
int main(){
    BinTree T;
    START("turi.txt");
    BuildTree(&T);
    PrintPrefix(T);
    return 0;
}
*/