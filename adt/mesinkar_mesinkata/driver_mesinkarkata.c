#include <stdio.h>
#include "mesinkata.h"

int main(void) {
  Kata tes;
  tes.TabKata[0] = *"t";
  tes.TabKata[1] = *"e";
  tes.TabKata[2] = *"s";
  tes.Length = 3;
  
  printf("Cek input: ");
  STARTKATA();
  while(!EndKata){
    if(isKataSama(CKata, tes)){
      printf("Kata sama dgn tes");
    } else {
      printf("Kata tidak sama dgn tes");
    }
    ADVKATA();
  }
  printf("\n");
  printf("Input angka: ");
  STARTKATA();
  while(!EndKata){
    printf("Input ditambah 5 = %i", (int) (ConvertToInt(CKata)+5));
    ADVKATA();
  }
  printf("\n");
  printf("Input dua kata: ");
  Kata K1,K2;
  STARTKATA();
  while(!EndKata){
    splitKata(CKata, &K1, &K2);
    printf("Kata dipisah spasi\nKata 1 : ");
    for (int i = 0; i < K1.Length; i++){
      printf("%c", K1.TabKata[i]);
    }
    printf("\nKata 2 : ");
    for (int i = 0; i < K2.Length; i++){
      printf("%c", K2.TabKata[i]);
    }
    ADVKATA();
  }
  printf("\n");
  return 0;
}