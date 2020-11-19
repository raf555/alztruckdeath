#ifndef mainprogram_H
#define mainprogram_H

#include "mesinkata.h"
#include "jam.h"
#include "point.h"
#include "stackt.h"
#include "boolean.h"
#include "matriks.h"
#include "point.h"

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
	Bahan bahan[100];
} Orang;

/* data keseluruhan program */
typedef struct {
	Orang orang;
	JAM sekarang;
	Wahana wahana[100];
	Stack prepexe;
  boolean Main;
  boolean Prep;
	MATRIKS Map;
	POINT posisi;
  POINT office;
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
