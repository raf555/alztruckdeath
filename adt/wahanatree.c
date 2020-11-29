#include "boolean.h"
#include "mesinpohon.h"
#include "wahanatree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

// Mohammad Sheva Almeyda Sofjan | 13519018
// Mengandung Implementasi yang diperlukan dalam program
/* *** Konstruktor *** */
BinTree Tree(Wahana Akar, BinTree L, BinTree R)
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (NULL) jika alokasi gagal */
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
    /* Alokasi Node Tree */
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
void Dealok(addrNode P){ /* Dealokasi Node */
    free(P);
}

void DealokTree(BinTree *P){ /* Dealokasi Node Tree */
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
   jika alokasi berhasil. P = NULL jika alokasi gagal. */
{
  (*P) = Tree(Akar, L, R);
}

boolean IsTreeEmpty (BinTree P) { /* Mengirimkan Keterangan Kekosongan Tree */
    return(P==NULL);
}

boolean IsTreeOneElmt(BinTree P)
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
{
    if(!IsTreeEmpty(P)) return((Left(P)==NULL)&&(Right(P)==NULL));
    else return false;
}

boolean IsUnerLeft (BinTree P) /* True jika current tree node hanya memiliki Left child */
{
    return((Left(P) != NULL) && (Right(P) == NULL));
}

boolean IsUnerRight (BinTree P) /* True ika cureent tree node hanya memiliki Right child */
{
    return((Left(P) == NULL) && (Right(P) != NULL));
}

boolean IsBiner (BinTree P) /* True jika current tree node mempunyai left dan right child */
{
    return((Left(P) != NULL) && (Right(P) != NULL));
}


// help fix gan

void PrintWahanode(Wahana W){ // Mencetak node wahana
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

void PrintIndent(BinTree P,int indent){ // Mencetak dalam bentuk indentasi
    if(!IsTreeEmpty(P)){
        printf("%*s",indent,"");
        PrintWahanode(Akar(P));
        printf("\n");

        PrintIndent(Left(P),indent+2);
        PrintIndent(Right(P),indent+2);

    }
}

void WahReader(char *namafile,BinTree *P){ // Membaca wahana dari file
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

void AddDaun (BinTree *P, int id, Wahana W, boolean Kiri) // Menambah daun pada tree
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

boolean SearchTree (BinTree P, int id) // Mencari id/tipe suatu wahana pada tree
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

int NbElmtTree(BinTree P)
/* Mengirimkan banyaknya elemen (node) pohon biner P */
{
    if(IsTreeEmpty(P)) return 0;
    else return(1+NbElmtTree(Left(P))+NbElmtTree(Right(P)));
}

int NbDaun(BinTree P)
/* Mengirimkan banyaknya daun (node) pohon biner P */
/* Prekondisi: P tidak kosong */
{
    if(IsTreeOneElmt(P)) return 1;
    else{
        if(IsUnerLeft(P)) return NbDaun(Left(P));
        else if(IsUnerRight(P)) return NbDaun(Right(P));
        else if(IsBiner(P)) return(NbDaun(Left(P)) + NbDaun(Right(P)));
    }
}

boolean IsSkewLeft(BinTree P)
/* Mengirimkan true jika P adalah pohon condong kiri */
/* Pohon kosong adalah pohon condong kiri */
{
    if(IsTreeEmpty(P)) return true;
    else{
        if(IsUnerRight(P) || IsBiner(P)) return false;
        else return(IsSkewLeft(Left(P)));
    }
}

boolean IsSkewRight(BinTree P)
/* Mengirimkan true jika P adalah pohon condong kanan */
/* Pohon kosong adalah pohon condong kanan */
{
    if(IsTreeEmpty(P)) return true;
    else{
        if(IsUnerLeft(P) || IsBiner(P)) return false;
        else return(IsSkewRight(Right(P)));
    }
}

int Tinggi(BinTree P)
/* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim "height" yaitu tinggi dari pohon */
{
    if(IsTreeEmpty(P)) return 0;
    else{ 
        if(Tinggi(Left(P)) < Tinggi(Right(P))) return(1+Tinggi(Right(P)));
        else return(1+Tinggi(Left(P)));
    }
}
