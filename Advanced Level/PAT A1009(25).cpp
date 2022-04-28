#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 2010;

//ÿһ������ʽ������ 
int K1, K2;

//ָ������ 
int N1[maxn];
int N2[maxn];

//ϵ������
double a1[maxn];
double a2[maxn];

 
//��� index��ʾ����ָ����ֵ��ʾϵ�� 
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
	//�˴��ļ���Ӧ��������֮���ټ������ڹ����м������еĵط��޷�ͨ�� 
	for(int i = 0; i < maxn; i++){
		if(res[i]!=0){
			count++;
		}
	}
	//������ 
	printf("%d", count);
	for(int i = maxn - 1; i >= 0; i--){
		if(res[i]!=0){
			printf(" %d %.1lf",i,res[i]);
		}	
	}
	
} 


/*
����������
2 1 2.4 0 3.2
2 2 1.5 1 0.5 
*/
