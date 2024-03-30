//#include <stdio.h>
//#include <string.h>
//#pragma warning(disable : 4996) //disable scanf warning
//
//typedef struct {
//	int studiepunten;
//	int cijfer;
//	char practicum;
//}student_t;
//
//void ken_studiepunten_toe(student_t *student, int cijfer, char practicum);
//
//int main() {
//
//	student_t student; 
//	student.cijfer = 7;
//	student.practicum = 'V';
//	student.studiepunten = 0;
//
//	ken_studiepunten_toe(&student, student.cijfer, student.practicum);
//
//	printf("Je hebt %d studiepunten.\n", student.studiepunten);
//
//	return 0;
//}
//
//void ken_studiepunten_toe(student_t *student, int cijfer, char practicum) { //pointer student want je wil de struct aanpassen
//	if (cijfer >= 5.5 && (practicum == 'V' || practicum == 'G')) {
//		student->studiepunten += 3; // (*student).studiepunten kan ook. -> om toegang te krijgen tot de variabelen in de struct
//	}
//}