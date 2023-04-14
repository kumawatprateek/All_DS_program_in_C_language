#include<stdio.h>
#define max 3

int rear=-1;
int front=-1;
void ins_que(int que[max],int v){
	if(rear==max-1){
		printf("Queue is overflow");
	}
	else{
		rear+=1;
		que[rear]=v;
	}
}
void delete_que(int que[max]){
	if((rear== -1 ) || (front== rear)){
		printf("Queue is underflow");
	}
	else{
		printf("Element deleted from queue is : %d\n",que[front+1]);
		front=front+1;
	}
}
void display(int que[max]){
	if(rear<=-1){
		printf("Queue is empty");
	}
	else{
		printf("\tQueue ");
		printf("\n             ");
		printf("\n\t+---------------------------+\n");
		for(int i=rear;i>=front+1;i--){
			
			printf("\t | %d",que[i]);
		}
		printf("\n\t+---------------------------+");
		printf("\n             ");
	}
}

int main(){
	int array_que[max],v,val;
	
	do{
		printf("\n\t+-------------------------------------+");
		printf("\n\t| 1. Do insert opration.              |");
		printf("\n\t| 2. Do delete opration.              |");
		printf("\n\t| 3. Do Disptay.                      |");
		printf("\n\t| 4. Do Exit.                         |");
		printf("\n\t+-------------------------------------+");
		scanf("\t\t\t%d",&v);
		switch(v){
			case 1:
				{
					printf("Enter value of= ");
					scanf("%d",&val);
					ins_que(array_que,val);
					break;
				}
			case 2:
				{
					delete_que(array_que);
					break;
				}
			case 3:
				{
					display(array_que);
					break;
				}
			case 4: break;
			default : printf(" Write choise value.");			
		}
	}		while(v!=4);
}
