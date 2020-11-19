#include "mainprogram.h"

void initmain(program *main, Kata nama) {
  Orang orgtemp = Info_Orang(*main);
  InfoOrang_Nama(orgtemp) = nama;
  InfoOrang_Duit(orgtemp) = 0;

  JAM skrg = MakeJAM(0, 0, 0);
  Info_Waktu(*main) = skrg;

  Info_Prep(*main) = true;
  Info_Main(*main) = false;
}