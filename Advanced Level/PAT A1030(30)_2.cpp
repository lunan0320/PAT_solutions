#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 501;
const int INF = 1000000;

int N,M,S,D;

//��¼distance 
int G[maxn][maxn];

//��¼·��cost
int cost[maxn][maxn];
 
//��¼���distance
int d[maxn];

//��¼�Ƿ񱻷��ʹ�
bool visit[maxn] = {false};
 
int pre[maxn];

//��¼���·���µ���С���� 
int c[maxn];

 
 //�ж���Сֵ���� 
int minCost = INF;
vector<int> resPath;


void Dijkstra(int s){
	fill(d,d+maxn,INF);
	fill(c,c+maxn,INF);
	for(int i = 0; i < maxn;i++){
		pre[i] = i;
	} 
	//��ʼ�� 
	d[s] = 0;
	c[s] = 0;
	for(int i = 0; i < N; i++){
		int u = -1, min = INF;
		for(int j = 0; j < N; j++){
			if(!visit[j] && d[j] < min){
				min = d[j];
				u = j;
			}	
		}
		//û���ҵ���С��u
		if(u == -1){
			return;
		} 
		//�����ѷ���
		visit[u] = true;
		for(int j = 0; j < N; j++){
			if(!visit[j] && G[u][j] != INF){
				if(d[u] + G[u][j] < d[j]){
					d[j] = G[u][j] + d[u];
					c[j] = cost[u][j] + c[u];
					pre[j] = u;
				}else if (d[u] + G[u][j] == d[j]){
					if(c[u] + cost[u][j] < c[j]){
						c[j] = c[u] + cost[u][j];
						pre[j] = u;
					}
				}
			}
		} 
	} 
}

void DFS(int index){
	//�ݹ鵽·����� 
	if(index == S){
		printf("%d ",index);
		return;
	}
	DFS(pre[index]);
	printf("%d ",index);
}

int main(){
	scanf("%d%d%d%d",&N,&M,&S,&D);
	fill(G[0],G[0] + maxn * maxn, INF);
	fill(cost[0],cost[0] + maxn * maxn, INF);
	int a,b,m,t;
	for(int i = 0; i < M; i++){
		 scanf("%d%d%d%d",&a,&b,&m,&t);
		 G[a][b] = G[b][a] = m;
		 cost[a][b] = cost[b][a] = t;
	}
	
	Dijkstra(S);
	
	DFS(D);

	printf("%d %d",d[D],c[D]);
	
	
	return 0;
}
