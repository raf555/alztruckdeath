#ifndef __WAHANATREE_H__
#define __WAHANATREE_H__

#include "mesinpohon.h"
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "point.h"
#include "mesinkata.h"
#include "jam.h"
#include "maindata.h"


#define Wlen 50


typedef struct tNode *addrNode;
typedef struct tNode
{
    Wahana wahana;
    addrNode left;
    addrNode right;
} Node;

typedef addrNode BinTree;

#define Akar(P) (P)->wahana
#define Left(P) (P)->left
#define Right(P) (P)->right

//addrNode AlokNode(wahanode X);
//void DealokNode(addrNode P);
BinTree Tree(Wahana Akar, BinTree L, BinTree R);
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (NULL) jika alokasi gagal */
void MakeTree(Wahana Akar, BinTree L, BinTree R, BinTree *P);
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R
   jika alokasi berhasil. P = NULL jika alokasi gagal. */
addrNode Alok(Wahana Akar);
/* Alokasi Node Tree */
boolean IsTreeEmpty (BinTree P);
/* Mengirimkan Keterangan Kekosongan Tree */
boolean IsUnerLeft (BinTree P);
 /* True jika current tree node hanya memiliki Left child */
boolean IsUnerRight (BinTree P);
/* True ika cureent tree node hanya memiliki Right child */
boolean IsBiner (BinTree P);
/* True jika current tree node mempunyai left dan right child */
void WahReader(char *namafile,BinTree *P);
// Membaca wahana dari file
void AddDaun (BinTree *P, int id, Wahana W, boolean Kiri);
// Menambah daun pada tree
void PrintPrefix (BinTree P);
// Print dalam form prefix
void PrintWahanode(Wahana W);
// Mencetak node wahana
void PrintIndent(BinTree P,int indent);
// Mencetak dengan indentasi tergantung level tree
void Dealok(addrNode P);
/* Dealokasi Node */
void DealokTree(BinTree *P);
/* Dealokasi Node Tree */
boolean SearchTree (BinTree P, int id);
// Mencari id/tipe suatu wahana pada tree
int NbElmtTree(BinTree P);
/* Mengirimkan banyaknya elemen (node) pohon biner P */
boolean IsTreeOneElmt(BinTree P);
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
int NbDaun(BinTree P);
/* Mengirimkan banyaknya daun (node) pohon biner P */
/* Prekondisi: P tidak kosong */
boolean IsSkewLeft(BinTree P);
/* Mengirimkan true jika P adalah pohon condong kiri */
/* Pohon kosong adalah pohon condong kiri */
boolean IsSkewRight(BinTree P);
/* Mengirimkan true jika P adalah pohon condong kanan */
/* Pohon kosong adalah pohon condong kanan */
int Tinggi(BinTree P);
/* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim "height" yaitu tinggi dari pohon */
#endif

