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

NODE *insertValueNoHead(int newValue,NODE *list){
    NODE * newNode = malloc(sizeof(NODE));
    newNode->sequence = list;
    newNode->value = newValue;

    list = newNode;
    
    return list;
}

void printListNoHead(NODE *list){
    NODE *aux;
    aux = list;

    while(aux != NULL){
        printf("%d\n",aux->value);
        aux = aux->sequence;
    }

}

NODE *deleteValueNoHead(NODE *list){
    NODE *aux;
    aux = list;

    list = aux->sequence;
    free(aux);

    return list;

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

    //INICIA LISTA SEM CABEÇA
    NODE *pListNH;
    pListNH = malloc(sizeof(NODE));
    pListNH->value = 2;
    pListNH->sequence = NULL;

    NODE *nv = insertValueNoHead(7,pListNH);
    NODE *li = insertValueNoHead(9,nv);
    NODE *delVal = deleteValueNoHead(li);
    printListNoHead(delVal);


}
