/* 
Nama : Mohammad Sheva Almeyda Sofjan
NIM : 13519018
Tanggal Prak: 26 November 2020
Topik : Tree
Deskripsi : bintree.c (ADT Tree)
*/

#include "../boolean.h"
#include "bintree.h"
#include <stdlib.h>
#include <stdio.h>

char CC;
boolean EOP;

static int retval;
static FILE *pt;
// Imported dari mesinkar yg ori

StrWahana NamaWahana[7] = {"RollerCoaster","uWuCoaster","EngiDescent","WangkyUniverse","HaloLintar","FieryFist","ChocolateDive"};
int HargaWahana[7] ={10,10,10,10,10,10,10};
int KapasitasWahana[7] = {10,10,10,10,10,10,10};
int DurasiWahana[7] = {10,10,10,10,10,10,10};
int UangBangunan[7] ={0,100,200,200,100,200,200};
StrWahana BahanBangunan[7] ={"iron","iron","iron","iron","iron","iron","cokelat"};

/* *** Konstruktor *** */
BinTree Tree(infotype Akar, BinTree L, BinTree R)
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
{
    BinTree P;
    P = (BinTree)malloc(sizeof(BinTree));
    if(P!=Nil){
        Akar(P) = Akar;
        Left(P) = L;
        Right(P) = R;
    }
    else P = Nil;
    return P;
}
void MakeTree(infotype Akar, BinTree L, BinTree R, BinTree *P)
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R 
		jika alokasi berhasil. P = Nil jika alokasi gagal. */
{
    *P = Tree(Akar,L,R);
}
BinTree BuildBalanceTree(int n)
/* Menghasilkan sebuah balanced tree dengan n node, nilai setiap node dibaca */
{
    addrNode P;
    BinTree L,R;
    infotype X;
    int nl,nr;
    if(n==0) return Nil;
    else{
        scanf("%d",&X);
        P = AlokNode(X);
        if(P!=Nil){
            Akar(P) = X;
            nl = n/2;
            nr = n - nl - 1;
            L = BuildBalanceTree(nl);
            R = BuildBalanceTree(nr);
            Left(P) = L;
            Right(P) = R;
        }
        return P;
    } 
}
/* Manajemen Memory */
addrNode AlokNode(infotype X)
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P, 
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    addrNode N;
    N = (addrNode)malloc(sizeof(addrNode));
    if(N!=Nil){
        Akar(N) = X;
        Left(N) = Nil;
        Right(N) = Nil;
    }
    else N = Nil;
    return N;
}
void DealokNode(addrNode P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */
{
    free(P);
}
/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(BinTree P)
/* Mengirimkan true jika P adalah pohon biner kosong */
{
    return(P==Nil);
}
boolean IsTreeOneElmt(BinTree P)
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
{
    if(!IsTreeEmpty(P)) return((Left(P)==Nil)&&(Right(P)==Nil));
    else return false;
}
boolean IsUnerLeft(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
{
    return(Left(P)!=Nil && Right(P)==Nil);
}
boolean IsUnerRight(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
{
    return(Left(P)==Nil && Right(P)!=Nil);
}
boolean IsBiner(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/
{
    return(Left(P)!=Nil && Right(P)!=Nil);
}
/* *** Traversal *** */
void PrintPreorder(BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
{
    printf("(");
    if(!IsTreeEmpty(P)){
        printf("%d",Akar(P));
        PrintPreorder(Left(P));
        PrintPreorder(Right(P));
    }
    printf(")");
}
void PrintInorder(BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
{
    printf("(");
    if(!IsTreeEmpty(P)){
        PrintInorder(Left(P));
        printf("%d",Akar(P));
        PrintInorder(Right(P));
    }
    printf(")");
}
void PrintPostorder(BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
{
    printf("(");
    if(!IsTreeEmpty(P)){
        PrintPostorder(Left(P));
        PrintPostorder(Right(P));
        printf("%d",Akar(P));
    }
    printf(")");
}

void PrintIndent(BinTree P,int indent,int h){
    if(!IsTreeEmpty(P)){
        printf("%*s",indent,"");
        printf("%d\n",Akar(P));
        PrintIndent(Left(P),indent+h,h);
        PrintIndent(Right(P),indent+h,h);

    }
}
void PrintTree(BinTree P, int h)
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/
{
    PrintIndent(P,0,h);
}
/* *** Searching *** */
boolean SearchTree(BinTree P, infotype X)
/* Mengirimkan true jika ada node dari P yang bernilai X */
{
    if(IsTreeEmpty(P)) return false;
    else{
        if(Akar(P)==X) return true;
        else return(SearchTree(Left(P),X) || SearchTree(Right(P),X));
    }
}
/* *** Fungsi-Fungsi Lain *** */
int NbElmt(BinTree P)
/* Mengirimkan banyaknya elemen (node) pohon biner P */
{
    if(IsTreeEmpty(P)) return 0;
    else return(1+NbElmt(Left(P))+NbElmt(Right(P)));
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
int Level(BinTree P, infotype X)
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P. 
   Akar(P) level-nya adalah 1. Pohon P tidak kosong. */
{
    if(Akar(P)==X) return 1;
    else{//Asumsi X selalu ada di P
        if(SearchTree(Left(P),X)) return(1+Level(Left(P),X));
        else return(1+Level(Right(P),X));
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
/* *** Operasi lain *** */
void AddDaunTerkiri(BinTree *P, infotype X)
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
{
    if(IsTreeEmpty(*P)) MakeTree(X,Nil,Nil,P);
    else AddDaunTerkiri(&Left(*P),X);
}
void AddDaun(BinTree *P, infotype X, infotype Y, boolean Kiri)
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau 
        sebagai anak Kanan X (jika Kiri = false) */
/*		Jika ada > 1 daun bernilai X, diambil daun yang paling kiri */
{
    if(IsTreeOneElmt(*P) && Akar(*P)==X){
        if(Kiri) MakeTree(Y,Nil,Nil,&Left(*P));
        else MakeTree(Y,Nil,Nil,&Right(*P));
    }
    else{ //Asumsi X selalu ada di P
    //if(SearchTree(*P,X))
        if(SearchTree(Left(*P),X)) AddDaun(&Left(*P),X,Y,Kiri);
        else AddDaun(&Right(*P),X,Y,Kiri);
    }
}
void DelDaunTerkiri(BinTree *P, infotype *X)
/* I.S. P tidak kosong */
/* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula 
        disimpan pada daun terkiri yang dihapus */
{
    addrNode N;
    if(IsTreeOneElmt(*P)){
        *X = Akar(*P);
        N = *P;
        *P = Nil;
        DealokNode(N);
    }
    else{
        if(IsUnerRight(*P)) DelDaunTerkiri(&Right(*P),X);
        else DelDaunTerkiri(&Left(*P),X);
    }
}
void DelDaun(BinTree *P, infotype X)
/* I.S. P tidak kosong, minimum ada 1 daun bernilai X. */
/* F.S. Semua daun bernilai X dihapus dari P. */
{
    if(!IsTreeEmpty(*P)){
        if(IsTreeOneElmt(*P) && Akar(*P)==X){
            *P = Nil;
            DealokNode(*P);
        }
        else{
            DelDaun(&Left(*P),X);
            DelDaun(&Right(*P),X);
        }
    }
}

/* *** Binary  Search  Tree  *** */
boolean BSearch(BinTree P, infotype X)
/* Mengirimkan true jika ada node dari P yang bernilai X */
{
    if(IsTreeEmpty(P)) return false;
    else{
        if(Akar(P)==X) return true;
        else return(BSearch(Left(P),X) || BSearch(Right(P),X));
    }
}
void InsSearch(BinTree *P, infotype X)
/* Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. */
{
    if(IsTreeEmpty(*P)) MakeTree(X,Nil,Nil,P);
    else{
        if(X < Akar(*P)) InsSearch(&Left(*P),X);
        else if(X > Akar(*P)) InsSearch(&Right(*P),X);
    }
}

void DelNode(BinTree *P){ 
    if(Right(*P)!=Nil) DelNode(&Right(*P));
    else
    {
       addrNode q;
       q = *P;
       *P = Left(*P); 
    }
    
}

void DelBtree(BinTree *P, infotype X)
/* I.S. Pohon P tidak  kosong */
/* F.S. Nilai X yang dihapus pasti ada */
/* Sebuah node dengan nilai X dihapus */
{
    if(X<Akar(*P)) DelBtree(&Left(*P),X);
    else if(X>Akar(*P)) DelBtree(&Right(*P),X);
    else{
        addrNode q;
        q = *P;
        if(IsTreeOneElmt(q)) *P = Nil;
        else if(IsUnerLeft(q)) *P = Left(q);
        else if(IsUnerRight(q)) *P = Right(q);
        else if(IsBiner(q)) DelNode(&Left(q));
        DealokNode(q);
    }
}


void STARTW(char *filename) {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca. 
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka 
		  EOP akan padam (false). Jika CC = MARK maka EOP akan menyala (true) */
	pt = fopen(filename,"r");
    ADVW();
}

void ADVW() {
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama, CC mungkin = MARK
		  Jika  CC = MARK maka EOP akan menyala (true) */
	retval = fscanf(pt,"%c",&CC);
	EOP = (CC == MARK);
    if(EOP)
        fclose(pt);
}

void BuildTreeFromFile(BinTree *P) { //Bikin tree dari ekspresi prefix
    ADVW();
    if(CC==')')
        *P = Nil;
    else{
        int tmp = (int)(CC) - 48;
        MakeTree(tmp,Nil,Nil,P);
        ADVW();
        BuildTreeFromFile(&(Left(*P)));
        BuildTreeFromFile(&(Right(*P)));
    }
    ADVW();
}