#include <stdio.h>
#include <stdlib.h>
#include "../adt/mainprogram.h"

int main() {
  program main;
  init(&main);

  /* load wahana */
  if(Info_Prep(main) || Info_Main(main)) {
    BinTree P;
    WahReader("wahana3.txt",&P);
    MakeListWahana(&main,&P);
  }

  // start
  play(&main);
	return 0;
}