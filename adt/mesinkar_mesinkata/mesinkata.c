/* File: mesinkata.c */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#include "../boolean.h"
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
  int ang;
  int num = 0;
    for (int j = 0; j < K.Length; j++){
      if (K.TabKata[j] == *"0"){
        ang = 0;
      } else if (K.TabKata[j] == *"1"){
        ang = 1;
      } else if (K.TabKata[j] == *"2"){
        ang = 2;
      } else if (K.TabKata[j] == *"3"){
        ang = 3;
      } else if (K.TabKata[j] == *"4"){
        ang = 4;
      } else if (K.TabKata[j] == *"5"){
        ang = 5;
      } else if (K.TabKata[j] == *"6"){
        ang = 6;
      } else if (K.TabKata[j] == *"7"){
        ang = 7;
      } else if (K.TabKata[j] == *"8"){
        ang = 8;
      } else if (K.TabKata[j] == *"9"){
        ang = 9;
      }
      int pow = K.Length-j-1;
      int res = 1;
      while (pow != 0){
        res *= 10;
        --pow;
      }
      num += ang*res;
    }
    return num;
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
