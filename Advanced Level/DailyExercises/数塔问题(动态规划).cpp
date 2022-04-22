#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100;

//dp[]��¼״̬����¼�˵�ǰ�������·������н������� 
int dp[maxn][maxn] = {0};
int f[maxn][maxn];

int n;

int main(){
	scanf("%d",&n);
	//�������� 
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			scanf("%d", &f[i][j]);
		}
	}
	//����dp����ĳ�ʼֵ 
	for(int i = 1; i <= n; i++){
		dp[n][i] = f[n][i];
	} 
	for(int i = n-1; i>= 1; i--){
		for(int j = 1; j <= i; j++){
			//״̬ת�Ʒ��� 
			dp[i][j] = max(dp[i+1][j],dp[i+1][j+1]) + f[i][j];
		}
	} 
	printf("%d\n",dp[1][1]);
	
	return 0;
} 

/*
���㷨�ʼǡ� page 426 

ÿ��ֻ��������һ�����ӵ��������֣���·�������ĺ��Ƕ��٣� 
 
����������
5
5
8 3 
12 7 16
4 10 11 6
9 5 3 9 4

Ԥ�������
44 
*/
