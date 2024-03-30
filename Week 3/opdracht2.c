//#include <stdio.h>
//#include <string.h>
//#pragma warning(disable : 4996) //disable scanf warning
//
//int checkLangsteWoord(char string[], int size);
//
//int main() {
//
//	char zin1[] = { "Het is bijna weekend" };
//	char zin2[] = { "Volgende week hebben wij een examen" };
//	char zin3[] = { "Zin in een feest" };
//
//	int size1 = sizeof(zin1) / sizeof(zin1[0]);
//	int size2 = sizeof(zin2) / sizeof(zin2[0]);
//	int size3 = sizeof(zin3) / sizeof(zin3[0]);
//
//	int getal1 = checkLangsteWoord(&zin1, size1);
//	int getal2 = checkLangsteWoord(&zin2, size2);
//	int getal3 = checkLangsteWoord(&zin3, size3);
//
//	//if (getal1 > getal2 && getal1 > getal3) {							//opdracht A
//	//	printf("Langste woord heeft: %d letters.", getal1);
//	//}
//	//else if (getal2 > getal1 && getal2 > 3) {
//	//	printf("Langste woord heeft: %d letters.", getal2);
//	//}
//	//else {
//	//	printf("Langste woord heeft: %d letters.", getal3);
//	//}
//
//
//	printf("Langste woord is %d", checkLangsteWoord(&zin3, size3)); //static variabele in de functie (opdracht B)
//
//	return 0;
//}
//
//int checkLangsteWoord(char string[], int size) {
//	static int langsteWoord = 0; //slaat het langste woord op door static (opdracht b), bij de laatste zin zal dit het grootste woord in alle zinnen ervoor  zijn
//	int lengte1 = 0;
//	int i = 0;
//
//	while (string[i] != '\0') {	//check of het niet het einde van de string is 
//		if (string[i] != ' ') {	//check voor spatie tussen de woorden
//			lengte1++;
//		}
//		else {
//			lengte1 = 0;
//		}
//		if (langsteWoord < lengte1) {
//			langsteWoord = lengte1;
//		}
//		i++;
//	}
//	return langsteWoord;
//}
//
