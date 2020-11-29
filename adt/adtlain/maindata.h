#ifndef maindata_H
#define maindata_H

#define maxeL 100

/* data wahana */
typedef struct {
	Kata nama;
	int tipe;
	int harga;
	int kapasitas;
	Kata deskripsi;
	JAM durasi;
	POINT lokasi;
  	int denah;
	int rusak;
	// history ama ukuran blom
} Wahana;

/* data bahan */
typedef struct {
	Kata nama;
	int jumlah;
	int harga;
} Bahan;

/* data orangnya */
typedef struct {
	Kata nama;
	int duit;
	Bahan bahan[maxeL];
} Orang;

/* selektor */
// wahana
#define InfoWahana_Nama(c) (c).nama
#define InfoWahana_Tipe(c) (c).tipe
#define InfoWahana_Harga(c) (c).harga
#define InfoWahana_Kapasitas(c) (c).kapasitas
#define InfoWahana_Deskripsi(c) (c).deskripsi
#define InfoWahana_Durasi(c) (c).durasi
#define InfoWahana_lokasi(c) (c).lokasi
#define InfoWahana_lokasidenah(c) (c).denah

// bahan
#define InfoBahan_Nama(c) (c).nama
#define InfoBahan_Jumlah(c) (c).jumlah
#define InfoBahan_Harga(c) (c).harga

// orang ama bahan
#define InfoOrang_Nama(c) (c).nama
#define InfoOrang_Duit(c) (c).duit
#define InfoOrang_Bahan(c, i) (c).bahan[(i)]
#define InfoOrang_Bahan_Nama(c, i) (c).bahan[(i)].nama
#define InfoOrang_Bahan_Jumlah(c, i) (c).bahan[(i)].jumlah

#endif