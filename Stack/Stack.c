#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int value;
    struct Node *sequence;
    
}NODE;

void incrementStack(int newValue,NODE *Stack){
	NODE *newCell;
	newCell = malloc(sizeof(NODE));
	newCell->value = newValue;
	newCell->sequence = Stack->sequence;
	
	Stack->sequence = newCell;
	
}

int removeTop(NODE *Stack){

	if(Stack->sequence == NULL){
		printf("Pilha está vazia");
		return 0;
	}
	else{
		int valueRemoved;
		NODE *aux;
		aux = Stack->sequence;
		valueRemoved = Stack->value;
		Stack->sequence = aux->sequence;
		free(Stack);
		return valueRemoved;
	
	}

}
int main(){
    //Iniciando uma pilha
    NODE stack;
    NODE *pStack;

	pStack = &stack;
	pStack->sequence = NULL;
	
	incrementStack(5,pStack);
	incrementStack(6,pStack);
	incrementStack(7,pStack);
	removeTop(pStack);


}