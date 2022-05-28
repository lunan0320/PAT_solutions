#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 10010;
 
//��¼ÿ��Ӳ�ҵ�value 
int w[maxn];

//N��Ӳ�ң�Ҫ��MԪ 
int N, M;

//��ʾ��iԪ��ʱ������ֵ 
int dp[maxn]; 

//�ڼ�ֵj��ʱ���Ƿ�ѡ���i��Ӳ�� 
bool choice[maxn][maxn];
bool flag[maxn] = {false};
 
bool cmp(int a,int b){
	return a> b;
}


int main(){
	scanf("%d %d",&N,&M);
	for(int i = 1; i <= N; i++){
		scanf("%d",&w[i]);
	}
	//Ҫ����ѡ��ֵ�ߵ� 
	sort(w+1,w+N+1,cmp);
	
	//���ѭ���Ǳ���ÿ��Ӳ�� 
	for(int i = 1;i <= N;i++){
		//�ڲ�ѭ���ǿ����Ӳ���ö��ٴ� 
		for(int v = M; v >= w[i];v--){
			//�۸�����ʣ��ڿռ�v��ʱ���õ�i��Ӳ�Ҵ���ļ�ֵ���� 
			if(dp[v] <= dp[v-w[i]] + w[i]){
				
				dp[v] = dp[v-w[i]] + w[i];
				//�ڼ۸�v��ʱ��ѡ��i 
				choice[i][v] = true;
			}else{
				choice[i][v] = false;
			}
		}
	}
	if(dp[M] != M){
		printf("No Solution");
		return 0;
	} 
	int num = 0,v = M;
	for(int k = N; k >= 0;k--){
		if(choice[k][v]){
			flag[k] = true;
			v -= w[k];
			num++;
		}
		else{
			flag[k] = false;
		}
	}
	for(int i = N; i >= 1; i--){
		if(flag[i] == true){
			printf("%d",w[i]);
			num--;
			if(num > 0){
				printf(" ");
			}
		}
	}
	return 0;
} 

