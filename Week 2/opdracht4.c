//#include <stdio.h>
//#include <string.h>
//#pragma warning(disable : 4996) //disable scanf warning
//
//int main() {
//
//	FILE* fp;
//	char ch;
//	char locatie[10];
//	int wedstrijden = 0;
//	int goalsEen = 0;
//	int goalsTwee = 0;
//
//	int punten = 0;
//
//	int goalsVoor = 0;
//	int goalsTegen = 0;
//	int doelSaldoVoor = 0;
//	int doelSaldoTegen = 0;
//
//	fp = fopen("C:\\School HBO ICT\\school 2023 - 2024\\periode 3\\C programmeren\\week 2\\bestand.txt", "r");
//
//	if (fp == NULL) {
//		printf("Bestand kan niet geopend worden.\n");
//		return -1;
//	}
//
//	while (fscanf(fp, "%s %d - %d", locatie, &goalsEen, &goalsTwee) == 3) {
//		wedstrijden++;
//		goalsVoor = 0; //reset aantal goals per game
//		goalsTegen = 0;
//
//		if (strcmp(locatie, "Thuis") == 0) { //checkt of de locatie thuis is. vb: (1 - 0) betekent 1 goal gemaakt en 0 goals tegen
//			doelSaldoVoor += goalsEen; //totale aantal goals voor
//			doelSaldoTegen += goalsTwee; //totale aantal goals tegen
//			goalsVoor += goalsEen; //goals deze game voor
//			goalsTegen += goalsTwee; //goals deze game tegen
//		}
//		else { //locatie is niet thuis, dan betekent (1 - 0), 1 goal tegen en 0 gemaakt
//			doelSaldoVoor += goalsTwee; //totale aantal goals voor 
//			doelSaldoTegen += goalsEen; //totale aantal goals tegen
//			goalsVoor += goalsTwee; //goals deze game voor
//			goalsTegen += goalsEen; //goals deze game tegen 
//		}
//		if (goalsVoor > goalsTegen) { //meer goals gemaakt dan tegenstander geeft 3 punten
//			punten += 3;
//		}
//		else if (goalsVoor == goalsTegen) { //gelijkspel geeft 1 punt
//			punten++;
//		}
//	}
//	printf("%d wedstrijden, %d punten en doelsaldo (%d-%d)\n", wedstrijden, punten, doelSaldoVoor, doelSaldoTegen);
//
//	fclose(fp);
//
//	return 0;
//}