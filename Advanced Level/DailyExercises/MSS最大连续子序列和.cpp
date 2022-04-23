#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 1000;

//A表示接受输入的每个值 
int A[maxn];

//N表示输入的数量 
int N; 
//dp[]表示以这个点为结束的最大连续子序列的和
int dp[maxn]; 

bool cmp(int a, int b){
	return a > b;
}

int MSS(){
	memset(dp,0,sizeof(dp));
	dp[0] = A[0];
	for(int i = 1; i < N; i++){
		//动态规划方程 
		dp[i] = max((dp[i-1] + A[i]),A[i]);
	}
	sort(dp,dp+N, cmp);
	int res = dp[0];
	return res;
}

int main(){
	//接受输入 
	scanf("%d", &N);
	for(int i =0; i < N; i++){
		scanf("%d", &A[i]);
	}
	//计算最大的连续子序列 
	int res = MSS();
	printf("最大连续子序列的和为:%d\n",res);
	return 0;
} 

/*
《算法笔记》 page 430

接受输入：
6
-2 11 -4 13 -5 -2

预期输出：
20 

*/
