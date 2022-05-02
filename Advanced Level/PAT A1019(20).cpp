#include <cstdio>

int N, b;
int z[50];
int length = 0;
//进制转换 除b取余 
void trans2b(){	
	while(N){
		z[length++] = N % b;
		N = N / b;
	}
}

//判断是不是回文数 
bool judgePnumber(){
	for(int i = 0; i < length / 2; i++){
		if(z[i] != z[length - i -1]){
			return false;
		}
	}
	return true;
}


int main(){
	scanf("%d %d", &N, &b);
	trans2b();
	bool res = judgePnumber();
	if(res){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	for(int i = length - 1; i >= 0; i--){
		if(i == 0){
			printf("%d",z[i]);
		}else{
			printf("%d ",z[i]);
		}
	}
}

/*
测试用例：
27 2
预期输出：
Yes
1 1 0 1 1

测试用例：
121 5
预期输出：
No
4 4 1
 
*/
