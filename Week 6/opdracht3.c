//#include <stdio.h>
//#include <string.h>
//#include <malloc.h>
//#pragma warning(disable : 4996) //disable scanf warning
//
//typedef struct Node {
//    struct Node* next;
//    double waarde;
//	char soort;
//}Node;
//
//Node* createNode(double waarde, char soort) {
//	Node* head = NULL;
//    Node* current = NULL;
//
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	if (newNode == NULL) {
//		return NULL;
//	}
//	newNode->waarde = waarde;
//	newNode->soort = soort;
//	newNode->next = NULL;
//
//	if (head == NULL) {
//		head = newNode;
//	}
//	else {
//		current = head;
//		while (current->next != NULL) {         //zoeken naar de laatste node
//			current = current->next;
//		}
//		current->next = newNode;                //de (laatste - 1) node naar de nieuwe node wijzen
//	}
//
//	return head;
//}
//
//double fNaarC(double f);
//double vNaarC(double v);
//double kNaarC(double k);
//
//Node* kopieer_en_conventeer(Node* src, double(*functie)(double)) {
//	if (src == NULL) {	//src linkedlist is leeg
//		return NULL;
//	}
//
//	Node* copyHead = NULL;
//	Node* currentSrc = src;
//	Node* currentCopy = NULL;
//
//	while (currentSrc != NULL) {
//		Node* newNode = createNode(currentSrc->waarde, currentSrc->soort);
//		newNode->next = NULL;
//
//		if (currentSrc->soort == 'f' && functie == fNaarC) {		//als het getal in fahrenheit is, converteer dan met de functie
//			newNode->waarde = functie(currentSrc->waarde);
//			newNode->soort = 'c';
//		}
//		else if (currentSrc->soort == 'v' && functie == vNaarC) {	//als het getal in volt is, converteer dan met de functie
//			newNode->waarde = functie(currentSrc->waarde);
//			newNode->soort = 'c';
//		}
//		else if (currentSrc->soort == 'k' && functie == kNaarC) {	//andere functie voor omrekenen (kelvin naar c)
//			newNode->waarde = functie(currentSrc->waarde);
//			newNode->soort = 'c';
//		}
//
//		if (copyHead == NULL) {
//			copyHead = newNode;
//		}
//		else {
//			currentCopy = copyHead;
//			while (currentCopy->next != NULL) {						//door de list heengaan
//				currentCopy = currentCopy->next;
//			}
//			currentCopy->next = newNode;							//(laatste - 1) wijzen naar de nieuwe laatste
//				
//		}
//		currentSrc = currentSrc->next;								//de orginele list eentje door gaan
//	}
//
//	return copyHead;
//}
//
//
//
//void freeList(Node* head);
//void printList(Node* current);
//
//int main() {
//
//	FILE* fp;
//	//fp = fopen("D:\\HBO ICT\\school 2023-2024\\periode 3\\C programmeren\\week6 opdracht3.txt", "r");	//computer
//	fp = fopen("C:\\School HBO ICT\\school 2023 - 2024\\periode 3\\C programmeren\\week 6\\week6 opdracht3.txt", "r");	//laptop
//
//	if (fp == NULL) {
//		printf("kan bestand niet openen.");
//		return -1;
//	}
//	
//	double waarde;
//	char soort;
//	Node* headList1 = NULL;
//
//	while (fscanf(fp, "%lf %c", &waarde, &soort) == 2) {		//inlezen
//		if (headList1 == NULL) {
//			headList1 = createNode(waarde, soort);				//nieuwe node aanmaken
//		}
//		else {
//			Node* newNode = createNode(waarde, soort);
//			Node* current = headList1;
//			while (current->next != NULL) {						//door de list heen gaan
//				current = current->next;
//			}
//			current->next = newNode;							//de (laatste - 1) node wijzen naar de laatste
//		}
//	}
//	fclose(fp);
//
//	printf("lijst1:\n");
//	printList(headList1);
//	printf("\n\n");
//
//	Node* kopie = kopieer_en_conventeer(headList1, &fNaarC);
//	//kopie = kopieer_en_conventeer(kopie, &vNaarC);
//	//kopie = kopieer_en_conventeer(kopie, &kNaarC);
//	printf("kopie:\n");
//	printList(kopie);
//
//	freeList(headList1);
//	freeList(kopie);
//
//	return 0;
//}
//
//
//double fNaarC(double f) {		// °C = (°F - 32) × 5/9
//	return (f - 32) * 5 / 9;
//}
//
//double vNaarC(double v) {
//	return v * 20 - 20;
//}
//
//double kNaarC(double k) {
//	return k - 273.15;
//}
//
//void freeList(Node* head) {
//	Node* temp;
//	while (head != NULL) {
//		temp = head;
//		head = head->next;
//		free(temp);
//	}
//}
//
//void printList(Node* current) {
//    while (current != NULL) {
//        printf("%.2lf %c -> ", current->waarde, current->soort);
//        current = current->next;
//    }
//    printf("NULL\n");
//}