#include<stdio.h>
#include<String.h>
#include<malloc.h>
#define MAX 10

struct studinfo{
	int id;
	char cname[MAX];
	struct studinfo *next;
}*start;
struct studinfo *newnode, *ptr, *store;
char ch;
void create_list(){
	do{
		newnode = (struct studinfo *)malloc(sizeof(struct studinfo));
		printf("\nEnter a new record: Id and name = ");
		scanf("%d%s",&newnode -> id,newnode->cname);
		newnode -> next = NULL;
		if(start == NULL){
		start = newnode;
		newnode->next=start;}
		else{
			ptr = start;
			while (ptr -> next!=start)
				ptr =ptr->next;
			ptr->next=newnode;
			newnode->next=start;}
		fflush(stdin);
		printf("\nyou want to continue (y/n) = ");
		scanf("%C",&ch);
	}while(ch=='y' || ch == 'Y');
} 
void insert_First(){
	
	if(start == NULL){
		printf("---Please create list first---");}
	else{
		newnode = (struct studinfo *)malloc(sizeof(struct studinfo));
		printf("\nEnter a new record: Id and name = ");
		scanf("%d%s",&newnode -> id,newnode->cname);
		newnode -> next = NULL;
		ptr =start;
		while(ptr->next!=start)
			ptr=ptr->next;
		newnode->next=start;
		start = newnode;
		ptr->next=start;		
	}
} 
void insert_Last(){

	if(start == NULL){
		printf("---Please create first list----");}
	else{
		newnode = (struct studinfo *)malloc(sizeof(struct studinfo));
		printf("\nEnter a new record: ID and name = ");
		scanf("%d%s",&newnode -> id,newnode->cname);		
		ptr = start;
		while (ptr -> next!=start)
			ptr =ptr->next;
		ptr->next=newnode;
		newnode->next=start;
	}
}
void insert_After(){
	char C_name[MAX];
	int a=strcmp(ptr->cname,C_name);
	printf("\n\nInsert Previous NODE name where you want to store next new NODE: ");
	scanf("%s",&C_name);
	ptr=start;
	while(a != 0){
		ptr=ptr->next;
		a = strcmp(ptr->cname,C_name);
	}
	newnode = (struct studinfo *)malloc(sizeof(struct studinfo));
	printf("\nEnter a new record: marks and name = ");
	scanf("%d%s",&newnode -> id,newnode->cname);
	newnode -> next = ptr->next;
	ptr->next=newnode;
}

void insert_Before(){
	int  no;
	printf("\nInsert Id where you want to store before new NODE: ");
	scanf("%d",&no);
	ptr=start;
	if(no==ptr->id){
		insert_First();
	}
	else{
		while(ptr->id !=no){
			store=ptr;
			ptr = ptr->next;
		 }
	newnode = (struct studinfo *)malloc(sizeof(struct studinfo));
	printf("\nEnter a new record: ID and name = ");
	scanf("%d%s",&newnode -> id,newnode->cname);
	newnode->next=ptr;
	store->next=newnode;
    }
}
void delete_Last(){
	ptr =start;
	if(start==NULL){
		printf("\n list is empty "); 
	}
	else{
		if(ptr->next==start){
			start=NULL;
			printf("\n\tSuccessfully Delete ");}
		else{
			while(ptr->next!=start){
				store=ptr;
				ptr = ptr->next;
			}
			store->next = start;
			printf("\n\tSuccessfully Delete ");
		}free(ptr);
	}
}

void delete_First(){
	store=start;
    ptr = start;
	if(start==NULL){
		printf("\nlist is empty");
	}
	else{
   		if(ptr->next == start)
			start = NULL;
 		else{
	   		while(ptr->next !=start)
				ptr = ptr->next;
	    	start=start->next;
	    	ptr->next = start;
	    	printf("\n\tSuccessfully Delete ");
   		}free(store);
  	}
}
void delete_id(){
	int no;
	printf("/nWrite ID of the STUDENT that you want to delete from LINKLIST: ");
	scanf("%d",&no);
	if(start == NULL){
		printf("\n list is empty");
	}
	else{
		if((start->next==start)||(no == ptr->id)){
			delete_First();
		}
		else{
			ptr=start;
			while(ptr->id!=no){
				store=ptr;
				ptr=ptr->next;
				printf("\n\tSuccessfully Delete ");
			}
		if(ptr->next == start)
		    delete_Last();
		store->next=ptr->next;
	    free(ptr);
		}
	}
}

void traverse(){
	struct studinfo *ptr;
	if(start==NULL){
		printf(" Link list is Empty ");
	}
	else{
		ptr=start;
		printf(" \nRecord:ID and name:= ");
		while(ptr->next!=start){
			printf("[ %d | %s ]-->",ptr->id,ptr->cname);
			ptr=ptr->next;
		}
			printf("[ %d | %s ]-->",ptr->id,ptr->cname);	
	}
}
void seacrh_list(){
	struct studinfo *ptr;
	char a[10];
	printf("Enter name to be want to search:- ");
	scanf("%s",a);
	ptr=start;
	while(ptr!=NULL){
		if(strcmp(ptr->cname,a)==0){
			printf("\nElement is found___");
			printf("\nFound recode: ID and Name:= ");
			printf("[ %d | %s ]-->",ptr->id,ptr->cname);
			break;
		}
		else
			ptr=ptr->next;
	}
	if(ptr==NULL)
		printf("\nnot found");
}
//Main function
int main(){
	int choice;
	start = NULL;
	do{
		printf("\n\t+----------------------------------------------------------------------------+");
		printf("\n\t|  Enter choice for linklist operations.                                     |");
		printf("\n\t|============================================================================|");
		printf("\n\t| 1. create linklist.                                                        |");
		printf("\n\t+---------------------------------------+------------------------------------+");
		printf("\n\t| 2. Insert NODE at First.              |    6. DELETE NODE from first.      |");
		printf("\n\t| 3. Insert NODE at last.               |    7. DELETE NODE from last.       |");
		printf("\n\t+---------------------------------------+------------------------------------+");
		printf("\n\t| 4. Insert after a node.               |    8. DELETE NODE from Between.    |");
		printf("\n\t| 5. Insert before a node.              |    9. Traverse list.               |");
		printf("\n\t+---------------------------------------+------------------------------------+");
		printf("\n\t|10. Exit.                              |   11.Seacrh a node .               |");
		printf("\n\t+---------------------------------------+------------------------------------+");
		scanf("%d",&choice);
		switch(choice){
			case 1:create_list();break;
			case 2:insert_First();break;
			case 3:insert_Last();break;
			case 4:insert_After();break;
			case 5:insert_Before();break;
			case 6:delete_First();break;
			case 7:delete_Last();break;
			case 8:delete_id();break;
			case 9:traverse();break;
			case 10:printf("\n\n\tThank for Exit.");break;
			case 11:seacrh_list();break;
			default:printf("\n\nEnter right choice: ");
		}
	}while(choice!=10);
}//End of the @traverse function
