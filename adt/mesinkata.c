/* File: mesinkata.c */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#include "boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include "string.h"
#include "stdlib.h"

boolean EndKata;
Kata CKata;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
{
  while (CC == BLANK){
    ADV();
  }
}

void STARTKATA()
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
  START();
  //IgnoreBlank();
  if (CC == MARK){
    EndKata = true;
  } else {
    EndKata = false;
    SalinKata();
  }
}

void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
  //IgnoreBlank();
  if (CC == MARK){
    EndKata = true;
  } else {
    SalinKata();
  }
}

void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
  int i = 0;
  while (!(CC == MARK/* || CC == BLANK*/) && i < NMax){
    CKata.TabKata[i] = CC;
    i += 1;
    ADV();
  }
  CKata.Length = i;
  //IgnoreBlank();
}

boolean isKataSama(Kata K1, Kata K2){
  // KAMUS
  int i;
  boolean sama = true;

  // ALGORITMA
  if (K1.Length != K2.Length){
    return false;
  } else {
    i = 0;
    while (i < K1.Length && sama){
      if(K1.TabKata[i] != K2.TabKata[i]){
        sama = false;
      }
      i += 1;
    }
    return sama;
  }
}

int ConvertToInt (Kata K){
  int i = 0;
  int num = 0;
  while (K.TabKata[i] != 0)
  {
      num =  (K.TabKata[i] - '0')  + (num * 10);
      i++;
  }
  return num;; 
}

void splitKata(Kata K, Kata *Jml, Kata *nama){
  int i1 = 0;
  while (K.TabKata[i1] != *" "){
    Jml->TabKata[i1] = K.TabKata[i1];
    i1++;
  }
  Jml->Length = i1;

  int i2 = i1+1;
  while (i2 < K.Length){
    nama->TabKata[i2-(i1+1)] = K.TabKata[i2];
    i2++;
  }
  nama->Length = i2; 
}
