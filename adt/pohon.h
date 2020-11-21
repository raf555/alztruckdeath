#ifndef pohon_h
#define pohon_h
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
//([Gocar,1000,4,5,serueuy,-1,-1]([Gotank,2000,4,5,lebiseru,10000,Iron]()())([Gomgomcar,2000,2,3,mobil elastis,10000,Gum]()())).
#define Wlen 50
#define Nil NULL

typedef struct {
	char nama[Wlen]; /* Nama Wahana */
	int prc; /* Price */
	int cap; /* Capacity */
	int mnt; /* Durasi(Menit) */
	char desc[Wlen]; /* Deskripsi*/
	int cost;/*Cost to upgrade, untuk akar didefine -1*/
	char bhn[Wlen];/* Bahan untuk upgrade, untuk akar didefine -1*/
} wahanode;

typedef struct tNode *addrNode;
typedef struct tNode
{
    wahanode wahana;
    addrNode left;
    addrNode right;
} Node;

typedef addrNode BinTree;

#define Akar(P) (P)->wahana
#define Left(P) (P)->left
#define Right(P) (P)->right

//addrNode AlokNode(wahanode X);
//void DealokNode(addrNode P);
BinTree Tree(wahanode Akar, BinTree L, BinTree R);
void MakeTree(wahanode Akar, BinTree L, BinTree R, BinTree *P);
boolean IsTreeEmpty (BinTree P);
void BuildTree(BinTree *P);
void WahReader(wahanode *W);
void PrintPrefix (BinTree P);
void PrintWahanode(wahanode W);
void PrintIndent(BinTree P,int indent);

#endif
