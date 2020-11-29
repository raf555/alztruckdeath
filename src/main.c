#include <stdio.h>
#include <stdlib.h>
#include "adt/mainprogram.h"

int main() {
  program main;
  init(&main);

  /* load wahana */
  if(Info_Prep(main) || Info_Main(main)) {
    WahReader("wahana3.txt",&Info_WahanaTree(main));
    MakeListWahana(&main,&Info_WahanaTree(main));
  }

  // start
  play(&main);
	return 0;
}