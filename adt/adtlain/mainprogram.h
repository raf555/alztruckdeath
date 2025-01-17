#ifndef mainprogram_H
#define mainprogram_H

#include "../mesinkar_mesinkata/mesinkata.h"
#include "../jam/jam.h"
#include "../point/point.h"
#include "../stack/stackt.h"
#include "../boolean.h"
#include "../matriks/matriks.h"
#include "../point/point.h"
#include "maindata.h"
#include "../tree/wahanatree.h"

#define maxel 100

/* data keseluruhan program */
typedef struct {
	Orang orang; // nyimpen data org
	Wahana wahana[maxel]; // nyimpen list wahana
  Wahana wahana_map[maxel]; // nyimpen list wahana yg ada di MAP
  BinTree wahana_tree; // tree wahana
  /* waktu-waktuan */
	JAM sekarang; // nyimpen jam skrg
  JAM opening; // opening
  JAM closing; // closing
  int dayprep;
  int daymain;
  /* cmd related */
	Stack prepexe; // stack preparation cmd
  int totalexe;
  JAM waktuexe;
  /* config program */
  boolean Main; // main phase
  boolean Prep; // prep phase
  /* data map */
	MATRIKS Map; // data map
	MATRIKS Map2;
	MATRIKS Map3;
	MATRIKS Map4;
  int currentmap;
	POINT posisi; // posisi pemain
  POINT office; // posisi office
} program;

/* selektor */

// keseluruhan program
#define Info_Orang(c) (c).orang
#define Info_Waktu(c) (c).sekarang
#define Info_Opening(c) (c).opening
#define Info_Closing(c) (c).closing
#define Info_Wahana(c, i) (c).wahana[(i)]
#define Info_WahanaMap(c, i) (c).wahana_map[(i)]
#define Info_WahanaTree(c) (c).wahana_tree
#define Info_StackCMD(c) (c).prepexe
#define Info_TotalPriceCMD(c) (c).totalexe
#define Info_WaktuCMD(c) (c).waktuexe
#define Info_Main(c) (c).Main
#define Info_Prep(c) (c).Prep
#define Info_Map(c) (c).Map
#define Info_Map2(c) (c).Map2
#define Info_Map3(c) (c).Map3
#define Info_Map4(c) (c).Map4
#define Info_CurrentMap(c) (c).currentmap
#define Info_Posisi(c) (c).posisi
#define Info_Office(c) (c).office
#define Info_DayPrep(c) (c).dayprep
#define Info_DayMain(c) (c).daymain

// init
void initmain(program *main, Kata nama);
void initgame(program *main);
void init(program *main);
void play(program *main);
void initMap(MATRIKS *M);
void initPlayer(MATRIKS *M, POINT *P);
void initOffice(MATRIKS *M, POINT *P);

// print2an
void printpemain(program main);
void PrintInfoWahana (Wahana x);
void PrintInfoPrep(program main);
void PrintInfoMain(program main);
void printwaktu(JAM jam);

// bool function
boolean IsOffice(POINT P1, program main);
boolean isWahanaAda(program main, Kata wahana);
boolean IsExit(program main);
boolean isBahanAda(program main, Kata bahan);

// search function
Wahana CariWahana(program main, Kata wahana);
Bahan CariBahan(program main, Kata bahan);

// fungsi-fungsi / prosedur lain
// prep n main
void SetPrepare(program *main);
void SetMain(program *main);

// wasd
void P_to_Dash(MATRIKS *M, POINT P);
void Dash_to_P(MATRIKS *M, POINT P);
void w(program *main);
void a(program *main);
void s(program *main);
void d(program *main);
void initpanah(program *M);

// office
void office(program main);
void wahana_print(program main, boolean prep);
void wahana_details_print(program main, Kata choice);
void wahana_details(program main);
void wahana_reports_print(program main, Kata choice);
void wahana_reports(program main);

// build
void AddWahanaToMap(MATRIKS *M, int X, int Y);
void build (program *main);

//buy
void buy (program *main);
void bahan_print(program main, boolean prep);

//repair
void repair (program *main);

//upgrade
void upgrade (program *main);
void LocateThenUpgrade(program main, int absis, int ordinat, cmd c);
Wahana LocateWahana (program main, int absis, int ordinat,int denah);

// execute
void execute(program *main);

//undo
void undo(program *main);

// tree wahana
void initListWahana(int i,program *main,BinTree *T);
void MakeListWahana(program *main,BinTree *T);
void initTreeWahana(BinTree *T);

// initmaterial
void addToListBahan(int i, program *main, Bahan B);
void BahReader(char *namafile, program *main);
void RusakinWahana(program *main);
boolean isWahanaRusak(Wahana W,program main);
void BenerinWahana(Wahana W,program *main);

Wahana CariWahanabyID(program main, int id);
void printFromListKata(Kata temp[]);
void searchUpgradeable (BinTree T, int ID, Kata temp[]);

#endif
