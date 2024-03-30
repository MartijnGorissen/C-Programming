#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double inkomstenBelasting(int inkomsten);
int randGetal(int laagste, int hoogste);
double gemiddelde(double cijfers[], int aantal);
int aantalLaag(double cijfers[], int aantal);


int main(void) {
	//opdracht 1
	int opdracht = 0;
	int inkomsten = 0;

	//opdracht 2
	int beurten = 5;
	int hoogste = 0;
	int laagste = 0;
	int keuzeSpeler[5];
	int correctAntwoord = 0;
	char antwoord;
	int pogingen;
	int goed;

	//opdracht 3
	int aantal = 0;
	double cijfers[10];

	//opdracht 4
	int score[2];
	int werpen[2];
	int strikeEenWorpTerug[2];
	int strikeTweeWorpenTerug[2];
	int spareVorigeBeurt[2];
	int huidigeSpeler = 0;
	int omgegooid = 0; //aantal omgegooid worp
	int totaalOmgegooid = 0; //totale aantal kegels deze beurt
	
	do { //do while zodat je alle opdrachten kan zien zonder het progamma af te sluiten
		printf("\nWelke opdracht wil je zien, kies: 1, 2, 3 of 4. \n");
		scanf_s("%d", &opdracht);

		switch (opdracht) { //switch case zodat alle opdracht in 1 bestand staan
		case 1: //opdracht 1 inkomstenbelasting
			printf("Inkomstenbelasting: Wat zijn uw jaarlijkse inkomsten? Vul het getal in euro's in zonder komma's of punten: \n");
			scanf_s("%d", &inkomsten);
			printf("U moet %.2lf euro aan belasting betalen.\n", inkomstenBelasting(inkomsten)); //.2lf voor 2 cijfers achter de komma en double inlezen
			break;
		case 2: //opdracht 2 hoger/lager
			do {
				pogingen = 0;
				goed = 0;
				printf("Kies een getal zonder komma's of punten voor de laagste waarde en hoogste waarde: \n");
				scanf_s("%d %d", &laagste, &hoogste);
				correctAntwoord = randGetal(laagste, hoogste);
				printf("Je hebt totaal 5 kansen.\n");

				for (int i = 0; i < beurten; i++)
				{
					printf("Raad het getal: \n");
					scanf_s("%d", &keuzeSpeler[i]);
					pogingen++;
					if (keuzeSpeler[i] == correctAntwoord) {
						printf("Correct\n\n");
						goed = 1;
						break;
					}
					else if (keuzeSpeler[i] < correctAntwoord) {
						printf("Hoger, nog %d kans(en).\n", beurten-i-1);
					}
					else {
						printf("Lager, nog %d kans(en).\n", beurten-i-1);
					}
				}
				if (!goed) {
					printf("Helaas, je hebt niet gewonnen.\n");
				}		
				printf("Het juiste antwoord was: %d \n", correctAntwoord);
				printf("Deze getallen heb je ingevuld: \n");
				for (int i = 0; i < pogingen; i++)
				{
					printf("%d ", keuzeSpeler[i]);
				}
				printf("\n");
				printf("Wil je nog een keer spelen? Kies 'j' of 'n' ");
				scanf_s(" %c", &antwoord, 1); //spatie ervoor om enter te negeren
			} while (antwoord == 'j');
			break;
		case 3://opdracht 3 gemiddelde cijfers
			printf("Hoeveel cijfers wil je invoeren? \n");
			scanf_s("%d", &aantal);
			printf("Vul de cijfers in: \n");

			for (int i = 0; i < aantal; i++)
			{
				if (scanf_s("%lf", &cijfers[i]) != 1) { //foute invoer (geen cijfer)
					printf("ongeldige invoer\n");
					i--;	// -1 om de lus niet verder te laten gaan bij foute invoer
					while (getchar() != '\n'); //de input wordt verwijderd totdat er een newline (enter) wordt gelezen, dan gaat het programma verder
					continue;					//^ buffer leegmaken
				}
				if (!(cijfers[i] > 0 && cijfers[i] <= 10)) { //cijfer buiten de 0 en 10
					printf("ongeldig cijfer\n");
					cijfers[i] = 1; //standaard waarde invullen bij foute invoer
					i--;		// -1 om de lus niet verder te laten gaan bij foute invoer
				}
			}

			double gemiddeldCijfer = gemiddelde(cijfers, aantal);
			int aantalTeLaag = aantalLaag(cijfers, aantal);

			if (gemiddeldCijfer >= 7.5 && aantalTeLaag == aantal) { //gemiddelde 7.5 en alle cijfers zijn 7 of hoger
				printf("Je hebt het vak met lof behaald. Goed bezig.\n");
			}
			else if (gemiddeldCijfer >= 5.5 && aantalTeLaag == 0) { //gemiddelde >5.5 en max 1 vier
				printf("Je hebt het vak gehaald.\n");
			}
			else if (aantalTeLaag >= 1) { // cijfers onder 4 of te veel vieren
				printf("Vak niet gehaald omdat je hebt een cijfer onder de 4 of te veel vieren. Aantal lage cijfers: %d.\n", aantalTeLaag);
			}
			if (gemiddeldCijfer < 5.5) { //gemiddelde is te laag
				printf("Vak niet gehaald omdat je gemiddelde te laag is. \n");
			}
	
			printf("Je gemiddelde is %.2lf \n\n", gemiddeldCijfer);
			break;
		case 4://score bowlen
			score[0] = 0;
			score[1] = 0;
			strikeEenWorpTerug[0] = 0;
			strikeEenWorpTerug[1] = 0;
			strikeTweeWorpenTerug[0] = 0;
			strikeTweeWorpenTerug[1] = 0;
			spareVorigeBeurt[0] = 0;
			spareVorigeBeurt[1] = 0;

			for (int i = 0; i < 2; i++) { // Vraag elke speler om het aantal worpen per beurt
				while (1) {
					printf("Speler %d, wil je 2 of 3 beurten per keer gooien?\n", i + 1);
					if (scanf_s("%d", &werpen[i]) != 1) { //geen getal ingevoerd
						printf("Ongeldige invoer. Voer 2 of 3 in.\n");
						i--;
						while (getchar() != '\n'); // Buffer leegmaken
					}
					else if (werpen[i] != 2 && werpen[i] != 3) { //getal is niet 2 of 3 dus foute invoer
						printf("Ongeldige invoer. Voer 2 of 3 in.\n");
						i--;
					}
					else {
						break; // Geldige invoer, stop met de lus
					}
				}
			}
			for (int beurt = 1; beurt <= 10; beurt++) //bijhouden welke beurt
			{
				for (huidigeSpeler = 0; huidigeSpeler < 2; huidigeSpeler++) //welke speler aan de beurt is.
				{
					totaalOmgegooid = 0;
					for (int j = 0; j < werpen[huidigeSpeler]; j++)//bijhouden welke worp, -1 voor index 0 dus speler 1 eerst
					{
						printf("Speler: %d, beurt: %d, worp: %d \nVul in hoeveel omgegooide kegels deze worp: \n", huidigeSpeler + 1, beurt, j + 1);
						scanf_s("%d", &omgegooid); //invullen hoeveel omgegooid
						score[huidigeSpeler] = score[huidigeSpeler] + omgegooid;
						totaalOmgegooid = totaalOmgegooid + omgegooid;

						//twee worpen terug was een strike, dus nu 2x zoveel punten
						if (strikeTweeWorpenTerug[huidigeSpeler]) { //
							score[huidigeSpeler] = score[huidigeSpeler] + omgegooid;
							strikeTweeWorpenTerug[huidigeSpeler] = 0;
						}
						//laatste worp was een strike dus 2x zoveel punten
						if (strikeEenWorpTerug[huidigeSpeler]) {
							score[huidigeSpeler] = score[huidigeSpeler] + omgegooid;
							strikeEenWorpTerug[huidigeSpeler] = 0;
							strikeTweeWorpenTerug[huidigeSpeler]++; //laatste worp was een strike, volgende beurt ook nog extra punten
						}
						//laatste worp was een spare dus 2x zoveel punten
						if (spareVorigeBeurt[huidigeSpeler]) { 
							score[huidigeSpeler] = score[huidigeSpeler] + omgegooid;
							spareVorigeBeurt[huidigeSpeler] = 0;
						}
						if (totaalOmgegooid == 10 && j == 0) { //strike (eerst worp)
							printf("Strike!\n\n");
							if (beurt == 10) { //2 extra worpen bij de laatste beurt voor een strike
								printf("Extra worp 1: \n");
								scanf_s("%d", &omgegooid);
								score[huidigeSpeler] = score[huidigeSpeler] + omgegooid;
								if (strikeTweeWorpenTerug[huidigeSpeler]) {		//als de worp hiervoor een strike was, extra punten
									score[huidigeSpeler] = score[huidigeSpeler] + omgegooid;
								}
								printf("Extra worp 2: \n");
								scanf_s("%d", &omgegooid);
								score[huidigeSpeler] = score[huidigeSpeler] + omgegooid;
							}
							strikeEenWorpTerug[huidigeSpeler] = 1; //volgend beurt meer punten
							break; // geen extra worp nodig bij strike, volgende speler is aan de beurt
						}
						if (totaalOmgegooid == 10 && (j == 1 || j == 2)) { //spare gegooid in worp 2 of 3 (alle kegels in 1 beurt), wist niet zeker of bij 3 worpen ook spare moest, anders de j == 2 weghalen
							printf("Spare!\n\n");
							spareVorigeBeurt[huidigeSpeler] = 1; //extra punten volgende beurt 
							if (beurt == 10) { //1 extra worp bij spare als het de laatste beurt was
								printf("Extra worp 1: \n");
								scanf_s("%d", &omgegooid);
								score[huidigeSpeler] = score[huidigeSpeler] + omgegooid;
							}
							break; // als spare wordt gegooid bij worp 2 wanneer je 3 worpen totaal hebt. Geen derde worp nodig.
						}
					}//einde for 3 (worpen invullen)
				}//einde for 2	(wisseling speler)
				printf("Score speler 1: %d \n", score[0]);
				printf("Score speler 2: %d \n\n", score[1]); 
				huidigeSpeler = 1 - huidigeSpeler; //verander van speler
			}//einde for 1 (aantal beurten)
			printf("Einde\n\n");
			break;
		default:
			printf("Dat is geen opdracht nummer, het programma sluit af.\n"); 
		}
	} while (opdracht == 1 || opdracht == 2 || opdracht == 3 || opdracht == 4); //om een andere opdracht te bekijken zonder het programma af te sluiten
	

	return 0;
}

double inkomstenBelasting(int inkomsten) {
	double belasting = 0;
	double schijfEen = 0;
	double schijfTwee = 0;
	double inkomstenOver = 0;

	if (inkomsten < 75518) { //belasting als je onder de de 75k verdient. Alleen schijf een.
		return (belasting = inkomsten * 0.3697);
	}
	else {
		schijfEen = 75518 * 0.3697; //eerste gedeelte van inkomsten belasten schijf een
		inkomstenOver = inkomsten - 75518;
		schijfTwee = inkomstenOver * 0.4950; //rest inkomsten belasten schijf twee
		return (schijfEen + schijfTwee);
	}
	return 0;
}

int randGetal(int laagste, int hoogste) {
	srand(time(NULL)); //gebruik huidige  tijd voor random seed
	return rand() % (hoogste - laagste + 1) + laagste; // random getal tussen hoogste en laagste waarde, +1 om die waardes ook mee te laten tellen, +laagste zodat het binnen de twee waardes is
}

double gemiddelde(double cijfers[], int aantal) {
	double totaal = 0; //double voor het returnen
	for (int i = 0; i < aantal; i++)
	{
		totaal = totaal + cijfers[i]; 
	}
	return totaal / aantal; //gemiddelde
}

int aantalLaag(double cijfers[], int aantal) {
	int aantalVieren = 0;
	int aantalZevens = 0;
	int teLaag = 0;

	for (int i = 0; i < aantal; i++)
	{
		if (cijfers[i] < 4) {
			teLaag++;	
		}
		if (cijfers[i] == 4) {
			aantalVieren++;
		}
		if (cijfers[i] >= 7) {
			aantalZevens++;
		}
	}
	if (aantalZevens == aantal) { //als het aantal zevens gelijk is aan het aantal cijfers (dus met lof behaald)
		return aantalZevens;	  //dan return aantal zevens
	}
	if (teLaag > 0) { //cijfer onder 4 betekent direct niet gehaald
		return teLaag + aantalVieren; //return alle lage cijfers
	} 
	if (aantalVieren > 1) { // meer dan 1 vier betekent niet gehaald
		return aantalVieren; 
	}
	return 0;	
	}