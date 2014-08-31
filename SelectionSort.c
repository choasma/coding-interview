// Exercise.cpp : Defines the entry point for the console application.
/*
 * This is the insertion sort practice implemented by c
 * index i in InsertionSort indicates the "current element" being inserted into the right position
 * created by fireass @ 8/31/2014
 */

#include "stdafx.h"
#include <stdio.h>
#include <system_error>
#define SIZE 6
#define PRINT(X) { for(int k=0;k<SIZE;k++) printf("%d",X[k]); printf("\n");} 
int i,j;
void InsertionSort(int *arr){
	int key;
	for(i=1;i<SIZE;i++){
		key = arr[i]; 
		j = i-1;
		while(key < arr[j] && j>=0) arr[j+1] = arr[j--];
		arr[j+1] = key;
		printf("interation:%d ", i);
		PRINT(arr);
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
	int a[SIZE] = {5,2,4,6,1,3};

	ShowData("Before Sorting",a);
	InsertionSort(a);
	ShowData("After Sorting",a);
	system("pause");
	return 0;
}

