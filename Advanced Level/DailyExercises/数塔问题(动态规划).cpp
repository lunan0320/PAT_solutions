#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100;

//dp[]记录状态，记录了当前结点出发下方的所有结点的最大和 
int dp[maxn][maxn] = {0};
int f[maxn][maxn];

int n;

int main(){
	scanf("%d",&n);
	//输入数塔 
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			scanf("%d", &f[i][j]);
		}
	}
	//设置dp数组的初始值 
	for(int i = 1; i <= n; i++){
		dp[n][i] = f[n][i];
	} 
	for(int i = n-1; i>= 1; i--){
		for(int j = 1; j <= i; j++){
			//状态转移方程 
			dp[i][j] = max(dp[i+1][j],dp[i+1][j+1]) + f[i][j];
		}
	} 
	printf("%d\n",dp[1][1]);
	
	return 0;
} 

/*
《算法笔记》 page 426 

每次只能走向下一层连接的两个数字，问路径上最大的和是多少？ 
 
测试样例：
5
5
8 3 
12 7 16
4 10 11 6
9 5 3 9 4

预期输出：
44 
*/
