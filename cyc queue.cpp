#include<stdio.h>
#define MAX 3
int cqueue_arr[MAX];
int front = -1;
int rear = -1;
void insert(){
	int item;
	if((front == 0 && rear == MAX-1) || (front == rear+1)){
		printf("Queue Overflow ");
	}
	else{
		printf("Input the element for insertion in queue : ");
		scanf("%d", &item);
		if(front == -1){
		front = 0;
		rear = 0;
		cqueue_arr[rear] = item ;
		printf("\t|You successfully insert %d in Your queue.. ",item);
		printf("\n\t+---------------------------------------+\n");
	    } 
		else{
		rear = (rear+1)%MAX;
		cqueue_arr[rear] = item ;
		printf("\t|You successfully insert %d in Your queue.. ",item);
		printf("\n\t+---------------------------------------+\n");
		}
	}
}
void deletion(){
	if(front == -1){
		printf("Queue Underflown");
	}
	
	else if(front == MAX-1 && rear == -1){
		front = -1;
		rear=-1;
	}
	else{
		printf("Element deleted from queue is : %d ",cqueue_arr[front]);
		if(front == MAX-1)
			front = 0;
		else
			front = (front+1)%MAX;
	}
}
 
void display(){
	int f  = front,r  = rear;
	if(front == -1){
		printf("Queue is emptyn");
	}
	
	else{
		printf("Queue elements : ");
		if( f  <= r  ){
			while(f  <= r ){
				printf("%d ",cqueue_arr[f ]);
				f++;
			}
		}
		else{
			while(f  <= MAX-1){
				printf("%d ",cqueue_arr[f]);
				f++;
			}
			f  = 0;
			while(f  <= r ){
				printf("%d ",cqueue_arr[f]);
				f++;
			}
		}	
	}
}
int main(){
	int choice;
	do{
		printf("\n\t+-------------------------------------+");
		printf("\n\t| 1. Do insert opration.              |");
		printf("\n\t| 2. Do delete opration.              |");
		printf("\n\t| 3. Do Disptay.                      |");
		printf("\n\t| 4. Do Exit.                         |");
		printf("\n\t+-------------------------------------+");
		scanf("\t\t\t%d",&choice);
	switch(choice){
		case 1 :
			
			insert();
			break;
		case 2 :
			deletion();
			break;
		case 3:
			display();
			break;
		case 4:
			break;
		default:
			printf("Wrong choicen");
	    }
	}while(choice!=4);
}
