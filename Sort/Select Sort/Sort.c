#include <stdio.h>
#include <stdlib.h>

void selection(int *Vec,int n){
	int minor,aux;
	int i;
	int j;
	for(i=0;i<n-1;i++){
 		minor=i;
		for(j=i+1;j<n;j++){
			if(Vec[minor]>Vec[j])
				minor=j;
		}
		if(i!=minor){
			aux=Vec[i];
			Vec[i] = Vec[minor];
			Vec[minor] = aux;
		}
	}
}

int main(){
	
	int n = 5;
	int Vector[5] = {4,2,3,1,5};
	
	selection(Vector,n);
	
	int i;
	for(i=0;i<n;i++){
		printf("%d - ",Vector[i]);
	}
	
	return 0;
	
}