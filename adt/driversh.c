#include "mainprogram.h"
#include <math.h>
#include <string.h>
#include "preparationcmd.h"
#include <stdio.h>
#include <stdlib.h>

 Wahana StrukWahana(infotype X){
   Wahana W;
   if(X==1){
     strcpy(W.nama.TabKata,"RollerCoaster");
     W.tipe = 1;
     W.harga = 10;
     W.kapasitas = 10;
     strcpy(W.deskripsi.TabKata,"RollerCoaster");
     W.durasi.HH = 0;
     W.durasi.MM = 10;
     W.durasi.SS = 0;
     W.lokasi = ;
   }
 }


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


