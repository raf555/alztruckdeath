#include <stdio.h>
#include "stackt.h"

int main(void) {
  Stack S;
  cmd tescmd;
  cmd pop;
  Kata tes,target;
  tes.TabKata[0] = *"t";
  tes.TabKata[1] = *"e";
  tes.TabKata[2] = *"s";
  tes.Length = 3;
  target.TabKata[0] = *"u";
  target.TabKata[1] = *"w";
  target.TabKata[2] = *"u";
  target.Length = 3;

  tescmd.harga = 9999;
  tescmd.perintah = tes;
  tescmd.waktu = MakeJAM(2, 2, 2);
  tescmd.target = target;
  tescmd.targetvalue.denah = 1;
  tescmd.targetvalue.titik = MakePOINT(2, 2);
  tescmd.targetvalue.jumlah = 2;
  tescmd.targetvalue.wahana = target;

  CreateEmpty(&S);
  Push(&S, tescmd);
  printf("nbelmt stack sblm pop = %i\n", NbElmtStack(S));
  Pop(&S, &pop);
  printf("nbelmt stack ssdh pop = %i\ndata hasil pop:\n", NbElmtStack(S));
  printf("harga cmd: %i\n", pop.harga);
  printf("perintah cmd: ");
  for (int i = 0; i < pop.perintah.Length; i++){
    printf("%c", pop.perintah.TabKata[i]);
  }
  printf("\ndurasi cmd: ");
  TulisJAM(pop.waktu);
  printf("\ntarget cmd: ");
  for (int i = 0; i < pop.target.Length; i++){
    printf("%c", pop.target.TabKata[i]);
  }
  printf("\ndenah target cmd buat build: %i\n", pop.targetvalue.denah);
  printf("titik target cmd buat build: ");
  TulisPOINT(pop.targetvalue.titik);
  printf("\njumlah target cmd buat buy: %i\nwahana target cmd buat upgrade: ", pop.targetvalue.jumlah);
  for (int i = 0; i < pop.targetvalue.wahana.Length; i++){
    printf("%c", pop.targetvalue.wahana.TabKata[i]);
  }
  printf("\n");
  return 0;
}