#include<stdio.h>
#define max 100
int top=-1;
void push(int arr[max],int x,int v){
	if(top>=x-1){
		printf("Stck is overflow");
	}
	else{
		++top;
		arr[top]=v;
	}
}
void pop(int arr[max]){
	if(top==-1){
		printf("Stack is underflow");
	}
	else{
		--top;
	}
}
void display(int arr[max]){
	if(top==-1){
		printf("Stck is empty");
	}
	else{
		printf("\tStack ");
		printf("\n             ");
		for(int i=top;i>=0;i--){
			
			printf("\n\t|  %d   |",arr[i]);
			printf("\n\t+-------+");
		}
		printf("\n             ");
	}
}

int main(){
	int array_stack[max],n,v,val;
	printf("Enter size of stack ");
	scanf("%d",&n);
	
	do{
		printf("\n\t+-------------------------------------+");
		printf("\n\t| 1. Do push opration.                |");
		printf("\n\t| 2. Do pop opration.                 |");
		printf("\n\t| 3. Do Disptay.                      |");
		printf("\n\t| 4. Do Exit.                         |");
		printf("\n\t+-------------------------------------+");
		scanf("\t\t\t%d",&v);
		switch(v){
			case 1:
				{
					printf("Enter value of= ");
					scanf("%d",&val);
					push(array_stack,n,val);
					break;
				}
			case 2:
				{
					pop(array_stack);
					break;
				}
			case 3:
				{
					display(array_stack);
					break;
				}
			case 4: break;
			default : printf(" Write choise value.");			
		}
	}		while(v!=4);
}
