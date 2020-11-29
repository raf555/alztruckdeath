#include "boolean.h"
#include "mesinpohon.h"
#include "wahanatree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>


/* data wahana 
typedef struct {
	Kata nama;
	int tipe;
	int harga;
	int kapasitas;
	Kata deskripsi;
	JAM durasi;
	POINT lokasi;
	// history ama ukuran blom
} Wahana;
*/

/* *** Konstruktor *** */
BinTree Tree(Wahana Akar, BinTree L, BinTree R)
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
{
  BinTree T = Alok(Akar);
  if (T != NULL)
  {
    Left(T) = L;
    Right(T) = R;
  }
  return T;
}

addrNode Alok(Wahana Akar){
  addrNode T = (addrNode) malloc(sizeof(Node));
  if (T != NULL)
  {
    CopyString(Akar(T).nama.TabKata,Akar.nama.TabKata);
    Akar(T).nama.Length =(Akar.nama.Length);
    (Akar(T)).tipe = Akar.tipe;
    (Akar(T)).harga = Akar.harga;
    (Akar(T)).kapasitas = Akar.kapasitas;
    CopyString((Akar(T)).deskripsi.TabKata,Akar.deskripsi.TabKata);
    Akar(T).deskripsi.Length = Akar.deskripsi.Length;
    Akar(T).durasi.HH = Akar.durasi.HH;
    Akar(T).durasi.MM = Akar.durasi.MM; 
    Akar(T).durasi.SS = Akar.durasi.SS;
    Akar(T).lokasi.X = -999;
    Akar(T).lokasi.Y = -999;
    Left(T) = NULL;
    Right(T) = NULL;
  }
      return T;
}
void Dealok(addrNode P){
    free(P);
}

void DealokTree(BinTree *P){
    if(*P != NULL){
        DealokTree(&Left(*P));
        DealokTree(&Right(*P));
        Dealok(*P);
        *P = NULL;
    }
}

void MakeTree(Wahana Akar, BinTree L, BinTree R, BinTree *P)
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R
   jika alokasi berhasil. P = Nil jika alokasi gagal. */
{
  (*P) = Tree(Akar, L, R);
}

boolean IsTreeEmpty (BinTree P) {
    return(P==NULL);
}

boolean IsUnerLeft (BinTree P)
{
    return((Left(P) != NULL) && (Right(P) == NULL));
}

boolean IsUnerRight (BinTree P)
{
    return((Left(P) == NULL) && (Right(P) != NULL));
}

boolean IsBiner (BinTree P)
{
    return((Left(P) != NULL) && (Right(P) != NULL));
}


// help fix gan

void PrintWahanode(Wahana W){
    printf("%s ",W.nama.TabKata);
    printf("%d ",W.tipe);
    printf("%d ",W.harga);
    printf("%d ",W.kapasitas);
    printf("%s ",W.deskripsi.TabKata);
    printf("%d ",W.durasi.MM);
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

void WahReader(char *namafile,BinTree *P){
    int i;
    Wahana W;
    boolean Kiri;
    i = 0;
    STARTW(namafile);
    while(CC!=NEW){
        W.nama.TabKata[i] = CC;
        i++;
        ADVW();
    }
    W.nama.Length = i;
    W.nama.TabKata[i] = '\0';
    ADVW();
    W.tipe = CC - '0';
    ADVW();
    ADVW();
    W.harga = 0;
    while(CC!=NEW){
        W.harga = W.harga * 10 + (CC- '0');
        ADVW();
    }
    ADVW();
    W.kapasitas = 0;
    while(CC!=NEW){
        W.kapasitas = W.kapasitas * 10 + (CC- '0');
        ADVW();
    }
    ADVW();
    i = 0;
    while(CC!=NEW){
        W.deskripsi.TabKata[i] = CC;
        i++;
        ADVW();
    }
    W.deskripsi.Length = i;
    W.deskripsi.TabKata[i] = '\0';
    ADVW();
    W.durasi.HH = 0;
    W.durasi.MM = 0;
    W.durasi.SS = 0;
    while(CC!=NEW && CC!=MARKW){
        W.durasi.MM = W.durasi.MM * 10 + (CC- '0');
        ADVW();
    }
    MakeTree(W,NULL,NULL,P);
    ADVW();
    Kiri = true;
    while(CC!=MARKW){
        i = 0;
        while(CC!=NEW){
            W.nama.TabKata[i] = CC;
            i++;
            ADVW();
        }
        W.nama.Length = i;
        W.nama.TabKata[i] = '\0';
        ADVW();
        W.tipe = CC - '0';
        ADVW();
        ADVW();
        W.harga = 0;
        while(CC!=NEW){
            W.harga = W.harga*10 + (CC- '0');
            ADVW();
        }
        ADVW();
        W.kapasitas = 0;
        while(CC!=NEW){
            W.kapasitas = W.kapasitas*10 + (CC- '0');
            ADVW();
        }
        ADVW();
        i = 0;
        while(CC!=NEW){
            W.deskripsi.TabKata[i] = CC;
            i++;
            ADVW();
        }
        W.deskripsi.Length = i;
        W.deskripsi.TabKata[i] = '\0';
        ADVW();
        W.durasi.HH = 0;
        W.durasi.MM = 0;
        W.durasi.SS = 0;
        while(CC!=NEW && CC!=MARKW){
            W.durasi.MM =W.durasi.MM * 10 + (CC- '0');
            ADVW();
        }
        AddDaun(P,W.tipe,W,Kiri);
        ADVW();
        if(Kiri) Kiri = false;
        else Kiri = true;

    }


}

void AddDaun (BinTree *P, int id, Wahana W, boolean Kiri)
{
    if(Akar(*P).tipe == (int) id/2)
    {
        if(Kiri)
        {
            Left(*P) = Alok(W);
        }
        else
        {
            Right(*P) = Alok(W);
        }
    }
    else
    {
        if(SearchTree(Left(*P), id))
        {
            AddDaun(&Left(*P), id, W, Kiri);
        }
        else
        {
            AddDaun(&Right(*P), id, W, Kiri);
        }
    }
}

boolean SearchTree (BinTree P, int id)
{
    /* ALGORITMA */
    if(IsTreeEmpty(P))
    {
        return false;
    }
    else if(Akar(P).tipe == (int) id/2)
    {
        return true;
    }
    else
    {
        return ((SearchTree(Left(P), id)) || SearchTree(Right(P), id));
    }

}