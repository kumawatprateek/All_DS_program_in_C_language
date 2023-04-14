//Code single linked list
#include<stdio.h>
#include<String.h>
#include<malloc.h>
#define MAX 10

struct studinfo{
	int marks;
	char name[MAX];
	struct studinfo *next;
}*start;
struct studinfo *newnode, *ptr, *store;
char ch;
void create_list(){
	do{
		newnode = (struct studinfo *)malloc(sizeof(struct studinfo));
		printf("\nEnter a new record: marks and name = ");
		scanf("%d%s",&newnode -> marks,newnode->name);
		newnode -> next = NULL;
		if(start == NULL){
		start = newnode;}
		else{
			ptr = start;
			while (ptr -> next!=NULL)
				ptr =ptr->next;
			ptr->next=newnode;}
		fflush(stdin);
		printf("\nyou want to continue (y/n) = ");
		scanf("%C",&ch);
	}while(ch=='y' || ch == 'Y');
} 
void insert_First(){
		if(start == NULL){
			printf(" Please create link list ");}
		else{
			newnode = (struct studinfo *)malloc(sizeof(struct studinfo));
			printf("\nEnter a new record: marks and name = ");
			scanf("%d%s",&newnode -> marks,newnode->name);
			newnode -> next = NULL;
			store = start;
			start = newnode;
			newnode->next = store;}
		fflush(stdin);
} 
void insert_Last(){
		if(start == NULL){
			printf(" Please create link list ");}
		else{
			newnode = (struct studinfo *)malloc(sizeof(struct studinfo));
			printf("\nEnter a new record: marks and name = ");
			scanf("%d%s",&newnode -> marks,newnode->name);
			newnode -> next = NULL;
			ptr = start;
			while (ptr -> next!=NULL)
				ptr =ptr->next;
			ptr->next=newnode;}
		fflush(stdin);
} 
void insert_After(){
	char C_name[MAX];
		printf("\n\nInsert Previous NODE name where you want to store next new NODE: ");
		scanf("%s",&C_name);
		newnode = (struct studinfo *)malloc(sizeof(struct studinfo));
		printf("\nEnter a new record: marks and name = ");
		scanf("%d%s",&newnode -> marks,newnode->name);
		newnode -> next = NULL;
		if(start == NULL){
			start = newnode;}
		else{
			ptr = start;
			int a = strcmp(ptr->name,C_name);//start = newnode;
			while(a!=0){
				ptr = ptr->next;
				a = strcmp(ptr->name,C_name);
			}
			newnode->next = ptr->next;
			ptr->next=newnode;			
			}
			fflush(stdin);
}

void insert_Before(){
	char p_name[10];
		printf("\nInsert name where you want to store before new NODE: ");
		scanf("%s",&p_name);
		newnode = (struct studinfo *)malloc(sizeof(struct studinfo));
		printf("\nEnter a new record: marks and name = ");
		scanf("%d%s",&newnode -> marks,newnode->name);
		newnode -> next = NULL;
		if(start == NULL){
			start = newnode;}
		else{
			ptr = start;
			int a = strcmp(ptr->name,p_name);//start = newnode;
			while(a!=0){
				store= ptr;
				ptr = ptr->next;
				a = strcmp(ptr->name,p_name);}
			newnode->next = store->next;
			store->next=newnode;}
		fflush(stdin);
}
void delete_Last(){
	ptr =start;
	if(start==NULL){
		printf("\n list is empty ");
		return;
	}
	else if(ptr->next==NULL){
		start=NULL;
		printf("\n\tSuccessfully Delete ");}
	else{
		while(ptr->next!=NULL){
			store=ptr;
			ptr = ptr->next;}
		store->next = NULL;
		printf("\n\tSuccessfully Delete ");
	}
}
void delete_First(){
	if(start==NULL){
		printf("\nlist is empty");
		return;
	}
	ptr = start;
	store = ptr->next;
	start = store;
	printf("\n\tSuccessfully Delete ");
} 
void delete_name(){
	char s_name[MAX];
	printf("/nEnter NAME of the STUDENT that you want to delete from LINKLIST: ");
	scanf("%s",s_name);
	if(start == NULL){
		printf("\n list is empty");
	}
	else{ptr=start;
		if(strcmp(ptr->name,s_name)==0){
			delete_First();
	 	}
		else{

			while(strcmp(ptr->name,s_name)!=0){
				store=ptr;
				ptr=ptr->next;
			}
			if (ptr->next == NULL){
				delete_Last();
	    	}
	   		store->next=ptr->next;
	   		free(ptr);
		}
	}
} 
void traverse(){
	struct studinfo *ptr;
	if(start == NULL){
		printf("\n list is empty ");
		return;}
	ptr = start;
	printf(" \nRecord:marks and name:= ");
	while(ptr!=NULL){
		printf("[ %d | %s ]-->",ptr->marks,ptr->name);
		ptr=ptr->next;
	}printf("\n");
}
void search_list(){
	struct studinfo *ptr;
	char a[10];
	printf("Enter name want to be search in list:- ");
	scanf("%s",a);
	ptr=start;
	while(ptr!=NULL){
		if(strcmp(ptr->name,a)==0){
			printf("\nRecord found_____");
            printf("\nRecord:marks and Name:= [ %d | %s ]-->",&ptr->marks,ptr->name);
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
		printf("\n\t| 4. Insert after a node.               |    8. DELETE NODE from name.       |");
		printf("\n\t| 5. Insert before a node.              |    9. Search node in link list.    |");
		printf("\n\t+---------------------------------------+------------------------------------+");
		printf("\n\t|10. Traverse list.                     |   11. Exit.                        |");
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
			case 8:delete_name();break;
			case 9: search_list();break;
			case 10:traverse();break;
			case 11:printf("\n\n\tThank for Exit.");break;
			default:printf("\n\nEnter right choice: ");
		}
	}while(choice!=11);
}//End of the @traverse function
