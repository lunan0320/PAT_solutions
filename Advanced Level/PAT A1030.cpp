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
	//此处要对每个点的最短路径的上一个结点赋值为自己（忘记！） 
	for(int i = 0; i < N; i++){
		pre[i] = i;
	}
	for(int i = 0; i < N; i++){
		//找到一个在未访问的部分，连通且距离最小的 
		int u = -1, MIN = INF;
		for(int j = 0; j < N; j++){
			if(!visit[j] && d[j] < MIN){
				u = j;
				MIN = d[u];
			}
		}
		//此时没有和源点s相连通的点 
		if(u == -1){
			return;
		}
		visit[u] = true;
		//如果找到u则dijkstra处理
		for(int j = 0; j < N; j++){
			if(!visit[j] && G[u][j].dist != INF){
				//判断如果最短路径相同，考虑第二标尺 
				if(G[u][j].dist + d[u] == d[j]){
					//如果花费更小了，那就更新花费 
					if(c[u]+ G[u][j].cost< c[j]){
						pre[j] = u;
						c[j] = c[u] + G[u][j].cost;
					}
				//如果满足条件，则更新最短路径 
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
	//此处首先要对原始的数组赋值（忘记！） 
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
	//递归，找到这个路径并打印 
	recursive(D);
	//打印最短距离和最小花费 
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

