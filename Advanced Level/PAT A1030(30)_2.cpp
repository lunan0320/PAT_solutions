#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 501;
const int INF = 1000000;

int N,M,S,D;

//记录distance 
int G[maxn][maxn];

//记录路径cost
int cost[maxn][maxn];
 
//记录最短distance
int d[maxn];

//记录是否被访问过
bool visit[maxn] = {false};
 
int pre[maxn];

//记录最短路径下的最小花费 
int c[maxn];

 
 //判断最小值条件 
int minCost = INF;
vector<int> resPath;


void Dijkstra(int s){
	fill(d,d+maxn,INF);
	fill(c,c+maxn,INF);
	for(int i = 0; i < maxn;i++){
		pre[i] = i;
	} 
	//初始化 
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
		//没有找到最小的u
		if(u == -1){
			return;
		} 
		//设置已访问
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
	//递归到路径起点 
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
