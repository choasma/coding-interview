// StackLinkList.cpp : Defines the entry point for the console application.
/*
 * the multiple stacks implemented by link list using pointer array
 * created by fireass @ 9/1/2014
 */

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#define MAX_VERTICES 6
#define MAX_EDGES_UNDIRECT 6
#define MAX_EDGES_DIRECT 6
enum {WHITE, GRAY, BLACK};


typedef struct node* NodePointer;
typedef struct node{
	int index;		
	int distance;	//distance from starting point
	NodePointer link;
};

int i,j;
bool visited[MAX_VERTICES];

void GraphGeneration(NodePointer *arr,int *data){
	
	for(i=0;i<MAX_EDGES_UNDIRECT;i++){
		int twice = 2*i;
		
		NodePointer *ptr = &arr[data[twice]]; 
		
		NodePointer temp = (NodePointer)malloc(sizeof(node));
		temp->index = data[twice+1];
		temp->link = NULL;

		if(!*ptr){
			*ptr = temp;
		}
		else{
			NodePointer p = arr[data[twice]];
			while(p->link) p = p->link;
			p->link = temp;	
		}
		//printf("%d\n",ptr);
	}
}

void BFS(NodePointer *ptr){
	NodePointer p;
	std::queue<int> q;
	int visited[MAX_VERTICES]; //0 white 1 gray 2 black
	for(i=0;i<MAX_VERTICES;i++){
		visited[i] = 0;
		p = ptr[i];
		while(p){
			p->distance = INT_MAX;
			p = p->link;
		}
	}

	visited[0] = 1;
	ptr[0]->distance = 0;
	q.push(0);
	
	while(!q.empty()){

		int popValue = q.front();
		p = ptr[popValue];
		
		while(p){
			if(visited[p->index]==0){ //unvisited yet
				visited[p->index] = 1;
				q.push(p->index);				
			}
			p = p->link;
		}
		printf("%d ",q.front());
		q.pop();
		if(q.empty()){
			for(i=0;i<MAX_VERTICES;i++) if(!visited[i]) {
				visited[i] = 1;
				ptr[i]->distance = 0;
				q.push(i);
				break;
			}
		}
	}

	printf("\n");
}

void DFS_VISITED(NodePointer *ptr,NodePointer p){

	while(p){
		if(!visited[p->index]){
			visited[p->index] = true;
			printf("%d ",p->index);
		    DFS_VISITED(ptr,ptr[p->index]);
			
		}
		p = p->link;
	}
}

void DFS(NodePointer *ptr){
	
	for(i=0;i<MAX_VERTICES;i++) visited[i]=0;
	NodePointer p;

	for(i=0;i<MAX_VERTICES;i++){
		if(!visited[i]){
			printf("%d ",i);
			visited[i] = true;
			
			DFS_VISITED(ptr,ptr[i]);
		}
	}
}

void GraphPrinter(NodePointer *ptr){
	NodePointer p = *ptr;
	//printf("ptr=%d *ptr=%d p=%d\n",ptr,*ptr,p);
	for(i=0;i<MAX_VERTICES;i++){
		p = ptr[i];
		//printf("ptr[%d]=%d\n",i,ptr[i]);
		printf("[%d]->",i);
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
	for(i=0;i<MAX_VERTICES;i++) N[i] = NULL;
	//for(i=0;i<MAX_VERTICES;i++) {N[i] = (NodePointer)malloc(sizeof(node)); N[i]->link=NULL; N[i]->index = i;}
	N[MAX_VERTICES] = NULL;
	memset(visited,false,MAX_VERTICES);


	int data[][2] = {
		{0,1},{0,3},{1,4},{2,4},{2,5},{3,1}
	};
	printf("Adjacency Link-list Representation:\n");
	GraphGeneration(N,data[0]);
	GraphPrinter(N);
	printf("Breadth-first Search:");BFS(N);
	printf("Depth-first   Search:");DFS(N);
	system("pause");
	return 0;
}
