/* Upgrade Tree */

#ifndef uptree_h
#define uptree_h

#include "boolean.h"
#include "mesinkar.h"
#include <stdio.h>
#include <stdlib.h>

#define Nil NULL
typedef int infotype;
typedef struct tNode *addrNode;
typedef struct tNode
{
    infotype info;
    addrNode left;
    addrNode right;
} Node;

typedef addrNode BinTree;

/* *** PROTOTYPE *** */

/* *** Selektor *** */
#define Akar(P) (P)->info
#define Left(P) (P)->left
#define Right(P) (P)->right

addrNode AlokNode(infotype X);
void DealokNode(addrNode P);
BinTree Tree(infotype Akar, BinTree L, BinTree R);
void MakeTree(infotype Akar, BinTree L, BinTree R, BinTree *P);
boolean IsTreeEmpty (BinTree P);
void PrintPrefix (BinTree P);
void BuildTree (BinTree *P);

#endif



