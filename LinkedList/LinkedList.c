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



int main(){
    //INICIA LISTA COM CABEÇA
    NODE *pList; 
    pList = malloc(sizeof(NODE));
    pList->sequence = NULL;

    insertValueHead(5,pList);
    insertValueHead(7,pList);

    insertValueHead(9,pList);

    printListHead(pList);


}