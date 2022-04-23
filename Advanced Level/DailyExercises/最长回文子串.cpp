#include <cstdio>
#include <cstring>

using namespace std; 

const int maxn = 1010;

//A表示输入的字符串 
char A[maxn];

//dp[][]表示从i到j是否是回文串 
int dp[maxn][maxn];

int main(){
	gets(A);
	int lenA = strlen(A);
	//初始化 
	memset(dp,0,sizeof(dp)); 
	int ans = 1; 
	for(int i = 0; i < lenA; i++){
		//自己到自己的回文串为1 
		dp[i][i] = 1;
		if(i < lenA-1){
			if(A[i] == A[i+1]){
				//则设置这个间隔2的回文串 
				dp[i][i+1] = 1;
				ans = 2;
			}			
		}

	}
//	for(int i = 0; i < lenA; i++){
//		printf("%c ",A[i]);
//	}
//	printf("\n");
//	
//	printf(" %c %c",A[0],A[4]);
	
	//对子串的间隔枚举 
	for(int L = 3; L <= lenA; L++){
		//枚举起始点 
		for(int i = 0; i + L -1 < lenA; i++){
			int j = i + L -1;
			//状态转移方程 
			printf("%d %d %c %c",i,j,A[i],A[j]);
			printf("\n");
			if(A[i] = A[j] && dp[i+1][j-1] ==1){
				//判断i+1 到 j-1之间是否是回文串 
				dp[i][j] = 1;
				ans = L;
			} 
		}
	}
	printf("最大回文串长度为：%d\n",ans);
}

/*
《算法笔记》 page 436

接受输入：
PATZJUJZTACCBCC

预期输出：
9 
*/
