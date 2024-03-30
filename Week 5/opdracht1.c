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

	FILE* fp;
	int sudoku[size][size];
	int blok = 0;
	int gevonden[size];
	int sudokuCopy[size][size];

	fp = fopen("C:\\School HBO ICT\\school 2023 - 2024\\periode 3\\C programmeren\\week 5\\sudoku.txt", "r");//r alleen lezen

	for (int rij = 0; rij < size; rij++) {
		for (int kolom = 0; kolom < size; kolom++) {
			fscanf(fp, " %d", &sudoku[rij][kolom]);		//inlezen .txt
		}
	}

	fclose(fp);

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