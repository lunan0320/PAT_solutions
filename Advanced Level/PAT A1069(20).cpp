#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
 
using namespace std;


bool cmp(int a,int b){
	return a > b;
}


void to_array(int num,int input_temp[]){
	for(int i = 3; i >= 0; i--){
		input_temp[i] = num%10;
		num /= 10;
	}
	
}

int arr2int(int c[5]){
	int ans = 0;
	for(int i = 0;i <=3;i++){
		int temp = pow(10,3-i);
		ans += c[i] * temp;
	}
	return ans;
}

int main(){

	int num;
	scanf("%d",&num);
	int input[4];
	int min,max;
	while(1){
		to_array(num,input);
		sort(input,input+4,cmp);
		max = arr2int(input);
		sort(input,input+4);
		min = arr2int(input); 
		num = max - min;
		printf("%04d - %04d = %04d\n",max,min,num);
		if(num == 0 || num == 6174){
			break;
		}
	}
	return 0;
}
