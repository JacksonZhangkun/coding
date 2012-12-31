// Question1.7
// Write an algorithm such that if an element in an M*N matrix is 0,
// its entire row and column is set to 0.

#include<stdlib.h>
#include<stdio.h>

void setzeros(int** a,int M,int N){
	int i,j;
	//int row[M]={0};      //error: variable-sized object may not be initialized
	//int column[N]={0};   //error: variable-sized object may not be initialized
	int* row=malloc(sizeof(int)*M);
	int* column=malloc(sizeof(int)*N);

	for(i=0;i<M;i++)
		for(j=0;j<N;j++){
			if(*((int*)a+i*M+j)==0){
				row[i]=1;column[j]=1;
			}
		}

	for(i=0;i<M;i++)
		for(j=0;j<N;j++)
			if((row[i]==1)||(column[j]==1))
				*((int*)a+i*M+j)=0;
}

void printarray(int** a,int M,int N){
	int i,j;
	for(i=0;i<M;i++){
		for(j=0;j<N;j++)
			printf("%d	",*((int*)a+i*M+j));
		printf("\n");
	}
}
int main(){

	int a[3][3];
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			a[i][j]=i+j;
	printarray((int**)a,3,3);
	setzeros((int**)a,3,3);
	printarray((int**)a,3,3);
	return 0;
}


