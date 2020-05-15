#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int value;
    struct Node *sequence;
    
}NODE;

void insert(NODE **start,NODE **end,int newValue){
	NODE *newCell = malloc(sizeof(NODE));
	newCell->value = newValue;
	newCell->sequence = NULL;
	
	if(*end == NULL){
		*end = *start = newCell;
	}
	else{
		(*start)->sequence = newCell;
		*start = newCell;
	}
}

int removeLast(NODE **end,NODE **end){
	NODE *aux = malloc(sizeof(NODE));
	int removed = (*start)->value;
	aux = *end;
	
	if(*end == NULL){
		printf("Fila está vazia");	
		return 0;
	}
	else{
		*end= aux->sequence;
		free(aux);
		return removed;
		
	}
	
}

int main(){
	//Fila sem cabeça
	NODE *start,*end;
	
	start = end = NULL;
	
	insert(&start,&end,7);
	insert(&start,&end,10);
	removeLast(&start,&end);

	
	return 0;
}