#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 1000000;
const int maxn = 1000;

int G[maxn][maxn];
int num[maxn] ;  //�������·��������
int weight[maxn]; //�����Ȩ
int d[maxn]; //�������ʼ�㵽v����̾��� 
int w[maxn]  ; //�������v������Ȩ 
bool visit[maxn] = {false};

int N, M, C1, C2;

void Dijkstra(int s){
	memset(w,0,sizeof(w));
	memset(num,0,sizeof(num));
	fill(d,d+maxn,INF);
	//�˴�Ҫ��¼�Լ����Լ�����̾��� 
	d[s] = 0;
	//�˴�Ҫ��¼�Լ����Լ������·�� 
	num[s] = 1;
	//�˴�Ҫ��¼�Լ����Լ������Ȩ�� 
	w[s] = weight[s]; 
	for(int i = 0; i < N; i++){
		int u = -1, MIN = INF;
		//�ҳ�һ��δ���ʵ���̵� 
		for(int j = 0; j < N; j++){
			if(!visit[j] && d[j] < MIN ){
				u = j;
				MIN = d[j];
			}			
		}
		//����Ҳ�����̵ģ�˵��û�к�s��ͨ�� 
		if(u == -1){
			return;
		}
		//��������ͨ�����
		visit[u] = true;
		for(int j = 0 ; j < N; j++){
			if(!visit[j] && G[u][j] != INF &&d[u] + G[u][j] < d[j]){
				//���µ�Ȩ�����·�� 
				num[j] = num[u];
				d[j] = d[u] +G[u][j]; 
				w[j] = w[u] + weight[j];
			}else if(!visit[j] && G[u][j] != INF && d[u] + G[u][j] == d[j]){
				num[j] += num[u];
				w[j] = w[u] + weight[j]; //���µ�Ȩ 
			}
		} 
		
	}
} 

int main(){
	scanf("%d%d%d%d", &N, &M, &C1, &C2);
	//����N�����еľ�Ԯ���� 
	for(int i = 0; i < N;i++){
		scanf("%d", &weight[i]);
	}
	//���빫·��Ȩ��
	fill(G[0],G[0]+maxn*maxn,INF);
	int c1,c2,W;
	for(int i = 0; i < M; i++){
		scanf("%d%d%d",&c1,&c2,&weight);
		G[c1][c2] = W;
		G[c2][c1] = W;
	} 
	//�����㷨��source 
	Dijkstra(C1);
	//���յ������ 
	printf("%d %d",num[C2],w[C2]); 
	return 0;
} 


/*

5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
*/
