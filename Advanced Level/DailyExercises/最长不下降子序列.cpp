#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100;

//N��ʾ����� 
int N;
//��¼ÿ�������ֵ 
int A[maxn];

//dp[]�����м�¼�����Ըý��Ϊ�յ��LIS�ĳ��� 
int dp[maxn]; 

//Longest Increasing Sequence
int LIS(){
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i = 1; i < N; i++){
		//���θ���iǰ��������� 
		for(int j = 0; j < i; j++){
			//�ж�����iǰ���ĳ����������С  �Ұ�i����j�������л�ʹ����i��β�������и��� 
			if(A[j] <= A[i] && dp[j] + 1 > dp[i]){
				//��ʾ��ʱ��iΪ��β��ǰ����d[j]
				dp[i] = dp[j] + 1;
			} 
		} 
	}
	int res = 0;
	for(int i = 0; i < N; i++){
		if(dp[i] > res){
			res = dp[i];
		}
	} 
	return res;
} 

int main(){
	//�������� 
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d",&A[i]);
	}	
	int res = LIS();
	printf("����������������г���Ϊ%d\n", res);
	return 0;
}

/*
���㷨�ʼǡ�  page 433 

��������:
8
1 2 3 -9 3 9 0 11

Ԥ�����:
6 

*/
