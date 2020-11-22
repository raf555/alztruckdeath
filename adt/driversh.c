#include "mainprogram.h"
#include <math.h>
#include "preparationcmd.h"
#include <stdio.h>
#include <stdlib.h>



int main(){
  program main;
  init(&main);
    InfoOrang_Bahan_Nama(Info_Orang(main),0).TabKata[0] = 'P';
    InfoOrang_Bahan_Nama(Info_Orang(main),0).TabKata[1] = 'G';
    InfoOrang_Bahan_Nama(Info_Orang(main),0).Length = 2;
  // tes wahana
  POINT bknwahana;
  bknwahana.X = -999;
  bknwahana.Y = -999;
  Wahana a;
  a.tipe = 0;
  a.harga = 2000;
  a.deskripsi.TabKata[0] = *"g";
  a.deskripsi.Length = 1;
  a.nama.TabKata[0] = *"g";
  a.nama.Length = 1;
  a.kapasitas = 1;
  a.lokasi = bknwahana;
  main.wahana[0] = a;

    play(&main);
}


