#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *sequence;
}NODE;


void insertValueHead(int newValue,NODE *list){
    NODE *newNODE = malloc(sizeof(NODE));

    newNODE->value = newValue;
    newNODE->sequence = list->sequence;
    list->sequence = newNODE;

}

void printListHead(NODE *list){
    NODE *aux;
    aux = list->sequence;

    while(aux != NULL)
    {
        printf("%d\n",aux->value);
        aux = aux->sequence;
    }

}

void deleteValueHead(NODE *list){
    NODE *aux;
    aux = list->sequence;

    list->sequence = aux->sequence;
    free(aux);


}

void insertValueNoHead(int newValue,NODE *list){
    NODE * newNode = malloc(sizeof(NODE));
    newNode->value = newValue;
    newNode->sequence = list;

    list->sequence = NULL;
    list = newNode;

}

void printListNoHead(NODE *list){
    NODE *aux;
    aux = list;

    while(aux != NULL){
        printf("%d\n",aux->value);
        aux = aux->sequence;
    }

}

void deleteValueNoHead(NODE **list){
    NODE *aux;
    aux = *list;

    *list = aux->sequence;
    free(aux);

}


int main(){
    //INICIA LISTA COM CABEÇA
    NODE *pList;
    pList = malloc(sizeof(NODE));
    pList->sequence = NULL;

    insertValueHead(5,pList);
    insertValueHead(7,pList);

    insertValueHead(9,pList);
    deleteValueHead(pList);
    printListHead(pList);

    //INICIA LISTA SEM CABEÇA
    NODE *pListNH;
    pListNH = malloc(sizeof(NODE));
    pListNH->value = 2;
    pListNH->sequence = NULL;

    insertValueNoHead(7,&pListNH);
    insertValueNoHead(10,&pListNH);
    insertValueNoHead(10,&pListNH);
    insertValueNoHead(8,&pListNH);
    deleteValueNoHead(&pListNH);

    printListNoHead(pListNH);


}
