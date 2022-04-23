#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100;

//dp[i][j]表示字符串A的i号位和字符串B的j号位之前的LCS 
int dp[maxn][maxn];

char A[maxn];
char B[maxn];


int main(){
	gets(A+1);
	gets(B+1);

	int lenA = strlen(A+1);
	int lenB = strlen(B+1);

	//设置边界 此处要包括lenA和lenB 
	for(int i = 0; i <= lenA ;i++){
		dp[i][0] = 0;
	} 
	for(int j = 0; j <= lenB; j++){
		dp[0][j] = 0;
	}
	//状态转移方程
	
	for(int i = 1; i <= lenA; i++){
		for(int j = 1; j <= lenB; j++){
			if(A[i] == B[j]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	} 
	printf("两个字符串的最大公共子序列的长度为:%d\n",dp[lenA][lenB]);
	return 0;
	
} 


/*
《算法笔记》page 435


接受输入：
sadstory
adminsorry

预期输出：
6 
*/
