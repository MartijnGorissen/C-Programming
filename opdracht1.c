#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996) //disable scanf warning

typedef struct {
	char naam[20];
	int uren;
}game;

int main() {

	game gameArray[3];
	game* gamePointer[3];

	int a = 5;
	int b = 10;
	int c = 15;

	strcpy(gameArray[0].naam, "CS");
	gameArray[0].uren = 2500;

	strcpy(gameArray[1].naam, "WoW");
	gameArray[1].uren = 15000;

	strcpy(gameArray[2].naam, "LoL");
	gameArray[2].uren = 600;

	gamePointer[0] = &gameArray[0];
	gamePointer[1] = &gameArray[1];
	gamePointer[2] = &gameArray[2];

	int sizeGameArray = sizeof(gameArray) / sizeof(gameArray[0]);

	for (int i = 0; i < sizeGameArray; i++) {
		printf("%s %d\n", gameArray[i].naam, gameArray[i].uren);
	}
	printf("\n");

	for (int i = 0; i < sizeGameArray; i++) {
		printf("%s %d\n", gamePointer[i]->naam, gamePointer[i]->uren);
	}
	printf("\n");
	
	game tempArray[3];
	game* tempPointer[3];

	tempArray[0] = gameArray[0];
	gameArray[0] = gameArray[2];
	gameArray[2] = tempArray[0];

	tempPointer[0] = gamePointer[0];
	gamePointer[0] = gamePointer[2];
	gamePointer[2] = tempPointer[0];

	//gamePointer[0] = &gameArray[2];
	//gamePointer[2] = &gameArray[0];
	
	for (int i = 0; i < 3; i++) {
		printf("%s %d\n", gameArray[i].naam, gameArray[i].uren);
	}
	printf("\n");
	for (int i = 0; i < 3; i++) {
		printf("%s %d\n", gamePointer[i]->naam, gamePointer[i]->uren);
	}
	printf("\n");

	return 0;
}