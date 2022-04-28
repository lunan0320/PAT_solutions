#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 2010;

//每一个多项式的项数 
int K1, K2;

//指数数组 
int N1[maxn];
int N2[maxn];

//系数数组
double a1[maxn];
double a2[maxn];

 
//输出 index表示的是指数，值表示系数 
double res[maxn];

 
int main(){
	
	scanf("%d", &K1);
	for(int i = 0;i < K1; i++){
		scanf("%d%lf",&N1[i],&a1[i]);
	}
	scanf("%d", &K2);
	for(int i = 0;i < K2;i++){
		scanf("%d%lf",&N2[i],&a2[i]);
	}
	memset(res,0,sizeof(res));
	int i = 0, j = 0;
	int K3 = 0;
	int count = 0;
	for(int i = 0; i < K1; i++){
		double a1_i = a1[i];
		int N1_i = N1[i];
		for(int j = 0; j < K2; j++){
			double a2_j = a2[j];
			int N2_j = N2[j];
			double temp = a1_i * a2_j;

			res[N1_i + N2_j] += temp;
		}
	}
	//此处的计数应该是算完之后再计数，在过程中计数会有的地方无法通过 
	for(int i = 0; i < maxn; i++){
		if(res[i]!=0){
			count++;
		}
	}
	//输出结果 
	printf("%d", count);
	for(int i = maxn - 1; i >= 0; i--){
		if(res[i]!=0){
			printf(" %d %.1lf",i,res[i]);
		}	
	}
	
} 


/*
测试用例：
2 1 2.4 0 3.2
2 2 1.5 1 0.5 
*/
