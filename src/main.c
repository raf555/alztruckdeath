#include <stdio.h>
#include <stdlib.h>
#include "../adt/matriks.h"
#include "../adt/point.h"
#include "../adt/mesinkata.h"
#include "../adt/boolean.h"
#include "../adt/mainprogram.h"

void initMap(MATRIKS *M) {
	for(int i=0; i < (*M).NBrsEff; i++) {
		for(int j=0; j < (*M).NKolEff; j++) {
			if (i == 0 || i == (*M).NBrsEff-1) {
				Elmt(*M,i,j) = '*';
			} else {
				if (j == 0 || j == (*M).NKolEff-1) {
					Elmt(*M,i,j) = '*';
				} else {
					Elmt(*M,i,j) = '-';
				}
			}
		}
	}
}

void initPlayer(MATRIKS *M, POINT *P) {
	Elmt(*M,(*M).NBrsEff/2,(*M).NKolEff/2) = 'P';
	*P = MakePOINT((*M).NBrsEff/2,(*M).NKolEff/2);
}

void P_to_Dash(MATRIKS *M, POINT P) {
	(*M).Mem[(int)P.Y][(int)P.X] = '-';
}

void Dash_to_P(MATRIKS *M, POINT P) {
	(*M).Mem[(int)P.Y][(int)P.X] = 'P';
}



void w(MATRIKS *M, POINT *P) {
	if ((*P).Y > 1) {
		P_to_Dash(M,*P);
		(*P).Y--;
		Dash_to_P(M,*P);
	}
}

void a(MATRIKS *M, POINT *P) {
	if ((*P).X > 1) {
		P_to_Dash(M,*P);
		(*P).X--;
		Dash_to_P(M,*P);
	}
}

void s(MATRIKS *M, POINT *P) {
	if ((*P).Y < 10) {
		P_to_Dash(M,*P);
		(*P).Y++;
		Dash_to_P(M,*P);
	}
}

void d(MATRIKS *M, POINT *P) {
	if ((*P).X < 10) {
		P_to_Dash(M,*P);
		(*P).X++;
		Dash_to_P(M,*P);
	}
}

boolean isKataSama(Kata K1, Kata K2){
  // KAMUS
  int i;
  boolean sama = true;

  // ALGORITMA
  if (K1.Length != K2.Length){
    return false;
  } else {
    i = 0;
    while (i < K1.Length && sama){
      if(K1.TabKata[i] != K2.TabKata[i]){
        sama = false;
      }
      i += 1;
    }
    return sama;
  }
}

void inputnama(program *main){
  printf("Masukkan nama:\n$ ");
  STARTKATA();
  while(!EndKata){
    MakeMATRIKS(12,12,&Info_Map(*main));
    initMap(&Info_Map(*main));
    initPlayer(&Info_Map(*main),&Info_Posisi(*main));
    initmain(main, CKata);
    ADVKATA();
  }
}

void init(program *main){
  Kata newgame,loadgame,exitgame;
  boolean end;

  newgame.TabKata[0] = *"n";
  newgame.TabKata[1] = *"e";
  newgame.TabKata[2] = *"w";
  newgame.Length = 3;
  
  loadgame.TabKata[0] = *"l";
  loadgame.TabKata[1] = *"o";
  loadgame.TabKata[2] = *"a";
  loadgame.TabKata[3] = *"d";
  loadgame.Length = 4;

  exitgame.TabKata[0] = *"e";
  exitgame.TabKata[1] = *"x";
  exitgame.TabKata[2] = *"i";
  exitgame.TabKata[3] = *"t";
  exitgame.Length = 4;

  end = false;
  printf("Met dateng (new / load / exit\n");
  while (!end){
    printf("$ ");
    STARTKATA();
    while(!EndKata){
      if(isKataSama(CKata, newgame)){
        inputnama(main);
        end = true;
      } else if(isKataSama(CKata, loadgame)){
        printf("game loaded\n");
        end = true;
      } else if(isKataSama(CKata, exitgame)){
        Info_Main(*main) = false;
        Info_Prep(*main) = false;
        printf("tq\n");
        end = true;
      } else {
        printf("Perintah salah!\n");
      }
      ADVKATA();
    }
  }
}

boolean IsExit(program main){
  return !Info_Main(main) && !Info_Prep(main);
}

void play(program *main){
  Kata exitgame,_w,_a,_s,_d;
  exitgame.TabKata[0] = *"e";
  exitgame.TabKata[1] = *"x";
  exitgame.TabKata[2] = *"i";
  exitgame.TabKata[3] = *"t";
  exitgame.Length = 4;
  _w.TabKata[0] = *"w";
  _a.TabKata[0] = *"a";
  _s.TabKata[0] = *"s";
  _d.TabKata[0] = *"d";
  _w.Length = 1;
  _a.Length = 1;
  _s.Length = 1;
  _d.Length = 1;

  if(!IsExit(*main)){
    while (!IsExit(*main)){
      printf("Preparation phase day 1\n");
      TulisMATRIKS(Info_Map(*main));
      printf("\n");
      printpemain(*main);
      printf("Masukkan perintah:\n$ ");
      STARTKATA();
      while(!EndKata){
        // do some cmd
        if (isKataSama(exitgame, CKata)){
          Info_Main(*main) = false;
          Info_Prep(*main) = false;
          printf("tq\n");
        } else if (isKataSama(_w, CKata)){
          w(&Info_Map(*main), &Info_Posisi(*main));
        } else if (isKataSama(_a, CKata)){
          a(&Info_Map(*main), &Info_Posisi(*main));
        } else if (isKataSama(_s, CKata)){
          s(&Info_Map(*main), &Info_Posisi(*main));
        } else if (isKataSama(_d, CKata)){
          d(&Info_Map(*main), &Info_Posisi(*main));
        } else {
          printf("Cmd salah!\n\n");
        }
        ADVKATA();
      }
    }
  }
}

int main() {
  program main;
  init(&main);

  play(&main);
	return 0;
}