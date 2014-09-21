// BubbleSort.cpp : Defines the entry point for the console application.
/*
 * created by fireass @ 9/21/2014
 */

#include "stdafx.h"
#include <iostream>
#define SIZE 10 // array size

//if a larger then b return true
bool Larger(int a, int b){
	return a>b;
}
//if a smaller then b return true
bool Smaller(int a, int b){
	return a<b;
}
void BubbleSort(int *arr,bool (*compare)(int,int)){
	int temp=0;
#if 1
	for(int i=0;i<SIZE-1;i++){
		for(int j=0;j<SIZE-i-1;j++){
			if(compare(arr[j],arr[j+1])){
				temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}
	}
#else 
	for(int i=0;i<SIZE;i++){
		arr[i]++;
	}
#endif
}

void PrintInfo(int *arr){
	for(int i=0;i<SIZE;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}


int main(void) {
	int arr[SIZE] = {10,3,8,45,2,1,9,5,7,20};
	PrintInfo(arr);
	BubbleSort(arr,Larger);
	PrintInfo(arr);
	system("pause");
}
