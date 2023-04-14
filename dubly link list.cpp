#include<stdio.h>
#include<String.h>
#include<malloc.h>
#define MAX 10
struct studinfo{
	int id;
	int marks;
	char name[MAX];
	struct studinfo *next , *priv;
}*start;
struct studinfo *newnode, *ptr,*tip;
char ch;
void create_list(){
	do{
		newnode = (struct studinfo *)malloc(sizeof(struct studinfo));
	printf("\nEnter a new record: Id,name and marks= ");
	scanf("%d %s %d",&newnode->id,newnode->name,&newnode -> marks);
	
		newnode -> next = NULL;
		newnode -> priv = NULL;
		if(start == NULL){
			start = newnode;}
		else{
			ptr = start;
			while (ptr -> next!=NULL)
				ptr =ptr->next;
			
			ptr->next=newnode;
			newnode->priv=ptr;}
		fflush(stdin);
		printf("\nyou want to continue (y/n) = ");
		scanf("%C",&ch);
	}while(ch=='y' || ch == 'Y');
}
void last_list(){
		if(start == NULL){
			printf("-----First create a list------");}
		else{
			newnode = (struct studinfo *)malloc(sizeof(struct studinfo));
			printf("\nEnter a new record: Id,name and marks= ");
			scanf("%d %s %d",&newnode->id,newnode->name,&newnode -> marks);
			newnode -> next = NULL;
			ptr = start;
			while (ptr -> next!=NULL)
				ptr =ptr->next;
			
			ptr->next=newnode;
			newnode->priv=ptr;}
		fflush(stdin);
}
void first_list(){
		if(start == NULL){
			printf("-----First create a list------");
		}
		else{
			newnode = (struct studinfo *)malloc(sizeof(struct studinfo));
			printf("\nEnter a new record: marks and name = ");
			scanf("%d%s%d",&newnode ->id,newnode->name,&newnode->marks);
			newnode -> priv = NULL;
			ptr = start;
			start = newnode;
			newnode->next = ptr;
			ptr->priv=newnode;
		}
		fflush(stdin);
}
void after_list(){
	int did;
		if(start == NULL){
			printf("-----First create a list------");}
		else{
			printf("\n\nInsert Previous NODE name where you want to store next new NODE ID: ");
			scanf("%d",&did);
			newnode = (struct studinfo *)malloc(sizeof(struct studinfo));
			printf("\nEnter a new record: Id, Name and marks = ");
			scanf("%d %s %d",&newnode ->id,newnode->name,&newnode->marks);
			ptr = start;
		    while(did!=ptr->id){
				ptr = ptr->next;
			}
			tip=ptr;
			tip = tip->next;
			newnode->next = ptr->next;
			ptr->next=newnode;
			newnode->priv=ptr;
			tip->priv=newnode;
			}fflush(stdin);	
}
void before_list(){
	int did;
		if(start == NULL){
			printf("-----First create a list------");}
		else{
			printf("\nInsert name where you want to store before new NODE ID: ");
			scanf("%d",&did);
			newnode = (struct studinfo *)malloc(sizeof(struct studinfo));
			printf("\nEnter a new record: Id, Name and marks = ");
			scanf("%d %s %d",&newnode ->id,newnode->name,&newnode->marks);
			ptr = start;
			while(did!=ptr->id){
				tip= ptr;
				ptr = ptr->next;
			 }
			newnode->next = tip->next;
			tip->next=newnode;
			newnode->priv=tip;
			ptr->priv=newnode;}
		fflush(stdin);
}
void delete_duf(){
	if(start==NULL){
		printf("\nlist is empty");
		return;
	}
	ptr = start;
	tip = ptr->next;
	tip->priv=NULL;
	start = tip;
	printf("\n\tSuccessfully Delete ");
}
void delete_dul(){
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
			tip=ptr;
			ptr = ptr->next;}
		tip->next = NULL;
		printf("\n\tSuccessfully Delete ");
	}
}
void delete_id(){
	char s_name[MAX];
	printf("/nEnter NAME of the STUDENT that you want to delete from LINKLIST: ");
	scanf("%s",s_name);
	if(start == NULL){
		printf("\n list is empty");
	}
	else{ptr=start;
		if(strcmp(ptr->name,s_name)==0){
			delete_duf();
	 	}
		else{

			while(strcmp(ptr->name,s_name)!=0){
				tip=ptr;
				ptr=ptr->next;
				printf("\n\tSuccessfully Delete ");
			}
			if (ptr->next == NULL){
				delete_dul();
	    	}
	   		tip->next=ptr->next;
	   		ptr->next->priv=tip;
	   		free(ptr);
		}
	}
}
void seaching(){
	struct studinfo *ptr;
	char a[10];
	printf("Enter name want to be search in list:- ");
	scanf("%s",a);
	ptr=start;
	while(ptr!=NULL){
		if(strcmp(ptr->name,a)==0){
			printf("\nRecord found_____");
            printf("\nRecord:ID,name and marks:= [ %d | %s | %d ]-->",ptr->id,ptr->name,ptr->marks);
			break;
		}
		else
			ptr=ptr->next;
	}
	if(ptr==NULL)
		printf("\nnot found");	
}
void traverse(){
	struct studinfo *ptr;
	if(start == NULL){
		printf("\n list is empty ");
		return;}
	ptr = start;
	printf(" \nRecord:Id,Name and Marks:= ");
	while(ptr!=NULL){
		printf("[ %d | %s | %d ]<-->",ptr->id,ptr->name,ptr->marks);
		ptr=ptr->next;
	}printf("\n");
}
void backward_traversing(){
	struct studinfo *ptr;
	ptr = start;
	if(start==NULL){
		printf("\n\n\t\t>>>>>>Doubly LinkedList is empty.<<<<<<");
		return;
	}
	while(ptr->next!=NULL)
		ptr=ptr->next;
	printf(" \nRecord:Id,Name and Marks:= ");
	while(ptr!=NULL){
		printf("[ %d | %s | %d ]<-->",ptr->id,ptr->name,ptr->marks);
		ptr=ptr->priv;
	}printf("\n");
}
int main(){
	int choice;
	start = NULL;
	do{
		printf("\n\t+----------------------------------------------------------------------------+");
		printf("\n\t|  Enter choice for linklist operations.                                     |");
		printf("\n\t|============================================================================|");
		printf("\n\t| 1. create linklist.                   |    2. Searrching linklist.         |");
		printf("\n\t| 3. Insert as firat.                   |    7. Delete node at first.        |");
		printf("\n\t| 4. Insert as last.                    |    8. Delete node at last.         |");
		printf("\n\t| 5. Insert as after node.              |    9. Delete node at ID.           |");
		printf("\n\t| 6. Insert as before node.             |   10. Traverse list.               |");
		printf("\n\t+---------------------------------------+------------------------------------+");
		printf("\n\t|11. BarckwordTraverse list.            |   12. Exit.                        |");
		printf("\n\t+---------------------------------------+------------------------------------+");
		printf("\nEnter a choice that you want to do..= ");
		scanf("%d",&choice);
		switch(choice){
			case 1:create_list();break;
			case 2:seaching(); break;
			case 3:first_list(); break;
			case 4:last_list(); break;
			case 5:after_list(); break;
			case 6:before_list(); break;
			case 7:delete_duf(); break;
			case 8:delete_dul(); break;
			case 9:delete_id(); break;
			case 10:traverse(); break;
			case 11:backward_traversing(); break;
			case 12:printf("\n\n\t-----Thank for Exit.-----");break;
			default:printf("\n\nEnter right choice: ");
		}
	}while(choice!=12);
}//End of the @traverse function
