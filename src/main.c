#include <stdio.h>
#include <stdlib.h>
#include "../adt/mainprogram.h"

int main() {
  program main;
  init(&main);

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

  // start
  play(&main);
	return 0;
}