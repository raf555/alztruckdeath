#ifndef mainprogram_H
#define mainprogram_H

#include "mesinkata.h"
#include "jam.h"
#include "point.h"
#include "stackt.h"
#include "boolean.h"
#include "matriks.h"
#include "point.h"

#define maxel 100

/* data wahana */
typedef struct {
	Kata nama;
	int tipe;
	int harga;
	int kapasitas;
	Kata deskripsi;
	JAM durasi;
	POINT lokasi;
	// history ama ukuran blom
} Wahana;

/* data bahan */
typedef struct {
	Kata nama;
	int jumlah;
} Bahan;

/* data orangnya */
typedef struct {
	Kata nama;
	int duit;
	Bahan bahan[maxel];
} Orang;

/* data keseluruhan program */
typedef struct {
	Orang orang; // nyimpen data org
	JAM sekarang; // nyimpen jam skrg
	Wahana wahana[maxel]; // nyimpen list wahana
  Wahana wahana_map[maxel]; // nyimpen list wahana yg ada di MAP
	Stack prepexe; // stack preparation cmd
  boolean Main; // main phase
  boolean Prep; // prep phase
	MATRIKS Map; // data map
	POINT posisi; // posisi pemain
  POINT office; // posisi office
} program;

/* selektor */

// wahana
#define InfoWahana_Nama(c) (c).nama
#define InfoWahana_Tipe(c) (c).tipe
#define InfoWahana_Harga(c) (c).harga
#define InfoWahana_Kapasitas(c) (c).kapasitas
#define InfoWahana_Deskripsi(c) (c).deskripsi
#define InfoWahana_Durasi(c) (c).durasi
#define InfoWahana_lokasi(c) (c).lokasi

// orang ama bahan
#define InfoOrang_Nama(c) (c).nama
#define InfoOrang_Duit(c) (c).duit
#define InfoOrang_Bahan_Nama(c, i) (c).bahan[(i)].nama
#define InfoOrang_Bahan_Jumlah(c, i) (c).bahan[(i)].jumlah

// keseluruhan program
#define Info_Orang(c) (c).orang
#define Info_Waktu(c) (c).sekarang
#define Info_Wahana(c, i) (c).wahana[(i)]
#define Info_WahanaMap(c, i) (c).wahana_map[(i)]
#define Info_StackCMD(c) (c).prepexe
#define Info_Main(c) (c).Main
#define Info_Prep(c) (c).Prep
#define Info_Map(c) (c).Map
#define Info_Posisi(c) (c).posisi
#define Info_Office(c) (c).office

// init
void initmain(program *main, Kata nama);

// print info orang
void printpemain(program main);

#endif
