#ifndef __WAHANATREE_H__
#define __WAHANATREE_H__

#include "mesinpohon.h"
#include <stdio.h>
#include <stdlib.h>
#include "../boolean.h"
#include "../point.h"
#include "../mesinkata.h"
#include "../jam.h"
#include "../maindata.h"


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
void MakeTree(Wahana Akar, BinTree L, BinTree R, BinTree *P);
addrNode Alok(Wahana Akar);
boolean IsTreeEmpty (BinTree P);
boolean IsUnerLeft (BinTree P);
boolean IsUnerRight (BinTree P);
boolean IsBiner (BinTree P);
void WahReader(char *namafile,BinTree *P);
void AddDaun (BinTree *P, int id, Wahana W, boolean Kiri);
void PrintPrefix (BinTree P);
void PrintWahanode(Wahana W);
void PrintIndent(BinTree P,int indent);
void Dealok(addrNode P);
void DealokTree(BinTree *P);
boolean SearchTree (BinTree P, int id);
#endif

