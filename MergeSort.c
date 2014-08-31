// Exercise.cpp : Defines the entry point for the console application.
/*
 * This is the merge sort practice implemented by c using recursive method
 * created by fireass @ 8/31/2014
 */

#include "stdafx.h"
#include <stdio.h>
#include <system_error>

#define SIZE 8
#define PRINT(X,Y,Z)  { for(int k=Y;k<Z;k++) printf("%d ",X[k]);} 
#define PRINT2(X,Y,Z) { printf("[ "); for(int k=Y;k<Z;k++) printf("%d ",X[k]); printf("] ");} 
int i,j,k;

void Merge(int *arr,int p,int q, int r){
	
	int n1 = q-p+1;
	int n2 = r-q;
	int *L = (int*)malloc(sizeof(n1+1)); memset(L,0,n1+1); 
	int *R = (int*)malloc(sizeof(n2+1)); memset(R,0,n2+1); 
	L[n1] = 1000;
	R[n2] = 1000;
	for(i=0;i<n1;i++) {L[i] = arr[p+i]; }
	for(i=0;i<n2;i++) {R[i] = arr[q+1+i];}
	i=0;j=0;
	for(k=p;k<=r;k++){
		//printf("k=%d L[%d]=%d R[%d]=%d \n",k,i,L[i],j,R[j]);
		if(L[i]<=R[j])arr[k] = L[i++];
		else arr[k] = R[j++];
	}
	printf("interation: "); PRINT(arr,0,p);PRINT2(arr,p,r+1);PRINT(arr,r+1,SIZE); printf("\n");

}

void MergeSort(int *arr,int p, int r){

	int q;
	
	if(p<r){
		q = (p+r)/2;
		MergeSort(arr,p,q);
		MergeSort(arr,q+1,r);
		//printf("p=%d q=%d r=%d \n",p,q,r);
		Merge(arr,p,q,r);
	}
}

void ShowData(char* str,int *arr){
	printf("%s:",str);
	i=0;
	while(i < SIZE) printf("%d ",arr[i++]);
	printf("\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[SIZE] = {5,2,7,4,3,1,6,2};

	ShowData("Before Sorting",a);
	MergeSort(a,0,SIZE-1);
	ShowData("After Sorting",a);
	system("pause");
	return 0;
}

