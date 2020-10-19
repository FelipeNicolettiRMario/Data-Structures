#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
	int value;
	struct Node *next;	
}NODE;

void insertElement(int newValue,NODE *list){
	NODE *newNode,*auxNode;
	
	auxNode = list;
	
	newNode = malloc(sizeof(NODE));
	newNode->value = newValue;
	newNode->next = NULL;
	
	while(auxNode->next != NULL){
		auxNode = auxNode->next;
	}
	
	auxNode->next = newNode;
}

void removeLastItem(NODE *list){
	NODE *auxList,*previousItem;
	
	auxList = list;
	
	while(auxList->next != NULL){
        previousItem = auxList;
		auxList = auxList->next;
	}
	previousItem->next = NULL;
	free(auxList);
}

void printList(NODE *list){
    NODE *aux;
    aux = list->next;

    while(aux != NULL)
    {
        printf("%d\n",aux->value);
        aux = aux->next;
    }

}



int main(){
	
	NODE *head;
	
	head = malloc (sizeof(NODE));
	
	head->next = NULL;
	
	insertElement(5,head);
	insertElement(4,head);
    insertElement(3,head);
    insertElement(3,head);
    removeLastItem(head);
    insertElement(7,head);
	printList(head);
	
	return 0;
}