#include <stdlib.h>
#include <stdio.h>

void shell(int vector[],int n){
	int h = n/2;
	
	while(h>0){
		int i = h;
		while(i<n){
			int aux = vector[i];
			int j = i;
			while(j>=h && aux<vector[j-h]){
				vector[j] = vector[j-h];
				j = j-h;
			}
			vector[j] = aux;
			i = i+1;
		}
		h = h/2;
	}
    
	int i;
	for(i = 0;i<=6;i++)
	{
		printf("%d -",vector[i]);
	}
}


int main(){
	
	int vector[7] = {2,4,1,6,7,8,9};
	shell(vector,7);
	
	return 0;
}