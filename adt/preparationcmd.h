#ifndef preparationcmd_H
#define preparationcmd_H

#include "jam.h"
#include "point.h"
#include "mesinkata.h"

/* target cmd */
typedef struct { 
	POINT titik; // untuk cmd build
	Kata wahana; // untuk cmd upgrade
	int jumlah; // untuk cmd buy
} targetcmd;

/* tipe data perintah pada preparation phase */
typedef struct {
  int harga; 
	JAM waktu; // banyaknya waktu yang dibutuhkan per-cmd
	Kata perintah; // command
	Kata target; // target cmd (bisa wahana / bahan)
	targetcmd targetvalue; // value yg akan diubah utk target
} cmd;

/* selektor */
#define HargaCMD(c) (c).harga
#define WaktuCMD(c) (c).waktu
#define PerintahCMD(c) (c).perintah
#define TargetCMD(c) (c).target
#define TargetBuild(c) (c).targetvalue.titik
#define TargetUpgrade(c) (c).targetvalue.wahana
#define TargetBuy(c) (c).targetvalue.jumlah

#endif
