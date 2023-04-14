#include<stdio.h>
#include<malloc.h>
struct poly_eq{
	int powerx;
	int cofic;
	struct poly_eq *next;
}*start;
struct poly_eq *loc, *ptr;
void findloc(int power){
		ptr=start;
		loc=NULL;
		while(ptr!=NULL){
			if(ptr->powerx<power)
				break;
			else{
				loc = ptr;
				ptr=ptr->next;
			}
		}
}
void Pinsert(int x){
	struct poly_eq *poly_NODE,*ptr;
	for(int i=1;i<=x;i++){
		poly_NODE = (struct poly_eq *)malloc(sizeof(struct poly_eq));
		printf("Enter record:Power & cofficente:= ");
		scanf("%d %d",&poly_NODE->powerx,&poly_NODE->cofic);
		poly_NODE->next = NULL;
		if(start==NULL)
			start=poly_NODE;
		else{
			ptr=start;
			findloc(poly_NODE->powerx);
			if(loc==NULL){
				poly_NODE->next=ptr;
				start=poly_NODE;
			}
			else{
				poly_NODE->next=loc->next;
				loc->next = poly_NODE;}
		}fflush(stdin);
	}
}
void traversing(){
	struct poly_eq *ptr;
	ptr = start;
		while(ptr!=NULL){
			printf("(%d)X^%d +",ptr->powerx,ptr->cofic);
			ptr=ptr->next;
		}
	
}
int main(){int n;
	start=NULL;
	printf("Enter how many term. are insert in= "); scanf("%d",&n);
	Pinsert(n);
	traversing();
}
