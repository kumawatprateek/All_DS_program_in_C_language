#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct stack{
	int marks;
	struct stack *next;
}*top;
struct stack *newnode, *ptr, *store;
void insert_stack(){
	newnode=(struct stack*)malloc(sizeof(struct stack));
	printf("Enter element in stack= ");
	scanf("%d",&newnode->marks);
	newnode->next=NULL;
	if(top==NULL){
		top=newnode;
	}
	else{
		ptr=top;
		top=newnode;
		newnode->next=ptr;
	}fflush(stdin);
}
void delete_stack(){
	if(top==NULL){
		printf("Stack is Empty"); return;
	}
	ptr=top;
	store=ptr->next;
	top=store; printf("Element Was deleted.");
}
void display(){
	struct stack *ptr;
	if(top==NULL){
		printf("Stack is Empty.");
	}
	else{
		ptr=top;printf("\n\t-------------------------------------|");
		while(ptr!=NULL){
			printf("\n\t Stack element:= %d",ptr->marks);
			ptr=ptr->next;
		}printf("\n\t________________________________________|");
	}
}
int main(){top=NULL;
	int choice;
	do{
		printf("\n\tEnter your chioce:- ");
		printf("\n\t 1. Incert element in stack.");
		printf("\n\t 2. Delete element in stack.");
		printf("\n\t 3. Display all element.");
		printf("\n\t 4. Exit form stack.");
		scanf("%d",&choice);
		switch(choice){
			case 1: insert_stack(); break;
			case 2: delete_stack(); break;
			case 3: display(); break;
			case 4: break;
			default : printf("Enter right choice Please. --");
		}
	}while(choice!=4);
}
