#include <cstdio>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn = 100000;

int N , M, L;
int like_id = 0;
	
int like[maxn];
int G[maxn];
int temp_path[maxn];
int res = -1;

int d[maxn] ;
int dp[maxn]; 
int main(){
	scanf("%d",&N);
	scanf("%d",&M);
	int temp;
	memset(like,-1,sizeof(like));
	for(int i = 0; i < M; i++){
		scanf("%d",&temp);
		like[temp] = i;
	}

	scanf("%d",&L);
	int num = 0;
	for(int i = 0; i < L; i++){
		scanf("%d",&G[i]);
		if(like[G[i]] >= 0){
			temp_path[num++] = like[G[i]]; 
		}
	}
	res = -1; 
	// LISµÄÄ£°å 
	for(int i = 0; i < num;i++){
		dp[i] = 1;
		for(int j = 0; j < i;j++){
			if(temp_path[j] <= temp_path[i] && dp[i] < dp[j] +1){
				dp[i] = dp[j] + 1;
			}
		}
		res = max(res,dp[i]);
	}

	printf("%d",res);
	return 0;
}
