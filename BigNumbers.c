/* BigNumbers.cpp : Defines the entry point for the console application.
 *
 * Welcome back this is the program soving the big number problem
 * such as the big factorial numbers 100!
 * one way to tackle the problem is using the array to store numbers!
 * after that, the carry number should be considered
 * 
 * by fireass @ 9/7/2014
 */

#include "stdafx.h"
#include <system_error>
#define MAXSIZE 1000
#define FACTORIAL 100

typedef struct{
	int *NUM;
	int length;
	bool sign;
}BIGNUMBERS;
int i;

void BigNumerMul(BIGNUMBERS *a,int b){
	int c=0,t=0,m=0;//carry, temp, additional length
	i=0;
	for(i=0;i<a->length;i++){
		t = a->NUM[i]*b + c; //iteratly calculate the number with adding carry
		a->NUM[i]=t%10;	     //assign the first number
		c = t/10;			 //generate carry
	}
	t = c;
	while(t>0){
		m++;
		t /= 10;
	}

	while(m-->0){
		a->NUM[a->length++] = c%10;
		c /= 10;
	}

}
void BigNumberPrint(BIGNUMBERS *a){
	printf("The answer:");
	for(i=a->length-1;i>=0;i--){
		printf("%d",a->NUM[i]);
	}
	printf("\n");
}
void BigNumberSetup(BIGNUMBERS *a,int t){
	while(t>0){
		a->NUM[i++] = t%10;
		t /= 10;
		a->length++;
	}
}
void BigNumberFactorial(BIGNUMBERS *a,int n){
	BigNumberSetup(a,FACTORIAL);
	for(int i=FACTORIAL-1;i>0;i--)BigNumerMul(a,i);
}

int _tmain(int argc, _TCHAR* argv[])
{
	BIGNUMBERS a; a.length=0;
	int* arr = (int*)malloc(MAXSIZE*sizeof(int));
	memset(arr,0,MAXSIZE);
	a.NUM = arr;

	BigNumberFactorial(&a,FACTORIAL);
	BigNumberPrint(&a);
	system("pause");
	return 0;
}

