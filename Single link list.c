// SingleLinkList.cpp : Defines the entry point for the console application.
/*
 * A Link list practice whatever....
 * created by fireass @ 8/31/2014
 */

#include "stdafx.h"
#include <stdio.h>
#include <system_error>
#include <random>
#define SIZE 10

typedef struct listNode *listPointer;
typedef struct listNode{
	int data;
	listPointer link;
};

void Insert(listPointer l,int index,int value){
	int i=0;
	listPointer temp = (listPointer)malloc(sizeof(listNode));
	temp->data = value;
	if(index <= 1){
		temp->link = l;
		l = temp;
	}
	else if(index>=SIZE){
		while(l->link) l = l->link;
		l->link = temp;
		temp->link = NULL;
	}
	else{
		while(i++<index-2) l = l->link;
		temp->link = l->link;
	}
	
	
	l->link = temp;
}
void PrintList(listPointer l,char* s){
	printf("%s:\n",s);
	while(l) {
		printf("%d ",l->data);
		l = l->link;
	}
	printf("\n");
}
void Deletion(listPointer l,int index){
	listPointer trail = l;
	if(index>=SIZE){
		while(l->link->link) l = l->link;
		trail = l;
		trail->link = NULL;
		l = l->link;
		free(l);
	}else if(index<=1){
		l = l->link;
		free(trail);
	}else{
		for(int i=0;i<index-1;i++) l = l->link;
		for(int i=0;i<index-2;i++) trail = trail->link;
		trail->link = l->link;
		free(l);
	}
}
void Create(listPointer l,int size){
	for(int i=0;i<size;i++){
		l->link = (listPointer)malloc(sizeof(listNode));
		l->data = rand()%100+1;
		if(i<size-1) l = l->link;
		else l->link = NULL;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	printf("+----------------------------------------------+\n");
	printf("|This project is created by fireass @ 8.31.2014|\n");
	printf("+----------------------------------------------+\n");
	listPointer first = (listPointer)malloc(sizeof(listNode));
	Create(first,SIZE);
	PrintList(first,"Initail link list");
	int choice;
	int index,value;
	while(1){

		printf("\nPlease enter the following choice..\n");
		printf("0...exit\n");
		printf("1...insert\n");
		printf("2...delete\n");
		scanf("%d",&choice);
		switch(choice){
			case 0://exit
				exit(0);
				break;
			case 1://insert the value at specific position
				printf("Please enter the number of index and value: [eg:3 10] ");
				scanf("%d %d",&index,&value);
				Insert(first,index,value);
				PrintList(first,"After Insert");
				break;
			case 2://delete value from the list with position index	
				printf("Please enter a position number:");
				scanf("%d",&index);
				Deletion(first,index);
				PrintList(first,"After Delete");
				break;
		}
	}
	system("pause");
	return 0;
}

