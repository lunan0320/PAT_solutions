#include <cstdio>
#include <algorithm>

using namespace std;

//��Ʒ����
const int maxn = 101;
//��������
const int maxv = 10000;

int N, V; //N��������V������

int w[maxn]; //��������
int v[maxn]; //��ֵ����

int dp[maxn] = {0}; //dp�����ʾ�����dp[i] ��iΪ�������޵�ʱ�򣬼�ֵ�����ֵ

int main(){
    scanf("%d%d", &N, &V);
    fill(w,w+maxn,maxv);
    for(int i = 0; i < N; i ++){
        scanf("%d", &w[i]);
    }
    for(int i = 0; i < N; i++){
        scanf("%d", &v[i]);
    }

    for(int i = 0; i < N; i++){         //i�ǵڼ�����Ʒ
        for(int j = V; j >= w[i]; j--){ //j�����ڵ�����
            dp[j] = max(dp[j],dp[j-w[i]] + v[i] );
        }
    }
    int res = 0;
    for(int i =  0; i <= V; i++){
    	if(dp[i] > res){
    		res = dp[i];
		}
	}
    printf("�ɷ������Ʒ����ֵΪ��%d",res);
    return 0;
}
/*
��������
5 8
3 5 1 2 2
4 5 2 1 3

Ԥ�����
10 

*/
