#include <stdio.h>
#include <stdlib.h>
#include "../adt/matriks/matriks.c"

void saveMap() {
	FILE *mainFile;
	FILE *savedFile;

	MATRIKS M;
	int i = 0, j = 0;

	// Opening
	mainFile = fopen("../exfile/map.txt", "r");		// Const namefile (mainFile)
	savedFile = fopen("../exfile/savedfile.txt", "w");	// Const namefile (savedFile)

	// Checking
	if (mainFile == NULL || savedFile == NULL) {
		printf("Error while opening file!");
		exit(1);
	}

	// Copy mainFile to Matriks
	MakeMATRIKS(12,12,&M);
	while (fscanf(mainFile, "%c", &Elmt(M,i,j)) != EOF) {
		if (j < 12) {
			j++;
		} else {
			j = 0;
			i++;
		}
	}

	// Put Matriks to savedFile
	for (i = 0; i < M.NBrsEff; i++) {
		for (j = 0; j < M.NKolEff; j++) {
			if (i != M.NBrsEff-1 && j == M.NKolEff-1) {
				fprintf(savedFile, "%c\n", Elmt(M,i,j));
			} else {
				fprintf(savedFile, "%c", Elmt(M,i,j));
			}
		}
	}

	// closing
	fclose(mainFile);
	fclose(savedFile);
}

void loadMap() {
	FILE *mainFile;
	FILE *savedFile;

	MATRIKS M;
	int i = 0, j = 0;

	// Opening
	savedFile = fopen("../exfile/savedfile.txt", "r");		// Const namefile (mainFile)
	mainFile = fopen("../exfile/map.txt", "w");	// Const namefile (savedFile)

	// Checking
	if (mainFile == NULL || savedFile == NULL) {
		printf("Error while opening file!");
		exit(1);
	}

	// Copy mainFile to Matriks
	MakeMATRIKS(12,12,&M);
	while (fscanf(savedFile, "%c", &Elmt(M,i,j)) != EOF) {
		if (j < 12) {
			j++;
		} else {
			j = 0;
			i++;
		}
	}

	// Put Matriks to savedFile
	for (i = 0; i < M.NBrsEff; i++) {
		for (j = 0; j < M.NKolEff; j++) {
			if (i != M.NBrsEff-1 && j == M.NKolEff-1) {
				fprintf(mainFile, "%c\n", Elmt(M,i,j));
			} else {
				fprintf(mainFile, "%c", Elmt(M,i,j));
			}
		}
	}

	// closing
	fclose(mainFile);
	fclose(savedFile);
}

int main() {
	// saveMap();
	// loadMap();
	return 0;
}