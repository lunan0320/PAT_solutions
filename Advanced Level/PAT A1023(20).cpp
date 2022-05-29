#include <cstdio>
#include <iostream>

using namespace std;

int orign_arr[21];
int new_arr[21];
int len = 0;

void change(string str){
	for(int i = 0; i < len; i++){
		orign_arr[i] = str[len - i - 1] - '0';
	} 
}

void multi(){
	int i = 0,carry = 0;//进位 
	for(; i < len; i++){
		int temp = orign_arr[i] * 2 + carry ;
		new_arr[i] = temp % 10;
		carry = temp / 10;
	}
	while(carry != 0){
		new_arr[i] = carry % 10;
		carry /= 10; 
	}
}

bool judge(){
	int count[10] = {0};
	for(int i = 0; i < len; i++){
		count[orign_arr[i]]++;
		count[new_arr[i]]--;
	}
	for(int i = 0; i < 10; i++){
		if(count[i] != 0){
			printf("%d\n",i);
			return false;
		}
	}
	return true;
}

int main(){
	string input;
	getline(cin,input);
	len = input.length();
	//转换为整数数组 
	change(input);
	//做乘法 
	multi();
	
	//判断
	bool res = judge(); 

	if(res){
		printf("Yes\n");
		for(int i = len - 1; i >= 0;i--){
			printf("%d",new_arr[i]);
		}
	}else{
		printf("No\n");
	}
	return 0;
}
