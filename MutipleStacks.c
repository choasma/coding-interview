// StackLinkList.cpp : Defines the entry point for the console application.
/*
 * the multiple stacks implemented by link list using pointer array
 * created by fireass @ 9/1/2014
 */

#include "stdafx.h"
#include <stdio.h>
#include <system_error>
#include <random>
#include <system_error>
#define STACKSIZE 10

typedef struct data{
	int id;
	const char *content;
}DATA;
typedef struct stack *StackPointer;
typedef struct stack{
	int data;
	StackPointer link;
};
void init(StackPointer s[]){
	for(int i=0;i<STACKSIZE;i++){
		s[i] = (StackPointer)malloc(sizeof(stack));
		s[i]->link = NULL;
	}
}

void PrintInformation(StackPointer s[]){
	printf("+----------STACKSBEGGING----------+\n");
	for(int i=0;i<STACKSIZE;i++){
		printf("[%2d ]",i);
		StackPointer temp = s[i];
		while(temp->link){
			printf("\33[%d]",temp->data);
			temp = temp->link;
		}
		if(i!=STACKSIZE-1)printf("\n  \031\n");
	}
	printf("\n+------------ENDSTACKS------------+\n");
}
void Push(StackPointer *s,int index,int value){
	StackPointer temp = (StackPointer)malloc(sizeof(stack)) ;
	temp->data = value;
	temp->link = s[index];
	s[index] = temp;
}
int Pop(StackPointer *s,int index){
	int value = s[index]->data;
	s[index] = s[index]->link;
	return value;
}

int _tmain(int argc, _TCHAR* argv[])
{
	StackPointer stack[STACKSIZE];//multiple stack
	init(stack);
	int index,choice = 0;
	printf("+----------------------------------------------+\n");
	printf("|This project is created by fireass @ 9.1.2014|\n");
	printf("+----------------------------------------------+\n");	
	int data=0;
	while(1){
		PrintInformation(stack);
		printf("0 exit 1 push 2 delete....\n");
		scanf("%d",&choice);
		switch(choice){
			case 0://exit
				exit(0);
				break;
			case 1://push
				printf("Push [index int]:");
				scanf("%d %d",&index,&data);
				Push(stack,index,data);
				break;
			case 2://pop
				printf("Pop [index]:");
				scanf("%d",&index);
				if(!stack[index]->link) continue;
				else printf("The value of pop element:[%d]\n",Pop(stack,index));
				break;
		}
		printf("\n\n");
	}
	
	system("pause");
}

