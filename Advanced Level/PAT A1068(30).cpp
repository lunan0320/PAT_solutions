#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 10010;
 
//记录每个硬币的value 
int w[maxn];

//N个硬币，要凑M元 
int N, M;

//表示在i元的时候最大价值 
int dp[maxn]; 

//在价值j的时候是否选择第i个硬币 
bool choice[maxn][maxn];
bool flag[maxn] = {false};
 
bool cmp(int a,int b){
	return a> b;
}


int main(){
	scanf("%d %d",&N,&M);
	for(int i = 1; i <= N; i++){
		scanf("%d",&w[i]);
	}
	//要先挑选价值高的 
	sort(w+1,w+N+1,cmp);
	
	//外层循环是遍历每个硬币 
	for(int i = 1;i <= N;i++){
		//内层循环是看这个硬币用多少次 
		for(int v = M; v >= w[i];v--){
			//价格更合适，在空间v的时候用第i个硬币创造的价值更高 
			if(dp[v] <= dp[v-w[i]] + w[i]){
				
				dp[v] = dp[v-w[i]] + w[i];
				//在价格v的时候选择i 
				choice[i][v] = true;
			}else{
				choice[i][v] = false;
			}
		}
	}
	if(dp[M] != M){
		printf("No Solution");
		return 0;
	} 
	int num = 0,v = M;
	for(int k = N; k >= 0;k--){
		if(choice[k][v]){
			flag[k] = true;
			v -= w[k];
			num++;
		}
		else{
			flag[k] = false;
		}
	}
	for(int i = N; i >= 1; i--){
		if(flag[i] == true){
			printf("%d",w[i]);
			num--;
			if(num > 0){
				printf(" ");
			}
		}
	}
	return 0;
} 

