#include <stdio.h>
#include <stdlib.h>
#include "../adt/mesinkata.c"

void saveMap() {
	FILE *mainFile;
	FILE *savedFile;

	// Opening
	mainFile = fopen("../exfile/map.txt", "r");		// Const namefile (mainFile)
	savedFile = fopen("../exfile/savedfile.txt", "w");	// Const namefile (savedFile)

	// Checking
	if (mainFile == NULL || savedFile == NULL) {
		printf("Error while opening file!");
		exit(1);
	}

	// Copy mainFile to savedFile
	while (fscanf(mainFile, "%s", &CKata.TabKata) != EOF) {
		fprintf(savedFile, "%s\n", CKata.TabKata);
	}

	// closing
	fclose(mainFile);
	fclose(savedFile);
}

void saveMap() {
	FILE *mainFile;
	FILE *savedFile;

	// Opening
	savedFile = fopen("../exfile/savedfile.txt", "r");	// Const namefile (savedFile)
	mainFile = fopen("../exfile/map.txt", "w");		// Const namefile (mainFile)

	// Checking
	if (mainFile == NULL || savedFile == NULL) {
		printf("Error while opening file!");
		exit(1);
	}

	// Copy mainFile to savedFile
	while (fscanf(savedFile, "%s", &CKata.TabKata) != EOF) {
		fprintf(mainFile, "%s\n", CKata.TabKata);
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