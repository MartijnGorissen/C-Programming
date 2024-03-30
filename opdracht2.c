//#include <stdio.h>
//#include <string.h>
//#include <malloc.h>
//#pragma warning(disable : 4996) //disable scanf warning
//
//typedef struct Node {
//    struct Node* next;
//    int getal;
//}Node;
//
//typedef struct Node2 {
//    struct Node2* next;
//    void* data;
//}Node2;
//
//Node* arrayToLinked(int array[], int size) {
//
//    Node* head = NULL;
//    Node* current = NULL;
//
//    for (int i = 0; i < size; i++) {
//        Node* newNode = (Node*)malloc(sizeof(Node));//maak nieuwe node aan         NIET VERGETEN #INCLUDE <MALLOC.H>!!
//        if (newNode == NULL) {                      //checken of het aanmaken goed is gegaan
//            return NULL;
//        }
//        newNode->next = NULL;
//        newNode->getal = array[i];
//
//
//        if (head == NULL) {                         //als head NULL is, betekent dat het de eerste node is = wordt head
//            head = newNode;
//        }
//        else {
//            current = head;
//            while (current->next != NULL) {         //zoeken naar de laatste node
//                current = current->next;
//            }
//            current->next = newNode;                //de laatste node naar de nieuwe node wijzen
//        }
//    }
//    return head;                                    //locatie van head terug geven
//}
//
//Node2* arrayToLinked2(void* array2, int size, size_t dataType) {
//
//    Node2* head2 = NULL;
//    Node2* current2 = NULL;
//
//    for (int i = 0; i < size; i++) {
//        Node2* newNode2 = (Node2*)malloc(sizeof(Node2)); //maak nieuwe node aan         
//        if (newNode2 == NULL) {                          //checken of het aanmaken van de Node goed is gegaan
//            return NULL;
//        }
//        newNode2->data = malloc(dataType);              //wijs de correcte grote geheugen toe
//        if (newNode2->data == NULL) {                     //check toewijzen geheugen data
//            return NULL;
//        }
//
//        memcpy(newNode2->data, (char*)array2 + (i * dataType), dataType);    //kopieer de waarde van het element in array naar de nieuwe Node2
//        newNode2->next = NULL;                                               //(char*) hierboven want char = 1 byte
//
//        if (head2 == NULL) {                         //als head NULL is, betekent dat het de eerste node is = wordt head
//            head2 = newNode2;
//        }
//        else {
//            current2 = head2;
//            while (current2->next != NULL) {         //zoeken naar de laatste node
//                current2 = current2->next;
//            }
//            current2->next = newNode2;                //de laatste node naar de nieuwe node wijzen
//        }
//    }
//    return head2;                                    //locatie van head terug geven
//
//}
//void copyArray(int src[], int dest[]);
//void printList(Node* head);
//void freeList(Node* head);
//
//void printInt(void* data);
//void printDouble(void* data);
//void printList2(Node2* head, void(*printFunctie)(void*));
//void freeList2(Node2* head2);
//
//int main() {
//    int getallen[5] = { 1, 5, 10, 20, 50 };
//    int copy[5];
//    int sizeGetallen1 = sizeof(getallen) / sizeof(getallen[0]);
//    copyArray(getallen, copy);
//
//    Node* head = arrayToLinked(copy, sizeGetallen1);
//
//    printList(head);
//    printf("\n");
//    freeList(head);
//
//    int getallen2[5] = { 2, 13, 54, 65, 5 };
//    double getallen3[5] = { 4.3, 64.2, 14.8, 46.85, 100.00 };
//
//    int sizeGetallen2 = sizeof(getallen2) / sizeof(getallen2[0]);
//    int sizeGetallen3 = sizeof(getallen3) / sizeof(getallen3[0]);
//
//    Node2* intHead = arrayToLinked2(getallen2, sizeGetallen2, sizeof(int));
//    Node2* doubleHead = arrayToLinked2(getallen3, sizeGetallen3, sizeof(double));
//
//    printList2(intHead, &printInt);
//    printf("\n");
//    printList2(doubleHead, &printDouble);
//
//    freeList2(intHead);
//    freeList2(doubleHead);
//
//    return 0;
//}
//
//void copyArray(int src[], int dest[]) {
//    for (int i = 0; i < 5; i++) {
//        dest[i] = src[i];
//    }
//}
//
//void printList(Node* current) {
//    while (current != NULL) {
//        printf("%d -> ", current->getal);
//        current = current->next;
//    }
//    printf("NULL\n");
//}
//
//void freeList(Node* head) {
//    Node* temp;
//    while (head != NULL) {
//        temp = head;
//        head = head->next;
//        free(temp);
//    }
//}
//
//void printInt(void* data) {         //int printen
//    printf("%d", *(int*)data);
//}
//
//void printDouble(void* data) {      //double printen
//    printf("%.2lf", *(double*)data);
//}
//
//void printList2(Node2* head, void(*printFunctie)(void*)) {      //begin adres(pointer) van de functie meegeven
//    while (head != NULL) {
//        printFunctie(head->data);
//        printf(" -> ");
//        head = head->next;
//    }
//    printf("NULL\n");
//}
//
//void freeList2(Node2* head2) {
//    Node2* temp;
//    while (head2 != NULL) {
//        temp = head2;
//        head2 = head2->next;
//        free(temp->data);       //nu ook de data zelf vrijgeven, ipv alleen de node
//        free(temp);
//    }
//}