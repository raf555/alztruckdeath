#include "boolean.h"
#include "mesinpohon.h"
#include <stdio.h>

boolean EndKataW = false;
char CKataW[100];
char CC;
boolean EOP;
static int retval;
static FILE *pt;

void STARTW() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca. 
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka 
		  EOP akan padam (false). Jika CC = MARK maka EOP akan menyala (true) */
	pt = fopen("turi.txt","r");
    ADVW();
}

void ADVW() {
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama, CC mungkin = MARK
		  Jika  CC = MARK maka EOP akan menyala (true) */
	retval = fscanf(pt,"%c",&CC);
    if(retval==EOF)
        fclose(pt);
        EOP = true;
}

void IgnoreBlankW(){
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
    while(CC==BLANK){
        ADVW();
    }
    if(CC==MARKW) EndKataW=true;

}
void STARTKATAW(){
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
    STARTW();
    IgnoreBlankW();
    if(CC==MARKW) EndKataW = true;
    else{
        SalinKataW();
    }

}
void ADVKATAW(){
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */
    IgnoreBlankW();
    if(CC==MARKW) EndKataW = true;
    else{ 
        SalinKataW();
    }

}
void SalinKataW(){
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    
    int i = 0;
    while(CKataW[i] != '\0'){
        CKataW[i] = '\0';
        i++;
    }
    i = 0;
    while((CC!=MARKW) && (CC!=BLANK) && (i<100)){
        CKataW[i] = CC;
        i++;
        ADVW();
        
    }

}


void StrConv(char str[],char ns[]){
    int i = 0;
    while(str[i]!='\0' || ns[i]!='\0'){
        ns[i] = str[i];
        i++;
    }

}