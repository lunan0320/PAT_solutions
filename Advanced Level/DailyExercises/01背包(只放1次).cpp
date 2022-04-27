#include <cstdio>
#include <algorithm>

using namespace std;

//物品上限
const int maxn = 101;
//重量上限
const int maxv = 10000;

int N, V; //N是数量，V是重量

int w[maxn]; //重量数组
int v[maxn]; //价值数组

int dp[maxn] = {0}; //dp数组表示以这个dp[i] 以i为重量上限的时候，价值的最大值

int main(){
    scanf("%d%d", &N, &V);
    fill(w,w+maxn,maxv);
    for(int i = 0; i < N; i ++){
        scanf("%d", &w[i]);
    }
    for(int i = 0; i < N; i++){
        scanf("%d", &v[i]);
    }

    for(int i = 0; i < N; i++){         //i是第几个物品
        for(int j = V; j >= w[i]; j--){ //j是现在的容量
            dp[j] = max(dp[j],dp[j-w[i]] + v[i] );
        }
    }
    int res = 0;
    for(int i =  0; i <= V; i++){
    	if(dp[i] > res){
    		res = dp[i];
		}
	}
    printf("可放入的物品最大价值为：%d",res);
    return 0;
}
/*
测试用例
5 8
3 5 1 2 2
4 5 2 1 3

预期输出
10 

*/
