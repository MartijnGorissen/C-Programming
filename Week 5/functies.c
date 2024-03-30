#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996) //disable scanf warning

#define size 9

int checkSomRij(int sudoku[size][size], int rij) {
	int som = 0;
	for (int kolom = 0; kolom < size; kolom++) {
		som += sudoku[rij][kolom];
	}
	return som;
}

int checkSomKolom(int sudoku[size][size], int kolom) {
	int som = 0;
	for (int rij = 0; rij < size; rij++) {
		som += sudoku[rij][kolom];
	}
	return som;
}

int checkSomBlok(int sudoku[size][size], int rij, int kolom) {
	int som = 0;
	int blokRij = rij + 3;
	int blokKolom = kolom + 3;
	int tempKolom;

	while (rij < blokRij) {
		tempKolom = kolom;				//reset het getal zodat de tweede while opnieuw door kan gaan
		while (tempKolom < blokKolom) {
			som += sudoku[rij][tempKolom];
			tempKolom++;
		}
		rij++;
	}
	return som;
}

void copySudoku(int src[size][size], int dest[size][size]) {	//kopieer de sudoku naar een andere array
	for (int rij = 0; rij < size; rij++) {
		for (int kolom = 0; kolom < size; kolom++) {
			dest[rij][kolom] = src[rij][kolom];
		}
	}
}

void sorteerRijSudoku(int sudoku[size][size], int rij) {			//sorteert de sudoku per rij van laag naar hoog
	int temp;
	for (int i = 0; i < size - 1; i++) {							//ga meerdere keren door de array heen
		for (int kolom = 0; kolom < size - 1; kolom++) {
			if (sudoku[rij][kolom] > sudoku[rij][kolom + 1]) {		//volgende plek in de array (rij)
				temp = sudoku[rij][kolom + 1];
				sudoku[rij][kolom + 1] = sudoku[rij][kolom];
				sudoku[rij][kolom] = temp;
			}
		}
	}
}

int checkGetallen1tm9Rij(int sudoku[size][size], int rij) {
	for (int kolom = 0; kolom < size; kolom++) {
		if (sudoku[rij][kolom] != kolom + 1) {						//check is het getal hetzelfde als (kolom + 1)
			return 1;												//door sorteer krijg je dus 1 == 1
		}
	}
	return 0;														//1 = getal komt niet voor, 0 = elk getal komt voor.
}

void sorteerKolomSudoku(int sudoku[size][size], int kolom) {		//bijna zelfde functie als sorteerRij
	int temp;														//sorteert de sudoku per kolom van laag naar hoog
	for (int i = 0; i < size - 1; i++) {							//ga meerdere keren door de array heen
		for (int rij = 0; rij < size - 1; rij++) {
			if (sudoku[rij][kolom] > sudoku[rij + 1][kolom]) {		//volgende plek in array (kolom)
				temp = sudoku[rij + 1][kolom];
				sudoku[rij + 1][kolom] = sudoku[rij][kolom];
				sudoku[rij][kolom] = temp;
			}
		}
	}
}

int checkGetallen1tm9Kolom(int sudoku[size][size], int kolom) {
	for (int rij = 0; rij < size; rij++) {							//bijna zelfde functie als checkGetallenRij
		if (sudoku[rij][kolom] != rij + 1) {						//check is het getal hetzelfde als (rij + 1)
			return 1;												//door sorteer krijg je dus 1 == 1
		}
	}
	return 0;														//1 = getal komt niet voor, 0 = elk getal komt voor.
}