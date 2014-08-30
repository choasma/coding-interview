/*
 * This project is the implementation of the question in Cracking the Coding Interview 4th 
 * In page 48, question 1.2
 * "Implement an algorithm to determine if a string has all unique characters. \n
 * What if you can not use additional data structures?"
 *  
 * created by fireass @ 8/30/2014
*/

#include "stdafx.h"
#include <stdio.h>
#include <system_error>
#include <iostream>
#include <string>

bool isUnique(char* s){
	char *cur = s; //examine the current element
	char *itr = s; //iteratly checking the previous element til the current one

	while(*++cur){
		for(;cur!=itr;itr++){
			if(*cur == *itr) return false;
		}
	}

	return true;
}

/*
 *which is a novel way to solve this problem, save time, save money, save space, save your life
 */
bool isUnique2(char *s){

	int a[8];//for all ASCII code can be represented as 256bit
	memset(a, 0, sizeof(a));//remember to reset the value...otherwise..

	while(*s++){
		int value = (int)(*s);
		int idx = value/32; int rem = value%32;
	
		if(a[idx] & (1<<rem)) return false;
		a[idx] |= (1<<rem);
	}

	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char *s1 = "fireass";
	char *s2 = "abcde";
	int a = 128;
	printf("%s\n",isUnique(s1)?"true":"flase"); //retrun false
	printf("%s\n",isUnique2(s2)?"true":"flase");//return true

	system("pause");
	return 0;
}

