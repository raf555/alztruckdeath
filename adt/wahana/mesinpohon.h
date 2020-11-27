#ifndef __MESINPOHON_H__
#define __MESINPOHON_H__

#include "../boolean.h"

#define NMax 150
#define BLANK ' '
#define MARKW '\n'
#define TrueMark '.'

/* State Mesin Kata */
extern boolean EndKataW;
extern char CKataW[100];
extern char CC;
extern boolean EOP;
void IgnoreBlankW();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTKATAW(char filename[]);
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATAW();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKataW();
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void STARTW(char filename[]);
void ADVW();
void StrConv(char str[],char ns[]);
int IntConv(char str[]);

#endif