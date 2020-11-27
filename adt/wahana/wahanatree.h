#ifndef __WAHANATREE_H__
#define __WAHANATREE_H__

#include "../boolean.h"
#include "mesinpohon.h"
#include <stdio.h>
#include <stdlib.h>

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
addrNode Alok(wahanode Akar);
boolean IsTreeEmpty (BinTree P);
BinTree BuildTree();
BinTree WahReader(char namafile[]);
void PrintPrefix (BinTree P);
void PrintWahanode(wahanode W);
void PrintIndent(BinTree P,int indent);
void Dealok(addrNode P);

#endif

