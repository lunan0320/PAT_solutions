#include <cstdio>
#include <cstring>

using namespace std; 

const int maxn = 1010;

//A��ʾ������ַ��� 
char A[maxn];

//dp[][]��ʾ��i��j�Ƿ��ǻ��Ĵ� 
int dp[maxn][maxn];

int main(){
	gets(A);
	int lenA = strlen(A);
	//��ʼ�� 
	memset(dp,0,sizeof(dp)); 
	int ans = 1; 
	for(int i = 0; i < lenA; i++){
		//�Լ����Լ��Ļ��Ĵ�Ϊ1 
		dp[i][i] = 1;
		if(i < lenA-1){
			if(A[i] == A[i+1]){
				//������������2�Ļ��Ĵ� 
				dp[i][i+1] = 1;
				ans = 2;
			}			
		}

	}
//	for(int i = 0; i < lenA; i++){
//		printf("%c ",A[i]);
//	}
//	printf("\n");
//	
//	printf(" %c %c",A[0],A[4]);
	
	//���Ӵ��ļ��ö�� 
	for(int L = 3; L <= lenA; L++){
		//ö����ʼ�� 
		for(int i = 0; i + L -1 < lenA; i++){
			int j = i + L -1;
			//״̬ת�Ʒ��� 
			printf("%d %d %c %c",i,j,A[i],A[j]);
			printf("\n");
			if(A[i] = A[j] && dp[i+1][j-1] ==1){
				//�ж�i+1 �� j-1֮���Ƿ��ǻ��Ĵ� 
				dp[i][j] = 1;
				ans = L;
			} 
		}
	}
	printf("�����Ĵ�����Ϊ��%d\n",ans);
}

/*
���㷨�ʼǡ� page 436

�������룺
PATZJUJZTACCBCC

Ԥ�������
9 
*/
