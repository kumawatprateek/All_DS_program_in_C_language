#include<stdio.h>
int arr1[100],arr2[100],arr[200];
int s;
void insert_array(int s,int arr[100]){printf("enter value of all element=\n");
	for(int i=0;i<s;i++){
		printf("Enter value [%d]= ",i);scanf("%d",&arr[i]);}
}
void marjing_arrays(int s1,int s2){
	for(int k=0,i=0,j=0;i<s1||j<s2; ){
		if(i>=s1){
			arr[k]=arr2[j];k++;j++;}
		else if(j>=s2){
			arr[k]=arr1[i];i++;k++;}
		else if(arr1[i]<arr2[j]){
			arr[k]=arr1[i];k++;i++;}
		else if(arr1[i]>arr2[j]){
			arr[k]=arr2[j];k++;j++;}
		else{
			arr[k]=arr1[i];j++;k++;i++;
			s-=1;}	
	}
}
void display(){printf("\nMerge array is here-- \n");
	for(int i=0;i<s;i++){
		printf("\n\t| Array[%d]= %d |",i,arr[i]);
	}   printf("\n\t+--------------+");
}
int main(){int size1,size2;
	printf("Enter size of first shorted array:- ");scanf("%d",&size1);
	insert_array(size1,arr1);
	printf("\nEnter size of second shorted array:- ");scanf("%d",&size2);
	insert_array(size2,arr2);
	s=size1+size2;
	marjing_arrays(size1,size2);
	display();}
