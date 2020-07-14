#include<stdio.h> 
#include<stdlib.h> 
   
typedef struct node{ 
    int key; 
    struct node *left, *right; 
}NODE; 
   
NODE *newNode(int item) 
{ 
    NODE *temp =(NODE *)malloc(sizeof(NODE)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
   
NODE *insert(NODE *node, int key) 
{ 
    if (node == NULL) return newNode(key); 
  
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key);    
  
    return node; 
} 

NODE *removeRoot(NODE *root){
	NODE *auxSubTree,*auxTree;
		
	if(root->left == NULL) auxSubTree = root->right;
	else{
		auxTree = root;
		auxSubTree = root->left;
		
		while(auxSubTree->right != NULL){
			auxTree = auxSubTree;
			auxSubTree = auxSubTree->right;
		}
		
		if(auxTree != root){
			auxTree->right = auxSubTree->left;
			auxSubTree->left = root->left;
		}
		auxSubTree->right = root->right;
	} 
	free(root);
	return auxSubTree;
}

NODE *search(NODE *root,int k){
	if(root == NULL ||  root->key == k)
		return root;
	
	if(root->key > k)
		search(root->left,k);
	else
		search(root->right,k);
	
}

NODE *searchFromFather(NODE *root,int k){
	if(root == NULL||root->left->key == k ||root->right->key == k ){
		return root;
	}

	if(root->key > k)
		searchFromFather(root->left,k);
	else
		searchFromFather(root->right,k);
	
}

void erd (NODE *root){
	if(root != NULL){
		erd(root->left);
		printf("%d\n",root->key);
		erd(root->right);
	}
}

 /*
		     50
		  /	  	 \
		30    	 70
	   /   \  	/   \
	  20   40 	60   80  
	 /	\			/  \
	2	 25   	   75  90	
	    /  \           /  \
	   24   27        85    95
 */

   
int main() 
{ 

    NODE *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
	insert(root, 25); 
	insert(root, 75); 
	insert(root, 90); 
	insert(root, 2); 
	insert(root, 27); 
	insert(root, 24); 
	insert(root, 95); 
	insert(root, 85);
	 
	NODE *procura = searchFromFather(root,40);
	procura->right = removeRoot(procura->right);
	erd(root);
	
    return 0; 
} 