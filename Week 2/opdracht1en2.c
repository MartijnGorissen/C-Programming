//#include <stdio.h>
//#include <string.h>
//
//void kopieerString(char src[], char dest[]);
//int kopieerString2(char src[], char dest[], int size);
//
//int main(){
//	char tekst1[10] = { "hamkaas" };
//	char tekst2[5];
//
//	//opdracht 2
//	//berekenen max size van arrays
//	int size1 = sizeof(tekst1) / sizeof(tekst1[0]);
//	int size2 = sizeof(tekst2) / sizeof(tekst2[0]);
//
//	printf("src: %s\n", tekst1);
//	printf("dest: %s\n", tekst2);
//
//	if (kopieerString2(tekst1, tekst2, size2)) { //geef nu ook  de size van de dest array mee
//		kopieerString2(tekst1, tekst2, size2);
//	}
//	else { //size is te klein, dus niet kopieëren
//		printf("0\n"); 
//	}
//
//	printf("\n\n");
//	printf("src: %s\n", tekst1);
//	printf("dest: %s\n", tekst2);	
//
//
//
//
//
//
//
////opdracht 1
////printf("src: %s\n", tekst1);
////printf("dest: %s\n", tekst2);
//
////kopieerString(tekst1, tekst2);
//
////printf("\n\n");
////printf("src: %s\n", tekst1);
////printf("dest: %s\n", tekst2);
//
//	return 0;
//}
//
//void kopieerString(char src[], char dest[]) { //opdracht 1
//	for (int i = 0; i < strlen(src); i++) 
//	{
//		dest[i] = src[i];
//	}
//	dest[strlen(src)] = '\0'; //voeg \0 toe aan het einde zodat er geen onzin wordt uitgeprint als de array een grotere lengte had
//}
//
//int kopieerString2(char src[], char dest[], int size) { //opdracht 2
//	if (size >= strlen(src)) {		//size is max grote van de array
//		for (int i = 0; i < strlen(src); i++)
//		{
//			dest[i] = src[i];
//		}
//		dest[strlen(src)] = '\0'; //voeg \0 toe aan het einde van de string
//		return 1;
//	}
//	else {
//		return 0;
//	}
//}