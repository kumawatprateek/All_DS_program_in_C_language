#include<stdio.h>
int array[100];
void insert_array(int x){
	for(int i=0;i<x;i++){
		printf("Array[%d]= ",i);
		scanf("%d",&array[i]);
	}
}
void radix_short(int x){int lrg,j,i,k,p;
	int digcnt,divsr,buktcnt[10],bukt[10][10],r;
	i=0; lrg=0;
	while(i<x){
		if(array[i]>lrg){
			lrg=array[i];}i++;
	}
	digcnt=0;
	while(lrg>0){
		digcnt+=1; lrg/=10;
	}
	i=1;divsr=1;
	while(i<=digcnt){
		j=0;
		while(j<10){
			buktcnt[j]=0;j++;
		}
	j=0;
		while(j<x){
			r=(array[j]/divsr)%10;
			bukt[r][buktcnt[r]]=array[j];
			buktcnt[r]++;j++;
		}
		j=0;p=0;
		while(j<10){
			k=0;
			while(k<buktcnt[j]){
				array[p]=bukt[j][k];
				p++;k++;
			}
		j++;	
		}
	i++;divsr*=10;			
	}
}
void display_array(int x){
	for(int i=0;i<x;i++){
		printf(" \narray[%d]= %d",i,array[i]);
	}
}
main(){int y;
	printf("Enter sizeof array:= "); scanf("%d",&y);
	insert_array(y);
	radix_short(y);
	display_array(y);
}
