#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996) //disable scanf warning

#define size 9

int checkSomRij(int sudoku[size][size], int rij);
int checkSomKolom(int sudoku[size][size], int kolom);
int checkSomBlok(int sudoku[size][size], int rij, int kolom);

void copySudoku(int src[size][size], int dest[size][size]);
void sorteerRijSudoku(int sudoku[size][size], int rij);
int checkGetallen1tm9Rij(int sudoku[size][size], int rij);

void sorteerKolomSudoku(int sudoku[size][size], int kolom);
int checkGetallen1tm9Kolom(int sudoku[size][size], int kolom);

int main() {

	FILE* bestand;
	int sudoku[size][size];
	int blok = 0;
	int gevonden[size];
	int sudokuCopy[size][size];

	printf("Dit is een test. \n\n");

	bestand = fopen("C:\\School HBO ICT\\school 2023 - 2024\\periode 3\\C programmeren\\week 5\\sudoku.txt", "r");//r alleen lezen

	for (int rij = 0; rij < size; rij++) {
		for (int kolom = 0; kolom < size; kolom++) {
			fscanf(bestand, " %d", &sudoku[rij][kolom]);		//inlezen .txt
		}
	}

	fclose(bestand);

	for (int rij = 0; rij < size; rij++) {			//uitprinten sudoku
		for (int kolom = 0; kolom < size; kolom++) {
			printf(" %d", sudoku[rij][kolom]);
		}
		printf("\n");
	}

	printf("\n");
	
	for (int rij = 0; rij < size; rij++) {			//checken of rij niet 45 is
		if (checkSomRij(sudoku, rij) != 45) {
			printf("Som van rij %d is niet 45.\n", rij + 1); 
		}
	}
	printf("\n");

	for (int kolom = 0; kolom < size; kolom++) {	//checken of kolom niet 45 is
		if (checkSomKolom(sudoku, kolom) != 45) {
			printf("Som van kolom %d is niet 45.\n", kolom + 1); 
		}
	}
	printf("\n");

	for (int rij = 0; rij < 9; rij+=3 ) {			//checken of blok niet 45 is	1 2 3
		for (int kolom = 0; kolom < 9; kolom+=3) {	//								4 5 6
			blok++;									//								7 8 9
			if (checkSomBlok(sudoku, rij, kolom) != 45) {		
				printf("Som van blok %d is niet 45.\n", blok); //uitprinten welk blok, zie ^
			}
		}
	}
	printf("\n");

	//check elk getal 1tm9 in rij
	copySudoku(sudoku, sudokuCopy);
	for (int rij = 0; rij < size; rij++) {
		sorteerRijSudoku(sudokuCopy, rij);
		if (checkGetallen1tm9Rij(sudokuCopy, rij)) {
			printf("Niet elk getal komt voor in rij %d.\n", rij + 1);
		}
	}
	printf("\n");

	//check elk getal 1tm9 in kolom
	copySudoku(sudoku, sudokuCopy);		//reset de gekopieerde array
	for (int kolom = 0; kolom < size; kolom++) {
		sorteerKolomSudoku(sudokuCopy, kolom);
		if (checkGetallen1tm9Kolom(sudokuCopy, kolom)) {
			printf("Niet elk getal komt voor in kolom %d.\n", kolom + 1);
		}
	}


	return 0;
}