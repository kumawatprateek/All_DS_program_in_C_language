#include<stdio.h>
int n,m;
int matrix[111][111];
void insert_matrix(){
	matrix[n][m];
	printf("Enter values of matrix:-\n\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("\tEnter values of matrix[%d][%d]:- ",i+1,j+1);
			scanf("%d",&matrix[i][j]);
		}
	}
}
void acending_matrix(){
	int a;
	matrix[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			for(int k=0;k<m-1;k++){
				if(matrix[i][k]>matrix[i][k+1]){
					a = matrix[i][k];
            		matrix[i][k] = matrix[i][k+1];
        			matrix[i][k+1] = a;
				}
			}
		}
	}
} 
void descending_matrix(){
	int a;
	matrix[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			for(int k=0;k<m-1;k++){
				if(matrix[i][k]<matrix[i][k+1]){
					a = matrix[i][k];
            		matrix[i][k] = matrix[i][k+1];
        			matrix[i][k+1] = a;
				}
			}
		}
	}
} 
void display_matrix(){
	matrix[n][m];
	for(int i=0;i<n;i++){printf("\t|");
		for(int j=0;j<m;j++){
			printf(" %d ",matrix[i][j]);
		}printf("|\n");
	}
}  
main(){
	printf("Enter size of row and colam:-- ");
	scanf("%d %d",&n,&m);
	matrix[n][m];
	insert_matrix();
	printf("Here is Normal matrix : \n");
	display_matrix();
	printf("Thise matrix after DESCENDING : \n");
	descending_matrix();
	display_matrix();
	printf("Thise matrix after ACENDING : \n");
	acending_matrix();
	display_matrix();
}
