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

void initOffice(MATRIKS *M, POINT *P) {
	Elmt(*M,8,8) = 'O';
	*P = MakePOINT(8,8);
}

void P_to_Dash(MATRIKS *M, POINT P) {
	(*M).Mem[(int)P.Y][(int)P.X] = '-';
}

void Dash_to_P(MATRIKS *M, POINT P) {
	(*M).Mem[(int)P.Y][(int)P.X] = 'P';
}

boolean IsOffice(POINT P1, program main){
  return EQ(P1, Info_Office(main));
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
    initmain(main, CKata);
    MakeMATRIKS(12,12,&Info_Map(*main));
    initMap(&Info_Map(*main));
    initPlayer(&Info_Map(*main),&Info_Posisi(*main));
    initOffice(&Info_Map(*main),&Info_Office(*main));
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

void PrintInfoPrep(program *main){
  printf("Preparation phase day 1\n");
  TulisMATRIKS(Info_Map(*main));
  printf("\n");
  printpemain(*main);
}

void PrintInfoMain(program *main){
  printf("Main phase day 1\n");
  TulisMATRIKS(Info_Map(*main));
  printf("\n");
  printpemain(*main);
}

void play(program *main){
  Kata _exitgame,_w,_a,_s,_d,_office,_main,_prep;
  _main.TabKata[0] = *"m";
  _main.TabKata[1] = *"a";
  _main.TabKata[2] = *"i";
  _main.TabKata[3] = *"n";
  _main.Length = 4;
  _prep.TabKata[0] = *"p";
  _prep.TabKata[1] = *"r";
  _prep.TabKata[2] = *"e";
  _prep.TabKata[3] = *"p";
  _prep.TabKata[4] = *"a";
  _prep.TabKata[5] = *"r";
  _prep.TabKata[6] = *"e";
  _prep.Length = 7;
  _exitgame.TabKata[0] = *"e";
  _exitgame.TabKata[1] = *"x";
  _exitgame.TabKata[2] = *"i";
  _exitgame.TabKata[3] = *"t";
  _exitgame.Length = 4;
  _office.TabKata[0] = *"o";
  _office.TabKata[1] = *"f";
  _office.TabKata[2] = *"f";
  _office.TabKata[3] = *"i";
  _office.TabKata[4] = *"c";
  _office.TabKata[5] = *"e";
  _office.Length = 6;
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
      if (Info_Prep(*main)){
        PrintInfoPrep(main);
      } else {
        PrintInfoMain(main);
      }
      printf("Masukkan perintah:\n");
      if (IsOffice(Info_Posisi(*main), *main)){
        printf("(masukkan office untuk membuka office)\n");
      }
      printf("$ ");
      STARTKATA();
      while(!EndKata){
        // do some cmd
        if (isKataSama(_exitgame, CKata)){
          Info_Main(*main) = false;
          Info_Prep(*main) = false;
          printf("tq\n");
        } else if (isKataSama(_w, CKata)){
          if (IsOffice(Info_Posisi(*main), *main)){
            w(&Info_Map(*main), &Info_Posisi(*main));
            initOffice(&Info_Map(*main),&Info_Office(*main));
          } else {
            w(&Info_Map(*main), &Info_Posisi(*main));
          }
        } else if (isKataSama(_a, CKata)){
          if (IsOffice(Info_Posisi(*main), *main)){
            a(&Info_Map(*main), &Info_Posisi(*main));
            initOffice(&Info_Map(*main),&Info_Office(*main));
          } else {
            a(&Info_Map(*main), &Info_Posisi(*main));
          }
        } else if (isKataSama(_s, CKata)){
          if (IsOffice(Info_Posisi(*main), *main)){
            s(&Info_Map(*main), &Info_Posisi(*main));
            initOffice(&Info_Map(*main),&Info_Office(*main));
          } else {
            s(&Info_Map(*main), &Info_Posisi(*main));
          }
        } else if (isKataSama(_d, CKata)){
          if (IsOffice(Info_Posisi(*main), *main)){
            d(&Info_Map(*main), &Info_Posisi(*main));
            initOffice(&Info_Map(*main),&Info_Office(*main));
          } else {
            d(&Info_Map(*main), &Info_Posisi(*main));
          }
        /* PERINTAH UNTUK PREP PHASE */
        } else if (isKataSama(_main, CKata)){
          Info_Prep(*main) = false;
          Info_Main(*main) = true;
        /* PERINTAH UNTUK MAIN PHASE */
        } else if (isKataSama(_prep, CKata)){
          Info_Prep(*main) = true;
          Info_Main(*main) = false;
        } else if (isKataSama(_office, CKata)){
          if (Info_Main(*main) && IsOffice(Info_Posisi(*main), *main)){
            printf("ini office\n\n");
          } else {
            printf("gabisa buka office krn masih prep atau bkn di posisi\n\n");
          }
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
