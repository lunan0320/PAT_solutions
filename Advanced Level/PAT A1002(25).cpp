#include <cstdio>

const int maxn = 30;

//每一个多项式的项数 
int K1, K2;
//指数数组 
int N1[maxn];
int N2[maxn];

//系数数组
double a1[maxn];
double a2[maxn];

 
//输出
int res_N[maxn];
double res_a[maxn];

 
int main(){
	scanf("%d", &K1);
	for(int i = 0;i < K1; i++){
		scanf("%d%lf",&N1[i],&a1[i]);
	}
	scanf("%d", &K2);
	for(int i = 0;i < K2;i++){
		scanf("%d%lf",&N2[i],&a2[i]);
	}
	int i = 0, j = 0;
	int K3 = 0;
	while(i < K1 && j < K2){
		if(N1[i] == N2[j]){
			res_a[K3] = a1[i] + a2[j++];
			res_N[K3++] = N1[i++];
			continue;
		}else if (N1[i] > N2[j]){
			res_a[K3] = a1[i];
			res_N[K3++] = N1[i++];
		}else if (N1[i] < N2[j]){
			res_a[K3] = a2[j];
			res_N[K3++] = N2[j++];
		}
	}
	while(i<K1){
		res_a[K3] = a1[i];
		res_N[K3++] = N1[i++];
	}
	while(j<K2){
		res_a[K3] = a2[j];
		res_N[K3++] = N2[j++];
	}
	//输出结果 
	printf("%d", K3);
	for(int i = 0; i < K3; i++){
		printf(" %d %.1lf",res_N[i],res_a[i]);
	}
	
} 


/*
测试用例：
2 1 2.4 0 3.2
2 2 1.5 1 0.5 
*/
