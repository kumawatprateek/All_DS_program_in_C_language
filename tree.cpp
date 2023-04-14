#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct tree_node{
	int num;
	struct tree_node *left , *right;
}*root;
struct tree_node *newnode, *ptr;
void tree_nod(int x){   
	newnode=(struct tree_node *)malloc(sizeof(struct tree_node));
	newnode->num=x;
	newnode->left=NULL;
	newnode->right=NULL;
}
struct tree_node* create_node(struct tree_node* root, int x){
	if(root==NULL)
		tree_nod(x);
	else{
		if(x<root->num)
			root->left=create_node(root->left,x);
		else if(x>root->num)
			root->right=create_node(root->right,x);
		else
			return (0);
	}
}
void display(struct tree_node* root){ 
	if(root!=NULL){
		display(root->left);
		printf("%d ", root->num);
		display(root->right);
	}
}
void displayp(struct tree_node* root){ 
	if(root!=NULL){
		display(root->left);
		display(root->right);
		printf("%d ", root->num);
	}
}
void displaypi(struct tree_node* root){ 
	if(root!=NULL){
		printf("%d ", root->num);
		display(root->left);
		display(root->right);
	}
}
void display_tree(struct tree_node* root, int t){
	int i=1;
	if (root){
	display_tree(root->right,t+1);
	printf("\n");
	for(i=0;i<=t;i++)
		printf("   ");
	printf("%d<",root->num);
	display_tree(root->left, t+1);
	}
}
int main(){int n;
	root=NULL;
	while(n!=-1){
		printf("Enter value of tree node(if enter -1 Exit):= ");scanf("%d",&n);
		if(n==-1)
			break;
		else{
			if(root==NULL)
				root=create_node(root,n);
			else
				create_node(root,n);
		}fflush(stdin);		
	}
    printf("\n\tIn-order traversal of binary tree: ");
	display(root);
	printf("\n\tpost-order traversal of binary tree: ");
	displayp(root);
	printf("\n\tpre-order traversal of binary tree: ");
	displaypi(root);
	printf("\n\nTree is here:- \n\n");
	display_tree(root,0);
}
