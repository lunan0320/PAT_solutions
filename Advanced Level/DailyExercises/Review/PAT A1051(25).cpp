#include <cstdio>
#include <stack>

using namespace std;

const int maxn = 1001;

int arr[maxn]; //存储一组

stack<int> st;

//栈的最大容量，序列长度，序列个数 
int M, N, K;

int main(){
	scanf("%d%d%d",&M,&N,&K);
	for(int i = 0; i < K; i++){
		for(int j = 1; j <= N; j++){
			scanf("%d",&arr[j]);
		}
		//清空栈 
		while(!st.empty()){
			st.pop();
		}
		//加入栈，并判断边界条件
		int k = 1;
		bool flag = true;
		for(int j = 1; j <= N; j++){
			st.push(j);
			//超过栈的容纳数量 
			if(st.size() > M){
				flag = false;
				printf("NO\n");
				break;
			}
			
			//判断是否和数组相等，相等则pop
			while(!st.empty() && st.top() == arr[k]){
				st.pop();
				k++;
			} 	
		} 
		if(st.empty() && flag){
			printf("YES\n");
		}
	}
	return 0;
} 
