#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

struct node{
	int x[1000];
	int len;
	node(){
		memset(x,0,sizeof(x));
		len = 0;
	}	
}; 


node change(string str){
	node res; 
	int length = str.length();
	res.len = length;
	for(int i = length - 1;i >= 0; i--){
		res.x[i] = str[length - i - 1] - '0';
	}
	return res;
}

node add(node a,node b){
	node res;
	int carry = 0;
	for(int i = 0; i < a.len || i < b.len; i++){
		int temp = a.x[i] + b.x[i] + carry;
		res.x[res.len++] = temp % 10;
		carry = temp/10;
	}
	if(carry != 0){
		res.x[res.len++] = carry;
	}
	return res;
}

node reverse(node a){
	node res;
	res.len = a.len;
	for(int i = 0; i < a.len; i++){
		res.x[res.len - i -1] = a.x[i];
	}
	return res;
}

bool judge(node a){
	int k = a.len /2;
	for(int i = 0; i <= k; i++){
		if(a.x[i] != a.x[a.len - i -1]){
			return false;
		}
	}
	return true;
}

void print(node a){
	int len = a.len;
	for(int i = len - 1; i >= 0;i--){
		printf("%d",a.x[i]);
	}	
	printf("\n");
}



int main(){
	string input;
	int K;
	cin >> input >> K;
	int count  = 0;
	node in1 = change(input);
	node in2 =  reverse(in1);
	node res = in1;
	if(judge(in1)){
		print(in1);
		printf("0\n");
		return 0;
	}
	bool flag = false;
	while(count < K){
		count++;
		in2 =  reverse(in1);
		res = add(in1,in2);
		flag = judge(res);
		if(flag){
			print(res);
			printf("%d\n",count);
			break;
		}
		in1 = res;
	}
	if(!flag){
		print(res);
		printf("%d\n",count);
	}
	return 0;
}

