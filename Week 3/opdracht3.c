//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <time.h>
//#pragma warning(disable : 4996) //disable scanf warning
//
//int* genereerArray(int hoogste, int laagste, int aantal);
//
//int main() {
//	int bovengrens = 0;
//	int ondergrens = 0;
//	int aantalGetallen = 0;
//	
//	printf("Vul de bovengrens in: \n");
//	scanf_s("%d", &bovengrens);
//	printf("Vul de ondergrens in: \n");
//	scanf_s("%d", &ondergrens);
//	printf("Vul het aantal getallen in: \n");
//	scanf_s("%d", &aantalGetallen);
//
//	int* kleinste = malloc(sizeof(int) * aantalGetallen);			//dynamisch aanmaken ruimte voor size kleinste en grootste array
//	int* grootste = malloc(sizeof(int) * aantalGetallen);
//	int* randomGetallen;											//hier nog niet nodig want dit wordt al gedaan in de for op regel 35
//
//	for (int i = 0; i < aantalGetallen; i++)						//alle waardes voor kleinste en hoogste invullen naar de minimale en maximale waarde
//	{																//anders is de array is leeg en hebben ze random/onzin waardes (bv -74304509)
//		kleinste[i] = bovengrens;
//		grootste[i] = ondergrens;
//	}
//
//	srand(time(NULL));												//huidige tijd voor random seed (buiten de for loop, anders krijg je dezelfde waardes)
//
//	for (int j = 0; j < 10; j++)									//10x random array genereren
//	{	
//		randomGetallen = genereerArray(bovengrens, ondergrens, aantalGetallen);
//		printf("[ ");
//		for (int i = 0; i < aantalGetallen; i++)
//		{
//			printf("%d ", randomGetallen[i]);
//		}
//		printf("]\n");
//
//		for (int i = 0; i < aantalGetallen; i++)
//		{
//			if (kleinste[i] > randomGetallen[i]) {					//kleinste getal is groter dan het randomgetal, dan wordt kleinste het huidige randomgetal
//				kleinste[i] = randomGetallen[i];
//			}
//			if (grootste[i] < randomGetallen[i]) {					//zelfde bij grootste, maar dan andersom
//				grootste[i] = randomGetallen[i];
//			}
//		}
//		free(randomGetallen);
//	}
//	printf("\n\nDe laagste waardes zijn: [");
//	for (int i = 0; i < aantalGetallen; i++)
//	{
//		printf("%d ", kleinste[i]);
//	}
//	printf("]\n");
//
//	printf("\nDe hoogste waardes zijn: [");
//	for (int i = 0; i < aantalGetallen; i++)
//	{
//		printf("%d ", grootste[i]);
//	}
//	printf("]\n");
//
//	free(kleinste);
//	free(grootste);
//	
//	return 0;
//}
//
//int* genereerArray(int hoogste, int laagste, int aantal) {			//pointer functie, want je returnt een pointer naar het begin van de array
//	int* getallen = malloc(sizeof(int) * aantal);					//dynamisch  size aanmaken											
//
//	for (int i = 0; i < aantal; i++)								//als aantal 0 is zal er nooit door de forloop heen worden gegaan
//	{
//		getallen[i] = rand() % (hoogste - laagste + 1) + laagste;	//dus kan de warning negeren (dereference nullptr)
//	}																//(anders zou getallen een nullptr zijn, bij aantal 0)
//	return getallen;
//}
