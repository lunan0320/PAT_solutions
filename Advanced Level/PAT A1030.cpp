#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


const int maxn = 1000;
const int INF = 10000000;

struct Node{
	int dist;
	int cost;

};


Node G[maxn][maxn];
int pre[maxn];
bool visit[maxn];
int c[maxn];
int d[maxn];

int N, M, S, D;


void Dijkstra(int s){
	 
	fill(c,c+maxn,INF);
	fill(d,d+maxn,INF);

	d[s] = 0;
	c[s] = 0;
	//�˴�Ҫ��ÿ��������·������һ����㸳ֵΪ�Լ������ǣ��� 
	for(int i = 0; i < N; i++){
		pre[i] = i;
	}
	for(int i = 0; i < N; i++){
		//�ҵ�һ����δ���ʵĲ��֣���ͨ�Ҿ�����С�� 
		int u = -1, MIN = INF;
		for(int j = 0; j < N; j++){
			if(!visit[j] && d[j] < MIN){
				u = j;
				MIN = d[u];
			}
		}
		//��ʱû�к�Դ��s����ͨ�ĵ� 
		if(u == -1){
			return;
		}
		visit[u] = true;
		//����ҵ�u��dijkstra����
		for(int j = 0; j < N; j++){
			if(!visit[j] && G[u][j].dist != INF){
				//�ж�������·����ͬ�����ǵڶ���� 
				if(G[u][j].dist + d[u] == d[j]){
					//������Ѹ�С�ˣ��Ǿ͸��»��� 
					if(c[u]+ G[u][j].cost< c[j]){
						pre[j] = u;
						c[j] = c[u] + G[u][j].cost;
					}
				//���������������������·�� 
				}else if(d[u] + G[u][j].dist < d[j]) {
					pre[j] = u;
					d[j] = d[u] + G[u][j].dist;
					c[j] = c[u] + G[u][j].cost;
				}
			}
		} 
	}
}

void recursive(int d){
	if(d == S){	
		printf("%d ",d);
		return;
	} 
	recursive(pre[d]);
	printf("%d ",d);
}

int main(){
	scanf("%d%d%d%d", &N, &M, &S, &D);
	int C1, C2, Dist, Cost;
	//�˴�����Ҫ��ԭʼ�����鸳ֵ�����ǣ��� 
	for(int i = 0; i < maxn; i++){
		for(int j = 0; j < maxn; j++){
			G[i][j].dist = INF;
		}
	}
	for(int i = 0; i < M; i++){
		scanf("%d%d%d%d", &C1, &C2, &Dist, &Cost);
		G[C1][C2].dist = Dist;
		G[C1][C2].cost = Cost;
		G[C2][C1].dist = Dist;
		G[C2][C1].cost = Cost;
	}
	printf("\n%d\n",G[10][10].dist);
	Dijkstra(S);
	//�ݹ飬�ҵ����·������ӡ 
	recursive(D);
	//��ӡ��̾������С���� 
	printf("%d %d",d[D],c[D]);
	
	return 0;
}

/*

4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20

*/

