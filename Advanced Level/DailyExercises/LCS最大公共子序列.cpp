#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100;

//dp[i][j]��ʾ�ַ���A��i��λ���ַ���B��j��λ֮ǰ��LCS 
int dp[maxn][maxn];

char A[maxn];
char B[maxn];


int main(){
	gets(A+1);
	gets(B+1);

	int lenA = strlen(A+1);
	int lenB = strlen(B+1);

	//���ñ߽� �˴�Ҫ����lenA��lenB 
	for(int i = 0; i <= lenA ;i++){
		dp[i][0] = 0;
	} 
	for(int j = 0; j <= lenB; j++){
		dp[0][j] = 0;
	}
	//״̬ת�Ʒ���
	
	for(int i = 1; i <= lenA; i++){
		for(int j = 1; j <= lenB; j++){
			if(A[i] == B[j]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	} 
	printf("�����ַ�������󹫹������еĳ���Ϊ:%d\n",dp[lenA][lenB]);
	return 0;
	
} 


/*
���㷨�ʼǡ�page 435


�������룺
sadstory
adminsorry

Ԥ�������
6 
*/
