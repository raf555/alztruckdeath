#include <stdio.h>
#include <stdlib.h>
#include "../adt/matriks.c"
#include "../adt/point.c"

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

int main() {
	MATRIKS M;
	POINT P;
	char input;

	MakeMATRIKS(12,12,&M);
	initMap(&M);
	initPlayer(&M,&P);
	TulisMATRIKS(M);
	while (true) {
		printf("\n$inputan: ");
		scanf("%c", &input);
		switch (input) {
			case 'w':
				w(&M,&P);
				break;
			case 'a':
				a(&M,&P);
				break;
			case 's':
				s(&M,&P);
				break;
			case 'd':
				d(&M,&P);
				break;
		}
		printf("\n");
		TulisMATRIKS(M);
		printf("\n");
	}
	return 0;
}