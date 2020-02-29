#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *sequence;
}NODE;

void insertValue(int newValue,NODE *list){
    NODE *newNode;
    newNode = malloc(sizeof(NODE));
    newNode->value = newValue;
    newNode->sequence = list->sequence;
    list->sequence = newNode;

}

void printList(NODE *list){
    NODE *itinerator;

    for(itinerator = list;itinerator != NULL;itinerator = itinerator->sequence){
        printf("%d \n",itinerator->value);
    }

}

NODE *searchValue(int searched,NODE * list){
    NODE *aux;
    aux = list->sequence;

    while (aux->sequence != NULL && aux->value != searched)
    {
        aux = aux->sequence;
    }

    return aux;

}

int main(){
    //CRIANDO UMA LISTA COM CABEÇA
    NODE noHead,*pnoHead;
    noHead.sequence = NULL;
    pnoHead = &noHead;

    insertValue(5,pnoHead);
    insertValue(10,pnoHead);

    pnoHead = searchValue(1,pnoHead);
    

    NODE head,*pHead;
    head.value = 2;
    head.sequence = NULL;
    pHead = &head;



}