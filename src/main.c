#include <stdio.h>
#include <stdlib.h>
#include "../adt/mesinkata.h"
#include "../adt/boolean.h"
#include "../adt/mainprogram.h"

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
    ADVKATA();
  }
  printf("Preparation day phase 1\n");
  printf("Ini map ama legend\n\n\n");
  printpemain(*main);
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
  Kata exitgame;
  exitgame.TabKata[0] = *"e";
  exitgame.TabKata[1] = *"x";
  exitgame.TabKata[2] = *"i";
  exitgame.TabKata[3] = *"t";
  exitgame.Length = 4;

  if(!IsExit(*main)){
    while (!IsExit(*main)){
      printf("Masukkan perintah:\n$ ");
      STARTKATA();
      while(!EndKata){
        // do some cmd
        if (isKataSama(exitgame, CKata)){
          Info_Main(*main) = false;
          Info_Prep(*main) = false;
          printf("tq\n");
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