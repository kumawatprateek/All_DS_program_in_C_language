#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct queue{
	int value;
	struct queue *next;
}*rear,*front;
struct queue *newnode, *ptr, *store;
void insert_que(){
	newnode=(struct queue*)malloc(sizeof(struct queue));
	printf("Enter value in queue= ");
	scanf("%d",&newnode->value);
	newnode->next=NULL;
	if(rear==front){
		rear=newnode;
	}
	else{
		ptr=rear;
		rear=newnode;
		newnode->next=ptr;
	}fflush(stdin);
}
void delete_que(){
	ptr=rear;
	if(rear==front){
		printf("Queue is Empty:");
	}
	else if(ptr->next==front){ 
		rear=front; printf("Value delete succefully.");
	}
	else{
		while(ptr->next!=front){
			store=ptr;
			ptr=ptr->next;
		}store->next=front; printf("Value delete succefully.");
	}
}
void display(){
	struct queue *ptr;
	if(rear==front){
		printf("Queue is Empty"); return;
	}
	ptr=rear;
	printf("\nQueue element:- ");
	while(ptr!=front){
		printf(" %d ->",ptr->value); ptr=ptr->next;
	}printf("\n");
}
int main(){
	int choice; rear=front;
	do{
		printf("\n\tEnter your choice in this:-");
		printf("\n\t 1. Insert value.");
		printf("\n\t 2. Delete value.");
		printf("\n\t 3. Display Queue.");
		printf("\n\t 4. Exit in Queue.");
		scanf("%d",&choice);
		switch(choice){
			case 1: insert_que();break;
			case 2: delete_que(); break;
			case 3: display(); break;
			case 4: break;
			default: printf("Enter right choice.");
		}
	}while(choice!=4);
}
