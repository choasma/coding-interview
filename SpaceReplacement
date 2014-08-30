/*
 * This project is the implementation of the question in Cracking the Coding Interview 4th 
 * In page 48, question 1.5
 * "Write a method to replace all spaces in a string with '%20'"
 *  
 * it's really simple, just think one character, the space, will be replace with three character 
 *
 * created by fireass @ 8/30/2014
*/

#include "stdafx.h"
#include <stdio.h>
#include <system_error>


void SpaceReplace(char **str){
	char *head = *str;
	int count = 0;
	int spaceCount = 0;
	while(*head) {
		if(*head == ' ') spaceCount++; 
		count++; head++; 
	}
	int newLength = count + 2*spaceCount;
	
	char *rst = (char*)malloc(newLength*sizeof(char));
	rst[newLength] = '\0';
	int tmp=0;
	for(int i=0;i<count;i++){
		if(*(*str+i) == ' '){
			rst[i+tmp] = '%';
			rst[i+tmp+1] = '2';
			rst[i+tmp+2] = '0';
			tmp+=2;
		}else{
			rst[i+tmp] = *(*str+i);
		}
	}
	*str = rst;
}



int _tmain(int argc, _TCHAR* argv[])
{
	char *s = "It is dangerous!";
	printf("Before :%s\n",s);
	SpaceReplace(&s);
	printf("After :%s\n",s);
	system("pause");
	return 0;
}

