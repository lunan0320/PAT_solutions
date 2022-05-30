#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;

int main(){
	int N,K;
	scanf("%d%d",&N,&K);
	int coins[maxn];
	int hashtable[maxn] = {0};
	for(int i = 0; i < N; i++){
		scanf("%d",&coins[i]);
		hashtable[coins[i]]++;
	} 
	sort(coins,coins+N);
	bool flag = false;
	for(int i = 0; i < N; i++){
		int a = coins[i];
		int res = K-a;
		if(a!= res && hashtable[res]> 0){
			flag = true;
			printf("%d %d\n",a,res);
			break;
		}else if(a == res && hashtable[res] > 1){
			flag = true;
			printf("%d %d\n",a,res);
			break;
		}
	} 
	if(!flag){
		printf("No Solution\n");
	} 
	return 0;
}
