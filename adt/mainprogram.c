#include "mainprogram.h"
#include <stdio.h>

void initmain(program *main, Kata nama) {
  for (int i = 0; i < nama.Length; i++){
    InfoOrang_Nama(Info_Orang(*main)).TabKata[i] = nama.TabKata[i];
  }
  
  InfoOrang_Nama(Info_Orang(*main)).Length = nama.Length;
  InfoOrang_Duit(Info_Orang(*main)) = 0;

  JAM skrg = MakeJAM(0, 0, 0);
  Info_Waktu(*main) = skrg;

  Info_Prep(*main) = true;
  Info_Main(*main) = false;
}

void printpemain(program main){
  printf("Name: ");
  for (int i = 0; i < InfoOrang_Nama(Info_Orang(main)).Length; i++){
    printf("%c", InfoOrang_Nama(Info_Orang(main)).TabKata[i]);
  }
  printf("\nMoney: %i\n", InfoOrang_Duit(Info_Orang(main)));
  printf("Opening: gatau\n");
  printf("Closing: gatau\n");
  printf("Time remaining: gatau\n");
}