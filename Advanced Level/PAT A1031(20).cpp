#include <iostream>
#include <string.h>
#include "stdio.h"

using namespace std;

char input[100];


int n1, n2, n3;


int main(){
	//此处不能用gets()，不太安全emmm 
	cin.getline(input,100);
	
	int length = strlen(input);
	n1 = n3 = (length + 2) / 3;
	n2 = length + 2 - n1 - n3;
	int space = n2 -2;
	//除了最后一行 
	for(int i = 0; i < n1 - 1; i++){
		printf("%c",input[i]);
		for(int j = 0; j < space; j++){
			printf(" ");
		} 
		printf("%c\n",input[length - 1 - i]);
	}
	//打印最后一行
	for(int i = n1 - 1; i < n1 + n2 -1; i++){
		printf("%c",input[i]);
	} 
	return 0;
}

/*
测试样例：
helloworld! 

*/
