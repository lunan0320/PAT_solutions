#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100;

//N表示结点数 
int N;
//记录每个输入的值 
int A[maxn];

//dp[]数组中记录的是以该结点为终点的LIS的长度 
int dp[maxn]; 

//Longest Increasing Sequence
int LIS(){
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i = 1; i < N; i++){
		//依次更新i前面的子序列 
		for(int j = 0; j < i; j++){
			//判断满足i前面的某个点比这个点小  且把i加入j的子序列会使得以i结尾的子序列更好 
			if(A[j] <= A[i] && dp[j] + 1 > dp[i]){
				//表示此时以i为结尾，前面是d[j]
				dp[i] = dp[j] + 1;
			} 
		} 
	}
	int res = 0;
	for(int i = 0; i < N; i++){
		if(dp[i] > res){
			res = dp[i];
		}
	} 
	return res;
} 

int main(){
	//接受输入 
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d",&A[i]);
	}	
	int res = LIS();
	printf("最大连续不降子序列长度为%d\n", res);
	return 0;
}

/*
《算法笔记》  page 433 

接受输入:
8
1 2 3 -9 3 9 0 11

预期输出:
6 

*/
