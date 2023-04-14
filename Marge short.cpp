#include<stdio.h>
#define max 100
void insert_array(int s,int arr[max]){printf("enter value of all element=\n");
	for(int i=0;i<s;i++){
		printf("Enter value [%d]= ",i);scanf("%d",&arr[i]);
	}
}
void marge_short(int low,int high,int array[max]){
	void marge_array(int,int,int,int[]);
	int mid;
	if(low<high){
		mid=(low+high)/2;
		marge_short(low,mid,array);
		marge_short(mid+1,high,array);
		marge_array(low,mid,high,array);
		return;
	}
}
void marge_array(int low,int mid,int high,int array[max]){
	int h,barray[max],i,j,k;
	h=low;i=low;j=mid+1;
	printf("\n Recursion calls :%d %d %d",low,mid,high);
	while((h<=mid) && (j<=high)){
		if (array[h]<= array[j]){
			barray[i]=array[h]; h=h+1; }
		else{
			barray[i]=array[j]; j=j+1; }
		i=i+1;
	}
	if (h>mid)
   		for(k=j;k<=high;k++){
		   barray[i] = array[k]; i=i+1; }
	else
   		for(k=h;k<=mid;k++){
		    barray[i] = array[k]; i=i+1; }
		for (k=low;k<=high;k++){
			array[k]=barray[k];}
return;	
}
void display(int s,int arr[max]){printf("\nMerge array is here-- \n");
	for(int i=0;i<s;i++){printf("\n\t+--------------+");
		printf("\n\t| Array[%d]= %d |",i,arr[i]);
	}   printf("\n\t+--------------+");
}
main(){
	int array[max],i,j,k,low=0,high,mid,n;
	printf("\nEnter the number of elements = ");
	scanf("%d",&n);	
	insert_array(n,array);
	high = n-1;
	marge_short(low,high,array);
	display(n,array);
}
