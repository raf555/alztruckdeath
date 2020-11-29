#include <stdio.h>
#include <stdlib.h>
#include "../adt/mainprogram.h"

int main() {
  program main;
  init(&main);

  /* load wahana */
  if(!IsExit(main)) {
    WahReader("wahana3.txt",&Info_WahanaTree(main));
    MakeListWahana(&main,&Info_WahanaTree(main));
  
    /*load bahan */
    BahReader("../exfile/material.txt",&Info_Orang(main).bahan);

  }
  // start
  play(&main);
	return 0;
}
