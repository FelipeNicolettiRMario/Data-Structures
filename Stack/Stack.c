#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int value;
    struct Node *sequence;
    
}NODE;

void incrementStack(int newValue,NODE **Stack){
    NODE *newNode,*aux;
    aux = *Stack;

    newNode = malloc(sizeof(NODE));
    newNode->sequence = NULL;
    newNode->value = newValue;

    if(aux != NULL){
        aux->sequence = newNode;
        *Stack = aux;
    }
    else
    {
        *Stack = newNode;
    }
    
}

void printTop(NODE *Stack){
    NODE *aux;
    aux = Stack;

    while (aux->sequence != NULL)
    {
        aux = aux->sequence;
    }
    printf("%d\n",aux->value);

}

void removeTop(NODE *Stack){

}
int main(){
    //Iniciando uma pilha
    NODE *pStack;
    pStack = malloc(sizeof(NODE));
    pStack = NULL;

    incrementStack(8,&pStack);
    incrementStack(9,&pStack);

    printTop(pStack);

}