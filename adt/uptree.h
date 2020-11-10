/* Upgrade Tree */

#ifndef uptree_h
#define uptree_h

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

#define Nil NULL
#define MARK '.'
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

extern char CC;
extern boolean EOP;

void START();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca. 
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita
   Jika CC != MARK maka EOP akan padam (false)
   Jika CC = MARK maka EOP akan menyala (true) */

void ADV();
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama, 
   CC mungkin = MARK
   Jika  CC = MARK maka EOP akan menyala (true) */

addrNode AlokNode(infotype X);
void DealokNode(addrNode P);
BinTree Tree(infotype Akar, BinTree L, BinTree R);
void MakeTree(infotype Akar, BinTree L, BinTree R, BinTree *P);
boolean IsTreeEmpty (BinTree P);
void PrintPrefix (BinTree P);
void BuildTree (BinTree *P);

#endif



