// Graph.cpp : Defines the entry point for the console application.
/*
 * the graph implemented by link list using pointer array
 * created by fireass @ 9/1/2014
 */

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_VERTICES 8
#define MAX_EDGES_UNDIRECT 20
#define MAX_EDGES_DIRECT 10



typedef struct node* NodePointer;
typedef struct node{
	int index;
	NodePointer link;
};

int i,j;

void GraphGeneration(NodePointer *arr,int *data){
	
	for(i=0;i<MAX_EDGES_UNDIRECT-1;i++){
		int twice = 2*i;
		
		NodePointer ptr = arr[data[twice]]; while(ptr->link) ptr = ptr->link;
		NodePointer temp = (NodePointer)malloc(sizeof(node));
		temp->index = data[twice+1];
		temp->link = NULL;
		ptr->link = temp;	
	}
}

void GraphPrinter(NodePointer *ptr){
	NodePointer p = *ptr;
	for(i=0;i<MAX_VERTICES;i++){
		p = ptr[i];
		printf("[%d]->",i);
		p = p->link;
		while(p){
			printf("[%d]",p->index);
			if(p->link)printf("->");
			p = p->link;
		}
		printf("\n");
	}
}


int main(void) {
	
	NodePointer *N = (NodePointer*)malloc(MAX_VERTICES*sizeof(NodePointer));
	for(i=0;i<MAX_VERTICES;i++) {N[i] = (NodePointer)malloc(sizeof(node)); N[i]->link=NULL;}
	N[MAX_VERTICES] = NULL;

	int data[][2] = {
		{0,1},{0,2},{0,5},{1,3},{1,4},{2,0},{2,5},{2,6},
		{3,1},{3,7},{4,1},{4,7},{5,2},{5,7},{6,3},{6,7},
		{7,3},{7,4},{7,5},{7,6}
	};
	printf("%d\n",*N);
	GraphGeneration(N,data[0]);
	GraphPrinter(N);

	system("pause");
	return 0;
}
