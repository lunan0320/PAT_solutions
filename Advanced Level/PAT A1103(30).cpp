#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int N, K, P;
int bestSum = -1;
vector<int> fac, ans ,temp;


void init(){
//	for(int i = 0; i < N; i ++){
//		int temp = pow(i,P);
//		if(temp <= N){
//			fac.push_back(temp);
//		}else{
//			return;
//		}
//	}
	int i = 0,temp = 0;
	while(temp <= N){
		fac.push_back(temp);
		temp = pow(++i,P);
	}
}

//index表示当前的底数，nowK表示选了几个，sum表示幂次和，facSum表示因子和 
void  DFS(int index,int nowK,int sum,int facSum){
	if(nowK == K && sum == N){
		if(facSum > bestSum){
			ans = temp;
			bestSum=facSum;
		}
		return;
	} 
	//不可能情况 
	if(sum > N || nowK > K) {
		return;
	} 
	//递归
	if(index > 0){ //fac[0]是0 
		temp.push_back(index);
		DFS(index,nowK+1,sum+fac[index],facSum+index);
		temp.pop_back();
		DFS(index-1,nowK,sum,facSum);
	} 
} 

int main(){
	scanf("%d %d %d",&N, &K, &P);
	init();
	//从最后一个开始dfs 
	DFS(fac.size() - 1,0,0,0);
	if(bestSum == -1){
		printf("Impossible\n");
	}else{
		printf("%d = %d^%d",N,ans[0],P);
		for(int i = 1; i < ans.size(); i++){
			printf(" + %d^%d",ans[i],P);
		}
	}
	return 0;
}
