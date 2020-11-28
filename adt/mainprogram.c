#include "mainprogram.h"
#include <stdio.h>

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

void initmain(program *main, Kata nama) {
  for (int i = 0; i < nama.Length; i++){
    InfoOrang_Nama(Info_Orang(*main)).TabKata[i] = nama.TabKata[i];
  }
  
  InfoOrang_Nama(Info_Orang(*main)).Length = nama.Length;
  InfoOrang_Duit(Info_Orang(*main)) = 1000;

  Info_Waktu(*main) = MakeJAM(21, 0, 0);
  Info_Opening(*main) = MakeJAM(9, 0, 0);
  Info_Closing(*main) = MakeJAM(21, 0, 0);

  Info_Prep(*main) = true;
  Info_Main(*main) = false;

  CreateEmpty(&Info_StackCMD(*main));
  Info_WaktuCMD(*main) = MakeJAM(0, 0, 0);
  Info_CurrentMap(*main) = 0;

  Info_DayPrep(*main) = 1;
}

void initpanah(program *main){
  Elmt(Info_Map(*main), 11, 5) = *"V";
  Elmt(Info_Map(*main), 5, 11) = *">";

  Elmt(Info_Map2(*main), 11, 5) = *"V";
  Elmt(Info_Map2(*main), 5, 0) = *"<";

  Elmt(Info_Map3(*main), 0, 5) = *"^";
  Elmt(Info_Map3(*main), 5, 0) = *"<";

  Elmt(Info_Map4(*main), 0, 5) = *"^";
  Elmt(Info_Map4(*main), 5, 11) = *">";
}

void initgame(program *main){
  printf("Memulai permainan baru...\nMasukkan nama:\n$ ");
  STARTKATA();
  while(!EndKata){
    initmain(main, CKata);
    MakeMATRIKS(12,12,&Info_Map(*main));
    MakeMATRIKS(12,12,&Info_Map2(*main));
    MakeMATRIKS(12,12,&Info_Map3(*main));
    MakeMATRIKS(12,12,&Info_Map4(*main));
    initMap(&Info_Map(*main));
    initMap(&Info_Map2(*main));
    initMap(&Info_Map3(*main));
    initMap(&Info_Map4(*main));
    initpanah(main);
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
        initgame(main);
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

void P_to_Dash(MATRIKS *M, POINT P) {
	(*M).Mem[(int)P.Y][(int)P.X] = '-';
}

void Dash_to_P(MATRIKS *M, POINT P) {
	(*M).Mem[(int)P.Y][(int)P.X] = 'P';
}

boolean IsOffice(POINT P1, program main){
  return EQ(P1, Info_Office(main));
}

void w(program *main) {
	if (Info_Posisi(*main).Y >= 1) {
    MATRIKS *mapb4, *mapa4;
    if (Info_CurrentMap(*main) == 2){
      mapb4 = &Info_Map3(*main);
      mapa4 = &Info_Map2(*main);
    } else if (Info_CurrentMap(*main) == 3){
      mapb4 = &Info_Map4(*main);
      mapa4 = &Info_Map(*main);
    } else if (Info_CurrentMap(*main) == 0){
      mapb4 = &Info_Map(*main);
    } else if (Info_CurrentMap(*main) == 1){
      mapb4 = &Info_Map2(*main);
    }
    if (Elmt(*mapb4, (int) Ordinat(Info_Posisi(*main))-1, (int) Absis(Info_Posisi(*main))) == *"^"){
      if (Info_CurrentMap(*main) == 2) {
        Info_CurrentMap(*main) = 1;
      } else if (Info_CurrentMap(*main) == 3) {
        Info_CurrentMap(*main) = 0;
      }
		  P_to_Dash(mapb4,Info_Posisi(*main));
      Info_Posisi(*main) = MakePOINT(5, 11);
		  Info_Posisi(*main).Y--;
		  Dash_to_P(mapa4,Info_Posisi(*main));
        if(Info_Main(*main)){
          int nows = JAMToDetik(Info_Waktu(*main));
          Info_Waktu(*main) = DetikToJAM((long) nows+60);
        }
    } else { 
      if(Info_Posisi(*main).Y > 1){
        P_to_Dash(mapb4,Info_Posisi(*main));
        Info_Posisi(*main).Y--;
        Dash_to_P(mapb4,Info_Posisi(*main));
        if(Info_Main(*main)){
          int nows = JAMToDetik(Info_Waktu(*main));
          Info_Waktu(*main) = DetikToJAM((long) nows+60);
        }
      }
    }
	}
}

void a(program *main) {
	if (Info_Posisi(*main).X >= 1) {
    MATRIKS *mapb4, *mapa4;
    if (Info_CurrentMap(*main) == 1){
      mapb4 = &Info_Map2(*main);
      mapa4 = &Info_Map(*main);
    } else if (Info_CurrentMap(*main) == 2){
      mapb4 = &Info_Map3(*main);
      mapa4 = &Info_Map4(*main);
    } else if (Info_CurrentMap(*main) == 3){
      mapb4 = &Info_Map4(*main);
    } else if (Info_CurrentMap(*main) == 0){
      mapb4 = &Info_Map(*main);
    }
    if (Elmt(*mapb4, (int) Ordinat(Info_Posisi(*main)), (int) Absis(Info_Posisi(*main))-1) == *"<"){
      if (Info_CurrentMap(*main) == 1) {
        Info_CurrentMap(*main) = 0;
      } else if (Info_CurrentMap(*main) == 2) {
        Info_CurrentMap(*main) = 3;
      }
		  P_to_Dash(mapb4,Info_Posisi(*main));
      Info_Posisi(*main) = MakePOINT(11, 5);
		  Info_Posisi(*main).X--;
		  Dash_to_P(mapa4,Info_Posisi(*main));
        if(Info_Main(*main)){
          int nows = JAMToDetik(Info_Waktu(*main));
          Info_Waktu(*main) = DetikToJAM((long) nows+60);
        }
    } else { 
      if(Info_Posisi(*main).X > 1){
        P_to_Dash(mapb4,Info_Posisi(*main));
        Info_Posisi(*main).X--;
        Dash_to_P(mapb4,Info_Posisi(*main));
        if(Info_Main(*main)){
          int nows = JAMToDetik(Info_Waktu(*main));
          Info_Waktu(*main) = DetikToJAM((long) nows+60);
        }
      }
    }
	}
}

void s(program *main) {
	if (Info_Posisi(*main).Y <= 10) {
    MATRIKS *mapb4, *mapa4;
    if (Info_CurrentMap(*main) == 0){
      mapb4 = &Info_Map(*main);
      mapa4 = &Info_Map4(*main);
    } else if (Info_CurrentMap(*main) == 1){
      mapb4 = &Info_Map2(*main);
      mapa4 = &Info_Map3(*main);
    } else if (Info_CurrentMap(*main) == 2){
      mapb4 = &Info_Map3(*main);
    } else if (Info_CurrentMap(*main) == 3){
      mapb4 = &Info_Map4(*main);
    }
    if (Elmt(*mapb4, (int) Ordinat(Info_Posisi(*main))+1, (int) Absis(Info_Posisi(*main))) == *"V"){
      if (Info_CurrentMap(*main) == 0) {
        Info_CurrentMap(*main) = 3;
      } else if (Info_CurrentMap(*main) == 1) {
        Info_CurrentMap(*main) = 2;
      }
		  P_to_Dash(mapb4,Info_Posisi(*main));
      Info_Posisi(*main) = MakePOINT(5, 0);
		  Info_Posisi(*main).Y++;
		  Dash_to_P(mapa4,Info_Posisi(*main));
        if(Info_Main(*main)){
          int nows = JAMToDetik(Info_Waktu(*main));
          Info_Waktu(*main) = DetikToJAM((long) nows+60);
        }
    } else { 
      if(Info_Posisi(*main).Y < 10){
        P_to_Dash(mapb4,Info_Posisi(*main));
        Info_Posisi(*main).Y++;
        Dash_to_P(mapb4,Info_Posisi(*main));
        if(Info_Main(*main)){
          int nows = JAMToDetik(Info_Waktu(*main));
          Info_Waktu(*main) = DetikToJAM((long) nows+60);
        }
      }
    }
	}
}

void d(program *main) {
	if (Info_Posisi(*main).X <= 10) {
    MATRIKS *mapb4, *mapa4;
    if (Info_CurrentMap(*main) == 0){
      mapb4 = &Info_Map(*main);
      mapa4 = &Info_Map2(*main);
    } else if (Info_CurrentMap(*main) == 3){
      mapb4 = &Info_Map4(*main);
      mapa4 = &Info_Map3(*main);
    } else if (Info_CurrentMap(*main) == 1){
      mapb4 = &Info_Map2(*main);
    } else if (Info_CurrentMap(*main) == 2){
      mapb4 = &Info_Map3(*main);
    }
    if (Elmt(*mapb4, (int) Ordinat(Info_Posisi(*main)), (int) Absis(Info_Posisi(*main))+1) == *">"){
      if (Info_CurrentMap(*main) == 0) {
        Info_CurrentMap(*main) = 1;
      } else if (Info_CurrentMap(*main) == 3) {
        Info_CurrentMap(*main) = 2;
      }
		  P_to_Dash(mapb4,Info_Posisi(*main));
      Info_Posisi(*main) = MakePOINT(0, 5);
		  Info_Posisi(*main).X++;
		  Dash_to_P(mapa4,Info_Posisi(*main));
        if(Info_Main(*main)){
          int nows = JAMToDetik(Info_Waktu(*main));
          Info_Waktu(*main) = DetikToJAM((long) nows+60);
        }
    } else { 
      if(Info_Posisi(*main).X < 10){
        P_to_Dash(mapb4,Info_Posisi(*main));
        Info_Posisi(*main).X++;
        Dash_to_P(mapb4,Info_Posisi(*main));
        if(Info_Main(*main)){
          int nows = JAMToDetik(Info_Waktu(*main));
          Info_Waktu(*main) = DetikToJAM((long) nows+60);
        }
      }
    }
	}
}

void wahana_print(program main, boolean prep) {
  //printf("List Wahana:\n");
  for (int i = 0; i < maxel; i++){
    if (prep) {
      for (int j = 0; j < InfoWahana_Nama(Info_Wahana(main, i)).Length; j++){
        if (InfoWahana_Nama(Info_Wahana(main, i)).Length>0){
          if (j == 0){
            printf("   - ");
          }
          printf("%c", InfoWahana_Nama(Info_Wahana(main, i)).TabKata[j]);
          if (j == InfoWahana_Nama(Info_Wahana(main, i)).Length-1){
            printf("\n");
          }
        }
      }
    } else {
      for (int j = 0; j < InfoWahana_Nama(Info_WahanaMap(main, i)).Length; j++){
        if (InfoWahana_Nama(Info_WahanaMap(main, i)).Length>0){
          if (j == 0){
            printf("   - ");
          }
          printf("%c", InfoWahana_Nama(Info_WahanaMap(main, i)).TabKata[j]);
          if (j == InfoWahana_Nama(Info_WahanaMap(main, i)).Length-1){
            printf(" (%i,%i) (Denah: %i)", (int) Absis(InfoWahana_lokasi(Info_WahanaMap(main, i))), (int) Ordinat(InfoWahana_lokasi(Info_WahanaMap(main, i))),InfoWahana_lokasidenah(Info_WahanaMap(main,i))+1);
            printf("\n");
          }
        }
      }
    }
  }
}

void wahana_details_print(program main, Kata choice) {
  boolean found = false;
  for (int i = 0; i < maxel; i++){
    if (isKataSama(choice, InfoWahana_Nama(Info_WahanaMap(main, i)))){
      PrintInfoWahana(Info_WahanaMap(main, i));
      printf("\n");
      found = true;
      //break;
    }
  }
  if (!found) {
    printf("Wahana tidak ditemukan\n\n");
  }
}

void wahana_details(program main) {
	// KAMUS

	// ALGORITMA
	printf("Pilih wahana pada Map:\n(jika terdapat lebih dari satu, maka pilih salah satu saja dan tulis nama tanpa koordinat)\n");
	wahana_print(main, false);
  printf("\n$ ");
	STARTKATA();
	while (!EndKata) {
		wahana_details_print(main, CKata);
    ADVKATA();
	}
}


void wahana_reports_print(program main, Kata choice) {
	// baca file
	// print semua detail sesuai choice
	// kalo gaada, kirim error
  printf("report wahana\n");
}

void wahana_reports(program main) {
	// KAMUS

	// ALGORITMA
	printf("Pilih wahana pada Map:\n(jika terdapat lebih dari satu, maka pilih salah satu saja dan tulis nama tanpa koordinat)\n");
	wahana_print(main, false);
  printf("\n$ ");
	STARTKATA();
	while (!EndKata) {
		wahana_reports_print(main, CKata);
    ADVKATA();
	}
}


void office(program main) {
	// KAMUS
	boolean end;

	// ALGORITMA
	end = false;
	while (!end) {
    Kata CCdetails;
    CCdetails.TabKata[0] = *"d";
    CCdetails.TabKata[1] = *"e";
    CCdetails.TabKata[2] = *"t";
    CCdetails.TabKata[3] = *"a";
    CCdetails.TabKata[4] = *"i";
    CCdetails.TabKata[5] = *"l";
    CCdetails.TabKata[6] = *"s";
    CCdetails.Length = 7;

    Kata CCreports;
    CCreports.TabKata[0] = *"r";
    CCreports.TabKata[1] = *"e";
    CCreports.TabKata[2] = *"p";
    CCreports.TabKata[3] = *"o";
    CCreports.TabKata[4] = *"r";
    CCreports.TabKata[5] = *"t";
    CCreports.TabKata[6] = *"s";
    CCreports.Length = 7;

    Kata CCexit;
    CCexit.TabKata[0] = *"e";
    CCexit.TabKata[1] = *"x";
    CCexit.TabKata[2] = *"i";
    CCexit.TabKata[3] = *"t";
    CCexit.Length = 4;
		printf("\nMasukkan perintah (details / reports / exit)\n$ ");

		STARTKATA();
		while (!EndKata) {
			if (isKataSama(CKata, CCdetails)) {
				wahana_details(main);
			} else if (isKataSama(CKata, CCreports)) {
				wahana_reports(main);
			} else if (isKataSama(CKata, CCexit)) {
				end = true;
			} else {
				printf("Command salah!\n");
			}
      ADVKATA();
		}
	}
}

void AddWahanaToMap(MATRIKS *M, int X, int Y) {
	Elmt(*M,Y,X) = 'W';
}

void build (program *main) {
	// KAMUS
	boolean sabi;
	JAM waktu;
	Kata _build;
	_build.TabKata[0] = *"b";
	_build.TabKata[1] = *"u";
	_build.TabKata[2] = *"i";
	_build.TabKata[3] = *"l";
	_build.TabKata[4] = *"d";
	_build.Length = 5;
  int price = 100;
  long durasi = 3600;
  cmd build;
  MATRIKS *map;
	
	// ALGORITMA
	if (!Info_Prep(*main)) {
		printf("Anda sedang dalam main phase!");
	} else {
    if(Info_CurrentMap(*main) == 0){
      map = &Info_Map(*main);
    } else if(Info_CurrentMap(*main) == 1){
      map = &Info_Map2(*main);
    } else if(Info_CurrentMap(*main) == 2){
      map = &Info_Map3(*main);
    } else if(Info_CurrentMap(*main) == 3){
      map = &Info_Map4(*main);
    }
		printf("Ingin membangun apa?\n");
		wahana_print(*main, true);
    printf("$ ");
		STARTKATA();
		while (!EndKata) {
      // cek duit
      if(InfoOrang_Duit(Info_Orang(*main))>=price && Info_TotalPriceCMD(*main)+price<=InfoOrang_Duit(Info_Orang(*main))){
        // cek waktu
        if (JAMToDetik(Info_WaktuCMD(*main))+durasi<=Durasi(Info_Waktu(*main), Info_Opening(*main))){
          if(!(Elmt(*map, (int) Ordinat(Info_Posisi(*main))+1, (int) Absis(Info_Posisi(*main))+1) == *"V" || Elmt(*map, (int) Ordinat(Info_Posisi(*main)), (int) Absis(Info_Posisi(*main))+1+1) == *">" || Elmt(*map, (int) Ordinat(Info_Posisi(*main))-1, (int) Absis(Info_Posisi(*main))+1) == *"^")){
            // cek wahana
            if (isWahanaAda(*main, CKata)){
              // cek sekitar pemain
              if(Elmt(*map, (int) Ordinat(Info_Posisi(*main)), (int) Absis(Info_Posisi(*main))+1) == *"-"){
                // masukin (semu) wahana ke map
                AddWahanaToMap(map, Absis(Info_Posisi(*main))+1,Ordinat(Info_Posisi(*main)));

                // tambahin waktu sama duit ke program
                Info_TotalPriceCMD(*main) += price;
                Info_WaktuCMD(*main) = DetikToJAM(JAMToDetik(Info_WaktuCMD(*main))+durasi);

                // masukin ke stack
                WaktuCMD(build) = DetikToJAM(durasi);
                HargaCMD(build) = price;
                PerintahCMD(build) = _build;
                TargetCMD(build) = CKata;
                TargetBuild(build).X = Absis(Info_Posisi(*main))+1;
                TargetBuild(build).Y = Ordinat(Info_Posisi(*main));
                TargetDenah(build) = Info_CurrentMap(*main);
                Push (&Info_StackCMD(*main), build);
              } else {
                printf("Ada sesuatu di kanan pemain, tidak dapat membangun wahana!\n");
              }
            } else {
              printf("Wahana tidak ditemukan!\n");
            }
          } else {
            printf("Tidak dapat membangun menghalangi entry!\n");
          }
        } else {
          printf("Tidak cukup waktu!\n");
        }
      } else {
          printf("Tidak cukup uang!\n");
      }
      ADVKATA();
		}
	}
}

void execute(program *main) {
	Stack target;
  cmd c;
	CopyStack(Info_StackCMD(*main), &target);
	ReverseStack(&target);
  Kata _build,_buy,_upgrade;

  _build.TabKata[0] = *"b";
  _build.TabKata[1] = *"u";
  _build.TabKata[2] = *"i";
  _build.TabKata[3] = *"l";
  _build.TabKata[4] = *"d";
  _build.Length = 5;

  _buy.TabKata[0] = *"b";
  _buy.TabKata[1] = *"u";
  _buy.TabKata[2] = *"y";
  _buy.Length = 3;

  _upgrade.TabKata[0] = *"u";
  _upgrade.TabKata[1] = *"p";
  _upgrade.TabKata[2] = *"g";
  _upgrade.TabKata[3] = *"r";
  _upgrade.TabKata[4] = *"a";
  _upgrade.TabKata[5] = *"d";
  _upgrade.TabKata[6] = *"e";
  _upgrade.Length = 7;

	while (!IsEmpty(target)) {
		Pop(&target, &c);
    InfoOrang_Duit(Info_Orang(*main)) -= HargaCMD(c);
		// KURANGWAKTU(sekian) keknya ini gaperlu, waktu diperluin buat undo aja
		if (isKataSama(c.perintah, _build)) {
      for (int i = 0; i < maxel; i++){
        if (InfoWahana_Nama(Info_WahanaMap(*main,i)).Length==0){
          Info_WahanaMap(*main,i) = CariWahana(*main, TargetCMD(c));
          Info_WahanaMap(*main,i).lokasi.X = c.targetvalue.titik.X;
          Info_WahanaMap(*main,i).lokasi.Y = c.targetvalue.titik.Y;
          Info_WahanaMap(*main,i).denah = c.targetvalue.denah;
          break;
        }
      }
		} else if (isKataSama(c.perintah, _buy)) {
        for (int i = 0; i < maxel; i++){
          if (isKataSama(Info_Orang(*main).bahan[i].nama,TargetCMD(c))){
            Info_Orang(*main).bahan[i] = CariBahan(*main, TargetCMD(c));
            Info_Orang(*main).bahan[i].jumlah += TargetBuy(c);
            break;
          }
        }
		} else if (isKataSama(c.perintah, _upgrade)) {
			 LocateThenUpgrade(*main,(int) Ordinat(Info_Posisi(*main)), (int) Absis(Info_Posisi(*main))+1,c);
      }

	}
	Info_Main(*main) = true;
	Info_Prep(*main) = false;
  Info_DayMain(*main) += 1;
  Info_TotalPriceCMD(*main) = 0;
  Info_WaktuCMD(*main) = MakeJAM(0, 0, 0);
  CreateEmpty(&Info_StackCMD(*main));
  Info_Waktu(*main) = Info_Opening(*main);
}

void play(program *main){
  Kata _exitgame,_w,_a,_s,_d,_office,_main,_prep,_build,_execute,_buy,_undo;
  _main.TabKata[0] = *"m";
  _main.TabKata[1] = *"a";
  _main.TabKata[2] = *"i";
  _main.TabKata[3] = *"n";
  _main.Length = 4;
  _build.TabKata[0] = *"b";
  _build.TabKata[1] = *"u";
  _build.TabKata[2] = *"i";
  _build.TabKata[3] = *"l";
  _build.TabKata[4] = *"d";
  _build.Length = 5;
  _execute.TabKata[0] = *"e";
  _execute.TabKata[1] = *"x";
  _execute.TabKata[2] = *"e";
  _execute.TabKata[3] = *"c";
  _execute.TabKata[4] = *"u";
  _execute.TabKata[5] = *"t";
  _execute.TabKata[6] = *"e";
  _execute.Length = 7;
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
  _buy.TabKata[0] = *"b";
  _buy.TabKata[1] = *"u";
  _buy.TabKata[2] = *"y";
  _buy.Length = 3;
  _undo.TabKata[0] = *"u";
  _undo.TabKata[1] = *"n";
  _undo.TabKata[2] = *"d";
  _undo.TabKata[3] = *"o";
  _undo.Length = 4;
  _w.TabKata[0] = *"w";
  _a.TabKata[0] = *"a";
  _s.TabKata[0] = *"s";
  _d.TabKata[0] = *"d";
  _w.Length = 1;
  _a.Length = 1;
  _s.Length = 1;
  _d.Length = 1;

  MATRIKS current;
  if(Info_CurrentMap(*main) == 0){
    current = Info_Map(*main);
  } else if(Info_CurrentMap(*main) == 1){
    current = Info_Map2(*main);
  } else if(Info_CurrentMap(*main) == 2){
    current = Info_Map3(*main);
  } else if(Info_CurrentMap(*main) == 3){
    current = Info_Map4(*main);
  }

  if(!IsExit(*main)){
    while (!IsExit(*main)){
      printf("\n");
      if (Info_Prep(*main)){
        PrintInfoPrep(*main);
      } else {
        PrintInfoMain(*main);
      }
      printf("\nMasukkan perintah:\n");
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
          if(Elmt(current, (int) Ordinat(Info_Posisi(*main))-1, (int) Absis(Info_Posisi(*main))) == *"W"){
            printf("Terdapat Wahana di atas pemain, tidak dapat berpindah.\n");
          } else {
            if (IsOffice(Info_Posisi(*main), *main)){
              w(main);
              initOffice(&Info_Map(*main),&Info_Office(*main));
            } else {
              w(main);
            }
          }
        } else if (isKataSama(_a, CKata)){
          if(Elmt(current, (int) Ordinat(Info_Posisi(*main)), (int) Absis(Info_Posisi(*main))-1) == *"W"){
            printf("Terdapat Wahana di kiri pemain, tidak dapat berpindah.\n");
          } else {
            if (IsOffice(Info_Posisi(*main), *main)){
              a(main);
              initOffice(&Info_Map(*main),&Info_Office(*main));
            } else {
              a(main);
            }
          }
        } else if (isKataSama(_s, CKata)){
          if(Elmt(current, (int) Ordinat(Info_Posisi(*main))+1, (int) Absis(Info_Posisi(*main))) == *"W"){
            printf("Terdapat Wahana di bawah pemain, tidak dapat berpindah.\n");
          } else {
            if (IsOffice(Info_Posisi(*main), *main)){
              s(main);
              initOffice(&Info_Map(*main),&Info_Office(*main));
            } else {
              s(main);
            }
          }
        } else if (isKataSama(_d, CKata)){
          if(Elmt(current, (int) Ordinat(Info_Posisi(*main)), (int) Absis(Info_Posisi(*main))+1) == *"W"){
            printf("Terdapat Wahana di kanan pemain, tidak dapat berpindah.\n");
          } else {
            if (IsOffice(Info_Posisi(*main), *main)){
              d(main);
              initOffice(&Info_Map(*main),&Info_Office(*main));
            } else {
              d(main);
            }
          }
        /* PERINTAH UNTUK PREP PHASE */
        } else if (isKataSama(_main, CKata)){
          if (Info_Prep(*main)){
            while (!IsEmpty(Info_StackCMD(*main))){
              undo(main,&Info_Map(*main)); /* nantidiganti */
            }
            Info_DayMain(*main) += 1;
            Info_Prep(*main) = false;
            Info_Main(*main) = true;
            Info_TotalPriceCMD(*main) = 0;
            Info_WaktuCMD(*main) = MakeJAM(0, 0, 0);
            CreateEmpty(&Info_StackCMD(*main));
            Info_Waktu(*main) = Info_Opening(*main);
          } else {
            printf("gabisa main soalnya lagi main\n\n");
          }
        } else if (isKataSama(_build, CKata)){
          if (Info_Prep(*main)){
            build(main);
          } else {
            printf("gabisa build soalnya lagi main\n\n");
          }
        } else if (isKataSama(_buy, CKata)){
           if (Info_Prep(*main)){
              buy(main);
            } else {
              printf("gabisa beli bahan soalnya lagi main\n\n");
            }
        } 
        else if (isKataSama(_undo, CKata)){
           if (Info_Prep(*main)){
              undo(main, &Info_Map(*main)); /* nantidiganti */
            } else {
              printf("gabisa Undo soalnya lagi main\n\n");
            }
        } 
        
        else if (isKataSama(_execute, CKata)){
          if (Info_Prep(*main)){
            execute(main);
          } else {
            printf("gabisa exe soalnya lagi main\n\n");
          }
        }
        /* PERINTAH UNTUK MAIN PHASE */
          else if (isKataSama(_prep, CKata)){
          Info_DayPrep(*main) += 1;
          Info_Prep(*main) = true;
          Info_Main(*main) = false;
          Info_Waktu(*main) = MakeJAM(21, 0, 0);
        } else if (isKataSama(_office, CKata)){
          if (Info_Main(*main) && IsOffice(Info_Posisi(*main), *main)){
            office(*main);
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

boolean IsExit(program main){
  return !Info_Main(main) && !Info_Prep(main);
}

void printwaktu(JAM jam){
  if (Hour(jam) > 0){
    if(Minute(jam) > 0){
      printf("%.2i Hour(s) %.2i Minute(s)", Hour(jam), Minute(jam));
    } else {
      printf("%.2i Hour(s)", Hour(jam));
    }
  } else {
    if(Minute(jam) > 0){
      printf("%.2i Minute(s)", Minute(jam));
    } else {
      printf("0");
    }
  }
}

void printpemain(program main){
  printf("Name: ");
  for (int i = 0; i < InfoOrang_Nama(Info_Orang(main)).Length; i++){
    printf("%c", InfoOrang_Nama(Info_Orang(main)).TabKata[i]);
  }
  printf("\nMoney: %i\n", InfoOrang_Duit(Info_Orang(main)));
  printf("Current Time: %.2i.%.2i\n", Hour(Info_Waktu(main)), Minute(Info_Waktu(main)));
  if (Info_Prep(main)){
    printf("Opening Time: %.2i.%.2i\n", Hour(Info_Opening(main)), Minute(Info_Opening(main)));
    printf("Time remaining: ");
    printwaktu(DetikToJAM(Durasi(Info_Waktu(main), Info_Opening(main))));
  } else {
    printf("Closing Time: %.2i.%.2i\n", Hour(Info_Closing(main)), Minute(Info_Closing(main)));
    printf("Time remaining: ");
    printwaktu(DetikToJAM(Durasi(Info_Waktu(main), Info_Closing(main))));
  }
  printf("\n");
}

void PrintInfoPrep(program main){
  printf("Preparation phase day %i\n", Info_DayPrep(main));
  MATRIKS current;

  if(Info_CurrentMap(main) == 0){
    current = Info_Map(main);
  } else if(Info_CurrentMap(main) == 1){
    current = Info_Map2(main);
  } else if(Info_CurrentMap(main) == 2){
    current = Info_Map3(main);
  } else if(Info_CurrentMap(main) == 3){
    current = Info_Map4(main);
  }
  TulisMATRIKS(current);
  printf("\nLegend:\nA = Antrian\nP = Player\nW = Wahana\nO = Office\n<, ^, >, V = Gerbang");
  printf("\n\n");
  printpemain(main);
  printf("Total aksi yang akan dilakukan: %i\n", NbElmtStack(Info_StackCMD(main)));
  printf("Total waktu yang diperlukan: ");
  printwaktu(Info_WaktuCMD(main));
  printf("\nTotal uang yang dibutuhkan: %i\n", Info_TotalPriceCMD(main));
}

void PrintInfoMain(program main){
  MATRIKS current;

  if(Info_CurrentMap(main) == 0){
    current = Info_Map(main);
  } else if(Info_CurrentMap(main) == 1){
    current = Info_Map2(main);
  } else if(Info_CurrentMap(main) == 2){
    current = Info_Map3(main);
  } else if(Info_CurrentMap(main) == 3){
    current = Info_Map4(main);
  }

  printf("Main phase day %i\n", Info_DayMain(main));
  TulisMATRIKS(current);
  printf("\nLegend:\nA = Antrian\nP = Player\nW = Wahana\nO = Office\n<, ^, >, V = Gerbang");
  printf("\n\n");
  printpemain(main);
}

boolean isWahanaAda(program main, Kata wahana) {
  boolean found = false;
  for (int i = 0; i < maxel; i++){
    if (InfoWahana_Nama(Info_Wahana(main, i)).Length>0){
      if (isKataSama(wahana, InfoWahana_Nama(Info_Wahana(main, i)))){
        found = true;
        break;
      }
    }
  }
  return found;
}

Wahana CariWahana(program main, Kata wahana){
  Wahana ret;
  for (int i = 0; i < maxel; i++){
    if (InfoWahana_Nama(Info_Wahana(main, i)).Length>0){
      if (isKataSama(wahana, InfoWahana_Nama(Info_Wahana(main, i)))){
        ret = Info_Wahana(main, i);
        break;
      }
    }
  }
  return ret;
}

void PrintInfoWahana (Wahana x){
  printf("Nama: ");
  for (int i = 0; i < InfoWahana_Nama(x).Length; i++){
    printf("%c",InfoWahana_Nama(x).TabKata[i]);
  }
  printf("\nTipe: %i\n", InfoWahana_Tipe(x));
  printf("Harga: %i\n", InfoWahana_Harga(x));
  printf("Lokasi: (%i,%i)\n",(int) Absis(InfoWahana_lokasi(x)), (int) Ordinat(InfoWahana_lokasi(x)));
  printf("Posisi Denah: %i\n",(InfoWahana_lokasidenah(x)+1));
  printf("Deskripsi: ");
  for (int i = 0; i < InfoWahana_Deskripsi(x).Length; i++){
    printf("%c",InfoWahana_Deskripsi(x).TabKata[i]);
  }
  printf("\nKapasitas: %i\n", InfoWahana_Kapasitas(x));
  printf("Durasi: ");
  printwaktu(InfoWahana_Durasi(x));
  printf("\nHistory: blom\n");
}

/* Baru ditambah tar gw cek lagi */
void buy (program *main) {
  // KAMUS
  boolean sabi;
  JAM waktu;
  Kata _buy;
  Kata namaBahan,qty;
  Bahan target;
  _buy.TabKata[0] = *"b";
  _buy.TabKata[1] = *"u";
  _buy.TabKata[2] = *"y";
  _buy.Length = 3;
  int price;
  int amount;
  int durasi = 5000;
  cmd buy;

  // ALGORITMA
  if (!Info_Prep(*main)) {
		printf("Anda sedang dalam main phase!");
  } else {
    	printf("Ingin beli apa?\n");
			bahan_print(*main,true);
			printf("$ ");
			STARTKATA();
			while (!EndKata) {
        splitKata(CKata,&qty,&namaBahan);
        // cek bahan
        if (isBahanAda(*main, namaBahan)){
          target = CariBahan(*main, namaBahan);
          amount = ConvertToInt(qty);
          price = InfoBahan_Harga(target)*amount;
          // cek duit
          if(InfoOrang_Duit(Info_Orang(*main))>=price && Info_TotalPriceCMD(*main)+price<=InfoOrang_Duit(Info_Orang(*main))){
            // cek waktu
            if (JAMToDetik(Info_WaktuCMD(*main))+durasi<=Durasi(Info_Waktu(*main), Info_Opening(*main))){

                // tambahin waktu sama duit ke program
                Info_TotalPriceCMD(*main) += price;
                Info_WaktuCMD(*main) = DetikToJAM(JAMToDetik(Info_WaktuCMD(*main))+durasi);

                // masukin ke stack
                WaktuCMD(buy) = DetikToJAM(durasi);
                PerintahCMD(buy) = _buy;
                TargetCMD(buy) = namaBahan;
                TargetBuy(buy) = amount;
                Push (&Info_StackCMD(*main), buy);

            } else {
                printf("Tidak cukup waktu!\n");
              }
          } else {
              printf("Tidak cukup uang!\n");
            }
        } else {
            printf("Material tidak ditemukan!\n");
          }
        ADVKATA();
			}
  }
}

boolean isBahanAda (program main, Kata bahan) {
  boolean found = false;
  for (int i = 0; i < maxel; i ++){
    if (InfoOrang_Bahan_Nama(Info_Orang(main), i).Length > 0){
      if (isKataSama(bahan, InfoOrang_Bahan_Nama(Info_Orang(main), i))){
        found = true;
        break;
      }
    }
  }
  return found;
}

Bahan CariBahan(program main, Kata bahan){
  Bahan ret;
  for (int i = 0; i < maxel; i++){
    if (InfoOrang_Bahan_Nama(Info_Orang(main), i).Length > 0){
      if (isKataSama(bahan, InfoOrang_Bahan_Nama(Info_Orang(main), i))){
        ret = InfoOrang_Bahan(Info_Orang(main), i);
        break;
      }
    }
  }
  return ret;
}

void bahan_print(program main, boolean prep) {
  printf("List Material:\n");
  for (int i = 0; i < maxel; i++){
    if (prep) {
      for (int j = 0; j < InfoOrang_Bahan_Nama(Info_Orang(main), i).Length; j++){
        if (InfoOrang_Bahan_Nama(Info_Orang(main), i).Length>0){
          if (j == 0){
            printf("- ");
          }
          printf("%c", InfoOrang_Bahan_Nama(Info_Orang(main), i).TabKata[j]);
          if (j == InfoOrang_Bahan_Nama(Info_Orang(main), i).Length-1){
            printf("\n");
          }
        }
      }
    }
  }
}

void LocateThenUpgrade(program main, int absis, int ordinat, cmd c) {
  boolean upgraded = false;
  int i = 0;
  while (!upgraded && i < maxel){
    if (InfoWahana_Nama(Info_WahanaMap(main, i)).Length>0){
      if (Absis(InfoWahana_lokasi(Info_Wahana(main, i))) == absis && Ordinat(InfoWahana_lokasi(Info_Wahana(main, i))) == ordinat){
        Info_WahanaMap(main, i) = CariWahana(main, TargetCMD(c));
        upgraded = true;
      } else {
        i++;
      }
    } else {
      i++;
    }
  }
}
Wahana LocateWahana (program main, int absis, int ordinat){
  Wahana ret;
  for (int i = 0; i < maxel; i++){
    if (InfoWahana_Nama(Info_Wahana(main, i)).Length>0){
      if (Absis(InfoWahana_lokasi(Info_Wahana(main, i))) == absis && Ordinat(InfoWahana_lokasi(Info_Wahana(main, i))) == ordinat){
        ret = Info_Wahana(main, i);
        break;
      }
    }
  }
  return ret;
}

void upgrade (program *main) { // harus nambah parameter node wahana yang ada di posisi sebelahhnya
// KAMUS
  boolean sabi;
  JAM waktu;
  Kata _upgrade;
  Kata namaBahan,qty;
  _upgrade.TabKata[0] = *"u";
  _upgrade.TabKata[1] = *"p";
  _upgrade.TabKata[2] = *"g";
  _upgrade.TabKata[3] = *"r";
  _upgrade.TabKata[4] = *"a";
  _upgrade.TabKata[5] = *"d";
  _upgrade.TabKata[6] = *"e";
  _upgrade.Length = 7;
  int price = 0;
  int durasi = 5*3600;
  // Algoritme
  if (!Info_Prep(*main)) {
		printf("Anda sedang dalam main phase!");
  } else {
    if (Elmt(Info_Map(*main), (int) Ordinat(Info_Posisi(*main)), (int) Absis(Info_Posisi(*main))+1) == *"W"){
      Wahana targetUp = LocateWahana(*main,(int) Ordinat(Info_Posisi(*main)), (int) Absis(Info_Posisi(*main))+1); 
      printf("Ingin upgrade menjadi wahana apa?\n");
      // print list wahana yang bisa diupgrade dari node wahana targerUp
      printf("$ ");
      STARTKATA();
      while (!EndKata) {
        // cek duit
        if(InfoOrang_Duit(Info_Orang(*main))>=price && Info_TotalPriceCMD(*main)+price<=InfoOrang_Duit(Info_Orang(*main))){
          // cek waktu
          if (JAMToDetik(Info_WaktuCMD(*main))+durasi<=Durasi(Info_Waktu(*main), Info_Opening(*main))){
            // cek wahana
            if (isWahanaAda(*main, CKata)){
              cmd upgrade;
              // tambahin waktu sama duit ke program
              Info_TotalPriceCMD(*main) += price;
              Info_WaktuCMD(*main) = DetikToJAM(JAMToDetik(Info_WaktuCMD(*main))+durasi);

              // masukin ke stack
              WaktuCMD(upgrade) = DetikToJAM(durasi);
              HargaCMD(upgrade) = price;
              PerintahCMD(upgrade) = _upgrade;
              TargetCMD(upgrade) = CKata;
              TargetUpgrade(upgrade) = CKata;
              Push (&Info_StackCMD(*main), upgrade);
            } else {
              printf("Wahana tidak ditemukan!\n");
            }
          } else {
            printf("Tidak cukup waktu!\n");
          }
        } else {
            printf("Tidak cukup uang!\n");
        }
        ADVKATA();
      }
    } else {
      printf("Kamu tidak sedang berada di sebelah kiri wahana\n");
    }
  }
}

void repair (program *main) { // repair wahana disebelah pemain, blm ditambah indikator wahana rusak , blm final
// KAMUS
  boolean sabi;
  JAM waktu;
  Kata _repair;
  Kata namaBahan,qty;
  _repair.TabKata[0] = *"r";
  _repair.TabKata[1] = *"e";
  _repair.TabKata[2] = *"p";
  _repair.TabKata[3] = *"a";
  _repair.TabKata[4] = *"i";
  _repair.TabKata[5] = *"r";
  _repair.Length = 6;
  int price = 0;
  int durasi = 5*3600;
  // Algoritme
  if (!Info_Prep(*main)) {
		printf("Anda sedang dalam main phase!");
  } else {
    if (Elmt(Info_Map(*main), (int) Ordinat(Info_Posisi(*main)), (int) Absis(Info_Posisi(*main))+1) == *"W"){ // Blm nambah is W rusak
      Wahana targetRep = LocateWahana(*main,(int) Ordinat(Info_Posisi(*main)), (int) Absis(Info_Posisi(*main))+1); 
      printf("Apakah anda ingin merepair wahana berikut :\n");
      printf("$ ");
      STARTKATA();
      while (!EndKata) {
        // cek duit
        if(InfoOrang_Duit(Info_Orang(*main))>=price && Info_TotalPriceCMD(*main)+price<=InfoOrang_Duit(Info_Orang(*main))){
          // cek waktu
          if (JAMToDetik(Info_WaktuCMD(*main))+durasi<=Durasi(Info_Waktu(*main), Info_Opening(*main))){
            // cek wahana
            if (isWahanaAda(*main, CKata)){
              cmd repair;
              // tambahin waktu sama duit ke program
              Info_TotalPriceCMD(*main) += price;
              Info_WaktuCMD(*main) = DetikToJAM(JAMToDetik(Info_WaktuCMD(*main))+durasi);

              // masukin ke stack
              WaktuCMD(repair) = DetikToJAM(durasi);
              HargaCMD(repair) = price;
              PerintahCMD(repair) = _repair;
              TargetCMD(repair) = CKata;
              TargetUpgrade(repair) = CKata;
              Push (&Info_StackCMD(*main), repair);
            } else {
              printf("Wahana tidak ditemukan!\n");
            }
          } else {
            printf("Tidak cukup waktu!\n");
          }
        } else {
            printf("Tidak cukup uang!\n");
        }
        ADVKATA();
      }
    } else {
      printf("Kamu tidak sedang berada di sebelah kiri wahana\n");
    }
  }
}



void undo(program *main,MATRIKS *M){
    cmd undone;
    int x,y;
    if(Info_Prep(*main)){
        Pop(&Info_StackCMD(*main),&undone);
        if(PerintahCMD(undone).TabKata[0]=='b' && PerintahCMD(undone).TabKata[1]=='u' && PerintahCMD(undone).TabKata[2]=='i' && PerintahCMD(undone).TabKata[3]=='l' && PerintahCMD(undone).TabKata[4]=='d'){
            printf("Menghapus perintah ");
            for (int i = 0; i < PerintahCMD(undone).Length; i++) printf("%c",PerintahCMD(undone).TabKata[i]);printf("\n");
            TargetBuild(undone).X = x;
            TargetBuild(undone).Y = y;
            Elmt(*M,y,x) = '-';
        }
        else{
        // Show deleted command
        printf("Menghapus perintah ");
        for (int i = 0; i < PerintahCMD(undone).Length; i++) printf("%c",PerintahCMD(undone).TabKata[i]);
        // Works for buy, fitur show deleted command dihapus (cuma dijadiin comment juga gpp)
        printf(" dari stack\n");
        }
    }
}

void initTreeWahana(BinTree *T){
    WahReader("wahana/wahana3.txt",T);
}

void initListWahana(int i,program *main,BinTree *T){
    if(*T != NULL){
      CopyString(Info_Wahana(*main,i).nama.TabKata,Akar(*T).nama.TabKata);
      Info_Wahana(*main,i).nama.Length = Akar(*T).nama.Length;
      Info_Wahana(*main,i).tipe = Akar(*T).tipe;
      Info_Wahana(*main,i).harga = Akar(*T).harga;
      Info_Wahana(*main,i).kapasitas = Akar(*T).kapasitas;
      CopyString(Info_Wahana(*main,i).deskripsi.TabKata,Akar(*T).deskripsi.TabKata);
      Info_Wahana(*main,i).deskripsi.Length = Akar(*T).deskripsi.Length;
      Info_Wahana(*main,i).durasi.HH =  Akar(*T).durasi.HH;
      Info_Wahana(*main,i).durasi.MM =  Akar(*T).durasi.MM;
      Info_Wahana(*main,i).durasi.SS =  Akar(*T).durasi.SS;
      Info_Wahana(*main,i).lokasi.X =   Akar(*T).lokasi.X;
      Info_Wahana(*main,i).lokasi.Y =   Akar(*T).lokasi.Y;
    }
}

void MakeListWahana(program *main,BinTree *T){
  initListWahana(0,&main,&T);
  initListWahana(1,&main,&Left(*T));
  initListWahana(2,&main,&Right(*T));
  initListWahana(3,&main,&Left(Left(*T)));
  initListWahana(4,&main,&Right(Left(*T)));
  initListWahana(5,&main,&Left(Right(*T)));
  initListWahana(6,&main,&Right(Right(*T)));
}