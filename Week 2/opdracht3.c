//#include <stdio.h>
//#include <string.h>
//#pragma warning(disable : 4996) //disable scanf warning
//
//
//int main() {
//	int tempGrens = 25; 
//	char invoer[50];
//	int temperatuur; 
//
//	char brandstof[20];
//	double lengte;
//	double breedte;
//	double opp;
//	char doorgaan[20];
//
//
//	do
//	{
//		//zet alles naar 0 voor hergebruik
//		temperatuur = 0;
//		lengte = 0;
//		breedte = 0;
//		opp = 0;
//		memset(invoer, 0, sizeof(invoer));
//		memset(brandstof, 0, sizeof(brandstof));
//		memset(doorgaan, 0, sizeof(doorgaan));
//
//		printf("Voer de graden, brandstof of lengte en breedte in: \n");
//		fgets(invoer, sizeof(invoer), stdin); //leest de invoer in van de gebruiker, (hoofdletter gevoelig)
//		invoer[strcspn(invoer, "\n")] = '\0'; //verwijderen van de newline bij invoer
//
//		if (sscanf(invoer, "Temperatuur : %d", &temperatuur) == 1) { //invoer wordt gescand of 'Temperatuur : %d' is, zet het nummer in de variabele.
//			if (temperatuur > tempGrens) {
//				printf("Het is warmer dan 25 graden.\n");
//			}
//			else if (temperatuur == tempGrens) {
//				printf("Het is 25 graden.\n");
//			}
//			else {
//				printf("Het is kouder dan 25 graden.\n");
//			}
//		}
//		else if (sscanf(invoer, "Brandstof : %s", brandstof) == 1) {
//			if (strcmp(brandstof, "benzine") == 0 || strcmp(brandstof, "LPG") == 0 || strcmp(brandstof, "diesel") == 0 || strcmp(brandstof, "kerosine") == 0) {
//				//checkt of de invoer gelijk is aan de soorten benzines.
//				printf("Geldige waarde.\n");
//			}
//			else {
//				printf("Ongeldige brandstof.\n");
//			}
//		}
//		else if (sscanf(invoer, "Lengte : %lf Breedte : %lf", &lengte, &breedte) == 2) {
//			opp = lengte * breedte;
//			printf("%.2lf x %.2lf = %.2lf\n", lengte, breedte, opp);
//		}
//
//		else {
//			printf("Geen geldige invoer.\n");
//		}
//
//		printf("Wil je stoppen? Typ dan Einde \n");
//		scanf("%s", doorgaan);
//			getchar(); // om newline op te vangen na scanf doorgaan
//
//	} while (strcmp(doorgaan, "Einde") != 0);
//
//
//
//
//	return 0;
//}