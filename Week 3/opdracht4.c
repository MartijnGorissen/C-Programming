#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable : 4996) //disable scanf warning

#define woordLengte 5

typedef struct {
	char letter;											//om de letter te vergelijken
	int anderePlek;											//om aan te geven of de letter op een andere plek hoort (0 of 1)
	int juistePlek;											//om aan te geven of de letter op de juiste plek staat (0 of 1)
} statusLetter;

int main() {
	char invoer[woordLengte + 1];							//+1 want '\0' komt er nog bij
	char woord1[woordLengte + 1] = { "water" };				//test woorden
	char woord2[woordLengte + 1] = { "tafel" };
	char woord3[woordLengte + 1] = { "regen" };

	int maxPogingen = 5;
	int poging = 0;
	int geraden = 0;
	int aantalGoed = 0;
	statusLetter status[woordLengte + 1];

	while (poging < maxPogingen && geraden == 0) {
		printf("Poging %d van de %d \n", poging+1, maxPogingen);
		printf("Gok een 5 letter woord: \n");
		scanf("%s", invoer);

		for (int i = 0; i < woordLengte; i++)				//te raden woord initialiseren
		{
			status[i].letter = woord3[i];					//hier aanpassen om het woord te veranderen
			status[i].juistePlek = 0;
			status[i].anderePlek = 0;
		}
		for (int i = 0; i < woordLengte; i++)
		{
			if (invoer[i] == status[i].letter) {			//als de letter overeenkomt, dan zit deze op de juiste plek
				status[i].juistePlek = 1;
			}
		}
		for (int i = 0; i < woordLengte; i++)
		{
			if (!status[i].juistePlek) {					//deze letter staat al goed, dus hoef niet te checken
				for (int j = 0; j < woordLengte; j++)
				{
					if (invoer[j] == status[i].letter && !status[j].anderePlek && !status[j].juistePlek) {	// && check of deze letter al geraden is of op een andere plek staat
						status[j].anderePlek = 1;
						break;							//break omdat je elke positie maar 1 keer wilt vergelijken
					}
				}
			}
		}
		for (int i = 0; i < woordLengte; i++)
		{
			if (status[i].juistePlek) {
				printf("+");										//print + als letter op de juiste plek zit
			}
			else if (status[i].anderePlek) {
				printf("/");										//print / als letter op een andere plek hoort
			}
			else {
				printf(".");										//print . als letter er niet in zit
			}
		}
		printf("\n");
		poging++;
		aantalGoed = 0;

		for (int i = 0; i < woordLengte; i++)
		{
			if (status[i].juistePlek) {
				aantalGoed++;
			}
		}
		if (aantalGoed == woordLengte) {			//aantal goede letters komt overeen met het aantal letters van het woord
			geraden++;								//dan heb je het woord geraden
		}
	}
	if (geraden) {
		printf("Je hebt gewonnen.\n");
	}
	else {
		printf("Je hebt verloren.\n");
	}
	return 0;
}