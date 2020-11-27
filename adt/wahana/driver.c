#include "../boolean.h"
#include "bintree.h"
#include <stdlib.h>
#include <stdio.h>
#include "bintree.c"

void TreeBuilder1(BinTree *P){
    BinTree L,R,Ll,Lr,Rl,Rr;
    Ll = AlokNode(3);
    Lr = AlokNode(8);
    Rl = AlokNode(13);
    Rr = AlokNode(18);
    L = Tree(5,Ll,Lr);
    R = Tree(15,Rl,Rr);
    *P = Tree(10,L,R);
}

void TreeBuilder2(BinTree *P){
    BinTree L,R,Ll,Lr,Rl,Rr;
    Ll = AlokNode(2);
    Lr = AlokNode(7);
    Rl = AlokNode(15);
    Rr = AlokNode(17);
    L = Tree(4,Ll,Lr);
    R = Tree(20,Rl,Rr);
    *P = Tree(16,L,R);
}



int main(){
    BinTree P1,P2;
    STARTW("wahana.txt");
    BuildTreeFromFile(&P1);
    PrintTree(P1,1);
    return 0;
}