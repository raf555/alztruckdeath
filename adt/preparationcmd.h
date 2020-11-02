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
	JAM waktu; // banyaknya waktu yang dibutuhkan per-cmd
	Kata perintah; // command
	targetcmd target; // target
} cmd;

/* selektor */
#define WaktuCMD(c) (c).waktu
#define PerintahCMD(c) (c).perintah
#define TargetBuild(c) (c).target.titik
#define TargetUpgrade(c) (c).target.wahana
#define TargetBuy(c) (c).target.jumlah

#endif
