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

void initmain(program *main, Kata nama) {
  /*
  typedef struct {
	Orang orang;
	JAM sekarang;
	Wahana wahana[100];
	Stack prepexe;
  boolean Main;
  boolean Prep;
	MATRIKS Map;
	POINT posisi;
  POINT office;
} program;
*/
  for (int i = 0; i < nama.Length; i++){
    InfoOrang_Nama(Info_Orang(*main)).TabKata[i] = nama.TabKata[i];
  }
  
  InfoOrang_Nama(Info_Orang(*main)).Length = nama.Length;
  InfoOrang_Duit(Info_Orang(*main)) = 0;

  JAM skrg = MakeJAM(0, 0, 0);
  Info_Waktu(*main) = skrg;

  Info_Prep(*main) = true;
  Info_Main(*main) = false;

  CreateEmpty(&Info_StackCMD(*main));
}

void initgame(program *main){
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

void wahana_print(program main, boolean prep) {
	// baca file
	// print semua nama wahana
  POINT bknwahana;
  bknwahana.X = -999;
  bknwahana.Y = -999;

  printf("List Wahana:\n");
  for (int i = 0; i < maxel; i++){
    if (prep) {
      for (int j = 0; j < InfoWahana_Nama(Info_Wahana(main, i)).Length; j++){
        if (InfoWahana_Nama(Info_Wahana(main, i)).Length>0){
          if (j == 0){
            printf("- ");
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
            printf("- ");
          }
          printf("%c", InfoWahana_Nama(Info_WahanaMap(main, i)).TabKata[j]);
          if (j == InfoWahana_Nama(Info_WahanaMap(main, i)).Length-1){
            printf(" (%i,%i)", (int) Absis(InfoWahana_lokasi(Info_WahanaMap(main, i))), (int) Ordinat(InfoWahana_lokasi(Info_WahanaMap(main, i))));
            printf("\n");
          }
        }
      }
    }
  }
}

void wahana_details_print(program main, Kata choice) {
  POINT bknwahana;
  bknwahana.X = -999;
  bknwahana.Y = -999;
	// baca file
	// print semua detail sesuai choice
	// kalo gaada, kirim error
  boolean found = false;
  for (int i = 0; i < maxel; i++){
    if (isKataSama(choice, InfoWahana_Nama(Info_WahanaMap(main, i)))){
      PrintInfoWahana(Info_WahanaMap(main, i));
      found = true;
      break;
    }
  }
  if (!found) {
    printf("Wahana tidak ditemukan\n\n");
  }
}

void wahana_details(program main) {
	// KAMUS

	// ALGORITMA
	printf("Pilih wahana:\n");
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
	printf("Pilih wahana:\n");
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
		printf("Masukkan perintah (details / reports / exit)\n$ ");

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

void buy (program *main) {
  // KAMUS
  boolean sabi;
  JAM waktu;
  Kata _buy;
  _buy.TabKata[0] = *"b";
  _buy.TabKata[1] = *"u";
  _buy.TabKata[2] = *"y";
  _buy.Length = 3;

  // ALGORITMA
  if (!Info_Prep(*main)) {
		printf("Anda sedang dalam main phase!");
  } else {
    	printf("Ingin beli apa?\n");
			// print list bahan
			printf("$ ");
			STARTKATA();
			while (!EndKata) {
				if (isWahanaAda(*main, CKata)){ //checking if bahan ada atau ga
          AddWahanaToMap(&Info_Map(*main), Absis(Info_Posisi(*main))+1, Ordinat(Info_Posisi(*main)));
          cmd buy;
          //WaktuCMD(buy) = /* JAM sekian */;
          PerintahCMD(buy) = _buy;
          TargetCMD(buy) = CKata; // harus di split dulu cuma idk
          TargetBuy(buy) = ConvertToInt(CKata);
          Push (&Info_StackCMD(*main), buy);
        } else {
          printf("Material tidak ditemukan!\n");
        }
        ADVKATA();
			}
  }
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
	
	// ALGORITMA
	if (!Info_Prep(*main)) {
		printf("Anda sedang dalam main phase!");
	} else {
		//if (cekwaktu(waktu, 888)) {
		//	kurangwaktu(&waktu, 1231213213132123131231);
			printf("Pilih wahana:\n");
			wahana_print(*main, true);
      printf("$ ");
			STARTKATA();
			while (!EndKata) {
				//sabi = cek_resource(CKata);
        if (isWahanaAda(*main, CKata)){
          if(Elmt(Info_Map(*main), (int) Ordinat(Info_Posisi(*main)), (int) Absis(Info_Posisi(*main))+1) == *"-"){
            AddWahanaToMap(&Info_Map(*main), Absis(Info_Posisi(*main))+1, Ordinat(Info_Posisi(*main)));
            cmd build;
            //WaktuCMD(build) = /* JAM sekian */;
            PerintahCMD(build) = _build;
            TargetCMD(build) = CKata;
            TargetBuild(build).X = Absis(Info_Posisi(*main))+1;
            TargetBuild(build).Y = Ordinat(Info_Posisi(*main));
            Push (&Info_StackCMD(*main), build);
          } else {
            printf("Ada sesuatu di kanan pemain, tidak dapat membangun wahana!\n");
          }
        } else {
          printf("Wahana tidak ditemukan!\n");
        }
        ADVKATA();
			}
			//if (sabi) {
				// tambahin wahana ke point buat semu

			//}
		//} else {
		//	printf("Tidak cukup waktu");
		//}
	}
}

void execute(program *e) {
	Stack target;
  cmd c;
	CopyStack(Info_StackCMD(*e), &target);
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
		// KURANGWAKTU(sekian)
		if (isKataSama(c.perintah, _build)) {
      for (int i = 0; i < maxel; i++){
        if (InfoWahana_Nama(Info_WahanaMap(*e,i)).Length==0){
          Info_WahanaMap(*e,i) = CariWahana(*e, TargetCMD(c));
          Info_WahanaMap(*e,i).lokasi.X = c.targetvalue.titik.X;
          Info_WahanaMap(*e,i).lokasi.Y = c.targetvalue.titik.Y;
          break;
        }
      }
		} else if (isKataSama(c.perintah, _buy)) {
			// do smrhng
		} else if (isKataSama(c.perintah, _upgrade)) {
			// do smthng
		}
	}
	Info_Main(*e) = true;
	Info_Prep(*e) = false;
}

void play(program *main){
  Kata _exitgame,_w,_a,_s,_d,_office,_main,_prep,_build,_execute;
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
      printf("\n");
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
        } else if (isKataSama(_build, CKata)){
          if (Info_Prep(*main)){
            build(main);
          } else {
            printf("gabisa build soalnya lagi main\n\n");
          }
        } else if (isKataSama(_execute, CKata)){
          if (Info_Prep(*main)){
            execute(main);
          } else {
            printf("gabisa exe soalnya lagi main\n\n");
          }
        }
        /* PERINTAH UNTUK MAIN PHASE */
          else if (isKataSama(_prep, CKata)){
          Info_Prep(*main) = true;
          Info_Main(*main) = false;
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

void printpemain(program main){
  printf("Name: ");
  for (int i = 0; i < InfoOrang_Nama(Info_Orang(main)).Length; i++){
    printf("%c", InfoOrang_Nama(Info_Orang(main)).TabKata[i]);
  }
  printf("\nMoney: %i\n", InfoOrang_Duit(Info_Orang(main)));
  printf("Opening: gatau\n");
  printf("Closing: gatau\n");
  printf("Time remaining: gatau\n");
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
  printf("Lokasi: blom\n");
  printf("Deskripsi: ");
  for (int i = 0; i < InfoWahana_Deskripsi(x).Length; i++){
    printf("%c",InfoWahana_Deskripsi(x).TabKata[i]);
  }
  printf("\nKapasitas: %i\n", InfoWahana_Kapasitas(x));
  printf("History: blom\n");
  printf("Durasi: blom\n\n");
}
