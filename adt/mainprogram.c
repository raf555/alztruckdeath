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
  InfoOrang_Duit(Info_Orang(*main)) = 1000;

  Info_Waktu(*main) = MakeJAM(21, 0, 0);
  Info_Opening(*main) = MakeJAM(9, 0, 0);
  Info_Closing(*main) = MakeJAM(21, 0, 0);

  Info_Prep(*main) = true;
  Info_Main(*main) = false;

  CreateEmpty(&Info_StackCMD(*main));
  Info_WaktuCMD(*main) = MakeJAM(0, 0, 0);
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
  long durasi = 5*3600;
  cmd build;
	
	// ALGORITMA
	if (!Info_Prep(*main)) {
		printf("Anda sedang dalam main phase!");
	} else {
		printf("Pilih wahana:\n");
		wahana_print(*main, true);
    printf("$ ");
		STARTKATA();
		while (!EndKata) {
      // cek duit
      if(InfoOrang_Duit(Info_Orang(*main))>=price && Info_TotalPriceCMD(*main)+price<=InfoOrang_Duit(Info_Orang(*main))){
        // cek waktu
        if (JAMToDetik(Info_WaktuCMD(*main))+durasi<=Durasi(Info_Waktu(*main), Info_Opening(*main))){
          // cek wahana
          if (isWahanaAda(*main, CKata)){
            // cek sekitar pemain
            if(Elmt(Info_Map(*main), (int) Ordinat(Info_Posisi(*main)), (int) Absis(Info_Posisi(*main))+1) == *"-"){
              // masukin (semu) wahana ke map
              AddWahanaToMap(&Info_Map(*main), Absis(Info_Posisi(*main))+1,Ordinat(Info_Posisi(*main)));

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
              Push (&Info_StackCMD(*main), build);
            } else {
              printf("Ada sesuatu di kanan pemain, tidak dapat membangun wahana!\n");
            }
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
          break;
        }
      }
		} else if (isKataSama(c.perintah, _buy)) {
			Bahan target = CariBahan(*main, TargetCMD(c));
      InfoBahan_Jumlah(target) += TargetBuy(c);
		} else if (isKataSama(c.perintah, _upgrade)) {
			// do smthng
		}
	}
	Info_Main(*main) = true;
	Info_Prep(*main) = false;
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
        } else if (isKataSama(_buy, CKata)){
           if (Info_Prep(*main)){
              buy(main);
            } else {
              printf("gabisa beli bahan soalnya lagi main\n\n");
            }
        } 
        else if (isKataSama(_undo, CKata)){
           if (Info_Prep(*main)){
              undo(main);
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
  printf("Preparation phase day 1\n");
  TulisMATRIKS(Info_Map(main));
  printf("\n");
  printpemain(main);
  printf("Total aksi yang akan dilakukan: %i\n", NbElmtStack(Info_StackCMD(main)));
  printf("Total waktu yang diperlukan: ");
  printwaktu(Info_WaktuCMD(main));
  printf("\nTotal uang yang dibutuhkan: %i\n", Info_TotalPriceCMD(main));
}

void PrintInfoMain(program main){
  printf("Main phase day 1\n");
  TulisMATRIKS(Info_Map(main));
  printf("\n");
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
  printf("Lokasi: blom\n");
  printf("Deskripsi: ");
  for (int i = 0; i < InfoWahana_Deskripsi(x).Length; i++){
    printf("%c",InfoWahana_Deskripsi(x).TabKata[i]);
  }
  printf("\nKapasitas: %i\n", InfoWahana_Kapasitas(x));
  printf("History: blom\n");
  printf("Durasi: blom\n\n");
}

/* Baru ditambah tar gw cek lagi */
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
			bahan_print(*main,true);
			printf("$ ");
			STARTKATA();
			while (!EndKata) {
				if (isBahanAda(*main, CKata)){ // ingat belum di split
          Bahan target = CariBahan(*main, CKata);
          if (InfoOrang_Duit(Info_Orang(*main)) >= InfoBahan_Harga(target)){
            cmd buy;
            //WaktuCMD(buy) = /* JAM sekian */;
            PerintahCMD(buy) = _buy;
            TargetCMD(buy) = CKata; // harus di split dulu cuma idk
            TargetBuy(buy) = ConvertToInt(CKata);
            Push (&Info_StackCMD(*main), buy);
          }
          else {
            printf("Uang Anda tidak mencukupi!\n");
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

void undo(program *main){
    cmd undone;
    if(Info_Prep(*main)){
        Pop(&Info_StackCMD(*main),&undone);
        // Show deleted command
        printf("Menghapus perintah ");
        for (int i = 0; i < PerintahCMD(undone).Length; i++) printf("%c",PerintahCMD(undone).TabKata[i]);
        // Works for buy, fitur show deleted command dihapus (cuma dijadiin comment juga gpp)
        printf(" ");
        for (int i = 0; i < TargetCMD(undone).Length; i++) printf("%c",TargetCMD(undone).TabKata[i]);
        printf(" dari stack\n");
    }
}
