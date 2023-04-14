#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct poly_node{
	int powerx;
	int cofi;
	struct poly_node *next;
}*p,*q,*r, *newnode;
struct poly_node *poly_insert(struct poly_node *,int);
struct poly_node *poly_findloc(struct poly_node *, int);
struct poly_node *poly_add(struct poly_node *, struct poly_node *);
struct poly_node *poly_last(struct poly_node *, int, int);
struct poly_node *poly_copy(struct poly_node *, struct poly_node *);
void poly_change_symble(struct poly_node *start){
	struct poly_node *ptr;
	ptr=start;
	while(ptr!=NULL){
		ptr->cofi*=-1;
		ptr = ptr->next;
	}
}
void display(struct poly_node *start){
	struct poly_node *ptr;
	ptr=start;
	printf("\n powerx coef:- ");
	while(ptr!=NULL){
		printf("(%d)X^%d +", ptr->cofi, ptr->powerx );
		ptr = ptr->next;
	}
}
void display(struct poly_node *);
int main(){int n,m;
	p = NULL; 
	q = NULL; 
	r = NULL; 
	printf("Enter how many term. are insert in First Equation = "); scanf("%d",&n);
	p=poly_insert(p,n);
	printf("Enter how many term. are insert in Second Equation = "); scanf("%d",&m);
	q=poly_insert(q,m);
	printf("\n Polynomial Equation P ");
	display(p);
	printf("\n Polynomial Equation Q ");
	display(q);
	r = poly_add(p, q);
	printf("\n Polynomial Equation R = P + Q ");
	display(r);
	poly_change_symble(q);
	r=NULL;
	r = poly_add(p, q);
	printf("\n Polynomial Equation R = P - Q ");
	display(r);
} 
struct poly_node *poly_insert(struct poly_node *start, int x){
	for(int i=1;i<=x;i++){
	struct poly_node *loc;
	newnode = (struct poly_node *)malloc(sizeof(struct poly_node));
	printf("Enter record: Power and cofficent:= ");
	scanf("%d %d",&newnode->powerx,&newnode->cofi);
	loc = poly_findloc(start, newnode->powerx);
	if (loc ==NULL){
		newnode->next = start;
		start = newnode;
	}
	else{
		newnode->next = loc->next;
		loc->next = newnode;
	}}return (start);
} 
struct poly_node *poly_findloc(struct poly_node *start, int x){
	struct poly_node *prevptr, *ptr;
	if (start ==NULL)
	   return (NULL);
	if (x >start->powerx)
		return (NULL);
	prevptr =start;
	ptr 	=start->next;
	while (ptr!=NULL){
		if (x > ptr->powerx)
			return (prevptr);
		prevptr =ptr;
		ptr = ptr->next;
	}
return (prevptr);
}
struct poly_node *poly_add(struct poly_node *p, struct poly_node *q){
	struct poly_node *ptrp, *ptrq, *ptrr;
	ptrr = r;
	ptrp = p;
	ptrq = q;

	while ((ptrp !=NULL) && (ptrq !=NULL))
	{
		if (ptrp->powerx == ptrq->powerx){
			if ((ptrp->cofi + ptrq->cofi) != 0)
				ptrr = poly_last(ptrr, ptrp->powerx, ptrp->cofi + ptrq->cofi);
			ptrp = ptrp->next;
			ptrq = ptrq->next;
		}
		else if (ptrp->powerx > ptrq->powerx){
			ptrr = poly_last(ptrr, ptrp->powerx, ptrp->cofi);
			ptrp = ptrp->next;
			}
		else{
			ptrr = poly_last(ptrr, ptrq->powerx, ptrq->cofi);
			ptrq = ptrq->next;
			}
	}
	if (ptrp != NULL)
		  ptrr = poly_copy (ptrp, ptrr);
	else
		  ptrr = poly_copy (ptrq, ptrr);
return (r);
}
struct poly_node *poly_last(struct poly_node *ptrr, int x, int c){
	newnode = (struct poly_node *)malloc(sizeof(struct poly_node));
	newnode->powerx = x;
	newnode->cofi = c;
	if (ptrr ==NULL)
		r = newnode;
	else
		ptrr->next =newnode;

	newnode->next = NULL;
return (newnode);
} 
struct poly_node *poly_copy(struct poly_node *ptr, struct poly_node *ptrr){
		while (ptr !=NULL){
			ptrr = poly_last(ptrr, ptr->powerx, ptr->cofi);
			ptr  = ptr->next;
		}
return (ptrr);
} 
   
