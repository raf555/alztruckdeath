#ifndef preparationcmd_H
#define preparationcmd_H

#include "jam.h"
#include "point.h"
#include "mesinkata.h"
#include "mainprogram.h"

/* tipe data perintah pada preparation phase */
typedef struct { 
	JAM waktu; // banyaknya waktu yang dibutuhkan per-cmd
	Kata perintah; // command
	Wahana targetwahana; // target utk wahana
  Bahan targetbahan; // target utk bahan
} cmd;

/* selektor */
#define WaktuCMD(c) (c).waktu
#define PerintahCMD(c) (c).perintah
#define TargetWahana(c) (c).targetwahana
#define TargetBahan(c) (c).targetbahan

#endif
