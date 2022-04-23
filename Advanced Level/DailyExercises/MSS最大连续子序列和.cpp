#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 1000;

//A��ʾ���������ÿ��ֵ 
int A[maxn];

//N��ʾ��������� 
int N; 
//dp[]��ʾ�������Ϊ������������������еĺ�
int dp[maxn]; 

bool cmp(int a, int b){
	return a > b;
}

int MSS(){
	memset(dp,0,sizeof(dp));
	dp[0] = A[0];
	for(int i = 1; i < N; i++){
		//��̬�滮���� 
		dp[i] = max((dp[i-1] + A[i]),A[i]);
	}
	sort(dp,dp+N, cmp);
	int res = dp[0];
	return res;
}

int main(){
	//�������� 
	scanf("%d", &N);
	for(int i =0; i < N; i++){
		scanf("%d", &A[i]);
	}
	//������������������ 
	int res = MSS();
	printf("������������еĺ�Ϊ:%d\n",res);
	return 0;
} 

/*
���㷨�ʼǡ� page 430

�������룺
6
-2 11 -4 13 -5 -2

Ԥ�������
20 

*/
