#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;

const int maxn = 1010;

//数组保存输入的序列 
int arr[maxn];

stack<int> st;



int main(){
	int M, N, K;
	scanf("%d %d %d",&M,&N,&K);
	//K组样例 
	for(int i = 0; i < K; i++){
		bool flag = true;
		//读入一组pop值 
		for(int j = 1; j <= N; j++){
			scanf("%d",&arr[j]);
		}
		//清空栈
		while(!st.empty()){
			st.pop();
		} 
		//k表示到了输入的第几个 
		int k = 1;
		//t表示stack此时push了多少个 
		for(int t = 1; t <= N; t++){
			st.push(t); 
			//超过规定的push数量 
			if(st.size() > M){
				flag = false;
				break;
			}
				
			while(!st.empty() && st.top() == arr[k]){
				st.pop();
				k++;
			}
		} 

		
		if(st.empty()==true && flag == true){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}


/*
测试样例：
5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2
 
*/
